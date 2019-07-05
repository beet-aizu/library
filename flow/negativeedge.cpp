#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename TF,typename TC>
struct PrimalDual{
  struct edge{
    int to;
    TF cap;
    TC cost;
    int rev;
    edge(){}
    edge(int to,TF cap,TC cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
  };

  static const TC INF;
  vector<vector<edge>> G;
  vector<TC> h,dist;
  vector<int> prevv,preve;

  PrimalDual(){}
  PrimalDual(int n):G(n),h(n),dist(n),prevv(n),preve(n){}

  void add_edge(int u,int v,TF cap,TC cost){
    G[u].emplace_back(v,cap,cost,G[v].size());
    G[v].emplace_back(u,0,-cost,G[u].size()-1);
  }

  void dijkstra(int s){
    struct P{
      TC first;
      int second;
      P(TC first,int second):first(first),second(second){}
      bool operator<(const P&a) const{return a.first<first;}
    };
    priority_queue<P> que;
    fill(dist.begin(),dist.end(),INF);

    dist[s]=0;
    que.emplace(dist[s],s);
    while(!que.empty()){
      P p=que.top();que.pop();
      int v=p.second;
      if(dist[v]<p.first) continue;
      for(int i=0;i<(int)G[v].size();i++){
        edge &e=G[v][i];
        if(e.cap==0) continue;
        if(dist[v]+e.cost+h[v]-h[e.to]<dist[e.to]){
          dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
          prevv[e.to]=v;
          preve[e.to]=i;
          que.emplace(dist[e.to],e.to);
        }
      }
    }
  }

  TC flow(int s,int t,TF f,int &ok){
    TC res=0;
    fill(h.begin(),h.end(),0);
    while(f>0){
      dijkstra(s);
      if(dist[t]==INF){
        ok=0;
        return res;
      }

      for(int v=0;v<(int)h.size();v++)
        if(dist[v]<INF) h[v]=h[v]+dist[v];

      TF d=f;
      for(int v=t;v!=s;v=prevv[v])
        d=min(d,G[prevv[v]][preve[v]].cap);

      f-=d;
      res=res+h[t]*d;
      for(int v=t;v!=s;v=prevv[v]){
        edge &e=G[prevv[v]][preve[v]];
        e.cap-=d;
        G[v][e.rev].cap+=d;
      }
    }
    ok=1;
    return res;
  }
};
template<typename TF, typename TC> const TC PrimalDual<TF, TC>::INF = numeric_limits<TC>::max()/2;

//BEGIN CUT HERE
template<typename TF,typename TC>
struct NegativeEdge{
  PrimalDual<TF, TC> G;
  vector<TF> fs;
  TC sum;
  int S,T;
  NegativeEdge(){}
  NegativeEdge(int n):G(n+2),fs(n+2,0),sum(0),S(n),T(n+1){}

  void use_edge(int u,int v,TF cap,TC cost){
    fs[u]-=cap;
    fs[v]+=cap;
    sum=sum+cost*cap;
  }

  void add_edge(int u,int v,TF cap,TC cost){
    if(cost<TC(0)){
      use_edge(u,v,cap,cost);
      swap(u,v);
      cost=-cost;
    }
    G.add_edge(u,v,cap,cost);
  }

