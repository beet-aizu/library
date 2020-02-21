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


# :heavy_check_mark: graph/chromatic.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/chromatic.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 22:09:22+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/1254.test.cpp.html">test/aoj/1254.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
int chromatic(vector< vector<int> > G){
  int n=G.size();
  if(n==0) return 0;
  assert(n<=30);

  vector<int> es(n,0);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      es[i]|=G[i][j]<<j;

  int s=1<<n;
  vector<int> dp(s);
  for(int b=0;b<s;b++)
    dp[b]=((n-__builtin_popcount(b))&1?-1:1);

  auto calc=
    [&](const int MOD){
      vector<int> res(s);
      res[0]=1;
      for(int b=1;b<s;b++){
        int ctz=__builtin_ctz(b);
        res[b]=res[b-(1<<ctz)]+res[(b-(1<<ctz))&~es[ctz]];
        if(res[b]>=MOD) res[b]-=MOD;
      }
      return res;
    };

  constexpr int MOD1 = 1077563119;
  constexpr int MOD2 = 1e9+7;
  vector<int> ind1=calc(MOD1);
  vector<int> ind2=calc(MOD2);

  using ll = long long;
  vector<int> dp1=dp,dp2=dp;
  for(int i=1;i<n;i++){
    ll sum1=0,sum2=0;
    for(int b=0;b<s;b++){
      dp1[b]=((ll)dp1[b]*ind1[b])%MOD1;
      sum1+=dp1[b];

      dp2[b]=((ll)dp2[b]*ind2[b])%MOD2;
      sum2+=dp2[b];
    }
    if(sum1%MOD1!=0) return i;
    if(sum2%MOD2!=0) return i;
  }
  return n;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: graph/chromatic.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

