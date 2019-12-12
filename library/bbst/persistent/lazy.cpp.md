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


# :warning: bbst/persistent/lazy.cpp
<a href="../../../index.html">Back to top page</a>

* category: bbst/persistent
* <a href="{{ site.github.repository_url }}/blob/master/bbst/persistent/lazy.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-24 23:32:19 +0900




## Depends On
* :heavy_check_mark: <a href="../basic/base.cpp.html">bbst/basic/base.cpp</a>
* :heavy_check_mark: <a href="../basic/lazy.cpp.html">bbst/basic/lazy.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../basic/base.cpp"
#include "../basic/lazy.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Node, size_t LIM>
struct PersistentLazy : Lazy<Node, LIM>{
  using super = Lazy<Node, LIM>;
  using super::super;
  using T = typename Node::T;

  inline Node* clone(Node* a){
    if(a==nullptr) return a;
    return super::create(*a);
  }

  Node* eval(Node* a){
    a=clone(a);
    a->l=clone(a->l);
    a->r=clone(a->r);
    return super::eval(a);
  }

  T query(Node *a,size_t l,size_t r){
    auto s=super::split(a,l);
    auto t=super::split(s.second,r-l);
    return super::query(t.first);
  }

  Node* rebuild(Node* a){
    auto vs=super::dump(a);
    super::ptr=0;
    return super::build(vs);
  }

  bool almost_full() const{
    return super::ptr>LIM*9/10;
  }
};
//END CUT HERE
//INSERT ABOVE HERE
signed ARC030_D(){
  int n,q;
  scanf("%d %d",&n,&q);

  using ll = long long;
  using P = pair<ll, ll>;
  vector<P> v(n,P(0,1));
  for(int i=0;i<n;i++) scanf("%lld",&v[i].first);

  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,ll b){return P(a.first+b*a.second,a.second);};
  auto h=[](ll a,ll b){return a+b;};

  using Node = NodeBase<P, ll>;
  constexpr size_t LIM = 6e6;
  PersistentLazy<Node, LIM> G(f,g,h,P(0,0),0);
  auto rt=G.build(v);

  for(int i=0;i<q;i++){
    int t;
    scanf("%d",&t);
    if(t==1){
      int a,b,v;
      scanf("%d %d %d",&a,&b,&v);
      a--;
      rt=G.update(rt,a,b,v);
    }
    if(t==2){
      int a,b,c,d;
      scanf("%d %d %d %d",&a,&b,&c,&d);
      a--;c--;
      auto s=G.split(rt,a);
      auto t=G.split(s.second,b-a);
      auto u=G.split(rt,c);
      auto v=G.split(u.second,d-c);

      rt=G.merge(G.merge(s.first,v.first),t.second);
    }
    if(t==3){
      int a,b;
      scanf("%d %d",&a,&b);
      a--;
      printf("%lld\n",G.query(rt,a,b).first);
    }

    if(G.almost_full()) rt=G.rebuild(rt);
  }
  return 0;
}
/*
  verified on 2019/10/22
  https://atcoder.jp/contests/arc030/tasks/arc030_4
*/

signed main(){
  ARC030_D();
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

