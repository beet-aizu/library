#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../combinatorics/enumeration.cpp"
#include "./base.cpp"
#include "./inv.cpp"
#include "./log.cpp"
#include "./exp.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename M>
vector<M> FormalPowerSeries<M>::pow(Poly as,long long k,int deg){
  if(as==Poly(as.size(),M(0))) return Poly(deg,M(0));

  int cnt=0;
  while(as[cnt]==M(0)) cnt++;
  if(cnt*k>=deg) return Poly(deg,M(0));
  as.erase(as.begin(),as.begin()+cnt);
  deg-=cnt*k;

  M c=as[0];
  Poly zs(cnt*k,M(0));
  Poly rs=mul(exp(mul(log(mul(as,c.inv()),deg),M(k)),deg),c.pow(k));
  zs.insert(zs.end(),rs.begin(),rs.end());
  return pre(zs,deg+cnt*k);
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
