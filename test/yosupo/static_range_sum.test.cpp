// verification-helper: PROBLEM https://judge.yosupo.jp/problem/static_range_sum

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/cumulativesum.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  using ll = long long;

  int n,q;
  cin>>n>>q;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  CumulativeSum cs(as);
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    cout<<cs.query(l,r)<<newl;
  }
  return 0;
}
