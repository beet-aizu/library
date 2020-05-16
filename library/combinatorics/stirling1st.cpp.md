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


# :x: combinatorics/stirling1st.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ac1ed416572b96a9f5d69740d174ef3d">combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/combinatorics/stirling1st.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-16 18:51:14+09:00




## Depends on

* :question: <a href="enumeration.cpp.html">combinatorics/enumeration.cpp</a>
* :question: <a href="../polynomial/formalpowerseries.cpp.html">polynomial/formalpowerseries.cpp</a>


## Verified with

* :x: <a href="../../verify/test/yosupo/stirling_number_of_the_first_kind.test.cpp.html">test/yosupo/stirling_number_of_the_first_kind.test.cpp</a>


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
struct Stirling1st : FormalPowerSeries<M_>{
  using M = M_;
  using super = FormalPowerSeries<M>;
  using super::super;
  using Poly = typename super::Poly;
  using super::fact;
  using super::finv;

  Poly rs;
  void build(int n){
    super::init(n+1);
    if(n==0){
      rs={M(1)};
      return;
    }
    int m=1;
    rs=Poly({M(0),M(1)});
    for(int e=31-__builtin_clz(n)-1;e>=0;e--){
      Poly as(m+1),bs(m+1);
      for(int i=0;i<=m;i++) as[i]=fact[i]*rs[i];
      bs[m-0]=M(1);
      for(int i=1;i<=m;i++) bs[m-i]=bs[m-(i-1)]*-M(m);
      for(int i=0;i<=m;i++) bs[m-i]*=finv[i];
      Poly cs=super::mul(as,bs);
      Poly ds(m+1);
      for(int i=0;i<=m;i++) ds[i]=finv[i]*cs[m+i];
      rs=super::mul(rs,ds);
      m<<=1;
      if((n>>e)&1){
        Poly ts(m+1+1,M(0));
        for(int i=0;i<=m;i++){
          ts[i+0]+=rs[i]*-M(m);
          ts[i+1]+=rs[i];
        }
        rs=ts;
        m|=1;
      }
    }
    assert(m==n);
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: combinatorics/stirling1st.cpp: line 8: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

