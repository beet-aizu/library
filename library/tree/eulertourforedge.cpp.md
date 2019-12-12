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


# :heavy_check_mark: tree/eulertourforedge.cpp
<a href="../../index.html">Back to top page</a>

* category: tree
* <a href="{{ site.github.repository_url }}/blob/master/tree/eulertourforedge.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 23:51:01 +0900




## Depends On
* :heavy_check_mark: <a href="../datastructure/binaryindexedtree.cpp.html">datastructure/binaryindexedtree.cpp</a>
* :warning: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>
* :warning: <a href="lca.cpp.html">tree/lca.cpp</a>


## Required By
* :warning: <a href="../algorithm/mo.cpp.html">algorithm/mo.cpp</a>


## Verified With
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_D.test.cpp.html">test/aoj/GRL_5_D.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
class EulerTourForEdge{
private:
  vector<int> ds,us,dep,btm;

  void dfs(int v,int p,int d){
    dep[v]=d;
    for(int u:G[v]){
      if(u==p) continue;
      ds[u]=btm.size();
      btm.emplace_back(u);
      dfs(u,v,d+1);
      us[u]=btm.size();
      btm.emplace_back(u);
    }
  }
public:
  vector< vector<int> > G;

  EulerTourForEdge(){}
  EulerTourForEdge(int n):
    ds(n),us(n),dep(n),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build(int r=0){
    btm.clear();
    ds[r]=btm.size();
    btm.emplace_back(r);
    dfs(r,-1,0);
    us[r]=btm.size();
    btm.emplace_back(r);
  }

  int child(int u,int v){
    return dep[u]<dep[v]?v:u;
  }

  int bottom(int e){
    return btm[e];
  }

  // lca(u, v) must be u or v
  template<typename F>
  void query(int u,int v,F f){
    if(dep[u]>dep[v]) swap(u,v);
    f(ds[u]+1,ds[v]+1);
  }

  template<typename T,typename G>
  void update(int v,T x,G g){
    g(ds[v], x);
    g(us[v],-x);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../datastructure/binaryindexedtree.cpp"
#include "lca.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed ABC133_F(){

  int n,q;
  cin>>n>>q;
  vector<int> as(n),bs(n),cs(n),ds(n);
  vector<int> xs(q),ys(q),us(q),vs(q);

  vector< vector<int> > C(n),D(n);
  EulerTourForEdge et(n);
  LCA lca(n);
  for(int i=1;i<n;i++){
    cin>>as[i]>>bs[i]>>cs[i]>>ds[i];
    as[i]--;bs[i]--;
    et.add_edge(as[i],bs[i]);
    lca.add_edge(as[i],bs[i]);
    C[cs[i]].emplace_back(i);
  }
  et.build();
  lca.build();

  for(int i=0;i<q;i++){
    cin>>xs[i]>>ys[i]>>us[i]>>vs[i];
    us[i]--;vs[i]--;
    D[xs[i]].emplace_back(i);
  }

  int ti=0;
  BIT<int> cnt(n*2,ti);
  BIT<int> sum(n*2,ti);

  for(int i=1;i<n;i++){
    int ch=et.child(as[i],bs[i]);
    auto g=[&](int v,int d){sum.add0(v,d);};
    et.update(ch,+ds[i],g);
  }

  vector<int> ans(q,0);
  for(int i=0;i<q;i++){
    int r=lca.lca(us[i],vs[i]);
    auto f=[&](int l,int r){ans[i]+=sum.query0(l,r);};
    et.query(r,us[i],f);
    et.query(r,vs[i],f);
  }

  for(int i=1;i<n;i++){
    int ch=et.child(as[i],bs[i]);
    auto g=[&](int v,int d){sum.add0(v,d);};
    et.update(ch,-ds[i],g);
  }

  for(int t=1;t<n;t++){
    auto g1=[&](int v,int d){cnt.add0(v,d);};
    auto g2=[&](int v,int d){sum.add0(v,d);};

    for(int i:C[t]){
      int ch=et.child(as[i],bs[i]);
      et.update(ch,+1,g1);
      et.update(ch,+ds[i],g2);
    }

    for(int i:D[t]){
      int res=0,num=0;
      auto f=[&](int l,int r){
               assert(l<=r);
               num+=cnt.query0(l,r);
               res+=sum.query0(l,r);
             };
      int r=lca.lca(us[i],vs[i]);
      et.query(r,us[i],f);
      et.query(r,vs[i],f);
      ans[i]+=num*ys[i];
      ans[i]-=res;
    }

    for(int i:C[t]){
      int ch=et.child(as[i],bs[i]);
      et.update(ch,-1,g1);
      et.update(ch,-ds[i],g2);
    }
  }

  for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/25
  https://atcoder.jp/contests/abc133/tasks/abc133_f
*/

signed main(){
  ABC133_F();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

