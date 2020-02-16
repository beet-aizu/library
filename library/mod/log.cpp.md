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

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ad148a3ca8bd0ef3b48c52454c493ec5">mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/mod/log.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-26 23:42:22+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/discrete_logarithm_mod.test.cpp.html">test/yosupo/discrete_logarithm_mod.test.cpp</a>


## Code

<a id="unbundled"></a>
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
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: mod/log.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

