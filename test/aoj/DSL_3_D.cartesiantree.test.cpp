#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../datastructure/cartesiantree.cpp"
#include "../../tree/lca.cpp"
#undef call_from_test

signed main(){
  int n,l;
  cin>>n>>l;

  vector<int> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];

  CartesianTree ct;
  int r=ct.build(vs);

  LCA lca(n);
  for(int i=0;i<n;i++)
    if(~ct.P[i]) lca.add_edge(i,ct.P[i]);
  lca.build(r);

  for(int i=0;i+l<=n;i++){
    if(i) cout<<" ";
    cout<<vs[lca.lca(i,i+l-1)];
  }
  cout<<endl;
  return 0;
}
