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


# :heavy_check_mark: graph/triangle.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/triangle.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-07 17:33:53+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/enumerate_triangles.test.cpp.html">test/yosupo/enumerate_triangles.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Triangle{
  // if not simple, use vector<set<int>>
  vector<vector<int>> G;
  Triangle(int n):G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  template<typename F>
  void build(F f){
    int n=G.size();
    using P = pair<int, int>;
    vector<P> vp(n);
    for(int i=0;i<n;i++) vp[i]=P(G[i].size(),i);

    vector<vector<int>> H(n);
    for(int i=0;i<n;i++)
      for(int j:G[i])
        if(vp[i]>vp[j])
          H[i].emplace_back(j);

    vector<int> used(n,0);
    // x->y->z
    for(int x=0;x<n;x++){
      for(int z:H[x]) used[z]=1;
      for(int y:H[x])
        for(int z:H[y])
          if(used[z]) f(x,y,z);
      for(int z:H[x]) used[z]=0;
    }
  }
};
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
#line 2 "graph/triangle.cpp"

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Triangle{
  // if not simple, use vector<set<int>>
  vector<vector<int>> G;
  Triangle(int n):G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  template<typename F>
  void build(F f){
    int n=G.size();
    using P = pair<int, int>;
    vector<P> vp(n);
    for(int i=0;i<n;i++) vp[i]=P(G[i].size(),i);

    vector<vector<int>> H(n);
    for(int i=0;i<n;i++)
      for(int j:G[i])
        if(vp[i]>vp[j])
          H[i].emplace_back(j);

    vector<int> used(n,0);
    // x->y->z
    for(int x=0;x<n;x++){
      for(int z:H[x]) used[z]=1;
      for(int y:H[x])
        for(int z:H[y])
          if(used[z]) f(x,y,z);
      for(int z:H[x]) used[z]=0;
    }
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

