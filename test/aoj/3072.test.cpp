#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3072"

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

  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  int n,k,p100;
  cin>>n>>k>>p100;

  M p=M(p100)/M(100);

  vector<M> as({M(n)/p});
  vector<M> bs(n+1,-p);
  bs[0]=n;

  auto cs=FPS.mul(as,FPS.inv(bs,k));

  M ans{1};
  for(int i=1;i<k;i++) ans-=M(cs[i])*(M(1)-p);
  cout<<ans<<endl;
  return 0;
}
