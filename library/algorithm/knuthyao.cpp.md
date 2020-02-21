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


# :heavy_check_mark: algorithm/knuthyao.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ed469618898d75b149e5c7c4b6a1c415">algorithm</a>
* <a href="{{ site.github.repository_url }}/blob/master/algorithm/knuthyao.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 22:20:47+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2415.knuthyao.test.cpp.html">test/aoj/2415.knuthyao.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2488.test.cpp.html">test/aoj/2488.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// f(i,l) + f(j,k) >= f(i,k) + f(j,l) (i <= j, k <= l)
template<typename T, typename F>
T KnuthYao(int n,F cost){
  vector< vector<T> > dp(n,vector<T>(n));
  vector< vector<int> > ar(n,vector<int>(n));
  for(int i=0;i<n;i++) dp[i][i]=T(0),ar[i][i]=i;
  for(int w=1;w<n;w++){
    for(int i=0;i+w<n;i++){
      int j=i+w;
      int p=ar[i][j-1],q=ar[i+1][j];
      dp[i][j]=dp[i][p]+dp[p+1][j]+cost(i,p,j);
      ar[i][j]=p;
      for(int k=p;k<=q&&k+1<=j;k++){
        T res=dp[i][k]+dp[k+1][j]+cost(i,k,j);
        if(res<dp[i][j]) dp[i][j]=res,ar[i][j]=k;
      }
    }
  }
  return dp[0][n-1];
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: algorithm/knuthyao.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

