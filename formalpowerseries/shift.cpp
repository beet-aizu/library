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
vector<M> FormalPowerSeries<M>::shift(Poly as,M c){
  super::init(as.size()+1);
  int n=as.size();
  for(int i=0;i<n;i++) as[i]*=fact[i];
  reverse(as.begin(),as.end());
  Poly bs(n,M(1));
  for(int i=1;i<n;i++)
    bs[i]=bs[i-1]*c*invs[i];
  as=pre(mul(as,bs),n);
  reverse(as.begin(),as.end());
  for(int i=0;i<n;i++) as[i]*=finv[i];
  return as;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
