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
vector<M> FormalPowerSeries<M>::sqrt(Poly as,int deg){
  assert(as[0]==M(1));
  M inv2=M(1)/M(2);
  Poly ss({M(1)});
  for(int i=1;i<deg;i<<=1){
    ss=pre(add(ss,mul(pre(as,i<<1),inv(ss,i<<1))),i<<1);
    for(M &x:ss) x*=inv2;
  }
  return ss;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
