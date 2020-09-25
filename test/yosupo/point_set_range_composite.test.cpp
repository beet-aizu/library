// verification-helper: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../math/linearfunction.cpp"
#include "../../segtree/basic/ushi.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  vector<int> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];

  using M = Mint<int, 998244353>;
  using T = LinearFunction<M>;
  auto f=[&](T x,T y){return x*y;};
  T ti=T::mul_identity();
  SegmentTree<T> seg(f,ti);

  vector<T> vt;
  for(int i=0;i<n;i++) vt.emplace_back(as[i],bs[i]);
  seg.build(vt);

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int p,c,d;
      cin>>p>>c>>d;
      seg.set_val(p,T(M(c),M(d)));
    }
    if(t==1){
      int l,r,x;
      cin>>l>>r>>x;
      cout<<seg.query(l,r)(x)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
