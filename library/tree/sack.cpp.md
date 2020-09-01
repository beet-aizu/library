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


# :heavy_check_mark: tree/sack.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/sack.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-01 22:32:20+09:00


* see: <a href="https://codeforces.com/blog/entry/44351">https://codeforces.com/blog/entry/44351</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2995.test.cpp.html">test/aoj/2995.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

/**
 * @see https://codeforces.com/blog/entry/44351
 */
//BEGIN CUT HERE
struct Sack{
  using F = function<void(int)>;

  vector<int> sub,hvy,big;
  vector< vector<int> > G,Q;
  F expand,shrink,query,reset;

  Sack(int n,F expand,F shrink,F query,F reset):
    sub(n,1),hvy(n,-1),big(n,0),G(n),Q(n),
    expand(expand),shrink(shrink),
    query(query),reset(reset){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void add_query(int v,int k){
    Q[v].emplace_back(k);
    sub[v]++;
  }

  void add(int v,int p,int x){
    if(x==1) expand(v);
    else shrink(v);
    for(int u:G[v])
      if(u!=p&&!big[u]) add(u,v,x);
  }

  void dfs(int v=0,int p=-1,bool k=0){
    for(int u:G[v])
      if(u!=p&&u!=hvy[v]) dfs(u,v,0);
    if(~hvy[v]){
      dfs(hvy[v],v,1);
      big[hvy[v]]=1;
    }
    add(v,p,1);
    for(int k:Q[v]) query(k);
    if(~hvy[v]) big[hvy[v]]=0;
    if(!k) add(v,p,0),reset(v);
  }

  void build(int v=0,int p=-1){
    for(int u:G[v]){
      if(u==p) continue;
      build(u,v);
      if(hvy[v]<0||sub[hvy[v]]<sub[u]) hvy[v]=u;
      sub[v]+=sub[u];
    }
    if(p==-1) dfs(v,p);
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
#line 2 "tree/sack.cpp"

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

/**
 * @see https://codeforces.com/blog/entry/44351
 */
//BEGIN CUT HERE
struct Sack{
  using F = function<void(int)>;

  vector<int> sub,hvy,big;
  vector< vector<int> > G,Q;
  F expand,shrink,query,reset;

  Sack(int n,F expand,F shrink,F query,F reset):
    sub(n,1),hvy(n,-1),big(n,0),G(n),Q(n),
    expand(expand),shrink(shrink),
    query(query),reset(reset){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void add_query(int v,int k){
    Q[v].emplace_back(k);
    sub[v]++;
  }

  void add(int v,int p,int x){
    if(x==1) expand(v);
    else shrink(v);
    for(int u:G[v])
      if(u!=p&&!big[u]) add(u,v,x);
  }

  void dfs(int v=0,int p=-1,bool k=0){
    for(int u:G[v])
      if(u!=p&&u!=hvy[v]) dfs(u,v,0);
    if(~hvy[v]){
      dfs(hvy[v],v,1);
      big[hvy[v]]=1;
    }
    add(v,p,1);
    for(int k:Q[v]) query(k);
    if(~hvy[v]) big[hvy[v]]=0;
    if(!k) add(v,p,0),reset(v);
  }

  void build(int v=0,int p=-1){
    for(int u:G[v]){
      if(u==p) continue;
      build(u,v);
      if(hvy[v]<0||sub[hvy[v]]<sub[u]) hvy[v]=u;
      sub[v]+=sub[u];
    }
    if(p==-1) dfs(v,p);
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

