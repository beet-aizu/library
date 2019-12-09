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


# :heavy_check_mark: graph/stronglyconnectedcomponent.cpp
* category: graph


[Back to top page](../../index.html)



## Required
* :heavy_check_mark: [graph/arborescence_edmond.cpp](arborescence_edmond.cpp.html)
* :heavy_check_mark: [graph/twosatisfiability.cpp](twosatisfiability.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/2222.test.cpp](../../verify/test/aoj/2222.test.cpp.html)
* :heavy_check_mark: [test/aoj/2309.tarjan.test.cpp](../../verify/test/aoj/2309.tarjan.test.cpp.html)
* :heavy_check_mark: [test/aoj/2309.test.cpp](../../verify/test/aoj/2309.test.cpp.html)
* :heavy_check_mark: [test/aoj/2647.test.cpp](../../verify/test/aoj/2647.test.cpp.html)
* :heavy_check_mark: [test/aoj/3102.test.cpp](../../verify/test/aoj/3102.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_2_B.test.cpp](../../verify/test/aoj/GRL_2_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_3_C.test.cpp](../../verify/test/aoj/GRL_3_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_4_A.test.cpp](../../verify/test/aoj/GRL_4_A.test.cpp.html)
* :heavy_check_mark: [test/yosupo/scc.test.cpp](../../verify/test/yosupo/scc.test.cpp.html)


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
struct SCC{
  vector<vector<int> > G,R,T,C;
  vector<int> vs,used,blg;
  SCC(){}
  SCC(int n):G(n),R(n),used(n),blg(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    R[v].emplace_back(u);
  }

  void dfs(int v){
    used[v]=1;
    for(int u:G[v])
      if(!used[u]) dfs(u);
    vs.emplace_back(v);
  }

  void rdfs(int v,int k){
    used[v]=1;
    blg[v]=k;
    C[k].emplace_back(v);
    for(int u:R[v])
      if(!used[u]) rdfs(u,k);
  }

  int build(){
    int n=G.size();
    for(int v=0;v<n;v++)
      if(!used[v]) dfs(v);

    fill(used.begin(),used.end(),0);
    int k=0;
    for(int i=n-1;i>=0;i--){
      if(!used[vs[i]]){
        T.emplace_back();
        C.emplace_back();
        rdfs(vs[i],k++);
      }
    }
    for(int v=0;v<n;v++)
      for(int u:G[v])
        if(blg[v]!=blg[u])
          T[blg[v]].push_back(blg[u]);

    for(int i=0;i<k;i++){
      sort(T[i].begin(),T[i].end());
      T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());
    }
    return k;
  }
  int operator[](int k) const{return blg[k];}
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

