#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
int jacobi(T a,const T MOD){
  int s=1;
  if(a<0) a=a%MOD+MOD;
  while(MOD>1){
    a%=MOD;
    if(a==0) return 0;
    int r=__builtin_ctz(a);
    if((r&1) and ((MOD+2)&4)) s=-s;
    a>>=r;
    if(a&MOD&2) s=-s;
    swap(a,MOD);
  }
  return s;
}

// MOD: prime
template<typename T>
vector<T> mod_sqrt(T a,const T MOD){
  if(MOD==2) return {a&1};
  int j=jacobi(a,MOD);
  if(j== 0) return {0};
  if(j==-1) return {};

  using ll = long long;
  mt19937 mt;
  ll b,d;
  while(1){
    b=mt()%MOD;
    d=(b*b-a)%MOD;
    if(d<0) d+=MOD;
    if(jacobi<ll>(d,MOD)==-1) break;
  }

  ll f0=b,f1=1,g0=1,g1=0;
  for(ll e=(MOD+1)>>1;e;e>>=1){
    if(e&1){
      ll tmp=(g0*f0+d*((g1*f1)%MOD))%MOD;
      g1=(g0*f1+g1*f0)%MOD;
      g0=tmp;
    }
    ll tmp=(f0*f0+d*((f1*f1)%MOD))%MOD;
    f1=(2*f0*f1)%MOD;
    f0=tmp;
  }
  if(g0>MOD-g0) g0=MOD-g0;
  return {T(g0),T(MOD-g0)};
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
