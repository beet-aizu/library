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


# :heavy_check_mark: tree/heavylightdecomposition.cpp
* category: tree


<a href="../../index.html">Back to top page</a>



## Dependencies
* :warning: <a href="../graph/lowlink.cpp.html">graph/lowlink.cpp</a>
* :warning: <a href="../segtree/basic/ushi.cpp.html">segtree/basic/ushi.cpp</a>


## Required
* :warning: <a href="../datastructure/binarytrie.cpp.html">datastructure/binarytrie.cpp</a>


## Verified
* :heavy_check_mark: <a href="../../verify/test/aoj/2450.test.cpp.html">test/aoj/2450.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2667.test.cpp.html">test/aoj/2667.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_C.test.cpp.html">test/aoj/GRL_5_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_path_sum.test.cpp.html">test/yosupo/vertex_add_path_sum.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
class HLD {
private:
  void dfs_sz(int v) {
    for(int &u:G[v]){
      if(u==par[v]) continue;
      par[u]=v;
      dep[u]=dep[v]+1;
      dfs_sz(u);
      sub[v]+=sub[u];
      if(sub[u]>sub[G[v][0]]) swap(u,G[v][0]);
    }
  }

  void dfs_hld(int v,int c,int &pos) {
    vid[v]=pos++;
    inv[vid[v]]=v;
    type[v]=c;
    for(int u:G[v]){
      if(u==par[v]) continue;
      head[u]=(u==G[v][0]?head[v]:u);
      dfs_hld(u,c,pos);
    }
  }

public:
  vector<vector<int> > G;
  vector<int> vid, head, sub, par, dep, inv, type;

  HLD(int n):
    G(n),vid(n,-1),head(n),sub(n,1),
    par(n,-1),dep(n,0),inv(n),type(n){}

  void add_edge(int u,int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build(vector<int> rs={0}) {
    int c=0,pos=0;
    for(int r:rs){
      dfs_sz(r);
      head[r]=r;
      dfs_hld(r,c++,pos);
    }
  }

  int lca(int u,int v){
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]==head[v]) return u;
      v=par[head[v]];
    }
  }

  int distance(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
  }

  // for_each(vertex)
  // [l, r) <- attention!!
  template<typename F>
  void for_each(int u, int v, const F& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      f(max(vid[head[v]],vid[u]),vid[v]+1);
      if(head[u]!=head[v]) v=par[head[v]];
      else break;
    }
  }

  template<typename T,typename Q,typename F>
  T for_each(int u,int v,T ti,const Q &q,const F &f){
    T l=ti,r=ti;
    while(1){
      if(vid[u]>vid[v]){
        swap(u,v);
        swap(l,r);
      }
      l=f(l,q(max(vid[head[v]],vid[u]),vid[v]+1));
      if(head[u]!=head[v]) v=par[head[v]];
      else break;
    }
    return f(l,r);
  }

  // for_each(edge)
  // [l, r) <- attention!!
  template<typename F>
  void for_each_edge(int u, int v,const F& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]!=head[v]){
        f(vid[head[v]],vid[v]+1);
        v=par[head[v]];
      }else{
        if(u!=v) f(vid[u]+1,vid[v]+1);
        break;
      }
    }
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../graph/lowlink.cpp"
#include "../segtree/basic/ushi.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed YUKI_529(){
  int n,e,q;
  scanf("%d %d %d",&n,&e,&q);

  LowLink big(n);
  for(int i=0;i<e;i++){
    int u,v;
    scanf("%d %d",&u,&v);
    u--;v--;
    big.add_edge(u,v);
  }

  int E=0,V=big.build();
  HLD hld(V);
  for(int i=0;i<V;i++)
    for(int j:big.T[i])
      if(i<j) hld.add_edge(i,j),E++;
  hld.build();

  SegmentTree<int> rmq([](int a,int b){return max(a,b);},-1);
  rmq.build(vector<int>(V,-1));

  vector<priority_queue<int> > pq(V);
  map<int,int> m;
  int num=0;
  for(int i=0;i<q;i++){
    int d;
    scanf("%d",&d);
    if(d==1){
      int u,w;
      scanf("%d %d",&u,&w);
      u--;
      u=big.blg[u];
      u=hld.vid[u];
      m[w]=u;
      if(pq[u].empty()||pq[u].top()<w) rmq.set_val(u,w);
      pq[u].push(w);
      num++;
    }
    if(d==2){
      int s,t;
      scanf("%d %d",&s,&t);
      s--;t--;
      s=big.blg[s];
      t=big.blg[t];
      auto f=[&](int l,int r){return rmq.query(l,r);};
      int ans=hld.for_each(s,t,-1,f,rmq.f);
      printf("%d\n",ans);
      if(~ans){
        int k=m[ans];
        pq[k].pop();
        rmq.set_val(k,(!pq[k].empty()?pq[k].top():-1));
        num--;
      }
    }
  }
  return 0;
}
/*
  verified on 2019/10/25
  https://yukicoder.me/problems/no/529
*/
signed main(){
  YUKI_529();
  return 0;
};
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

