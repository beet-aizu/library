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


# :heavy_check_mark: test/yosupo/dominatortree.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/dominatortree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-05 21:02:53+09:00


* see: <a href="https://judge.yosupo.jp/problem/dominatortree">https://judge.yosupo.jp/problem/dominatortree</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/dominatortree.cpp.html">graph/dominatortree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/dominatortree"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/dominatortree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,s;
  cin>>n>>m>>s;
  DominatorTree G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    G.add_edge(a,b);
  }
  G.build(s);
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<G[i];
  }
  cout<<endl;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/dominatortree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/dominatortree"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "graph/dominatortree.cpp"

#line 3 "graph/dominatortree.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
struct DominatorTree{
  struct UnionFind{
    vector<int> &semi;
    vector<int> ps,ms;
    UnionFind(vector<int> &semi):
      semi(semi),ps(semi.size()),ms(semi.size()){
      iota(ps.begin(),ps.end(),0);
      iota(ms.begin(),ms.end(),0);
    }
    int find(int v){
      if(ps[v]==v) return v;
      int r=find(ps[v]);
      if(semi[ms[v]]>semi[ms[ps[v]]]) ms[v]=ms[ps[v]];
      return ps[v]=r;
    }
    int eval(int v){
      find(v);
      return ms[v];
    }
    void link(int p,int v){ps[v]=p;}
  };

  vector< vector<int> > G,R;
  vector<int> ord,par,idom,semi;
  DominatorTree(int n):
    G(n),R(n),par(n),idom(n,-1),semi(n,-1){
    ord.reserve(n);
  }

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    R[v].emplace_back(u);
  }

  void dfs(int v){
    semi[v]=ord.size();
    ord.emplace_back(v);
    for(int u:G[v]){
      if(~semi[u]) continue;
      par[u]=v;
      dfs(u);
    }
  }

  void build(int rt){
    int n=G.size();
    dfs(rt);

    vector< vector<int> > bkt(n);
    UnionFind uf(semi);
    vector<int> us(n);

    for(int i=(int)ord.size()-1;i>=0;i--){
      int v=ord[i];
      for(int u:R[v]){
        if(semi[u]<0) continue;
        u=uf.eval(u);
        if(semi[v]>semi[u]) semi[v]=semi[u];
      }
      bkt[ord[semi[v]]].emplace_back(v);
      for(int u:bkt[par[v]]) us[u]=uf.eval(u);
      bkt[par[v]].clear();
      uf.link(par[v],v);
    }

    for(int i=1;i<(int)ord.size();i++){
      int v=ord[i],u=us[v];
      idom[v]=(semi[v]==semi[u]?semi[v]:idom[u]);
    }

    for(int i=1;i<(int)ord.size();i++){
      int v=ord[i];
      idom[v]=ord[idom[v]];
    }

    idom[rt]=rt;
  }

  int operator[](int k){return idom[k];}
};
//END CUT HERE
#ifndef call_from_test
int main(){
  return 0;
}
#endif
#line 8 "test/yosupo/dominatortree.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,s;
  cin>>n>>m>>s;
  DominatorTree G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    G.add_edge(a,b);
  }
  G.build(s);
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<G[i];
  }
  cout<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

