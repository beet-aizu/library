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


# :warning: graph/topologicalsort.cpp
* category: graph


<a href="../../index.html">Back to top page</a>



## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
struct TopologicalSort{
  vector< set<int> > G;
  vector<int> used,indeg,ps;

  TopologicalSort(){}
  TopologicalSort(int n):G(n),used(n,0),indeg(n,0){}

  void add_edge(int s,int t){
    G[s].emplace(t);
    indeg[t]++;
  }

  void bfs(int s){
    queue<int> que;
    que.emplace(s);
    used[s]=1;
    while(!que.empty()){
      int v=que.front();que.pop();
      ps.emplace_back(v);
      for(int u:G[v]){
        indeg[u]--;
        if(indeg[u]==0&&!used[u]){
          used[u]=1;
          que.emplace(u);
        }
      }
    }
  }

  vector<int> build(){
    int n=G.size();
    for(int i=0;i<n;i++)
      if(indeg[i]==0&&!used[i]) bfs(i);
    return ps;
  }
};
//END CUT HERE
#ifndef call_from_test
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

