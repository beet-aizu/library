---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: mod/log.cpp
* category: mod


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [math/extgcd.cpp](../math/extgcd.cpp.html)
* :warning: [math/kitamasa.cpp](../math/kitamasa.cpp.html)
* :heavy_check_mark: [mod/mint.cpp](mint.cpp.html)
* :heavy_check_mark: [tools/chminmax.cpp](../tools/chminmax.cpp.html)
* :heavy_check_mark: [tools/drop.cpp](../tools/drop.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](../tools/fastio.cpp.html)


## Verified
* :heavy_check_mark: [test/yosupo/discrete_logarithm_mod.test.cpp](../../verify/test/yosupo/discrete_logarithm_mod.test.cpp.html)


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// find x s.t. a^x = b (x >= 0)
template<typename T>
T mod_log(T a,T b,T mod){
  using ll = long long;
  ll g=1;
  {
    ll m=mod;
    while(m){
      g=(ll)g*a%mod;
      m>>=1;
    }
  }
  g=__gcd(g,(ll)mod);
  ll c=0,t=1;
  while(t%g){
    if(t==b) return c;
    t=t*a%mod;
    c++;
  }
  // not found
  if(b%g) return mod;
  t/=g;b/=g;
  const ll n=mod/g;
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
  return mod;
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "mint.cpp"
#include "../tools/chminmax.cpp"
#include "../math/kitamasa.cpp"
#include "../math/extgcd.cpp"
#include "../tools/drop.cpp"
#include "../tools/fastio.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed CFR536_F(){
  const int MOD = 998244353;
  using M = Mint<int, MOD>;
  using P = Mint<int, MOD-1>;

  int k;
  cin>>k;

  vector<P> bs(k);
  for(int i=0;i<k;i++){
    int b;
    cin>>b;
    bs[i]=P(b);
  }

  int n,m;
  cin>>n>>m;

  reverse(bs.begin(),bs.end());
  Kitamasa<P> ktms(bs);
  vector<P> as(k,0);
  as[k-1]=1;

  int v=ktms.calc(as,--n).v;
  int h=mod_log(3,m,MOD)%(MOD-1);

  if(v!=0||h!=0){
    int g=__gcd(v,h);
    v/=g;
    h/=g;
  }

  if(h!=0&&__gcd(v,MOD-1)!=1){
    cout<<-1<<endl;
    return 0;
  }

  cout<<M(3).pow((long long)h*mod_inverse(v,MOD-1))<<endl;
  return 0;
}
/*
  verified on 2019/10/24
  https://codeforces.com/contest/1106/problem/F
*/

signed BBC002_F(){
  using ll = long long;
  ll n,p;
  cin>>n>>p;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];
  ll x;
  cin>>x;
  if(x==1) drop(0);

  ll s=1;
  for(ll a:as) s=s*a%p;

  const ll INF = 1e18;
  ll ans=INF;
  ll v=1;
  for(int i=0;i<n;i++){
    ll y=x*mod_inverse(v,p)%p;
    ll t=mod_log(s,y,p);
    if(t!=p) chmin(ans,t*n+i);
    v*=as[i];
    v%=p;
  }

  if(ans==INF) drop("Fracture");
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/10/24
  https://www.hackerrank.com/contests/bbc002/challenges/bbc002-f/problem
*/

signed main(){
  //CFR536_F();
  //BBC002_F();
  return 0;
}
#endif

```
{% endraw %}

[Back to top page](../../index.html)

