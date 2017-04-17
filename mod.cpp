#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
#define MAX_N 100000
#define MAX_P 200005
int fact[MAX_P];
int extgcd(int a,int b,int& x,int& y){
  int d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}
int mod_inverse(int a,int m){
  int x,y;
  extgcd(a,m,x,y);
  return (m+x%m)%m;
}

int euler_phi(int n){
  int res=n;
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      res=res/i*(i-1);
      for(;n%i==0;n/=i);
    }
  }
  if(n!=1) res=res/n*(n-1);
  return res;
}

int euler[MAX_N];

void euler_phi2(){
  for(int i=0;i<MAX_N;i++) euler[i]=i;
  for(int i=2;i<MAX_N;i++){
    if(euler[i]==i){
      for(int j=i;j<MAX_N;j+=i) euler[j]=euler[j]/i*(i-1);
    }
  }
}


int mod_pow(int x,int n,int mod){
  int res=1;
  while(n>0){
    if(n&1) res=res*x%mod;
    x=x*x%mod;
    n>>=1;
  }
  return res;
}

void init(int p){
  fact[0]=1;
  for(int i=1;i<MAX_P;i++) fact[i]=(fact[i-1]*i)%p;
}

int mod_fact(int n,int p,int& e){
  e=0;
  if(n==0) return 1;
  int res=mod_fact(n/p,p,e);
  e+=n/p;
  if(n/p%2!=0)return res*(p-fact[n%p]) %p;
  return res*fact[n%p]%p;
} 
int mod_comb(int n,int k,int p){
  if(n==k||k==0) return 1;
  int e1,e2,e3;
  int a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);
  if(e1>e2+e3) return 0;
  return a1*mod_inverse(a2*a3%p,p)%p;
}

signed main(){
  return 0;
}
