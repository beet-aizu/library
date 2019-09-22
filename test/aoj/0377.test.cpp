#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0377"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fixpoint.cpp"
#include "../../graph/lowlink.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  LowLink bg(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    bg.add_edge(a,b);
  }
  int k=bg.build();
  auto& G=bg.T;

  vector<int> cs(k);
  for(int i=0;i<k;i++) cs[i]=bg.C[i].size();

  vector< vector<int> > dp(2,vector<int>(k,0));
  vector<int> used(k,0);
  auto dfs=
    MFP([&](auto dfs,int v,int p)->void{
          if(used[v]) return;
          used[v]=1;
          dp[0][v]=0;
          dp[1][v]=cs[v];
          for(int u:G[v]){
            if(u==p) continue;
            dfs(u,v);
            dp[0][v]+=max(dp[0][u],dp[1][u]);
            dp[1][v]+=dp[0][u];
          }
          return;
        });

  int ans=0;
  for(int i=0;i<k;i++){
    if(used[i]) continue;
    dfs(i,-1);
    ans+=max(dp[0][i],dp[1][i]);
  }
  cout<<ans<<endl;
  return 0;
}
