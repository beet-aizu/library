#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "pow.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T>
T order(T x,T MOD){
  static map<T, vector<T>> dp;
  static map<T, T> phi;

  vector<T> &ps=dp[MOD];
  if(ps.empty()){
    T res=MOD,n=MOD;
    for(T i=2;i*i<=n;i++){
      if(n%i) continue;
      res=res/i*(i-1);
      while(n%i==0) n/=i;
    }
    if(n!=1) res=res/n*(n-1);
    phi[MOD]=res;

    for(T i=2;i*i<=res;i++){
      if(res%i) continue;
      ps.emplace_back(i);
      if(i*i!=res) ps.emplace_back(res/i);
    }
  }

  T res=phi[MOD];
  for(T p:ps){
    while(res%p==0){
      if(mod_pow(x,res/p,MOD)!=1) break;
      res/=p;
    }
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
