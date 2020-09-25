// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2720

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/carmichael.cpp"
#undef call_from_test

// x^n mod m
template<typename T>
T mpow(T x,T n,T m){
  T r=1;
  x%=m;
  while(n){
    if(n&1) r=r*x%m;
    x=x*x%m;
    n>>=1;
  }
  return r;
}

signed main(){
  using ll = long long;
  ll n;
  cin>>n;
  if(n==2){
    cout<<1<<endl;
    return 0;
  }
  for(ll i=2;i*i<=n;i++){
    if(n%(i*i)==0){
      cout<<-1<<endl;
      return 0;
    }
  }

  ll a=carmichael_lambda(n);
  ll b=carmichael_lambda(a);
  assert(n!=1);
  assert(a!=1);
  assert(b!=0);
  {
    ll x=mpow(n,b,a)!=1;
    ll y=__gcd(n%a,a)!=1;
    assert(x==y);
  }
  if(mpow(n,b,a)!=1){
    assert(n%a!=1);
    cout<<-1<<endl;
    return 0;
  }

  if(n%a==1) b=1;
  for(ll i=2;i*i<=b;i++){
    if(b%i!=0) continue;
    while(b%i==0){
      if(mpow(n,b/i,a)==1) b/=i;
      else break;
    }
    ll j=b/i;
    if(j==1) continue;
    while(b%j==0){
      if(mpow(n,b/j,a)==1) b/=j;
      else break;
    }
  }
  cout<<b<<endl;
  return 0;
}
