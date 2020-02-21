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


# :heavy_check_mark: tools/chminmax.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4a931512ce65bdc9ca6808adf92d8783">tools</a>
* <a href="{{ site.github.repository_url }}/blob/master/tools/chminmax.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 20:42:16+09:00




## Required by

* :heavy_check_mark: <a href="../datastructure/cartesiantree.cpp.html">datastructure/cartesiantree.cpp</a>
* :heavy_check_mark: <a href="../datastructure/slidingwindowaggregation.cpp.html">datastructure/slidingwindowaggregation.cpp</a>
* :heavy_check_mark: <a href="../graph/nicetree.cpp.html">graph/nicetree.cpp</a>
* :heavy_check_mark: <a href="../string/longestcommonsubstring.cpp.html">string/longestcommonsubstring.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0391.test.cpp.html">test/aoj/0391.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0415.test.cpp.html">test/aoj/0415.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0596.test.cpp.html">test/aoj/0596.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0613.test.cpp.html">test/aoj/0613.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1549.test.cpp.html">test/aoj/1549.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1607.test.cpp.html">test/aoj/1607.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2187.test.cpp.html">test/aoj/2187.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2230.test.cpp.html">test/aoj/2230.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2308.test.cpp.html">test/aoj/2308.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2627.test.cpp.html">test/aoj/2627.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2736.test.cpp.html">test/aoj/2736.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2790.test.cpp.html">test/aoj/2790.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2975.test.cpp.html">test/aoj/2975.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3069.lichao.test.cpp.html">test/aoj/3069.lichao.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3069.test.cpp.html">test/aoj/3069.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3112.test.cpp.html">test/aoj/3112.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_10_C.test.cpp.html">test/aoj/ALDS1_10_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_3_B.test.cpp.html">test/aoj/DPL_3_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_A.linkcuttree.test.cpp.html">test/aoj/GRL_5_A.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/2334.test.cpp.html">test/aoj/geometry/2334.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/3049.test.cpp.html">test/aoj/geometry/3049.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/3056.test.cpp.html">test/aoj/geometry/3056.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1732.test.cpp.html">test/yukicoder/1732.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/3227.test.cpp.html">test/yukicoder/3227.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: tools/chminmax.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

