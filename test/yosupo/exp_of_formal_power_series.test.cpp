// verification-helper: PROBLEM https://judge.yosupo.jp/problem/exp_of_formal_power_series

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../combinatorics/enumeration.cpp"
#include "../../polynomial/formalpowerseries.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  vector<M> as(n);
  for(int i=0;i<n;i++) cin>>as[i].v;

  auto bs=FPS.exp(as,n);
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<bs[i];
  }
  cout<<endl;
  return 0;
}
