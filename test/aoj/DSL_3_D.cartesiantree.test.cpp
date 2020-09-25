// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/cartesiantree.cpp"
#include "../../tree/lca.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,l;
  cin>>n>>l;

  vector<int> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];

  auto ps=cartesian_tree(vs);

  LCA lca(n);
  int rt;
  for(int i=0;i<n;i++){
    if(~ps[i]) lca.add_edge(i,ps[i]);
    else rt=i;
  }
  lca.build(rt);

  for(int i=0;i+l<=n;i++){
    if(i) cout<<" ";
    cout<<vs[lca.lca(i,i+l-1)];
  }
  cout<<endl;
  return 0;
}
