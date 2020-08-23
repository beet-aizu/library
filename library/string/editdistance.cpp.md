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


# :heavy_check_mark: string/editdistance.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/editdistance.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-29 17:38:35+09:00




## Depends on

* :heavy_check_mark: <a href="../tools/chminmax.cpp.html">tools/chminmax.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_1_E.test.cpp.html">test/aoj/DPL_1_E.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../tools/chminmax.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
int edit_distance(string s,string t){
  int n=s.size(),m=t.size();
  vector< vector<int> > dp(n+1,vector<int>(m+1,n+m+1));
  dp[0][0]=0;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(i<n) chmin(dp[i+1][j],dp[i][j]+1);
      if(j<m) chmin(dp[i][j+1],dp[i][j]+1);
      if(i<n and j<m)
        chmin(dp[i+1][j+1],dp[i][j]+(s[i]!=t[j]));
    }
  }
  return dp[n][m];
}
//END CUT HERE
//INSERT ABOVE HERE
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 398, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/editdistance.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

