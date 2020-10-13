// verification-helper: PROBLEM https://yukicoder.me/problems/2744

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/fastfouriertransform.cpp"
#include "../../convolution/arbitrarymod.cpp"
#include "../../combinatorics/enumeration.cpp"
#include "../../formalpowerseries/base.cpp"
#include "../../formalpowerseries/inv.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int k,n;
  cin>>k>>n;
  vector<int> xs(n);
  for(int i=0;i<n;i++) cin>>xs[i];

  using M = Mint<int>;
  ArbitraryMod<M> arb;
  auto conv=[&](auto as,auto bs){return arb.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  const int sz=1<<17;
  vector<M> bs(sz,M(0));
  bs[0]=1;
  for(int x:xs) bs[x]-=M(1);
  cout<<FPS.inv(bs,k+1)[k]<<endl;
  return 0;
}
