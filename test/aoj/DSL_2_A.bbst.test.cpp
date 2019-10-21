#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../bbst/basic/ushi.cpp"
#undef call_from_test

signed main(){
  int n,q;
  cin>>n>>q;

  auto f=[](int a,int b){return min(a,b);};
  SRBST<int> rmq(f,INT_MAX);
  vector<int> vs(n,INT_MAX);
  auto rt=rmq.build(vs);

  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c==0) rmq.set_val(rt,x,y);
    if(c==1) cout<<rmq.query(rt,x,y+1)<<"\n";
  }
  cout<<flush;
  return 0;
}
