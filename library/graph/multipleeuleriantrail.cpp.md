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


# :heavy_check_mark: graph/multipleeuleriantrail.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/multipleeuleriantrail.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-22 14:49:35+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2324.test.cpp.html">test/aoj/2324.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// no muliple edge
template<typename Graph>
bool hasMultipleEulerianTrail(Graph &G){
  int n=G.size();
  vector<int> ind(n,0),outd(n,0),pre(n,-1),loop(n,0);
  for(int v=0;v<n;v++){
    for(int u:G[v]){
      ind[u]++,outd[v]++;
      if(u==v) loop[v]=1;
      if(u!=v) pre[u]=v;
    }
  }

  int st=-1,en=-1,sz=0;
  for(int i=0;i<n;i++){
    if(ind[i]>=3||outd[i]>=3) return true;
    if(ind[i]<outd[i]) st=i;
    if(ind[i]>outd[i]) en=i;
    if(ind[i]+outd[i]) sz++;
  }
  if(sz<2) return false;
  if(st<0) return true;

  while(ind[en]==1+loop[en]&&st!=en) en=pre[en];
  if(st==en) return false;

  queue<int> que;
  vector<int> rs(n,0);
  que.emplace(st);
  rs[st]=1;
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int u:G[v]){
      if(u==en||rs[u]) continue;
      rs[u]=1;
      que.emplace(u);
    }
  }

  vector<int> us(n,0);
  que.emplace(en);
  us[en]=1;
  while(!que.empty()){
    int v=que.front();que.pop();
    if(rs[v]) return true;
    for(int u:G[v]){
      if(u==en||us[u]) continue;
      us[u]=1;
      que.emplace(u);
    }
  }
  return false;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: graph/multipleeuleriantrail.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

