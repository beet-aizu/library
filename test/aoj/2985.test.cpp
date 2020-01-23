#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2985"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/mint.cpp"
#include "../../convolution/fastfouriertransform.cpp"
#include "../../convolution/arbitrarymod.cpp"
#include "../../polynomial/formalpowerseries.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;

  using M = Mint<int>;
  ArbitraryMod<M> arb;
  auto conv=[&](auto as,auto bs){return arb.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  vector<M> line(n+1,0),quad(n+1,0);
  for(int i=1;i<=n;i++){
    line[i]=M(i).pow(0);
    quad[i]=M(i).pow(1);
  }

  M v1=FPS.exp(line,n+1)[n];
  M v2=FPS.exp(quad,n+1)[n];

  M ans=v2-v1*v1;
  cout<<ans<<endl;
  return 0;
}
