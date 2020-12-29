#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../mod/mint.cpp"
#include "../convolution/numbertheoretictransform.cpp"
#include "../combinatorics/enumeration.cpp"
#include "base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
namespace fps_998244353{
  NTT<2> ntt;
  using M = decltype(ntt)::M;
  using E = Enumeration<M>;
  auto conv=[](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);
}

//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
