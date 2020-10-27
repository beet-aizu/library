#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "extgcd.cpp"
#include "../mod/inverse.cpp"
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
    for(int i=1;i<(int)sz;i++)
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
    if(n==k or k==0) return 1;
    T e1,e2,e3;
    T a1=mod_fact(n,e1),a2=mod_fact(k,e2),a3=mod_fact(n-k,e3);
    if(e1>e2+e3) return 0;
    return a1*mod_inverse<ll>((ll)a2*a3%mod,mod)%mod;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  string s;
  cin>>s;

  vector<int> as(n);
  for(int i=0;i<n;i++) as[i]=s[i]-'1';

  const int sz = 1e6+10;
  Combination<int, sz> C(2);

  int is_one=0;
  for(int i=0;i<n;i++)
    if(as[i]&1) is_one^=C.mod_comb(n-1,i);

  if(is_one){
    cout<<1<<endl;
    return 0;
  }

  for(int i=0;i<n;i++){
    if(as[i]==1){
      cout<<0<<endl;
      return 0;
    }
    as[i]/=2;
  }

  int is_two=0;
  for(int i=0;i<n;i++)
    if(as[i]&1) is_two^=C.mod_comb(n-1,i);

  cout<<is_two*2<<endl;
  return 0;
}
/*
  verified on 2020/03/22
  https://atcoder.jp/contests/agc043/tasks/agc043_b
*/
#endif
