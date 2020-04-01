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


# :heavy_check_mark: toptree/distancesum.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5c8bf2a6852b9bc7e4261d66e9a6b762">toptree</a>
* <a href="{{ site.github.repository_url }}/blob/master/toptree/distancesum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 15:51:05+09:00




## Depends on

* :question: <a href="toptree.cpp.html">toptree/toptree.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/2587.test.cpp.html">test/yukicoder/2587.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "toptree.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE

template<typename T, size_t LIM>
struct DistanceSum{
  struct Vertex{
    void* handle;
    T color;
    Vertex(T color=0):handle(nullptr),color(color){}
  };

  struct Cluster{
    struct pi{
      T cnt;
      Vertex* ptr;
      pi():cnt(-1),ptr(nullptr){}
      pi(T cnt,Vertex* ptr):cnt(cnt),ptr(ptr){}
      bool operator<(const pi &o)const{return cnt<o.cnt;}
    };

    T len,cnt,chd,ans;
    T sum_l,sum_r;
    pi md;

    Cluster(T len=0):len(len),cnt(0),chd(0),ans(0),sum_l(0),sum_r(0){}

    void toggle(){swap(sum_l,sum_r);}

    static Cluster compress(Cluster x,Vertex *v,Cluster y){
      Cluster nxt;
      nxt.len=x.len+y.len;
      nxt.cnt=x.cnt+x.chd+(v->color)+y.cnt;
      nxt.chd=0;
      assert(y.chd==0);

      nxt.ans=x.sum_l+y.sum_r;

      nxt.sum_l+=x.sum_l;
      nxt.sum_l+=y.sum_l;
      nxt.sum_l+=(x.cnt+x.chd+(v->color))*y.len;

      nxt.sum_r+=x.sum_r;
      nxt.sum_r+=y.sum_r;
      nxt.sum_r+=(x.chd+(v->color)+y.cnt)*x.len;

      nxt.md=pi(nxt.cnt,v);

      return nxt;
    }

    static Cluster rake(Cluster x,Cluster y,Vertex *v){
      assert((v->color)==0);
      Cluster nxt;
      nxt.len=x.len;
      nxt.cnt=x.cnt;
      nxt.chd=x.chd+y.cnt+y.chd;

      nxt.ans=x.sum_l+y.sum_l;

      nxt.sum_l+=x.sum_l;
      nxt.sum_l+=y.sum_l;

      nxt.sum_r+=x.sum_r;
      nxt.sum_r+=y.sum_l;

      nxt.md=max(x.md,y.md);

      return nxt;
    }
  };

  TopTree<Vertex, Cluster, LIM> G;
  using Type = typename decltype(G)::Type;

  Vertex* centroid(Vertex* v){
    auto rt=G.expose(v);
    if(rt->type==Type::Edge) return v;

    auto cc=rt;
    Vertex* ctr=nullptr;

    T lv=0,rv=0,sum=rt->dat.cnt;
    while(cc->type==Type::Compress){
      G.propagate(cc);

      auto ll=cc->ch[0];
      if((ll->dat.cnt+lv)*2>sum){
        assert(ll->type!=Type::Edge);
        rv+=cc->dat.md.cnt-ll->dat.cnt;
        cc=ll;
        continue;
      }

      auto rr=cc->ch[1];
      if((rr->dat.cnt+rv)*2>sum){
        assert(rr->type!=Type::Edge);
        lv+=cc->dat.md.cnt-rr->dat.cnt;
        cc=rr;
        continue;
      }

      auto mm=cc->q;
      if(mm and mm->dat.md.cnt*2>sum){
        assert(mm->type!=Type::Edge);
        rv+=lv;lv=0;
        rv+=cc->dat.md.cnt-mm->dat.md.cnt;
        cc=(decltype(cc))mm->dat.md.ptr->handle;
        continue;
      }

      ctr=cc->dat.md.ptr;
      break;
    }
    return ctr;
  }

  T query(Vertex* v){return G.get_subtree(v).ans;}
};
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
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 170, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 281, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: toptree/distancesum.cpp: line 8: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

