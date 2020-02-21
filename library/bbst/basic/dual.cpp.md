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


# :heavy_check_mark: bbst/basic/dual.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fdd417a23ea00086418babb4ed5c9a26">bbst/basic</a>
* <a href="{{ site.github.repository_url }}/blob/master/bbst/basic/dual.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-27 08:56:10+09:00




## Depends on

* :heavy_check_mark: <a href="base.cpp.html">bbst/basic/base.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/1579.test.cpp.html">test/aoj/1579.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_D.bbst.test.cpp.html">test/aoj/DSL_2_D.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_E.bbst.test.cpp.html">test/aoj/DSL_2_E.bbst.test.cpp</a>


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
template<typename Ep>
struct NodeBase{
  using E = Ep;
  NodeBase *l,*r,*p;
  size_t cnt;
  bool rev;
  E dat,laz;
  NodeBase():cnt(1),rev(0){l=r=p=nullptr;}
  NodeBase(E dat,E laz):
    cnt(1),rev(0),dat(dat),laz(laz){l=r=p=nullptr;}
};

template<typename Node, size_t LIM>
struct Dual : BBSTBase<Node, LIM>{
  using E = typename Node::E;
  using super = BBSTBase<Node, LIM>;
  using H = function<E(E, E)>;

  H h;
  E ei;

  Dual(H h,E ei):super(),h(h),ei(ei){}

  using super::create;
  using super::merge;
  using super::split;

  Node* build(size_t l,size_t r){
    if(l+1==r) return create(Node(ei,ei));
    size_t m=(l+r)>>1;
    return merge(build(l,m),build(m,r));
  }

  Node* init(int n){
    return build(0,n);
  }

  using super::count;
  Node* recalc(Node *a){
    a->cnt=count(a->l)+1+count(a->r);
    return a;
  }

  void propagate(Node *a,E x){
    a->dat=h(a->dat,x);
    a->laz=h(a->laz,x);
  }

  using super::toggle;
  void toggle(Node *a){
    swap(a->l,a->r);
    a->rev^=1;
  }

  // remove "virtual" for optimization
  virtual Node* eval(Node* a){
    if(a->laz!=ei){
      if(a->l) propagate(a->l,a->laz);
      if(a->r) propagate(a->r,a->laz);
      a->laz=ei;
    }
    if(a->rev){
      if(a->l) toggle(a->l);
      if(a->r) toggle(a->r);
      a->rev=false;
    }
    return recalc(a);
  }

  Node* update(Node *a,size_t l,size_t r,E x){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=eval(t.first);
    propagate(u,x);
    return merge(s.first,merge(u,t.second));
  }

  Node* set_val(Node *a,size_t k,E x){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) a->l=set_val(a->l,k,x);
    if(k>num) a->r=set_val(a->r,k-(num+1),x);
    if(k==num) a->dat=x;
    return recalc(a);
  }

  E get_val(Node *a,size_t k){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) return get_val(a->l,k);
    if(k>num) return get_val(a->r,k-(num+1));
    return a->dat;
  }

  void dump(Node* a,typename vector<E>::iterator it){
    if(!count(a)) return;
    a=eval(a);
    dump(a->l,it);
    *(it+count(a->l))=a->dat;
    dump(a->r,it+count(a->l)+1);
  }

  vector<E> dump(Node* a){
    vector<E> vs(count(a));
    dump(a,vs.begin());
    return vs;
  }
};
//END CUT HERE
//INSERT ABOVE HERE
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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: bbst/basic/base.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

