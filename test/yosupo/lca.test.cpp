#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/lowestcommonancestor.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  LowestCommonAncestor G(n);
  for(int i=1;i<n;i++){
    int p;
    cin>>p;
    G.add_edge(p,i);
  }
  G.build();

  for(int i=0;i<q;i++){
    int u,v;
    cin>>u>>v;
    cout<<G.lca(u,v)<<"\n";
  }
  cout<<flush;
  return 0;
}
