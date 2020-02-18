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


# :heavy_check_mark: tools/precision.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4a931512ce65bdc9ca6808adf92d8783">tools</a>
* <a href="{{ site.github.repository_url }}/blob/master/tools/precision.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 16:46:59+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2294.test.cpp.html">test/aoj/2294.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2308.test.cpp.html">test/aoj/2308.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2309.tarjan.test.cpp.html">test/aoj/2309.tarjan.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2309.test.cpp.html">test/aoj/2309.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2736.test.cpp.html">test/aoj/2736.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2975.test.cpp.html">test/aoj/2975.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_15_B.test.cpp.html">test/aoj/ALDS1_15_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/3049.test.cpp.html">test/aoj/geometry/3049.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_2_D.test.cpp.html">test/aoj/geometry/CGL_2_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/CGL_7_H.test.cpp.html">test/aoj/geometry/CGL_7_H.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1923.test.cpp.html">test/yukicoder/1923.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: tools/precision.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

