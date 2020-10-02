#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../vector/compress.cpp"
#include "../../segtree/cht/lichao.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  int n,q;
  cin>>n>>q;
  vector<ll> ls(n),rs(n),as(n),bs(n);
  for(int i=0;i<n;i++) cin>>ls[i]>>rs[i]>>as[i]>>bs[i];

  vector<ll> ts(q);
  vector<ll> v0(q),v1(q),v2(q),v3(q);
  vector<ll> ps;
  for(int i=0;i<q;i++){
    cin>>ts[i];
    if(ts[i]==0) cin>>v0[i]>>v1[i]>>v2[i]>>v3[i];
    if(ts[i]==1) cin>>v0[i];
    ps.emplace_back(v0[i]);
    ps.emplace_back(v1[i]);
  }
  for(int i=0;i<n;i++){
    ps.emplace_back(ls[i]);
    ps.emplace_back(rs[i]);
  }
  LiChao<ll, true> seg(ps);

  for(int i=0;i<n;i++) seg.add_segment(as[i],bs[i],ls[i],rs[i]);
  for(int i=0;i<q;i++){
    if(ts[i]==0) seg.add_segment(v2[i],v3[i],v0[i],v1[i]);
    if(ts[i]==1){
      auto res=seg.get(v0[i]);
      if(res==decltype(seg)::INF) cout<<"INFINITY"<<'\n';
      else cout<<res<<"\n";
    }
  }
  return 0;
}
