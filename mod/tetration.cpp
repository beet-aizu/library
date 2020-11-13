#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../math/totient.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T>
T mpow(T a,T n,T m,T &f){
  using ull = unsigned long long;
  if(a==1 or n==0) return 1;
  ull v=1,x=a,z=m;
  f|=x>=z;
  x%=m;
  while(1){
    if(n&1) v*=x;
    if(v>=z) f=1,v%=m;
    n>>=1;
    if(!n) break;
    x=x*x;
    if(x>=z) f=1,x%=m;
  }
  return v;
}

// a^a^a^... (repeat n times)
// MOD can be composite numbers
template<typename T>
T tetration(T a,T n,const T MOD,T &f){
  if(a==0) return ~n&1;
  if(MOD==1) return f=1;
  if(a==1 or n==0) return 1;
  if(n==1){
    f|=a>=MOD;
    return a%MOD+f*MOD;
  }
  T z=tetration(a,n-1,totient(MOD),f);
  T r=mpow(a,z,MOD,f);
  return r+f*MOD;
}

// MOD can be composite numbers
template<typename T>
T tetration(T a,T n,const T MOD){
  T f=0;
  return tetration(a,n,MOD,f)%MOD;
}

//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
