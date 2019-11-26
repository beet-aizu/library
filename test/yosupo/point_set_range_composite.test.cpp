#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/mint.cpp"
#include "../../segtree/basic/ushi.cpp"
#undef call_from_test

signed main(){
  using M = Mint<int, 998244353>;
  int n,q;
  cin>>n>>q;

  vector<int> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];

  struct T{
    M a,b;
    T(M a,M b):a(a),b(b){}
  };

  auto f=[&](T x,T y){return T(x.a*y.a,x.b*y.a+y.b);};
  T ti(M(1),M(0));
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
      T res=seg.query(l,r);
      cout<<res.a*M(x)+res.b<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
