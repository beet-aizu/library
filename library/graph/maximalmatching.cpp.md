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


# :heavy_check_mark: graph/maximalmatching.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/maximalmatching.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 16:09:50+09:00




## Depends on

* :heavy_check_mark: <a href="../mod/mint.cpp.html">mod/mint.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2983.test.cpp.html">test/aoj/2983.test.cpp</a>


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
int maximal_matching(vector< vector<int> > G){
  int n=G.size();

  random_device rd;
  mt19937 mt(rd());
  using M = Mint<int>;
  uniform_int_distribution<int> ud(1,M::mod-1);

  vector< vector<M> > H(n,vector<M>(n,0));
  for(int v=0;v<n;v++){
    for(int u:G[v]){
      if(u>=v) continue;
      M val(ud(mt));
      H[u][v]= val;
      H[v][u]=-val;
    }
  }

  int res=0;
  for(int i=0,j=0;i<n;i++){
    while(j<n&&H[i][j]==M(0)){
      int p=i;
      for(int k=i+1;k<n;k++)
        if(H[k][j]!=M(0)) p=k;
      if(i!=p) swap(H[i],H[p]);
      else j++;
    }
    if(j==n) break;
    M tmp=H[i][j].inv();
    for(int s=j;s<n;s++) H[i][s]*=tmp;
    for(int k=i+1;k<n;k++)
      for(int s=n-1;s>=j;s--)
        H[k][s]-=H[k][j]*H[i][s];

    j++;res++;
  }
  return (res+1)/2;
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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: mod/mint.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

