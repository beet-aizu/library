#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// MOD can be composite numbers
template<typename T>
T mod_pow(T a,long long n,const T MOD){
  using ll = long long;
  T res(1);
  while(n){
    if(n&1) res=(ll)res*a%MOD;
    a=(ll)a*a%MOD;
    n>>=1;
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
