#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
#define MOD 1000000007
#define MAX_P 200005
Int fact[MAX_P],inv[MAX_P],finv[MAX_P];;
Int extgcd(Int a,Int b,Int& x,Int& y){
  Int d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}
Int mod_inverse(Int a,Int mod){
  Int x,y;
  extgcd(a,mod,x,y);
  return (mod+x%mod)%mod;
}

Int mod_pow(Int x,Int n,Int mod){
  Int res=1;
  while(n){
    if(n&1) (res*=x)%=mod;
    (x*=x)%=mod;
    n>>=1;
  }
  return res;
}

Int mod_inverse2(Int a,Int mod){
  return mod_pow(a,mod-2,mod);
}

void init(Int mod){
  fact[0]=1;
  for(Int i=1;i<MAX_P;i++)
    fact[i]=(fact[i-1]*i)%mod;

  inv[1]=1;
  for(Int i=2;i<MAX_P;i++)
    inv[i]=inv[mod%i]*(mod-mod/i)%mod;
  
  finv[0]=1;
  for(Int i=1;i<MAX_P;i++)
    finv[i]=finv[i-1]*inv[i]%mod;
}

Int mod_fact(Int n,Int mod,Int& e){
  e=0;
  if(n==0) return 1;
  Int res=mod_fact(n/mod,mod,e);
  e+=n/mod;
  if(n/mod%2!=0)return res*(mod-fact[n%mod]) %mod;
  return res*fact[n%mod]%mod;
}

Int mod_comb(Int n,Int k,Int mod){
  if(n==k||k==0) return 1;
  Int e1,e2,e3;
  Int a1=mod_fact(n,mod,e1),a2=mod_fact(k,mod,e2),a3=mod_fact(n-k,mod,e3);
  if(e1>e2+e3) return 0;
  return a1*mod_inverse(a2*a3%mod,mod)%mod;
}

Int mod_comb2(Int n,Int k,Int mod){
  Int res=1;
  for(Int i=0;i<k;i++){
    res*=(n-i)%mod;
    res%=mod;
    res*=mod_inverse(i+1,mod);
    res%=mod;
  }
  return res;
}

//only for prime mod
Int mod_comb3(Int n,Int k,Int mod){
  if(k<0||k>n) return 0;
  return fact[n]*finv[k]%mod*finv[n-k]%mod;
}

Int montmort(Int n,Int mod){
  Int res=0,inv=1;
  for(Int k=2;k<=n;k++){
    (inv*=mod_inverse(k,mod))%=mod;
    if(k%2) (res+=mod-inv)%=mod;
    else (res+=inv)%=mod;
  }
  for(Int i=1;i<=n;i++)
    (res*=i)%=mod;
  return res;
}

// calculate P(t) from given points in [0,N]
Int LagrangePolynomial(vector<Int> &y,Int t,const Int mod){
  init(mod);
  Int n=y.size()-1;
  Int num=1;
  for(Int i=0;i<=n;i++)
    num=num*((t-i)%mod)%mod;
  Int res=0;
  for(Int i=0;i<=n;i++){
    Int tmp=(y[i]*num%mod)*mod_inverse((t-i)%mod,mod)%mod;
    tmp=tmp*finv[i]%mod;
    tmp=tmp*finv[n-i]%mod;
    if((n-i)&1) tmp=mod-tmp;
    res=(res+tmp)%mod;
  }
  return res;
}
//END CUT HERE

//mod_pow
signed AOJ_NTL1B(){
  Int n,m;
  cin>>m>>n;
  cout<<mod_pow(m,n,MOD)<<endl;
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp
*/

//extgcd
signed AOJ_NTL1E(){
  Int a,b;
  cin>>a>>b;
  Int x,y;
  extgcd(a,b,x,y);
  cout<<x<<" "<<y<<endl;
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=jp
*/

//montmort
signed ARC009_C(){
  Int n,k;
  cin>>n>>k;
  const Int MMOD=1777777777;
  Int a=montmort(k,MMOD);
  a=a*mod_comb2(n,k,MMOD)%MMOD;
  cout<<a<<endl;
  return 0;
}
/*
  verified on 2017/12/31
  https://arc009.contest.atcoder.jp/tasks/arc009_3
*/


signed yuki_665(){
  Int n,k;
  cin>>n>>k;
  vector<Int> y(k+2,0);
  for(Int i=1;i<=k+1;i++) y[i]=(y[i-1]+mod_pow(i,k,MOD))%MOD;
  if(n<=k+1) cout<<y[n]<<endl;
  else cout<<LagrangePolynomial(y,n,MOD)<<endl;
  return 0;
}
/*
  verified on 2018/03/10
  https://yukicoder.me/problems/no/665
*/

signed ARC033_D(){
  Int n;
  cin>>n;
  vector<Int> y(n+1);
  for(Int i=0;i<=n;i++) cin>>y[i];
  Int t;
  cin>>t;
  if(t<=n) cout<<y[t]<<endl;
  else cout<<LagrangePolynomial(y,t,MOD)<<endl;
  return 0;
}
/*
  verified on 2018/03/10
  https://beta.atcoder.jp/contests/arc033/tasks/arc033_4
*/



signed main(){
  //AOJ_NTL1B();
  //AOJ_NTL1E();
  //ARC009_C();
  //yuki_665();
  ARC033_D();
  return 0;
}
