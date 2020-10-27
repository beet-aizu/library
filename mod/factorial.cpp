#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../mod/mint.cpp"
#include "../convolution/numbertheoretictransform.cpp"
#include "../convolution/garner.cpp"
#include "../mod/rint.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
int factorial(long long n,int MOD){
  if(n>=MOD) return 0;
  Garner arb;
  using R = Rint<int>;
  R::set_mod(MOD);

  int d=1<<15;
  vector<R> fact(d*2+1,1),finv(d*2+1,1);
  for(int i=1;i<=d*2;i++) fact[i]=fact[i-1]*R(i);
  finv[d*2]=fact[d*2].inv();
  for(int i=d*2-1;i>=0;i--) finv[i]=finv[i+1]*R(i+1);

  vector<R> seq({1,d+1});
  seq.reserve(d+1);

  int sz=1;
  while(sz<d){
    vector<R> aux(sz,1);
    vector<R> f(sz*4,0),g(sz*4,0);
    for(int i=0;i<=sz;i++){
      f[i]=finv[i]*finv[sz-i]*seq[i];
      if(((sz+i)&1) and (f[i].v!=0)) f[i]=-f[i];
    }

    vector<R> pf(f);
    vector<R> as;
    as.emplace_back(R(sz+1));
    as.emplace_back(R(sz)/R(d));
    as.emplace_back(R(sz)/R(d)+R(sz+1));

    for(int idx=0;idx<3;idx++){
      for(int i=0;i<sz*4;i++) f[i]=pf[i];
      for(int i=1;i<sz*2+2;i++)
        g[i]=(as[idx]-R(sz-i+1)).inv();
      f=arb.multiply(f,g);
      f.resize(sz*4);

      R prod=1;
      for(int i=0;i<=sz;i++) prod*=as[idx]-R(i);

      for(int i=0;i<=sz;i++){
        f[sz+i+1]*=prod;
        prod*=as[idx]+R(i+1);
        prod/=as[idx]-R(sz-i);
      }
      if(idx==0){
        for(int i=0;i<sz;i++)
          aux[i]=f[sz+i+1];
      }
      if(idx==1){
        for(int i=0;i<=sz;i++)
          seq[i]*=f[sz+i+1];
      }
      if(idx==2){
        for(int i=0;i<sz;i++)
          aux[i]*=f[sz+i+1];
      }
    }
    for(R x:aux) seq.emplace_back(x);
    sz<<=1;
  }

  using ll = long long;
  R res=1;
  int l=min((ll)d,(n+1)/d);
  for(ll i=0;i<l;i++) res*=seq[i];
  for(ll i=l*d+1;i<=n;i++) res*=R(i);
  return res.v;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
