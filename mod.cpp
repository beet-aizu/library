#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
#define MOD 1000000007
#define MAX_N 100000
#define MAX_P 200005
Int fact[MAX_P],inv[MAX_P];
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
Int euler_phi(Int n){
  Int res=n;
  for(Int i=2;i*i<=n;i++){
    if(n%i==0){
      res=res/i*(i-1);
      for(;n%i==0;n/=i);
    }
  }
  if(n!=1) res=res/n*(n-1);
  return res;
}

Int euler[MAX_N];

void euler_phi2(){
  for(Int i=0;i<MAX_N;i++) euler[i]=i;
  for(Int i=2;i<MAX_N;i++){
    if(euler[i]==i){
      for(Int j=i;j<MAX_N;j+=i) euler[j]=euler[j]/i*(i-1);
    }
  }
}

Int mod_pow(Int x,Int n,Int mod){
  Int res=1;
  while(n>0){
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


//euler_phi:
signed AOJ_NTL1D(){
  Int n;
  cin>>n;
  cout<<euler_phi(n)<<endl;
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D&lang=jp
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


signed main(){
  //AOJ_NTL1B();
  //AOJ_NTL1D();
  AOJ_NTL1E();
  
  //ARC009_C();
  return 0;
}
