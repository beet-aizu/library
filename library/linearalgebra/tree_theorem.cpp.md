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


# :warning: linearalgebra/tree_theorem.cpp
* category: linearalgebra


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [datastructure/unionfindtree.cpp](../datastructure/unionfindtree.cpp.html)
* :heavy_check_mark: [graph/kruskal.cpp](../graph/kruskal.cpp.html)
* :heavy_check_mark: [linearalgebra/matrix.cpp](matrix.cpp.html)
* :heavy_check_mark: [mod/mint.cpp](../mod/mint.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/0314.test.cpp](../../verify/test/aoj/0314.test.cpp.html)


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "matrix.cpp"
#include "../datastructure/unionfindtree.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename K, typename T>
struct MatrixTreeTheorem{
  using M = Matrix<K>;
  struct edge{
    int a,b;
    T c;
    edge(int a,int b,T c):a(a),b(b),c(c){}
    bool operator<(const edge &e)const{
      return c<e.c;
    }
  };

  vector<edge> es;
  vector<int> used;
  vector<vector<int> > H;
  UnionFind uf;

  MatrixTreeTheorem(int n):used(n),H(n),uf(n){}

  void add_edge(int a,int b,T c){
    es.emplace_back(a,b,c);
  }

  vector<int> bfs(int v){
    vector<int> vs;
    queue<int> q;
    used[v]=1;
    q.emplace(v);
    while(!q.empty()){
      v=q.front();q.pop();
      vs.emplace_back(v);
      for(int u:H[v]){
        if(used[u]) continue;
        used[u]=1;
        q.emplace(u);
      }
    }
    return vs;
  }

  K build(){
    sort(es.begin(),es.end());
    fill(used.begin(),used.end(),0);
    K res(1);
    for(int i=0;i<(int)es.size();){
      queue<int> q,r;
      for(auto &h:H) h.clear();
      int p=i;
      while(i<(int)es.size()&&es[i].c==es[p].c){
        int u=uf.find(es[i].a);
        int v=uf.find(es[i++].b);
        H[u].emplace_back(v);
        H[v].emplace_back(u);
        q.emplace(u);q.emplace(v);
        r.emplace(u);r.emplace(v);
      }
      while(!q.empty()){
        int v=q.front();q.pop();
        if(used[v]) continue;
        vector<int> vs=bfs(v);
        int m=vs.size();
        if(m==1) continue;

        sort(vs.begin(),vs.end());
        auto idx=
          [&](int x){
            return lower_bound(vs.begin(),vs.end(),x)-vs.begin();
          };
        M A(m,m);
        for(int x:vs)
          for(int y:H[x])
            if(x!=y) A[idx(x)][idx(y)]-=K(1);

        for(int x=0;x<m;x++)
          for(int y=0;y<m;y++)
            if(x!=y) A[x][x]-=A[x][y];

        A.dat.pop_back();
        for(auto &a:A.dat) a.pop_back();

        res*=A.determinant();
        for(int x:vs) uf.unite(v,x);
      }
      while(!r.empty()){
        int v=r.front();r.pop();
        used[v]=0;
      }
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../mod/mint.cpp"
#include "../graph/kruskal.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed ARC018_D(){
  using M = Mint<int>;
  int n,m;
  scanf("%d %d",&n,&m);
  MatrixTreeTheorem<M, int> mtt(n);
  Kruskal<int> G(n);
  for(int i=0;i<m;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    a--;b--;
    mtt.add_edge(a,b,c);
    G.add_edge(a,b,c);
  }
  printf("%d %d\n",G.build(),mtt.build().v);
  return 0;
}
/*
  verified on 2018/10/30
  https://atcoder.jp/contests/arc018/tasks/arc018_4
*/

signed main(){
  ARC018_D();
  return 0;
}
#endif

```
{% endraw %}

[Back to top page](../../index.html)

