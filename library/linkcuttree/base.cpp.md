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


# :heavy_check_mark: linkcuttree/base.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e406bcf916b254ab0f908ae657d2d754">linkcuttree</a>
* <a href="{{ site.github.repository_url }}/blob/master/linkcuttree/base.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-11 22:28:12+09:00




## Required by

* :heavy_check_mark: <a href="farthest.cpp.html">linkcuttree/farthest.cpp</a>
* :heavy_check_mark: <a href="path.cpp.html">linkcuttree/path.cpp</a>
* :heavy_check_mark: <a href="subtree.cpp.html">linkcuttree/subtree.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0367.linkcuttree.test.cpp.html">test/aoj/0367.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1595.linkcuttree.test.cpp.html">test/aoj/1595.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2450.linkcuttree.test.cpp.html">test/aoj/2450.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_A.linkcuttree.test.cpp.html">test/aoj/GRL_5_A.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_D.linkcuttree.test.cpp.html">test/aoj/GRL_5_D.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_E.linkcuttree.test.cpp.html">test/aoj/GRL_5_E.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp.html">test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Node, size_t LIM>
struct LinkCutTreeBase{
  static array<Node, LIM> pool;
  size_t ptr;

  LinkCutTreeBase():ptr(0){}

  inline Node* create(){
    return &pool[ptr++];
  }

  inline Node* create(Node v){
    return &(pool[ptr++]=v);
  }

  virtual void toggle(Node *t) = 0;
  virtual void eval(Node *t) = 0;
  virtual void pushup(Node *t) = 0;

  void rotR(Node *t){
    Node *x=t->p,*y=x->p;
    if((x->l=t->r)) t->r->p=x;
    t->r=x;x->p=t;
    pushup(x);pushup(t);
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
      pushup(y);
    }
  }

  void rotL(Node *t){
    Node *x=t->p,*y=x->p;
    if((x->r=t->l)) t->l->p=x;
    t->l=x;x->p=t;
    pushup(x);pushup(t);
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
      pushup(y);
    }
  }

  bool is_root(Node *t){
    return !t->p||(t->p->l!=t&&t->p->r!=t);
  }

  void splay(Node *t){
    eval(t);
    while(!is_root(t)){
      Node *q=t->p;
      if(is_root(q)){
        eval(q);eval(t);
        if(q->l==t) rotR(t);
        else rotL(t);
      }else{
        auto *r=q->p;
        eval(r);eval(q);eval(t);
        if(r->l==q){
          if(q->l==t) rotR(q),rotR(t);
          else rotL(t),rotR(t);
        }else{
          if(q->r==t) rotL(q),rotL(t);
          else rotR(t),rotL(t);
        }
      }
    }
  }

  virtual Node* expose(Node *t){
    Node *rp=nullptr;
    for(Node *c=t;c;c=c->p){
      splay(c);
      c->r=rp;
      pushup(c);
      rp=c;
    }
    splay(t);
    return rp;
  }

  void link(Node *par,Node *c){
    expose(c);
    expose(par);
    c->p=par;
    par->r=c;
    pushup(par);
  }

  void cut(Node *c){
    expose(c);
    Node *par=c->l;
    c->l=nullptr;
    pushup(c);
    par->p=nullptr;
  }

  void evert(Node *t){
    expose(t);
    toggle(t);
    eval(t);
  }

  Node *parent(Node *t){
    expose(t);
    t=t->l;
    while(t&&t->r) t=t->r;
    if(t) splay(t);
    return t;
  }

  Node *root(Node *t){
    expose(t);
    while(t->l) t=t->l;
    splay(t);
    return t;
  }

  bool is_connected(Node *a,Node *b){
    return root(a)==root(b);
  }

  Node *lca(Node *a,Node *b){
    expose(a);
    return expose(b);
  }
};
template<typename Node, size_t LIM>
array<Node, LIM> LinkCutTreeBase<Node, LIM>::pool;
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
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 328, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: linkcuttree/base.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

