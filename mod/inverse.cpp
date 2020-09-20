#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../math/extgcd.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T>
T mod_inverse(T a,T mod){
  T x,y;
  extgcd(a,mod,x,y);
  return (x%mod+mod)%mod;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
