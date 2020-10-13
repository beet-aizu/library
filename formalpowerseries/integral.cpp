#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../combinatorics/enumeration.cpp"
#include "./base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename M>
vector<M> FormalPowerSeries<M>::integral(Poly as){
  super::init(as.size()+1);
  int n=as.size();
  Poly rs(n+1);
  rs[0]=M(0);
  for(int i=0;i<n;i++) rs[i+1]=as[i]*invs[i+1];
  return rs;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
