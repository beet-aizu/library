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


# :heavy_check_mark: datastructure/weightedunionfindtree.cpp
* category: datastructure


[Back to top page](../../index.html)



## Verified
* :heavy_check_mark: [test/aoj/DSL_1_B.test.cpp](../../verify/test/aoj/DSL_1_B.test.cpp.html)


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template <typename T>
struct WeightedUnionFind{
  vector<int> rs,ps;
  vector<T> ws;

  WeightedUnionFind(){}
  WeightedUnionFind(int n):
    rs(n,1),ps(n),ws(n,T(0)){iota(ps.begin(),ps.end(),0);}

  int find(int x){
    if(x==ps[x]) return x;
    int t=find(ps[x]);
    ws[x]+=ws[ps[x]];
    return ps[x]=t;
  }

  T weight(int x){
    find(x);
    return ws[x];
  }

  bool same(int x,int y){
    return find(x)==find(y);
  }

  void unite(int x,int y,T w){
    w+=weight(x);
    w-=weight(y);
    x=find(x);y=find(y);
    if(x==y) return;
    if(rs[x]<rs[y]) swap(x,y),w=-w;
    rs[x]+=rs[y];
    ps[y]=x;
    ws[y]=w;
  }

  T diff(int x,int y){
    return weight(y)-weight(x);
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

[Back to top page](../../index.html)

