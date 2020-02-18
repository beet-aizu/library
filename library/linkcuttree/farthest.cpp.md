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


# :heavy_check_mark: linkcuttree/farthest.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e406bcf916b254ab0f908ae657d2d754">linkcuttree</a>
* <a href="{{ site.github.repository_url }}/blob/master/linkcuttree/farthest.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-07 13:27:51+09:00




## Depends on

* :heavy_check_mark: <a href="base.cpp.html">linkcuttree/base.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/1595.linkcuttree.test.cpp.html">test/aoj/1595.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_A.linkcuttree.test.cpp.html">test/aoj/GRL_5_A.linkcuttree.test.cpp</a>


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
template<typename Tp>
struct NodeBase{
  using T = Tp;
  NodeBase *l,*r,*p;
  bool rev;
  T val,ld,rd,smd;
  multiset<T> td;
  NodeBase(){}
  NodeBase(T val):rev(0),val(val){
    l=r=p=nullptr;
    ld=rd=smd=val;
    td.emplace(0);
  }
};
template<typename Np, size_t LIM>
struct Farthest : LinkCutTreeBase<Np, LIM>{
  using super = LinkCutTreeBase<Np, LIM>;
  using Node = Np;
  using T = typename Node::T;

  Farthest():super(){}

  Node* create(T val){
    return super::create(Node(val));
  }

  inline void toggle(Node *t){
    swap(t->l,t->r);
    swap(t->ld,t->rd);
    t->rev^=1;
  }

  inline Node* eval(Node *t){
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
    return t;
  }

  inline void pushup(Node *t){
    if(t==nullptr) return;
    t->smd=t->val;
    if(t->l) t->smd+=t->l->smd;
    if(t->r) t->smd+=t->r->smd;

    T lld=t->l?t->l->ld:0;
    T rrd=t->r?t->r->rd:0;

    T lsmd=t->l?t->l->smd:0;
    T rsmd=t->r?t->r->smd:0;

    t->ld=max(lld,lsmd+t->val+*(t->td).rbegin());
    if(t->r) t->ld=max(t->ld,lsmd+t->val+t->r->ld);

    t->rd=max(rrd,rsmd+t->val+*(t->td).rbegin());
    if(t->l) t->rd=max(t->rd,rsmd+t->val+t->l->rd);
  }

  using super::splay;

  Node* expose(Node *t){
    Node *rp=nullptr;
    for(Node *c=t;c;c=c->p){
      splay(c);
      if(c->r) c->td.emplace(c->r->ld);
      c->r=rp;
      if(c->r) c->td.erase(c->td.find(c->r->ld));
      pushup(c);
      rp=c;
    }
    splay(t);
    return rp;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed TKPPC2015_J(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;
  using Node = NodeBase<ll>;
  constexpr size_t LIM = 1e6+200;
  using LCT = Farthest<Node, LIM>;
  LCT lct;

  vector<LCT::Node*> vs;
  vector<LCT::Node*> es;
  vs.reserve(5e5+100);
  es.reserve(5e5+100);

  int num=0;
  vs.emplace_back(lct.create(0));
  es.emplace_back(lct.create(0));
  num++;

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t,a,c;
    cin>>t>>a>>c;
    if(t==1){
      vs.emplace_back(lct.create(0));
      es.emplace_back(lct.create(c));
      lct.link(vs[a],es[num]);
      lct.link(es[num],vs[num]);
      num++;
    }
    if(t==2){
      lct.expose(es[a]);
      es[a]->val=c;
      lct.pushup(es[a]);
    }
    if(t==3){
      lct.evert(vs[a]);
      cout<<(vs[a]->ld)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2020/01/06
  https://atcoder.jp/contests/tkppc/tasks/tkppc2015_j
*/

signed main(){
  TKPPC2015_J();
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

