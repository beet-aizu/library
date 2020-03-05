#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/compress.cpp"
#include "../../segtree/cht/lichao.cpp"
#undef call_from_test

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
    if(ts[i]==1){
      cin>>xs[i];
      ps.emplace_back(xs[i]);
    }
  }

  LiChao<ll, true> seg(compress(ps));
  for(int i=0;i<n;i++) seg.addLine(as[i],bs[i]);
  for(int i=0;i<q;i++){
    if(ts[i]==0) seg.addLine(xs[i],ys[i]);
    if(ts[i]==1) cout<<seg.query(xs[i])<<"\n";
  }
  cout<<flush;
  return 0;
}
