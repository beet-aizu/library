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


# :heavy_check_mark: bbst/basic/ushi.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fdd417a23ea00086418babb4ed5c9a26">bbst/basic</a>
* <a href="{{ site.github.repository_url }}/blob/master/bbst/basic/ushi.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-27 08:56:10+09:00




## Depends on

* :heavy_check_mark: <a href="base.cpp.html">bbst/basic/base.cpp</a>


## Required by

* :warning: <a href="../persistent/ushi.cpp.html">bbst/persistent/ushi.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/1508.test.cpp.html">test/aoj/1508.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_A.bbst.test.cpp.html">test/aoj/DSL_2_A.bbst.test.cpp</a>


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
  size_t cnt;
  bool rev;
  T val,dat;
  NodeBase():cnt(1),rev(0){l=r=p=nullptr;}
  NodeBase(T val):
    cnt(1),rev(0),val(val),dat(val){l=r=p=nullptr;}
};

template<typename Node, size_t LIM>
struct Ushi : BBSTBase<Node, LIM>{
  using super = BBSTBase<Node, LIM>;

  using T = typename Node::T;

  using F = function<T(T, T)>;
  using S = function<T(T)>;

  F f;
  S flip;
  T ti;

  Ushi(F f,T ti):super(),f(f),ti(ti){
    flip=[](T a){return a;};
  }

  Ushi(F f,S flip,T ti):
    super(),f(f),flip(flip),ti(ti){}

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

  using super::toggle;
  void toggle(Node *a){
    swap(a->l,a->r);
    a->dat=flip(a->dat);
    a->rev^=1;
  }

  // remove "virtual" for optimization
  virtual Node* eval(Node* a){
    if(a->rev){
      if(a->l) toggle(a->l);
      if(a->r) toggle(a->r);
      a->rev=false;
    }
    return recalc(a);
  }

  using super::merge;
  using super::split;

  T query(Node *&a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=t.first;
    T res=query(u);
    a=merge(s.first,merge(u,t.second));
    return res;
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
    return super::find_by_order(a,k)->val;
  }

  void dump(Node* a,typename vector<T>::iterator it){
    if(!count(a)) return;
    if(a->rev){
      if(a->l) toggle(a->l);
      if(a->r) toggle(a->r);
      a->rev=false;
    }
    dump(a->l,it);
    *(it+count(a->l))=a->val;
    dump(a->r,it+count(a->l)+1);
  }

  // destroy data
  vector<T> dump(Node* a){
    vector<T> vs(count(a));
    dump(a,vs.begin());
    return vs;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE

// test toggle
signed HAPPYQUERY_C(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<int> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];

  int q;
  cin>>q;
  vector<int> ts(q);
  vector<int> ls(q),rs(q);
  vector<int> ps(q),xs(q);
  vector<int> as(q),bs(q),cs(q),ds(q);
  for(int i=0;i<q;i++){
    cin>>ts[i];
    if(ts[i]==1) cin>>ls[i]>>rs[i],ls[i]--;
    if(ts[i]==2) cin>>ps[i]>>xs[i],ps[i]--;
    if(ts[i]==3){
      cin>>as[i]>>bs[i]>>cs[i]>>ds[i];
      as[i]--;cs[i]--;
    }
  }

  using ll = long long;
  auto f=[](ll a,ll b){return a+b;};
  ll ti=0;

  using Node=NodeBase<ll>;
  constexpr size_t LIM = 1e6;
  Ushi<Node, LIM> G(f,ti);

  unordered_map<int, ll> memo;
  auto hs=
    [&](int x){
      if(!memo.count(x))
        memo[x]=G.xor128();
      return memo[x];
    };

  vector<Node> ws(n);
  for(int i=0;i<n;i++) ws[i]=Node(hs(vs[i]));
  auto rt=G.build(ws);

  for(int i=0;i<q;i++){
    if(ts[i]==1) rt=G.toggle(rt,ls[i],rs[i]);
    if(ts[i]==2) rt=G.set_val(rt,ps[i],hs(xs[i]));
    if(ts[i]==3){
      ll x=G.query(rt,as[i],bs[i]);
      ll y=G.query(rt,cs[i],ds[i]);
      cout<<(x==y?"Yes":"No")<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/24
  https://www.hackerrank.com/contests/happy-query-contest/challenges/range-sorting-query
*/

signed main(){
  HAPPYQUERY_C();
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

