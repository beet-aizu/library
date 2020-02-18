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


# :heavy_check_mark: mod/sqrt.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ad148a3ca8bd0ef3b48c52454c493ec5">mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/mod/sqrt.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-30 20:19:31+09:00




## Required by

* :heavy_check_mark: <a href="../polynomial/formalpowerseries.cpp.html">polynomial/formalpowerseries.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/sqrt_mod.test.cpp.html">test/yosupo/sqrt_mod.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/sqrt_of_formal_power_series.test.cpp.html">test/yosupo/sqrt_of_formal_power_series.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
int jacobi(T a,T mod){
  int s=1;
  if(a<0) a=a%mod+mod;
  while(mod>1){
    a%=mod;
    if(a==0) return 0;
    int r=__builtin_ctz(a);
    if((r&1)&&((mod+2)&4)) s=-s;
    a>>=r;
    if(a&mod&2) s=-s;
    swap(a,mod);
  }
  return s;
}

template<typename T>
vector<T> mod_sqrt(T a,T mod){
  if(mod==2) return {a&1};
  int j=jacobi(a,mod);
  if(j== 0) return {0};
  if(j==-1) return {};

  using ll = long long;
  mt19937 mt;
  ll b,d;
  while(1){
    b=mt()%mod;
    d=(b*b-a)%mod;
    if(d<0) d+=mod;
    if(jacobi<ll>(d,mod)==-1) break;
  }

  ll f0=b,f1=1,g0=1,g1=0;
  for(ll e=(mod+1)>>1;e;e>>=1){
    if(e&1){
      ll tmp=(g0*f0+d*((g1*f1)%mod))%mod;
      g1=(g0*f1+g1*f0)%mod;
      g0=tmp;
    }
    ll tmp=(f0*f0+d*((f1*f1)%mod))%mod;
    f1=(2*f0*f1)%mod;
    f0=tmp;
  }
  if(g0>mod-g0) g0=mod-g0;
  return {T(g0),T(mod-g0)};
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: mod/sqrt.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

