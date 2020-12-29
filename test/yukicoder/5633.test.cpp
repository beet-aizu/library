// verification-helper: PROBLEM https://yukicoder.me/problems/5633

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../vector/powers.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../combinatorics/enumeration.cpp"
#include "../../formalpowerseries/base.cpp"
#include "../../formalpowerseries/inv.cpp"
#include "../../formalpowerseries/diff.cpp"
#include "../../formalpowerseries/integral.cpp"
#include "../../formalpowerseries/log.cpp"
#include "../../formalpowerseries/exp.cpp"
#include "../../formalpowerseries/pow.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  NTT<2> ntt;
  using M = decltype(ntt)::M;
  using E = Enumeration<M>;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  int n,m,k;
  cin>>n>>m>>k;

  E::init(n+m);

  auto ps=FPS.exp({M(0),M(1)},n+1);
  ps[0]-=M(1);
  auto qs=FPS.pow(ps,k,n+1);

  auto po=powers(n,M(m));

  M ans{0};
  for(int l=k;l<=n;l++)
    ans+=E::C(m,k)*E::C(n,l)*E::Fact(l)*qs[l]*po[n-l];

  cout<<ans<<endl;
  return 0;
}
