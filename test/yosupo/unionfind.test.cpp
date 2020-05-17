#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/unionfind.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  UnionFind uf(n);
  for(int i=0;i<q;i++){
    int t,u,v;
    cin>>t>>u>>v;
    if(t==0) uf.unite(u,v);
    if(t==1) cout<<uf.same(u,v)<<"\n";
  }
  cout<<flush;
  return 0;
}
