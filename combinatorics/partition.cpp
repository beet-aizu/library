#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "enumeration.cpp"
#include "../polynomial/formalpowerseries.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename M_>
struct Partition : FormalPowerSeries<M_>{
  using M = M_;
  using super = FormalPowerSeries<M>;
  using super::super;
  using Poly = typename super::Poly;

  Poly rs;
  void build(int n){
    rs.resize(n+1);
    rs[0]=M(1);
    for(int k=1;k<=n;k++){
      if(1LL*k*(3*k+1)/2<=n) rs[k*(3*k+1)/2]+=k%2?-M(1):M(1);
      if(1LL*k*(3*k-1)/2<=n) rs[k*(3*k-1)/2]+=k%2?-M(1):M(1);
    }
    rs=super::inv(rs,n+1);
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
