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


# :heavy_check_mark: mod/enumeration.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ad148a3ca8bd0ef3b48c52454c493ec5">mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/mod/enumeration.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-19 22:42:36+09:00




## Depends on

* :heavy_check_mark: <a href="mint.cpp.html">mod/mint.cpp</a>


## Required by

* :heavy_check_mark: <a href="../graph/lowlink.cpp.html">graph/lowlink.cpp</a>
* :heavy_check_mark: <a href="bell.cpp.html">mod/bell.cpp</a>
* :heavy_check_mark: <a href="stirling_2nd.cpp.html">mod/stirling_2nd.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_A.test.cpp.html">test/aoj/DPL_5_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_B.test.cpp.html">test/aoj/DPL_5_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_C.test.cpp.html">test/aoj/DPL_5_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_D.test.cpp.html">test/aoj/DPL_5_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_E.test.cpp.html">test/aoj/DPL_5_E.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_F.test.cpp.html">test/aoj/DPL_5_F.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_G.test.cpp.html">test/aoj/DPL_5_G.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_H.test.cpp.html">test/aoj/DPL_5_H.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_I.test.cpp.html">test/aoj/DPL_5_I.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_J.test.cpp.html">test/aoj/DPL_5_J.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_K.test.cpp.html">test/aoj/DPL_5_K.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../mod/mint.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename M>
class Enumeration{
private:
  static vector<M> fact,finv,invs;
public:
  static void init(int n){
    n=min<decltype(M::mod)>(n,M::mod-1);

    int m=fact.size();
    if(n<m) return;

    fact.resize(n+1,1);
    finv.resize(n+1,1);
    invs.resize(n+1,1);

    if(m==0) m=1;
    for(int i=m;i<=n;i++) fact[i]=fact[i-1]*M(i);
    finv[n]=M(1)/fact[n];
    for(int i=n;i>=m;i--) finv[i-1]=finv[i]*M(i);
    for(int i=m;i<=n;i++) invs[i]=finv[i]*fact[i-1];
  }

  static M Fact(int n){
    init(n);
    return fact[n];
  }
  static M Finv(int n){
    init(n);
    return finv[n];
  }
  static M Invs(int n){
    init(n);
    return invs[n];
  }

  static M C(int n,int k){
    if(n<k||k<0) return M(0);
    init(n);
    return fact[n]*finv[n-k]*finv[k];
  }

  static M P(int n,int k){
    if(n<k||k<0) return M(0);
    init(n);
    return fact[n]*finv[n-k];
  }

  // put n identical balls into k distinct boxes
  static M H(int n,int k){
    if(n<0||k<0) return M(0);
    if(!n&&!k) return M(1);
    init(n+k);
    return C(n+k-1,n);
  }
};
template<typename M>
vector<M> Enumeration<M>::fact=vector<M>();
template<typename M>
vector<M> Enumeration<M>::finv=vector<M>();
template<typename M>
vector<M> Enumeration<M>::invs=vector<M>();
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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: mod/mint.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

