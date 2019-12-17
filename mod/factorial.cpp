#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif

#define call_from_test
#include "mint.cpp"
#include "../convolution/numbertheoretictransform.cpp"
#include "../convolution/arbitrarymodconvolution_with_garner.cpp"
#undef call_from_test

//BEGIN CUT HERE
int factorial(long long n,int MOD){
  if(n>=MOD) return 0;
  ArbitraryModConvolution arb;
  auto inv=[&](int a){return ArbitraryModConvolution::inv(a,MOD);};

  using ll = long long;
  auto add=[&](int a,int b){return a+b>=MOD?a+b-MOD:a+b;};
  auto sub=[&](int a,int b){return a-b<0?a-b+MOD:a-b;};
  auto mul=[&](int a,int b){return (ll)a*b%MOD;};
  auto div=[&](int a,int b){return mul(a,inv(b));};

  int d=1<<15;
  vector<int> fact(d*2+1,1),finv(d*2+1,1);
  for(int i=1;i<=d*2;i++) fact[i]=mul(fact[i-1],i);
  finv[d*2]=inv(fact[d*2]);
  for(int i=d*2-1;i>=0;i--) finv[i]=mul(finv[i+1],i+1);

  vector<int> seq({1,d+1});
  seq.reserve(d+1);

  int sz=1;
  while(sz<d){
    vector<int> aux(sz,1);
    vector<int> f(sz*4,0),g(sz*4,0);
    for(int i=0;i<=sz;i++){
      f[i]=mul(mul(finv[i],finv[sz-i]),seq[i]);
      if(((sz+i)&1)&&(f[i]!=0)) f[i]=MOD-f[i];
    }

    vector<int> pf(f);
    vector<int> as;
    as.emplace_back(sz+1);
    as.emplace_back(div(sz,d));
    as.emplace_back(add(div(sz,d),sz+1));

    for(int idx=0;idx<3;idx++){
      for(int i=0;i<sz*4;i++) f[i]=pf[i];
      for(int i=1;i<sz*2+2;i++)
        g[i]=inv(as[idx]+MOD-sz+i-1);
      f=arb.multiply(f,g,MOD);
      f.resize(sz*4);

      int prod=1;
      for(int i=0;i<=sz;i++) prod=mul(prod,sub(as[idx],i));

      for(int i=0;i<=sz;i++){
        f[sz+i+1]=mul(f[sz+i+1],prod);
        prod=mul(prod,add(as[idx],i+1));
        prod=div(prod,sub(as[idx],sz-i));
      }
      if(idx==0){
        for(int i=0;i<sz;i++)
          aux[i]=f[sz+i+1];
      }
      if(idx==1){
        for(int i=0;i<=sz;i++)
          seq[i]=mul(seq[i],f[sz+i+1]);
      }
      if(idx==2){
        for(int i=0;i<sz;i++)
          aux[i]=mul(aux[i],f[sz+i+1]);
      }
    }
    for(int x:aux) seq.emplace_back(x);
    sz<<=1;
  }

  int res=1;
  int l=min((ll)d,(n+1)/d);
  for(int i=0;i<l;i++) res=mul(res,seq[i]);
  for(int i=l*d+1;i<=n;i++) res=mul(res,i);
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed YUKI_502(){
  const int MOD = 1e9+7;
  long long n;
  cin>>n;
  cout<<factorial(n,MOD)<<endl;
  return 0;
}
/*
  verified on 2019/12/17
  https://yukicoder.me/problems/no/502
*/

signed main(){
  YUKI_502();
  return 0;
}
#endif
