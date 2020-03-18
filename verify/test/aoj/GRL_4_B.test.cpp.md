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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/GRL_4_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_4_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 21:51:08+09:00




## Depends on

* :heavy_check_mark: <a href="../../../library/graph/topologicalsort.cpp.html">graph/topologicalsort.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/fastio.cpp.html">tools/fastio.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../graph/topologicalsort.cpp"
#undef call_from_test

#define IGNORE

signed main(){
  int n,e;
  cin>>n>>e;
  TopologicalSort ts(n);
  for(int i=0;i<e;i++){
    int s,t;
    cin>>s>>t;
    ts.add_edge(s,t);
  }

  auto ps=ts.build();
  for(int i:ps) cout<<i<<endl;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_4_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "test/aoj/../../tools/fastio.cpp"

#line 3 "test/aoj/../../tools/fastio.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 1 "test/aoj/../../graph/topologicalsort.cpp"

#line 3 "test/aoj/../../graph/topologicalsort.cpp"
using namespace std;
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
#line 9 "test/aoj/GRL_4_B.test.cpp"
#undef call_from_test

#define IGNORE

signed main(){
  int n,e;
  cin>>n>>e;
  TopologicalSort ts(n);
  for(int i=0;i<e;i++){
    int s,t;
    cin>>s>>t;
    ts.add_edge(s,t);
  }

  auto ps=ts.build();
  for(int i:ps) cout<<i<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

