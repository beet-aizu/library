#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../combinatorics/enumeration.cpp"
#include "base.cpp"
#include "inv.cpp"
#include "diff.cpp"
#include "integral.cpp"
#include "log.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename M>
vector<M> FormalPowerSeries<M>::exp(Poly as,int deg){
  Poly fs({M(1)});
  as[0]+=M(1);
  for(int i=1;i<deg;i<<=1)
    fs=pre(mul(fs,sub(pre(as,i<<1),log(fs,i<<1))),i<<1);
  return fs;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
