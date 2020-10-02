#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

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
  vector<ll> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];

  vector<ll> ts(q),xs(q),ys(q);
  vector<ll> ps;
  for(int i=0;i<q;i++){
    cin>>ts[i];
    if(ts[i]==0) cin>>xs[i]>>ys[i];
    if(ts[i]==1) cin>>xs[i];
    ps.emplace_back(xs[i]);
  }
  int lb=-1e9,ub=+1e9;
  ps.emplace_back(lb);
  ps.emplace_back(ub);
  LiChao<ll, true> seg(ps);

  for(int i=0;i<n;i++) seg.add_segment(as[i],bs[i],lb,ub);
  for(int i=0;i<q;i++){
    if(ts[i]==0) seg.add_segment(xs[i],ys[i],lb,ub);
    if(ts[i]==1) cout<<seg.get(xs[i])<<"\n";
  }
  return 0;
}
