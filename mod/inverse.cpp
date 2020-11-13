#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../math/extgcd.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
// a, MOD coprime
template<typename T>
T mod_inverse(T a,const T MOD){
  T x,y;
  extgcd(a,MOD,x,y);
  return (x%MOD+MOD)%MOD;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
