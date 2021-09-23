// verification-helper: PROBLEM https://judge.yosupo.jp/problem/bitwise_xor_convolution

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/bitwise/fwht.cpp"
#include "../../convolution/bitwise/xor.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  using M = Mint<int, 998244353>;

  int sz=1<<n;
  vector<M> as(sz),bs(sz);
  for(int i=0;i<sz;i++) cin>>as[i].v;
  for(int i=0;i<sz;i++) cin>>bs[i].v;

  fwht(as,bitwise_xor::zeta);
  fwht(bs,bitwise_xor::zeta);

  for(int i=0;i<sz;i++) as[i]*=bs[i];

  fwht(as,bitwise_xor::zeta);
  M inv=M(sz).inv();
  for(int i=0;i<sz;i++) as[i]*=inv;

  for(int i=0;i<sz;i++){
    if(i) cout<<' ';
    cout<<as[i];
  }
  cout<<endl;
  return 0;
}
