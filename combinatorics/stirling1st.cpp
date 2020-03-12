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
struct Stirling1st : FormalPowerSeries<M_>{
  using M = M_;
  using super = FormalPowerSeries<M>;
  using super::super;
  using Poly = typename super::Poly;
  using super::fact;
  using super::finv;

  Poly rs;
  void build(int n){
    super::init(n+1);
    if(n==0){
      rs={M(1)};
      return;
    }
    int m=1;
    rs=Poly({M(0),M(1)});
    for(int e=31-__builtin_clz(n)-1;e>=0;e--){
      Poly as(m+1),bs(m+1);
      for(int i=0;i<=m;i++) as[i]=fact[i]*rs[i];
      bs[m-0]=M(1);
      for(int i=1;i<=m;i++) bs[m-i]=bs[m-(i-1)]*-M(m);
      for(int i=0;i<=m;i++) bs[m-i]*=finv[i];
      Poly cs=super::mul(as,bs);
      Poly ds(m+1);
      for(int i=0;i<=m;i++) ds[i]=finv[i]*cs[m+i];
      rs=super::mul(rs,ds);
      m<<=1;
      if((n>>e)&1){
        Poly ts(m+1+1,M(0));
        for(int i=0;i<=m;i++){
          ts[i+0]+=rs[i]*-M(m);
          ts[i+1]+=rs[i];
        }
        rs=ts;
        m|=1;
      }
    }
    assert(m==n);
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
