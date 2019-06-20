#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct SCC{
  vector<vector<int> > G,R;
  vector<int> vs,used,blg;
  SCC(){}
  SCC(int n):G(n),R(n),used(n),blg(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    R[v].emplace_back(u);
  }

  void dfs(int v){
    used[v]=1;
    for(int u:G[v])
      if(!used[u]) dfs(u);
    vs.emplace_back(v);
  }

  void rdfs(int v,int k){
    used[v]=1;
    blg[v]=k;
    for(int u:R[v])
      if(!used[u]) rdfs(u,k);
  }

  int build(){
    int n=G.size();
    for(int v=0;v<n;v++)
      if(!used[v]) dfs(v);

    fill(used.begin(),used.end(),0);
    int k=0;
    for(int i=n-1;i>=0;i--)
      if(!used[vs[i]]) rdfs(vs[i],k++);
    return k;
  }

  int operator[](int i) const{return blg[i];};
};
//BEGIN CUT HERE
template<typename T>
struct Arborescence{
  struct edge{
    int to;
    T cost;
    edge(int to,T cost):to(to),cost(cost){}
  };
  vector<vector<edge>> B;

  Arborescence(int n):B(n){}

  void add_edge(int u,int v,T cost){
    assert(u!=v);
    B[u].emplace_back(v,cost);
  }

  T build(int r){
    T res=0;
    auto G=B;
    const T INF = numeric_limits<T>::max()/2;
    while(1){
      int n=G.size();
      vector<T> ws(n,INF);
      vector<int> rs(n,-1);
      for(int v=0;v<n;v++){
        for(edge &e:G[v]){
          if(e.cost<ws[e.to]){
            ws[e.to]=e.cost;
            rs[e.to]=v;
          }
        }
      }
      SCC scc(n);
      for(int i=0;i<n;i++){
        if(i==r) continue;
        scc.add_edge(rs[i],i);
        res+=ws[i];
      }
      int m=scc.build();
      if(m==n) break;
      vector<vector<edge>> H(m);
      for(int v=0;v<n;v++){
        for(auto &e:G[v]){
          if(scc[v]==scc[e.to]) continue;
          H[scc[v]].emplace_back(scc[e.to],e.cost-ws[e.to]);
        }
      }
      r=scc[r];
      G=H;
    }
    return res;
  }
};
//END CUT HERE

//INSERT ABOVE HERE
signed AOJ_GRL_2B(){
  int n,m,r;
  cin>>n>>m>>r;
  Arborescence<int> G(n);
  for(int i=0;i<m;i++){
    int s,t,w;
    cin>>s>>t>>w;
    G.add_edge(s,t,w);
  }
  cout<<G.build(r)<<endl;
  return 0;
}
/*
  verified on 2019/06/20
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B&lang=jp
*/

signed AOJ_2309(){
  double v[111][111];
  double c[111][111];

  Int n,m;
  cin>>n>>m;
  for(Int i=0;i<m;i++)
    for(Int j=0;j<n;j++)
      cin>>v[i][j];

  for(Int i=0;i<m;i++){
    c[i][i]=0;
    for(Int j=0;j<n;j++) c[i][i]+=v[i][j]*v[i][j];
  }

  for(Int i=0;i<m;i++){
    for(Int j=0;j<m;j++){
      if(i==j) continue;
      if(c[j][j]==0){
        c[i][j]=c[i][i];
        continue;
      }
      double r=0;
      for(Int k=0;k<n;k++)
        r+=v[i][k]*v[j][k];
      r/=c[j][j];
      c[i][j]=0;
      for(Int k=0;k<n;k++)
        c[i][j]+=(v[i][k]-r*v[j][k])*(v[i][k]-r*v[j][k]);
    }
  }

  Arborescence<double> G(m+1);
  for(Int i=0;i<m;i++){
    G.add_edge(m,i,c[i][i]);
    for(Int j=0;j<m;j++){
      if(i==j) continue;
      G.add_edge(j,i,c[i][j]);
    }
  }
  cout<<fixed<<setprecision(12)<<G.build(m)<<endl;
  return 0;
}
/*
  verified on 2019/06/20
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2309
*/

signed AOJ_2647(){
  int n,m;
  cin>>n>>m;

  vector<vector<int>> G(n),R(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    G[a].emplace_back(b);
    R[b].emplace_back(a);
  }

  vector<int> vs;
  for(int i=0;i<n;i++)
    if(R[i].empty()) vs.emplace_back(i);

  int sz=vs.size();
  map<int, int> rev;
  for(int i=0;i<sz;i++) rev[vs[i]]=i;

  const int INF = 1e9;
  vector<vector<int>> H;
  for(int r:vs){
    vector<int> dp(n,INF);

    using P = pair<int, int>;
    deque<P> deq;

    dp[r]=0;
    deq.emplace_back(r,0);

    while(!deq.empty()){
      int v,d;
      tie(v,d)=deq.front();deq.pop_front();
      if(dp[v]<d) continue;
      for(int u:G[v]){
        if(dp[u]<=dp[v]) continue;
        dp[u]=dp[v];
        deq.emplace_front(u,dp[u]);
      }
      for(int u:R[v]){
        if(dp[u]<=dp[v]+1) continue;
        dp[u]=dp[v]+1;
        deq.emplace_back(u,dp[u]);
      }
    }

    vector<int> di(sz);
    for(int i=0;i<sz;i++) di[i]=dp[vs[i]];
    H.emplace_back(di);
  }

  int cost=INF;
  vector<int> ans;

  for(int i=0;i<sz;i++){
    Arborescence<int> arb(sz);
    for(int j=0;j<sz;j++)
      for(int k=0;k<sz;k++)
        if(j!=k) arb.add_edge(j,k,H[j][k]);

    int res=arb.build(i);
    if(res<cost) cost=res,ans.clear();
    if(res==cost) ans.emplace_back(vs[i]);
  }

  cout<<ans.size()<<" "<<cost<<endl;
  for(int i=0;i<(int)ans.size();i++){
    if(i) cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}
/*
  verified on 2019/06/20
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2647
*/


signed main(){
  //AOJ_GRL_2B();
  //AOJ_2309();
  //AOJ_2647();
  return 0;
}
