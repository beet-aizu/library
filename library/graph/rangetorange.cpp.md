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


# :heavy_check_mark: graph/rangetorange.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/rangetorange.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-20 13:09:57+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/4387.test.cpp.html">test/yukicoder/4387.test.cpp</a>


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
template<typename T>
struct RangeToRange{
  using E = pair<int, T>;
  const int n;
  vector<vector<E>> G;
  // (0n, 2n) : top segtree (to)
  // (2n, 4n) : bottom segtree (from)
  RangeToRange(int n):n(n){
    G.resize(n*4);
    for(int i=1;i<n;i++){
      int l=(i<<1)|0;
      int r=(i<<1)|1;
      G[0*n+i].emplace_back(0*n+l,0);
      G[0*n+i].emplace_back(0*n+r,0);
      G[2*n+l].emplace_back(2*n+i,0);
      G[2*n+r].emplace_back(2*n+i,0);
    }
    for(int i=0;i<n;i++)
      G[1*n+i].emplace_back(3*n+i,0);
  }
  // [l1, r1) -> [l2, r2)
  void add_edge(int l1,int r1,int l2,int r2,T c){
    int k=G.size();
    for(l1+=n,r1+=n;l1<r1;l1>>=1,r1>>=1){
      if(l1&1) G[2*n+(l1++)].emplace_back(k,0);
      if(r1&1) G[2*n+(--r1)].emplace_back(k,0);
    }
    vector<E> es;
    for(l2+=n,r2+=n;l2<r2;l2>>=1,r2>>=1){
      if(l2&1) es.emplace_back(l2++,c);
      if(r2&1) es.emplace_back(--r2,c);
    }
    G.emplace_back(es);
  }
  int idx(int v)const{return 1*n+v;}
  size_t size()const{return G.size();}
  const vector<E>& operator[](int k)const{return G[k];}
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
#line 2 "graph/rangetorange.cpp"

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct RangeToRange{
  using E = pair<int, T>;
  const int n;
  vector<vector<E>> G;
  // (0n, 2n) : top segtree (to)
  // (2n, 4n) : bottom segtree (from)
  RangeToRange(int n):n(n){
    G.resize(n*4);
    for(int i=1;i<n;i++){
      int l=(i<<1)|0;
      int r=(i<<1)|1;
      G[0*n+i].emplace_back(0*n+l,0);
      G[0*n+i].emplace_back(0*n+r,0);
      G[2*n+l].emplace_back(2*n+i,0);
      G[2*n+r].emplace_back(2*n+i,0);
    }
    for(int i=0;i<n;i++)
      G[1*n+i].emplace_back(3*n+i,0);
  }
  // [l1, r1) -> [l2, r2)
  void add_edge(int l1,int r1,int l2,int r2,T c){
    int k=G.size();
    for(l1+=n,r1+=n;l1<r1;l1>>=1,r1>>=1){
      if(l1&1) G[2*n+(l1++)].emplace_back(k,0);
      if(r1&1) G[2*n+(--r1)].emplace_back(k,0);
    }
    vector<E> es;
    for(l2+=n,r2+=n;l2<r2;l2>>=1,r2>>=1){
      if(l2&1) es.emplace_back(l2++,c);
      if(r2&1) es.emplace_back(--r2,c);
    }
    G.emplace_back(es);
  }
  int idx(int v)const{return 1*n+v;}
  size_t size()const{return G.size();}
  const vector<E>& operator[](int k)const{return G[k];}
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

