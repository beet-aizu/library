#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../mod/enumeration.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
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

  using E = Enumeration<M>;
  auto ps=FPS.stirling_1st<E>(n);
  for(int i=0;i<=n;i++){
    if(i) cout<<" ";
    cout<<ps[i];
  }
  cout<<endl;
  return 0;
}
