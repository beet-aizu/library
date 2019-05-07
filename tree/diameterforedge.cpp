#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
template<typename T>
struct DiameterForEdge{
  using Edge = pair<int, T>;
  vector<T> dp;
  vector<vector<Edge> > G;
  DiameterForEdge(int n):dp(n),G(n){}
  void add_edge(int u,int v,T c){
    G[u].emplace_back(v,c);
    G[v].emplace_back(u,c);
  }
  void dfs(int v,int p,int &s){
    if(p<0) dp[v]=T(0);
    if(dp[s]<dp[v]) s=v; 
    for(Edge e:G[v]){
      int u=e.first;
      if(u==p) continue;
      dp[u]=dp[v]+e.second;      
      dfs(u,v,s);
    }
  }
  T build(){  
    int s=0;
    dfs(s,-1,s);
    dfs(s,-1,s);
    return dp[s];
  }
};
//END CUT HERE

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed GRL_5_A(){
  int n;
  cin>>n;
  DiameterForEdge<int> G(n);
  for(int i=1;i<n;i++){
    int s,t,w;
    cin>>s>>t>>w;
    G.add_edge(s,t,w);
  }
  cout<<G.build()<<endl;
  return 0;
}
/*
  verified on 2019/05/07
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp
*/

signed main(){
  GRL_5_A();  
  return 0;
}
