#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bbst/rbst/basic/base.cpp"
#include "../../bbst/rbst/basic/ushi.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  auto f=[](int a,int b){return min(a,b);};
  using Node = NodeBase<int>;
  constexpr size_t LIM = 1e6;
  Ushi<Node, LIM> rmq(f,INT_MAX);
  auto rt=rmq.build(vector<Node>(n,INT_MAX));

  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c==0) rmq.set_val(rt,x,y);
    if(c==1) cout<<rmq.query(rt,x,y+1)<<"\n";
  }
  cout<<flush;
  return 0;
}
