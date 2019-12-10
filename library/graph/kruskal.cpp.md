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


# :heavy_check_mark: graph/kruskal.cpp
<a href="../../index.html">Back to top page</a>

* category: graph
* <a href="{{ site.github.repository_url }}/blob/master/graph/kruskal.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-21 16:50:01 +0900




## Required
* :warning: <a href="voronoiminimumspanningtree.cpp.html">graph/voronoiminimumspanningtree.cpp</a>
* :heavy_check_mark: <a href="../linearalgebra/tree_theorem.cpp.html">linearalgebra/tree_theorem.cpp</a>


## Verified
* :heavy_check_mark: <a href="../../verify/test/aoj/0403.test.cpp.html">test/aoj/0403.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_2_A.test.cpp.html">test/aoj/GRL_2_A.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct Kruskal{

  struct edge{
    int from,to;
    T cost;
    int used;
    edge(int from,int to,T cost):
      from(from),to(to),cost(cost),used(0){}
    bool operator<(const edge& e) const{
      return cost<e.cost;
    }
  };
  vector<int> r,p;
  vector<edge> es;

  Kruskal(){}
  Kruskal(int n):r(n,1),p(n){
    iota(p.begin(),p.end(),0);
  }

  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }

  bool same(int x,int y){
    return find(x)==find(y);
  }

  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }

  void add_edge(int u,int v,T c){
    es.emplace_back(u,v,c);
  }

  T build(){
    sort(es.begin(),es.end());
    T res=0;
    for(auto &e:es){
      if(!same(e.from,e.to)){
        res+=e.cost;
        unite(e.from,e.to);
        e.used=1;
      }
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
int main(){
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