  TC flow(int ts,int tt,TF tf,int &ok){
    fs[ts]+=tf;
    fs[tt]-=tf;

    TF f=0;
    for(int i=0;i<S;i++){
      if(fs[i]>0){
        f+=fs[i];
        G.add_edge(S,i,+fs[i],TC(0));
      }
      if(fs[i]<0){
        G.add_edge(i,T,-fs[i],TC(0));
      }
    }
    return sum+G.flow(S,T,f,ok);
  }
};
//END CUT HERE

//INSERT ABOVE HERE
signed CFR190_B(){
  using ll = long long;
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  vector<string> vp(n);
  vector<int> vs(n);
  for(int i=0;i<n;i++) cin>>vp[i]>>vs[i];
  vector<int> ss(m);
  for(int i=0;i<m;i++) cin>>ss[i];

  int S=n+m,T=n+m+1;
  NegativeEdge<ll, ll> G(n+m+2);

  for(int i=0;i<m;i++){
    G.add_edge(S,i,1,0);
    for(int j=0;j<n;j++){
      if(vp[j]=="ATK"){
        if(ss[i]>=vs[j]) G.add_edge(i,m+j,1,vs[j]-ss[i]);
      }
      if(vp[j]=="DEF"){
        if(ss[i]> vs[j]) G.add_edge(i,m+j,1,0);
      }
    }
  }

  auto H=G;
  for(int i=0;i<m;i++){
    G.add_edge(i,T,1,-ss[i]);
    H.add_edge(i,T,1,0);
  }

  for(int j=0;j<n;j++){
    G.use_edge(m+j,T,1,0);
    H.add_edge(m+j,T,1,0);
  }

  int ok;
  ll ans=0;
  if(n<m){
    ll gv=G.flow(S,T,m,ok);
    if(ok) chmin(ans,gv);
  }
  ll hv=H.flow(S,T,m,ok);
  if(ok) chmin(ans,hv);

  cout<<-ans<<endl;
  return 0;
}
/*
  verified on 2019/07/05
  https://codeforces.com/contest/321/problem/B
*/

signed AOJ_2627(){
  using ll = long long;
  const ll INF = 1e9;
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  NegativeEdge<int, ll> G(n+1);

  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    map<int, int> dst;
    for(int j=0;j<k;j++){
      int t,c;
      cin>>t>>c;
      t--;
      G.use_edge(i,t,1,c);
      if(!dst.count(t)) dst[t]=c;
      chmin(dst[t],c);
    }

    for(auto p:dst)
      G.add_edge(i,p.first,INF,p.second);

    G.add_edge(i,n,INF,0);
  }

  int ok;
  ll ans=G.flow(0,n,INF,ok);
  assert(ok);
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/07/05
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2627
*/

const int MAX = 52;
struct ARR{
  array<int, MAX> val;
  ARR(){fill(val.begin(),val.end(),0);}
  ARR(int x){fill(val.begin(),val.end(),x);}
  int& operator[](int k){return val[k];};
  int operator[](int k)const{return val[k];};
  ARR operator+(const ARR &oth) const{
    ARR res;
    for(int i=0;i<MAX;i++)
      res[i]=val[i]+oth[i];
    return res;
  }
  ARR operator-(const ARR &oth) const{
    ARR res;
    for(int i=0;i<MAX;i++)
      res[i]=val[i]-oth[i];
    return res;
  }
  ARR operator-() const{
    ARR res;
    for(int i=0;i<MAX;i++)
      res[i]=-val[i];
    return res;
  }
  ARR operator*(const int &k) const{
    ARR res;
    for(int i=0;i<MAX;i++)
      res[i]=val[i]*k;
    return res;
  }
  ARR operator/(const int &k) const{
    ARR res;
    for(int i=0;i<MAX;i++)
      res[i]=val[i]/k;
    return res;
  }
  bool operator< (const ARR &oth) const{
    return val< oth.val;
  }
  bool operator==(const ARR &oth) const{
    return val==oth.val;
  }
};

namespace std {
  template<> class numeric_limits<ARR> {
  public:
    static ARR max() {return ARR(numeric_limits<int>::max());};
  };
}

signed AOJ_2679(){
  int n;
  cin>>n;
  vector<string> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];

  auto enc=
    [&](char c){
      if(isupper(c)) return c-'A';
      return 26+c-'a';
    };
  auto dec=
    [&](int d){
      if(d<26) return 'A'+d;
      return 'a'+d-26;
    };

  int S=n*2,T=n*2+1;
  NegativeEdge<int, ARR> G(n*2+2);
  for(int i=0;i<n;i++){
    G.add_edge(S,i,1,ARR());
    G.add_edge(n+i,T,1,ARR());
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ARR cost;
      cost[enc(vs[i][j])]=-1;
      G.add_edge(i,n+j,1,cost);
    }
  }

  int ok;
  auto res=G.flow(S,T,n,ok);
  assert(ok);

  string ans;
  for(int i=0;i<MAX;i++)
    for(int j=0;j<-res[i];j++)
      ans+=dec(i);
  cout<<ans<<endl;

  return 0;
}
/*
  verified on 2019/07/05
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2679
*/


signed main(){
  //CFR190_B();
  //AOJ_2627();
  AOJ_2679();
  return 0;
}
