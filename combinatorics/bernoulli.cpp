#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "enumeration.cpp"
#include "../polynomial/formalpowerseries.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename M_>
struct Bernoulli : FormalPowerSeries<M_>{
  using M = M_;
  using super = FormalPowerSeries<M>;
  using super::super;
  using Poly = typename super::Poly;
  using super::fact;
  using super::finv;

  Poly rs;
  void build(int n){
    super::init(n+2);
    rs.assign(n+1,M(1));
    for(int i=1;i<=n;i++) rs[i]=finv[i+1];
    rs=super::inv(rs,n+1);
    for(int i=1;i<=n;i++) rs[i]*=fact[i];
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
