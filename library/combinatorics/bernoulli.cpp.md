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


# :heavy_check_mark: combinatorics/bernoulli.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ac1ed416572b96a9f5d69740d174ef3d">combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/combinatorics/bernoulli.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-12 17:47:27+09:00




## Depends on

* :heavy_check_mark: <a href="enumeration.cpp.html">combinatorics/enumeration.cpp</a>
* :heavy_check_mark: <a href="../polynomial/formalpowerseries.cpp.html">polynomial/formalpowerseries.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/bernoulli_number.test.cpp.html">test/yosupo/bernoulli_number.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "enumeration.cpp"
#include "../polynomial/formalpowerseries.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename M_>
struct Bernoulli : FormalPowerSeries<M_>{
  using M = M_;
  using super = FormalPowerSeries<M>;
  using super::super;
  using Poly = typename super::Poly;
  using super::fact;
  using super::finv;

  Poly rs;
  void build(int n){
    super::init(n+2);
    rs.assign(n+1,M(1));
    for(int i=1;i<=n;i++) rs[i]=finv[i+1];
    rs=super::inv(rs,n+1);
    for(int i=1;i<=n;i++) rs[i]*=fact[i];
  }

  M operator[](int k)const{return rs[k];}
};
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
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 172, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 281, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: combinatorics/bernoulli.cpp: line 8: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

