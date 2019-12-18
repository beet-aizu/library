#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2951"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../mod/lagrange_interpolation.cpp"
#undef call_from_test

using M = Mint<int>;
const int MAX = 6060;
M dp[2020][MAX]={};
M ad[2020][MAX]={};

signed main(){
  int n,m;
  while(cin>>n>>m,n||m){
    vector<int> as(m),bs(m),cs(m);
    vector< vector<int> > G(n+1);
    for(int i=0;i<m;i++){
      cin>>as[i]>>bs[i]>>cs[i];
      G[as[i]].emplace_back(i);
    }
    as.emplace_back(0);
    bs.emplace_back(1);
    cs.emplace_back(0);
    G[0].emplace_back(m);

    dp[0][0]=M(1);
    for(int v=0;v<=n;v++){
      for(int j=0;j<MAX;j++){
        if(j) ad[v][j]+=ad[v][j-1];
        dp[v][j]+=ad[v][j];
      }

      for(int i:G[v])
        for(int j=0;j+cs[i]<MAX;j++)
          ad[bs[i]][j+cs[i]]+=dp[as[i]][j];
    }

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
      int d,e;
      cin>>d>>e;
      vector<M> ys(dp[d]+n+n,dp[d]+n+n+n+1);
      if(e<n+n+n) cout<<dp[d][e]<<"\n";
      else cout<<lagrange_interpolation(ys,M(e-n-n))<<"\n";
    }

    for(int v=0;v<=n;v++)
      for(int j=0;j<MAX;j++)
        dp[v][j]=ad[v][j]=M(0);
  }
  cout<<flush;
  return 0;
}
