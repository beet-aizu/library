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


# :warning: linkcuttree/farthest.cpp
* category: linkcuttree


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [linkcuttree/base.cpp](base.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/1595.linkcuttree.test.cpp](../../verify/test/aoj/1595.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_A.linkcuttree.test.cpp](../../verify/test/aoj/GRL_5_A.linkcuttree.test.cpp.html)


## Code
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
  int idx;
  bool rev;
  T val,ld,rd,smd;
  multiset<T> td;
  NodeBase(){}
  NodeBase(int idx,T val):
    idx(idx),rev(0),val(val){
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

  Node* create(int idx,T val){
    return super::create(Node(idx,val));
  }

  inline void toggle(Node *t){
    swap(t->l,t->r);
    swap(t->ld,t->rd);
    t->rev^=1;
  }

  inline void eval(Node *t){
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
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
  vs.emplace_back(lct.create(num,0));
  es.emplace_back(lct.create(num,0));
  num++;

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t,a,c;
    cin>>t>>a>>c;
    if(t==1){
      vs.emplace_back(lct.create(num,0));
      es.emplace_back(lct.create(num,c));
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
  verified on 2019/10/30
  https://atcoder.jp/contests/tkppc/tasks/tkppc2015_j
*/

signed main(){
  TKPPC2015_J();
  return 0;
}
#endif

```
{% endraw %}

[Back to top page](../../index.html)

