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


# :heavy_check_mark: datastructure/quickfind.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/quickfind.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-22 00:23:31 +0900




## Verified With
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_1_A.quickfind.test.cpp.html">test/aoj/DSL_1_A.quickfind.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
struct QuickFind{
  int n;
  vector<int> rs,ps;
  vector<vector<int> > vs;
  QuickFind(){}
  QuickFind(int sz):n(sz),rs(sz,1),ps(sz),vs(sz){
    iota(ps.begin(),ps.end(),0);
    for(int i=0;i<n;i++) vs[i].assign(1,i);
  }
  int find(int x) const{return ps[x];}
  bool same(int x,int y) const{
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=ps[x];y=ps[y];
    if(x==y) return;
    if(rs[x]<rs[y]) swap(x,y);
    rs[x]+=rs[y];
    for(int e:vs[y]){
      ps[e]=x;
      vs[x].push_back(e);
    }
    vs[y].clear();
    vs[y].shrink_to_fit();
  }
  const vector<int>& elements(int x) const{return vs[x];}
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

