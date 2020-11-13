#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// find x s.t. a^x = b (x >= 0)
// return MOD if not found
// MOD can be composite numbers
template<typename T>
T mod_log(T a,T b,const T MOD){
  using ll = long long;
  ll g=1;
  {
    ll m=MOD;
    while(m){
      g=(ll)g*a%MOD;
      m>>=1;
    }
  }
  g=__gcd(g,(ll)MOD);
  ll c=0,t=1;
  while(t%g){
    if(t==b) return c;
    t=t*a%MOD;
    c++;
  }
  // not found
  if(b%g) return MOD;
  t/=g;b/=g;
  const ll n=MOD/g;
  ll h=0,gs=1;
  while(h*h<n){
    gs=gs*a%n;
    ++h;
  }
  unordered_map<ll, ll> bs;
  {
    ll s=0,e=b;
    while(s<h){
      e=e*a%n;
      bs[e]=++s;
    }
  }
  {
    ll s=0,e=t;
    while(s<n){
      e=e*gs%n;
      s+=h;
      if(bs.count(e))
        return c+s-bs[e];
    }
  }
  // not found
  return MOD;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
