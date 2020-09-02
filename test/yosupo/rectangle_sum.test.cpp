#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../vector/compress.cpp"
#include "../../segtree/count/dynamic_offline.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  vector<int> xs(n),ys(n),ws(n);
  for(int i=0;i<n;i++) cin>>xs[i]>>ys[i]>>ws[i];

  auto vs=compress(xs);
  auto idx=
    [&](int x){return lower_bound(vs.begin(),vs.end(),x)-vs.begin();};

  using ll = long long;
  RangeCount<int, ll> seg(vs.size());

  for(int i=0;i<n;i++)
    seg.preupdate(idx(xs[i]),ys[i]);

  seg.build();

  for(int i=0;i<n;i++)
    seg.update(idx(xs[i]),ys[i],ws[i]);

  for(int i=0;i<q;i++){
    int l,d,r,u;
    cin>>l>>d>>r>>u;
    cout<<seg.query(idx(l),idx(r),d,u)<<"\n";
  }
  cout<<flush;
  return 0;
}
