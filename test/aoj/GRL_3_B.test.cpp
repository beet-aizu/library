// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B

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

  auto bs=G.bs;
  for(auto &e:bs)
    if(e.first>e.second) swap(e.first, e.second);

  sort(bs.begin(),bs.end());
  for(auto e:bs) cout<<e.first<<" "<<e.second<<"\n";
  cout<<flush;
  return 0;
}
