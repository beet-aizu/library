#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
template<typename T>
struct DiameterForVertex{
  vector<T> vs,dp;
  vector<vector<int> > G;
  DiameterForVertex(vector<T> vs):vs(vs),dp(vs.size()),G(vs.size()){}
  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  void dfs(int v,int p,int &s){
    if(p<0) dp[v]=T(0);
    dp[v]+=vs[v];
    if(dp[s]<dp[v]) s=v; 
    for(int u:G[v]){
      if(u==p) continue;
      dp[u]=dp[v];
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

signed AGC033_C(){
  int n;
  cin>>n;
  vector<int> vs(n,1);
  DiameterForVertex<int> G(vs);
  for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    G.add_edge(x,y);
  }  
  int ans=G.build();
  cout<<((ans%3!=2)?"First":"Second")<<endl;
  return 0;
}
/*
  verified on 2019/05/07
  https://atcoder.jp/contests/agc033/tasks/agc033_c
*/

signed main(){
  AGC033_C();
  return 0;
}
