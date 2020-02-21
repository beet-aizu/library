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


# :heavy_check_mark: linkcuttree/path.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e406bcf916b254ab0f908ae657d2d754">linkcuttree</a>
* <a href="{{ site.github.repository_url }}/blob/master/linkcuttree/path.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-08 13:40:23+09:00




## Depends on

* :heavy_check_mark: <a href="base.cpp.html">linkcuttree/base.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0367.linkcuttree.test.cpp.html">test/aoj/0367.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2450.linkcuttree.test.cpp.html">test/aoj/2450.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_D.linkcuttree.test.cpp.html">test/aoj/GRL_5_D.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_E.linkcuttree.test.cpp.html">test/aoj/GRL_5_E.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp.html">test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/lca.linkcuttree.test.cpp.html">test/yosupo/lca.linkcuttree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Tp,typename Ep>
struct NodeBase{
  using T = Tp;
  using E = Ep;
  NodeBase *l,*r,*p;
  bool rev;
  T val,dat;
  E laz;
  NodeBase(){}
  NodeBase(T val,E laz):
    rev(0),val(val),dat(val),laz(laz){
    l=r=p=nullptr;}
};

template<typename Np, size_t LIM>
struct Path : LinkCutTreeBase<Np, LIM>{
  using super = LinkCutTreeBase<Np, LIM>;
  using Node = Np;
  using T = typename Node::T;
  using E = typename Node::E;

  using F = function<T(T, T)>;
  using G = function<T(T, E)>;
  using H = function<E(E, E)>;
  using S = function<T(T)>;
  F f;
  G g;
  H h;
  S flip;
  E ei;

  Path(F f,G g,H h,E ei):
    super(),f(f),g(g),h(h),ei(ei){
    flip=[](T a){return a;};
  }

  Path(F f,G g,H h,S flip,E ei):
    super(),f(f),g(g),h(h),flip(flip),ei(ei){}

  Node* create(T val){
    return super::create(Node(val,ei));
  }

  inline void propagate(Node *t,E v){
    t->laz=h(t->laz,v);
    t->val=g(t->val,v);
    t->dat=g(t->dat,v);
  }

  inline void toggle(Node *t){
    swap(t->l,t->r);
    t->dat=flip(t->dat);
    t->rev^=1;
  }

  inline Node* eval(Node *t){
    if(t->laz!=ei){
      if(t->l) propagate(t->l,t->laz);
      if(t->r) propagate(t->r,t->laz);
      t->laz=ei;
    }
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
    return t;
  }

  inline void pushup(Node *t){
    t->dat=t->val;
    if(t->l) t->dat=f(t->l->dat,t->dat);
    if(t->r) t->dat=f(t->dat,t->r->dat);
  }

  using super::expose;

  T query(Node *t){
    expose(t);
    return t->dat;
  }

  void update(Node *t,E v){
    expose(t);
    propagate(t,v);
    eval(t);
  }
};
//END CUT HERE
#ifndef call_from_test

// test dynamic tree
signed SPOJ_DYNACON1(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  using Node = NodeBase<int, int>;
  constexpr size_t LIM = 1e6;
  using LCT = Path<Node, LIM>;

  auto f=[](int a,int b){return a+b;};
  LCT lct(f,f,f,0);
  for(int i=0;i<n;i++) lct.create(0);

  for(int i=0;i<m;i++){
    string s;
    int a,b;
    cin>>s>>a>>b;
    a--;b--;
    if(s=="add"s){
      lct.evert(lct[b]);
      lct.link(lct[a],lct[b]);
    }
    if(s=="rem"s){
      auto v=lct.lca(lct[a],lct[b])==lct[a]?lct[b]:lct[a];
      lct.cut(v);
    }
    if(s=="conn"s)
      cout<<(lct.is_connected(lct[a],lct[b])?"YES\n":"NO\n");
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2020/01/08
  https://www.spoj.com/problems/DYNACON1/
*/

signed main(){
  //SPOJ_DYNACON1();
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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: linkcuttree/base.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

