#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../combinatorics/enumeration.cpp"
#include "./base.cpp"
#include "./inv.cpp"
#include "./div.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename M>
vector<M> FormalPowerSeries<M>::mod(Poly as,Poly bs){
  if(as==Poly(as.size(),0)) return Poly({0});
  as=sub(as,mul(div(as,bs),bs));
  if(as==Poly(as.size(),0)) return Poly({0});
  while(as.back()==M(0)) as.pop_back();
  return as;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
