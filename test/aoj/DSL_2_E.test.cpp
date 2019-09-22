#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../segtree/basic/dual.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  auto h=[](int a,int b){return a+b;};
  int ei=0;
  SegmentTree<int> seg(h,ei);
  seg.init(n);
  for(int i=0;i<q;i++){
    int tp;
    cin>>tp;
    if(tp==0){
      int s,t,x;
      cin>>s>>t>>x;
      s--;
      seg.update(s,t,x);
    }
    if(tp==1){
      int s;
      cin>>s;
      s--;
      cout<<seg.get_val(s)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
