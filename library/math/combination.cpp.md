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


# :warning: math/combination.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/combination.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 21:51:08+09:00




## Depends on

* :heavy_check_mark: <a href="extgcd.cpp.html">math/extgcd.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "extgcd.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T, size_t sz>
struct Combination{
  using ll = long long;
  array<T, sz> fact;

  T mod;
  Combination(T mod):mod(mod){init();}

  void init(){
    fact[0]=1;
    for(int i=1;i<sz;i++)
      fact[i]=(ll)fact[i-1]*i%mod;
  }

  T mod_fact(T n,T& e){
    e=0;
    if(n==0) return 1;
    T res=mod_fact(n/mod,e);
    e+=n/mod;
    if(n/mod%2!=0)return res*(mod-fact[n%mod])%mod;
    return res*fact[n%mod]%mod;
  }

  T mod_comb(T n,T k){
    if(n==k||k==0) return 1;
    T e1,e2,e3;
    T a1=mod_fact(n,e1),a2=mod_fact(k,e2),a3=mod_fact(n-k,e3);
    if(e1>e2+e3) return 0;
    return (ll)a1*mod_inverse((ll)a2*a3%mod,mod)%mod;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  // !! not verified !!
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 154, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: math/extgcd.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

