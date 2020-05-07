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


# :heavy_check_mark: tree/eulertourforbfs.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/eulertourforbfs.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-23 23:46:43+09:00




## Depends on

* :heavy_check_mark: <a href="levelancestor.cpp.html">tree/levelancestor.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/3405.test.cpp.html">test/yukicoder/3405.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "levelancestor.cpp"
#undef call_from_test

#endif

//BEGIN CUT HERE
struct EulerTourForBFS : LevelAncestor{
  using super = LevelAncestor;
  vector<int> ls;
  vector<vector<int>> H;
  EulerTourForBFS(int n):super(n),ls(n),H(n){}

  using super::par;
  using super::dep;
  void build(int r=0){
    super::build(r);
    int pos=0;
    queue<int> que;
    que.emplace(r);
    while(!que.empty()){
      int v=que.front();que.pop();
      ls[v]=pos++;
      H[dep[v]].emplace_back(v);
      for(int u:super::G[v]){
        if(u==par[0][v]) continue;
        que.emplace(u);
      }
    }
  }

  int idx(int v){return ls[v];}

  int find(int v,int d,int a){
    int l=-1,r=H[d].size();
    while(l+1<r){
      int m=(l+r)>>1;
      int p=super::up(H[d][m],d-dep[v]);
      if(ls[v]+a<=ls[p]) r=m;
      else l=m;
    }
    return ls[H[d][0]]+r;
  }

  template<typename F>
  void exec(int v,int d,F f){
    if(dep[v]+d>=n or H[dep[v]+d].empty()) return;
    int l=find(v,dep[v]+d,0);
    int r=find(v,dep[v]+d,1);
    if(l<r) f(l,r);
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
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 172, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 281, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: tree/eulertourforbfs.cpp: line 8: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

