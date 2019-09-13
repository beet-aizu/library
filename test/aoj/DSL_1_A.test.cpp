#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/unionfindtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  UnionFind uf(n);
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c) cout<<uf.same(x,y)<<"\n";
    else uf.unite(x,y);
  }
  cout<<flush;
  return 0;
}
