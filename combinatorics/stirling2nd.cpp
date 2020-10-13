#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "enumeration.cpp"
#include "../formalpowerseries/base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename M_>
struct Stirling2nd : FormalPowerSeries<M_>{
  using M = M_;
  using super = FormalPowerSeries<M>;
  using Poly = typename super::Poly;
  using super::super, super::finv;

  Poly rs;
  void build(int n){
    super::init(n+1);
    Poly as(n+1),bs(n+1);
    for(int i=0;i<=n;i++){
      as[i]=M(i).pow(n)*finv[i];
      bs[i]=(i&1?-M(1):M(1))*finv[i];
    }
    rs=super::pre(super::mul(as,bs),n+1);
  }

  M operator[](int k)const{return rs[k];}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
