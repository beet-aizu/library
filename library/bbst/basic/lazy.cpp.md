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


# :heavy_check_mark: bbst/basic/lazy.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fdd417a23ea00086418babb4ed5c9a26">bbst/basic</a>
* <a href="{{ site.github.repository_url }}/blob/master/bbst/basic/lazy.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-27 08:56:10+09:00




## Depends on

* :heavy_check_mark: <a href="base.cpp.html">bbst/basic/base.cpp</a>


## Required by

* :warning: <a href="../persistent/lazy.cpp.html">bbst/persistent/lazy.cpp</a>


## Verified with

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

#define call_from_test
#include "base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Tp, typename Ep>
struct NodeBase{
  using T = Tp;
  using E = Ep;
  NodeBase *l,*r,*p;
  size_t cnt;
  bool rev;
  T val,dat;
  E laz;
  NodeBase():cnt(1),rev(0){l=r=p=nullptr;}
  NodeBase(T val,E laz):
    cnt(1),rev(0),val(val),dat(val),laz(laz){l=r=p=nullptr;}
};

template<typename Node, size_t LIM>
struct Lazy : BBSTBase<Node, LIM>{
  using super = BBSTBase<Node, LIM>;

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
  T ti;
  E ei;

  Lazy(F f,G g,H h,T ti,E ei):
    super(),f(f),g(g),h(h),ti(ti),ei(ei){
    flip=[](T a){return a;};
  }

  Lazy(F f,G g,H h,S flip,T ti,E ei):
    super(),f(f),g(g),h(h),flip(flip),ti(ti),ei(ei){}

  using super::create;
  using super::merge;
  using super::split;

  T query(const Node *a){
    return a?a->dat:ti;
  }

  using super::count;
  Node* recalc(Node *a){
    a->cnt=count(a->l)+1+count(a->r);
    a->dat=a->val;
    if(a->l) a->dat=f(a->l->dat,a->dat);
    if(a->r) a->dat=f(a->dat,a->r->dat);
    return a;
  }

  void propagate(Node *a,E v){
    a->laz=h(a->laz,v);
    a->val=g(a->val,v);
    a->dat=g(a->dat,v);
  }

  using super::toggle;
  void toggle(Node *a){
    swap(a->l,a->r);
    a->dat=flip(a->dat);
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

  T query(Node *&a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=t.first;
    T res=query(u);
    a=merge(s.first,merge(u,t.second));
    return res;
  }

  Node* update(Node *a,size_t l,size_t r,E x){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=eval(t.first);
    propagate(u,x);
    return merge(s.first,merge(u,t.second));
  }

  Node* set_val(Node *a,size_t k,T val){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) a->l=set_val(a->l,k,val);
    if(k>num) a->r=set_val(a->r,k-(num+1),val);
    if(k==num) a->val=val;
    return recalc(a);
  }

  T get_val(Node *a,size_t k){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) return get_val(a->l,k);
    if(k>num) return get_val(a->r,k-(num+1));
    return a->val;
  }

  void dump(Node* a,typename vector<T>::iterator it){
    if(!count(a)) return;
    a=eval(a);
    dump(a->l,it);
    *(it+count(a->l))=a->val;
    dump(a->r,it+count(a->l)+1);
  }

  vector<T> dump(Node* a){
    vector<T> vs(count(a));
    dump(a,vs.begin());
    return vs;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
char buf[114514];
signed CODEFESTIVAL2014EXHIBITION_B(){
  int Q;
  scanf("%d",&Q);
  scanf("%s\n",buf);
  string S(buf);
  using T = tuple<int, int, int>;
  using P = pair<int, int>;
  auto f=[](T a,T b){
           return T(min(get<0>(a),get<0>(b)),min(get<1>(a),get<1>(b)),0);
         };
  auto g=[](T a,P b){
           return T(get<0>(a)+b.first,get<1>(a)+b.second,get<2>(a));
         };
  auto h=[](P a,P b){
           return P(a.first+b.first,a.second+b.second);
         };
  const int INF = 1e9;

  using Node = NodeBase<T, P>;
  constexpr size_t LIM = 1e6;
  Lazy<Node, LIM> G(f,g,h,T(INF,INF,0),P(0,0));

  vector<Node> vs(S.size()+2);
  for(int i=0;i<(int)S.size();i++)
    vs[i+1].val=T(0,0,S[i]=='('?1:-1);

  auto rt=G.build(vs);
  for(int i=1;i<=(int)S.size();i++){
    int z=get<2>(G.get_val(rt,i));
    rt=G.update(rt,i,G.count(rt),P(z,0));
    rt=G.update(rt,0,i+1,P(0,-z));
  }

  for(int i=0;i<Q;i++){
    char x;
    int y,z;
    scanf("%c %d %d\n",&x,&y,&z);
    z++;
    if(x=='('||x==')'){
      z=(x=='('?1:-1);
      T prv=G.get_val(rt,y-1);
      T nxt=G.get_val(rt,y);
      T cur(get<0>(prv),get<1>(nxt),z);
      rt=G.insert(rt,y,Node(cur,P(0,0)));
      rt=G.update(rt,y,G.count(rt),P(z,0));
      rt=G.update(rt,0,y+1,P(0,-z));
    }

    if(x=='D'){
      z=get<2>(G.get_val(rt,y));
      rt=G.erase(rt,y);
      rt=G.update(rt,y,G.count(rt),P(-z,0));
      rt=G.update(rt,0,y,P(0,z));
    }

    if(x=='Q'){
      T prv=G.get_val(rt,y-1);
      T cur=G.query(rt,y,z);
      T nxt=G.get_val(rt,z);
      int ans=0;
      if(get<0>(prv)>get<0>(cur)) ans+=get<0>(prv)-get<0>(cur);
      if(get<1>(nxt)>get<1>(cur)) ans+=get<1>(nxt)-get<1>(cur);
      printf("%d\n",ans);
    }
  }

  return 0;
}
/*
  verified on 2019/12/27
  https://atcoder.jp/contests/code-festival-2014-exhibition-open/tasks/code_festival_exhibition_b
*/

signed main(){
  CODEFESTIVAL2014EXHIBITION_B();
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

