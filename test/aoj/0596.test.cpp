#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0596"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/bfs.cpp"
#include "../../tools/chminmax.cpp"
#undef call_from_test

signed main(){
  int n,k;
  cin>>n>>k;

  vector<int> cs(n),rs(n);
  for(int i=0;i<n;i++) cin>>cs[i]>>rs[i];

  vector<vector<int> > G(n);
  for(int i=0;i<k;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    G[x].emplace_back(y);
    G[y].emplace_back(x);
  }

  vector< vector<int> > di(n);
  for(int i=0;i<n;i++) di[i]=bfs(i,G);

  const int INF = 1e9;
  vector<int> dp(n,INF);
  vector<int> used(n,0);
  dp[0]=0;

  for(int i=0;i<n;i++){
    int u=-1;
    for(int j=0;j<n;j++){
      if(used[j]||dp[j]==INF) continue;
      if(u<0||dp[u]>dp[j]) u=j;
    }
    if(u<0) break;
    used[u]=1;
    for(int j=0;j<n;j++){
      if(di[u][j]>rs[u]) continue;
      chmin(dp[j],dp[u]+cs[u]);
    }
  }

  cout<<dp[n-1]<<endl;
  return 0;
}
