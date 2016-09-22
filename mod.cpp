#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define MAX_N 100000
#define MAX_P 200005
ll fact[MAX_P];
ll extgcd(ll a,ll b,ll& x,ll& y){
  ll d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}
ll mod_inverse(ll a,ll m){
  ll x,y;
  extgcd(a,m,x,y);
  return (m+x%m)%m;
}

ll euler_phi(ll n){
  ll res=n;
  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      res=res/i*(i-1);
      for(;n%i==0;n/=i);
    }
  }
  if(n!=1) res=res/n*(n-1);
  return res;
}

ll euler[MAX_N];

void euler_phi2(){
  for(ll i=0;i<MAX_N;i++) euler[i]=i;
  for(ll i=2;i<MAX_N;i++){
    if(euler[i]==i){
      for(int j=i;j<MAX_N;j+=i) euler[j]=euler[j]/i*(i-1);
    }
  }
}

ll mod_fact(ll n,ll p,ll& e){
  e=0;
  if(n==0) return 1;
  ll res=mod_fact(n/p,p,e);
  e+=n/p;
  if(n/p%2!=0)return res*(p-fact[n%p]) %p;
  return res*fact[n%p]%p;
} 
ll mod_comb(ll n,ll k,ll p){
  if(n==k||k==0) return 1;
  ll e1,e2,e3;
  ll a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);
  if(e1>e2+e3) return 0;
  return a1*mod_inverse(a2*a3%p,p)%p;
}

int main(){
  return 0;
}
