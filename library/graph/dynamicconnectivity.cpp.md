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


# :heavy_check_mark: graph/dynamicconnectivity.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dynamicconnectivity.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 22:09:22+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2235.test.cpp.html">test/aoj/2235.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct PersistentUnionFind{
  using T = pair<int, int>;
  vector<int> rs,ps;
  stack<T> st;
  PersistentUnionFind(){}
  PersistentUnionFind(int n):
    rs(n,1),ps(n,0){iota(ps.begin(),ps.end(),0);}
  int find(int x){
    return x==ps[x]?ps[x]:find(ps[x]);
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    st.emplace(-1,-1);
    if(x==y) return;
    if(rs[x]<rs[y]) swap(x,y);
    rs[x]+=rs[y];
    ps[y]=x;
    st.top()=T(x,y);
  }
  void undo(int t=1){
    for(int i=0;i<t;i++){
      int x,y;
      tie(x,y)=st.top();st.pop();
      if(x<0) continue;
      rs[x]-=rs[y];
      ps[y]=y;
    }
  }
};

struct DynamicConnectivity{
  using edge = pair<int, int>;
  using range = pair<int, int>;

  int q;
  PersistentUnionFind puf;
  vector< vector<edge> > edges;
  vector <pair<range, edge> > prc;
  map<edge, int> cnt,app;

  DynamicConnectivity(){}
  DynamicConnectivity(int n,int q_):q(1),puf(n){
    while(q<q_) q<<=1;
    edges.resize(q*2);
  }

  void insert(int t,int u,int v){
    edge e=minmax(u,v);
    if(cnt[e]++==0) app[e]=t;
  }

  void erase(int t,int u,int v){
    edge e=minmax(u,v);
    if(--cnt[e]==0) prc.emplace_back(range(app[e],t),e);
  }

  void add(int a,int b,edge e,int k,int l,int r){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b){
      edges[k].emplace_back(e);
      return;
    }
    int m=(l+r)>>1;
    add(a,b,e,(k<<1)|0,l,m);
    add(a,b,e,(k<<1)|1,m,r);
  }

  void add(range r,edge e){
    add(r.first,r.second,e,1,0,q);
  }

  void build(){
    for(auto &e:cnt){
      if(!e.second) continue;
      prc.emplace_back(range(app[e.first],q),e.first);
    }
    for(auto &s:prc)
      add(s.first,s.second);
  }

  template<typename F>
  void exec(const F &f,int k=1){
    for(auto &e:edges[k])
      puf.unite(e.first,e.second);

    if(k<q){
      exec(f,(k<<1)|0);
      exec(f,(k<<1)|1);
    }else{
      f(k-q);
    }

    puf.undo(edges[k].size());
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

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: graph/dynamicconnectivity.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

