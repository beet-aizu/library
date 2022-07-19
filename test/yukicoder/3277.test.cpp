// verification-helper: PROBLEM https://yukicoder.me/problems/3277

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../segtree/basic/ushi.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,q;
  cin>>n>>q;
  auto as=read(n);

  auto f=[](int a,int b){return min(a,b);};
  SegmentTree seg(f,n+1);
  seg.build(as);

  for(int i=0;i<q;i++){
    int t,l,r;
    cin>>t>>l>>r;
    if(t==1){
      l--;r--;
      swap(as[l],as[r]);
      seg.set_val(l,as[l]);
      seg.set_val(r,as[r]);
    }
    if(t==2){
      l--;
      int m=seg.query(l,r);
      auto check=[&](int x){return x>m;};
      cout<<seg.max_right(l,check)+1<<newl;
    }
  }
  return 0;
}
