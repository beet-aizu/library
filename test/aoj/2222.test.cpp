#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2222"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../graph/stronglyconnectedcomponent.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using M = Mint<int>;

  int n,m;
  cin>>n>>m;

  SCC scc(n);
  for(int i=0;i<m;i++){
    int s,d;
    cin>>s>>d;
    s--;d--;
    scc.add_edge(s,d);
  }

  int k=scc.build();
  vector<M> dp(k,1);
  vector<int> indeg(k,0);

  M ans(1);
  for(int i=0;i<k;i++){
    if(indeg[i]!=0) dp[i]-=M(1);
    for(int j:scc.T[i])
      dp[j]*=dp[i]+M(1);
    if(scc.T[i].empty()) ans*=dp[i]+M(1);
  }

  cout<<ans<<endl;
  return 0;
}
