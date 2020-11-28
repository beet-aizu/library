// verification-helper: PROBLEM https://judge.yosupo.jp/problem/range_affine_range_sum

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../math/affine.cpp"
#include "../../segtree/basic/lazy.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  using M = Mint<int, 998244353>;
  using T = pair<M, M>;
  using E = pair<M, M>;
  auto [f,g,h,ti,ei]=Affine::params<T, E>();
  SegmentTree<T, E> seg(f,g,h,ti,ei);

  int n,q;
  cin>>n>>q;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];
  vector<T> vt;
  for(int i=0;i<n;i++) vt.emplace_back(as[i],1);
  seg.build(vt);

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int l,r,b,c;
      cin>>l>>r>>b>>c;
      seg.update(l,r,T(M(b),M(c)));
    }
    if(t==1){
      int l,r;
      cin>>l>>r;
      cout<<seg.query(l,r).first<<newl;
    }
  }
  return 0;
}
