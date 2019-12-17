#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "extgcd.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T, size_t sz>
struct Combination{
  using ll = long long;
  array<T, sz> fact;

  T mod;
  Combination(T mod):mod(mod){init();}

  void init(){
    fact[0]=1;
    for(int i=1;i<sz;i++)
      fact[i]=(ll)fact[i-1]*i%mod;
  }

  T mod_fact(T n,T& e){
    e=0;
    if(n==0) return 1;
    T res=mod_fact(n/mod,e);
    e+=n/mod;
    if(n/mod%2!=0)return res*(mod-fact[n%mod])%mod;
    return res*fact[n%mod]%mod;
  }

  T mod_comb(T n,T k){
    if(n==k||k==0) return 1;
    T e1,e2,e3;
    T a1=mod_fact(n,e1),a2=mod_fact(k,e2),a3=mod_fact(n-k,e3);
    if(e1>e2+e3) return 0;
    return (ll)a1*mod_inverse((ll)a2*a3%mod,mod)%mod;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  // !! not verified !!
  return 0;
}
#undef call_from_test
