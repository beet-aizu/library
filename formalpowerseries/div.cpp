#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../combinatorics/enumeration.cpp"
#include "base.cpp"
#include "inv.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename M>
vector<M> FormalPowerSeries<M>::div(Poly as,Poly bs){
  shrink(as);shrink(bs);
  if(as.size()<bs.size()) return Poly({0});
  reverse(as.begin(),as.end());
  reverse(bs.begin(),bs.end());
  int need=as.size()-bs.size()+1;
  Poly ds=pre(mul(as,inv(bs,need)),need);
  reverse(ds.begin(),ds.end());
  return ds;
}

//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
