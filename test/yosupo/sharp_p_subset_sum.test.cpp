// verification-helper: PROBLEM https://judge.yosupo.jp/problem/sharp_p_subset_sum

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../combinatorics/enumeration.cpp"
#include "../../formalpowerseries/base.cpp"
#include "../../formalpowerseries/inv.cpp"
#include "../../formalpowerseries/integral.cpp"
#include "../../formalpowerseries/diff.cpp"
#include "../../formalpowerseries/log.cpp"
#include "../../formalpowerseries/exp.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,t;
  cin>>n>>t;

  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);
  decltype(FPS)::init(t+1);

  vector<int> cnt(t+1,0);
  for(int i=0;i<n;i++){
    int s;
    cin>>s;
    cnt[s]++;
  }

  vector<M> as(t+1);
  for(int s=1;s<=t;s++){
    for(int k=1;s*k<=t;k++){
      if(k&1) as[s*k]+=M(cnt[s])*decltype(FPS)::Invs(k);
      else as[s*k]-=M(cnt[s])*decltype(FPS)::Invs(k);
    }
  }

  auto bs=FPS.exp(as,t+1);
  for(int i=1;i<=t;i++){
    if(i>1) cout<<" ";
    cout<<bs[i];
  }
  cout<<endl;
  return 0;
}
