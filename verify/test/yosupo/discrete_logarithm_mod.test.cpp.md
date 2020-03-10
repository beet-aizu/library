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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/yosupo/discrete_logarithm_mod.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/discrete_logarithm_mod.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-05 21:02:53+09:00


* see: <a href="https://judge.yosupo.jp/problem/discrete_logarithm_mod">https://judge.yosupo.jp/problem/discrete_logarithm_mod</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/mod/log.cpp.html">mod/log.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/log.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin>>t;
  while(t--){
    int x,y,m;
    cin>>x>>y>>m;
    int l=mod_log(x,y,m);
    if(l==m) l=-1;
    cout<<l<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/discrete_logarithm_mod.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "test/yosupo/../../mod/log.cpp"

#line 3 "test/yosupo/../../mod/log.cpp"
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
signed main(){
  return 0;
}
#endif
#line 8 "test/yosupo/discrete_logarithm_mod.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin>>t;
  while(t--){
    int x,y,m;
    cin>>x>>y>>m;
    int l=mod_log(x,y,m);
    if(l==m) l=-1;
    cout<<l<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

