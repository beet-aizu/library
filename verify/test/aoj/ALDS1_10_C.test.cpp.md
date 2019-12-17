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


# :heavy_check_mark: test/aoj/ALDS1_10_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_10_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-18 20:46:22 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/string/longestcommonsubstring.cpp.html">string/longestcommonsubstring.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/chminmax.cpp.html">tools/chminmax.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../string/longestcommonsubstring.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int q;
  cin>>q;
  while(q--){
    string s,t;
    cin>>s>>t;
    cout<<longest_common_substring(s,t)<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 339, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 150, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 52, in _resolve
    raise BundleError(path, -1, "no such header")
onlinejudge_verify.bundle.BundleError: ../../tools/chminmax.cpp: line -1: no such header

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

