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
    - Last commit date: 2020-08-20 13:52:10+09:00




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
struct RangeToRange{
  const int n;
  int ptr;
  RangeToRange(int n):n(n),ptr(3*n){}

  // (0n, 2n) : top segtree (to)
  // (2n, 4n) : bottom segtree (from)

  // map [3n, 4n) -> [n, 2n)
  template<typename F>
  void add_edge(int u,int v,F f){
    if(3*n<=u and u<4*n) u-=2*n;
    f(u,v);
  }

  template<typename F>
  void init(F f){
    for(int i=1;i<n;i++){
      int l=(i<<1)|0;
      int r=(i<<1)|1;
      add_edge(0*n+i,0*n+l,f);
      add_edge(0*n+i,0*n+r,f);
      add_edge(2*n+l,2*n+i,f);
      add_edge(2*n+r,2*n+i,f);
    }
  }

  // [l1, r1) -> [l2, r2)
  template<typename F,typename G>
  void add_edge(int l1,int r1,int l2,int r2,F f,G g){
    int k=ptr++;
    for(l1+=n,r1+=n;l1<r1;l1>>=1,r1>>=1){
      if(l1&1) add_edge(2*n+(l1++),k,f);
      if(r1&1) add_edge(2*n+(--r1),k,f);
    }
    for(l2+=n,r2+=n;l2<r2;l2>>=1,r2>>=1){
      if(l2&1) g(k,l2++);
      if(r2&1) g(k,--r2);
    }
  }
  int idx(int v)const{return 1*n+v;}
  size_t size()const{return ptr;}
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
struct RangeToRange{
  const int n;
  int ptr;
  RangeToRange(int n):n(n),ptr(3*n){}

  // (0n, 2n) : top segtree (to)
  // (2n, 4n) : bottom segtree (from)

  // map [3n, 4n) -> [n, 2n)
  template<typename F>
  void add_edge(int u,int v,F f){
    if(3*n<=u and u<4*n) u-=2*n;
    f(u,v);
  }

  template<typename F>
  void init(F f){
    for(int i=1;i<n;i++){
      int l=(i<<1)|0;
      int r=(i<<1)|1;
      add_edge(0*n+i,0*n+l,f);
      add_edge(0*n+i,0*n+r,f);
      add_edge(2*n+l,2*n+i,f);
      add_edge(2*n+r,2*n+i,f);
    }
  }

  // [l1, r1) -> [l2, r2)
  template<typename F,typename G>
  void add_edge(int l1,int r1,int l2,int r2,F f,G g){
    int k=ptr++;
    for(l1+=n,r1+=n;l1<r1;l1>>=1,r1>>=1){
      if(l1&1) add_edge(2*n+(l1++),k,f);
      if(r1&1) add_edge(2*n+(--r1),k,f);
    }
    for(l2+=n,r2+=n;l2<r2;l2>>=1,r2>>=1){
      if(l2&1) g(k,l2++);
      if(r2&1) g(k,--r2);
    }
  }
  int idx(int v)const{return 1*n+v;}
  size_t size()const{return ptr;}
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

