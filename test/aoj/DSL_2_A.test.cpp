#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../segtree/basic/ushi.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  auto f=[](int a,int b){return min(a,b);};
  SegmentTree<int> rmq(f,INT_MAX);
  rmq.init(n);

  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c) cout<<rmq.query(x,y+1)<<"\n";
    else rmq.set_val(x,y);
  }
  cout<<flush;
  return 0;
}
