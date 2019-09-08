#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/weightedunionfindtree.cpp"
#undef call_from_test

signed DSL_1_B(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  WeightedUnionFind<int> wuf(n,0);

  for(int i=0;i<q;i++){
    int t,x,y,z;
    cin>>t>>x>>y;
    if(t){
      if(wuf.same(x,y)) cout<<wuf.diff(x,y)<<"\n";
      else cout<<"?\n";
    }else{
      cin>>z;
      wuf.unite(x,y,z);
    }
  }
  cout<<flush;
  return 0;
}
