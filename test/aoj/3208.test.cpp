// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3208
// verification-helper: ERROR 1e-10

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/precision.cpp"
#include "../../tools/chminmax.cpp"
#include "../../graph/topologicalsort.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  while(cin>>n>>m,n){
    TopologicalSort G(n);
    for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      a--;b--;
      G.add_edge(a,b);
    }

    auto ps=G.build();
    if(ps.empty()){
      cout<<0<<endl;
      continue;
    }

    vector<int> dp(n,0);
    for(int i=n-1;i>=0;i--){
      int v=ps[i];
      for(int u:G.G[v])
        chmax(dp[v],dp[u]+1);
    }

    cout<<-1.0/accumulate(dp.begin(),dp.end(),0.0)<<endl;
  }
  return 0;
}
