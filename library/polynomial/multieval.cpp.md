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


# :x: polynomial/multieval.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#89693d3333328e76f4fdeed379e8f9ea">polynomial</a>
* <a href="{{ site.github.repository_url }}/blob/master/polynomial/multieval.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-06 18:54:39+09:00




## Depends on

* :heavy_check_mark: <a href="formalpowerseries.cpp.html">polynomial/formalpowerseries.cpp</a>


## Required by

* :x: <a href="interpolate.cpp.html">polynomial/interpolate.cpp</a>


## Verified with

* :x: <a href="../../verify/test/yosupo/multipoint_evaluation.test.cpp.html">test/yosupo/multipoint_evaluation.test.cpp</a>
* :x: <a href="../../verify/test/yosupo/polynomial_interpolation.test.cpp.html">test/yosupo/polynomial_interpolation.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "formalpowerseries.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
// O(N log^2 N)
template<typename T>
struct MultiEval{
  FormalPowerSeries<T> FPS;
  using Poly = typename FormalPowerSeries<T>::Poly;
  using Conv = typename FormalPowerSeries<T>::Conv;

  MultiEval(Conv conv):FPS(conv){}

  using P = pair<int, int>;
  map<P, Poly> mem;
  void dfs(const vector<T> &cs,int l,int r){
    if(l+1==r){
      mem[{l,r}]=Poly({-cs[l],T(1)});
      return;
    }
    int m=(l+r)>>1;
    dfs(cs,l,m);
    dfs(cs,m,r);
    mem[{l,r}]=FPS.mul(mem[{l,m}],mem[{m,r}]);
  }

  void multi_eval(Poly ps,vector<T> &ws,int l,int r){
    if(l+1==r){
      ws[l]=FPS.mod(ps,mem[{l,r}])[0];
      return;
    }
    int m=(l+r)>>1;
    multi_eval(FPS.mod(ps,mem[{l,m}]),ws,l,m);
    multi_eval(FPS.mod(ps,mem[{m,r}]),ws,m,r);
  }

  vector<T> build(Poly ps,const vector<T> &cs){
    int n=cs.size();
    mem.clear();
    dfs(cs,0,n);
    vector<T> ws(n);
    multi_eval(ps,ws,0,n);
    return ws;
  }
};
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
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 68, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 181, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: polynomial/multieval.cpp: line 9: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
