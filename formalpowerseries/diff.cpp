#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../combinatorics/enumeration.cpp"
#include "base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename M>
vector<M> FormalPowerSeries<M>::diff(Poly as){
  int n=as.size();
  Poly rs(n);
  for(int i=1;i<n;i++) rs[i-1]=as[i]*M(i);
  return rs;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
