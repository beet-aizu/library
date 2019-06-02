#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//BEGIN CUT HERE
template<typename T>
struct PrimalDual{
  struct edge{
    int to;
    T cap,cost;
    int rev;
    edge(){}
    edge(int to,T cap,T cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
  };
  
  T INF;
  vector<vector<edge> > G;
  vector<T> h,dist;
  vector<int> prevv,preve;

  PrimalDual(){}
  PrimalDual(int n,T INF):INF(INF),G(n),h(n),dist(n),prevv(n),preve(n){}
  
  void add_edge(int from,int to,T cap,T cost){
    G[from].emplace_back(to,cap,cost,G[to].size());
    G[to].emplace_back(from,0,-cost,G[from].size()-1);
  }

  T flow(int s,int t,T f,int &ok){    
    T res=0;
    fill(h.begin(),h.end(),0);
    while(f>0){
      struct P{
        T first;
        int second;
        P(T first,int second):first(first),second(second){}
        bool operator<(const P&a) const{return first>a.first;}
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
          if(dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
            dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
            prevv[e.to]=v;
            preve[e.to]=i;
            que.emplace(dist[e.to],e.to);
          }
        }
      }
      if(dist[t]==INF) return ok=0;
      
      for(int v=0;v<(int)h.size();v++) h[v]+=dist[v];

      T d=f;
      for(int v=t;v!=s;v=prevv[v])
        d=min(d,G[prevv[v]][preve[v]].cap);
      
      f-=d;
      res+=d*h[t];
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
//END CUT HERE

int GRL_6_B(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int v,e,f;
  cin>>v>>e>>f;
  
  const int INF = 1<<28;
  PrimalDual<int> pd(v,INF);
  for(int i=0;i<e;i++){
    int u,v,c,d;
    cin>>u>>v>>c>>d;
    pd.add_edge(u,v,c,d);
  }
  int ok=0;
  int res=pd.flow(0,v-1,f,ok);
  cout<<(ok?res:-1)<<endl;
  return 0;
}
/*
  verified on 2018/03/17
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=jp
*/

signed SPOJ_GREED_solve(){  
  int n;
  cin>>n;
  vector<int> cnt(n,0);
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    cnt[x-1]++;
  }
  using ll = long long;
  const ll INF = 1<<28;
  int S=n,T=n+1;
  PrimalDual<ll> G(n+2,INF);

  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    G.add_edge(x,y,INF,1);
    G.add_edge(y,x,INF,1);
  }
  
  for(int i=0;i<n;i++){
    G.add_edge(S,i,cnt[i],0);
    G.add_edge(i,T,1,0);
  }

  int ok=0;
  ll res=G.flow(S,T,n,ok);
  assert(ok);
  cout<<res<<endl;
  return 0;
}

signed SPOJ_GREED(){  
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--) SPOJ_GREED_solve();
  return 0;
}
/*
  verified on 2018/03/17
  https://www.spoj.com/problems/GREED/
*/

signed CFR190_B(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  int n,m;
  cin>>n>>m;
  vector<string> vp(n);
  vector<int> vs(n);
  for(int i=0;i<n;i++) cin>>vp[i]>>vs[i];
  vector<int> ss(m);
  for(int i=0;i<m;i++) cin>>ss[i];
  
  const int INF = 1<<28;

  using ll = long long;
  PrimalDual<ll> G(n+m+3,INF);
  int S=n+m,T=n+m+1,V=n+m+2;
  for(int i=0;i<m;i++){
    G.add_edge(S,i,1,0);
    G.add_edge(i,V,1,-ss[i]);
    for(int j=0;j<n;j++){
      if(vp[j]=="ATK"){
        if(ss[i]>=vs[j]) G.add_edge(i,m+j,1,vs[j]-ss[i]);
      }
      if(vp[j]=="DEF"){
        if(ss[i]> vs[j]) G.add_edge(i,m+j,1,0);        
      }
    }
  }
  
  for(int i=0;i<n;i++)
    G.add_edge(m+i,T,1,-INF);

  G.add_edge(V,T,m,0);
  
  ll ans=0,res=0;
  for(int i=1;i<=m;i++){
    int ok=0;
    res+=G.flow(S,T,1,ok);
    if(i<=n) res+=INF;
    if(ok) chmax(ans,-res);
    else break;
  }
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2018/03/17
  https://codeforces.com/contest/321/problem/B
*/

signed main(){
  //GRL_6_B();
  //SPOJ_GREED();
  //CFR190_B();
  return 0;
}
