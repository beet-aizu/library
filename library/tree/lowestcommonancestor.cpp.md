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


# :warning: tree/lowestcommonancestor.cpp
* category: tree


[Back to top page](../../index.html)



## Required
* :heavy_check_mark: [tree/eulertourforvertex.cpp](eulertourforvertex.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/GRL_5_C.lowestcommonancestor.test.cpp](../../verify/test/aoj/GRL_5_C.lowestcommonancestor.test.cpp.html)
* :heavy_check_mark: [test/yosupo/lca.test.cpp](../../verify/test/yosupo/lca.test.cpp.html)


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
struct LowestCommonAncestor{
  int n,h;
  vector< vector<int> > G,par;
  vector<int> dep;
  LowestCommonAncestor(){}
  LowestCommonAncestor(int n):n(n),G(n),dep(n){
    h=1;
    while((1<<h)<=n) h++;
    par.assign(h,vector<int>(n,-1));
  }

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void dfs(int v,int p,int d){
    par[0][v]=p;
    dep[v]=d;
    for(int u:G[v])
      if(u!=p) dfs(u,v,d+1);
  }

  void build(int r=0){
    dfs(r,-1,0);
    for(int k=0;k+1<h;k++)
      for(int v=0;v<n;v++)
        if(~par[k][v])
          par[k+1][v]=par[k][par[k][v]];
  }

  int lca(int u,int v){
    if(dep[u]>dep[v]) swap(u,v);
    for(int k=0;k<h;k++)
      if((dep[v]-dep[u])>>k&1)
        v=par[k][v];

    if(u==v) return u;

    for(int k=h-1;k>=0;k--)
      if(par[k][u]!=par[k][v])
        u=par[k][u],v=par[k][v];

    return par[0][u];
  }

  int distance(int u,int v){
    return dep[u]+dep[v]-dep[lca(u,v)]*2;
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

