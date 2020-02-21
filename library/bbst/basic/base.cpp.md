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


# :heavy_check_mark: bbst/basic/base.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fdd417a23ea00086418babb4ed5c9a26">bbst/basic</a>
* <a href="{{ site.github.repository_url }}/blob/master/bbst/basic/base.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-24 23:20:46+09:00




## Required by

* :heavy_check_mark: <a href="array.cpp.html">bbst/basic/array.cpp</a>
* :heavy_check_mark: <a href="dual.cpp.html">bbst/basic/dual.cpp</a>
* :heavy_check_mark: <a href="lazy.cpp.html">bbst/basic/lazy.cpp</a>
* :heavy_check_mark: <a href="ushi.cpp.html">bbst/basic/ushi.cpp</a>
* :warning: <a href="../persistent/array.cpp.html">bbst/persistent/array.cpp</a>
* :warning: <a href="../persistent/lazy.cpp.html">bbst/persistent/lazy.cpp</a>
* :warning: <a href="../persistent/ushi.cpp.html">bbst/persistent/ushi.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/1508.test.cpp.html">test/aoj/1508.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/1579.test.cpp.html">test/aoj/1579.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2890.test.cpp.html">test/aoj/2890.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_A.bbst.test.cpp.html">test/aoj/DSL_2_A.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_D.bbst.test.cpp.html">test/aoj/DSL_2_D.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_E.bbst.test.cpp.html">test/aoj/DSL_2_E.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_F.bbst.test.cpp.html">test/aoj/DSL_2_F.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_G.bbst.test.cpp.html">test/aoj/DSL_2_G.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_H.bbst.test.cpp.html">test/aoj/DSL_2_H.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_I.bbst.test.cpp.html">test/aoj/DSL_2_I.bbst.test.cpp</a>


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
struct BBSTBase{
  using u32 = uint32_t;
  u32 xor128(){
    static u32 x = 123456789;
    static u32 y = 362436069;
    static u32 z = 521288629;
    static u32 w = 88675123;

    u32 t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }

  static array<Node, LIM> pool;
  size_t ptr;
  BBSTBase():ptr(0){}

  size_t count(const Node *a){
    return a?a->cnt:0;
  }

  inline Node* create(){
    return &pool[ptr++];
  }

  inline Node* create(Node v){
    return &(pool[ptr++]=v);
  }

  virtual void toggle(Node *a)=0;
  virtual Node* eval(Node* a)=0;
  virtual Node* recalc(Node* a)=0;

  Node* toggle(Node *a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=eval(t.first);
    toggle(u);
    return merge(s.first,merge(u,t.second));
  }

  Node* merge(Node* a,Node* b){
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    if(xor128()%(count(a)+count(b))<count(a)){
      a=eval(a);
      a->r=merge(a->r,b);
      a->r->p=a;
      return recalc(a);
    }
    b=eval(b);
    b->l=merge(a,b->l);
    b->l->p=b;
    return recalc(b);
  }

  pair<Node*, Node*> split(Node* a,size_t k){
    if(a==nullptr) return make_pair(a,a);
    a=eval(a);
    if(k<=count(a->l)){
      if(a->l) a->l->p=nullptr;
      auto s=split(a->l,k);
      a->l=s.second;
      if(a->l) a->l->p=a;
      return make_pair(s.first,recalc(a));
    }
    if(a->r) a->r->p=nullptr;
    auto s=split(a->r,k-(count(a->l)+1));
    a->r=s.first;
    if(a->r) a->r->p=a;
    return make_pair(recalc(a),s.second);
  }

  Node* insert(Node *a,size_t pos,Node v){
    Node* b=create(v);
    auto s=split(a,pos);
    return a=merge(merge(s.first,b),s.second);
  }

  Node* erase(Node *a,size_t pos){
    auto s=split(a,pos);
    auto t=split(s.second,1);
    return merge(s.first,t.second);
  }

  Node* find_by_order(Node *a,size_t k){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) return find_by_order(a->l,k);
    if(k>num) return find_by_order(a->r,k-(num+1));
    return a;
  }

  inline bool is_right(Node* a){
    return a->p&&a->p->r==a;
  }

  size_t order_of_key(Node* a){
    size_t res=count(a->l);
    while(a){
      if(is_right(a)) res+=count(a->p->l)+1;
      a=a->p;
    }
    return res;
  }

  Node* build(size_t l,size_t r,const vector<Node> &vs){
    if(l+1==r) return create(vs[l]);
    size_t m=(l+r)>>1;
    return merge(build(l,m,vs),build(m,r,vs));
  }

  Node* build(const vector<Node> &vs){
    return build(0,vs.size(),vs);
  }
};
template<typename Node, size_t LIM>
array<Node, LIM> BBSTBase<Node, LIM>::pool;
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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: bbst/basic/base.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

