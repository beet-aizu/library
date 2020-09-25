// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/lowlink.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;

  LowLink G(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    G.add_edge(u,v);
  }
  G.build();

  auto ap=G.ap;
  sort(ap.begin(),ap.end());
  for(int v:ap) cout<<v<<"\n";
  cout<<flush;
  return 0;
}
