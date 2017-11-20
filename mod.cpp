#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
#define MOD 1000000007
#define MAX_N 100000
#define MAX_P 200005
Int fact[MAX_P];
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

void init(Int p){
  fact[0]=1;
  for(Int i=1;i<MAX_P;i++) fact[i]=(fact[i-1]*i)%p;
}

Int mod_fact(Int n,Int p,Int& e){
  e=0;
  if(n==0) return 1;
  Int res=mod_fact(n/p,p,e);
  e+=n/p;
  if(n/p%2!=0)return res*(p-fact[n%p]) %p;
  return res*fact[n%p]%p;
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
    res*=n-i;
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
    if(k%2 ) (res+=mod-inv)%=mod;
    else (res+=inv)%=mod;
  }
  for(Int i=1;i<=n;i++)
    (res*=i)%=mod;
  return res;
}

//END CUT HERE
signed main(){
  for(Int i=1;i<10;i++) cout<<i<<":"<<montmort(i,MOD)<<endl;
  return 0;
}
