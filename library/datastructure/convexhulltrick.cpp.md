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


# :heavy_check_mark: datastructure/convexhulltrick.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/convexhulltrick.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-27 08:27:21+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2725.test.cpp.html">test/aoj/2725.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2975.test.cpp.html">test/aoj/2975.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template <typename T, bool isMin>
struct ConvexHullTrick {
  #define F first
  #define S second
  using P = pair<T, T>;
  deque<P> H;
  bool empty()const{return H.empty();}
  void clear(){H.clear();}

  inline int sgn(T x){return x==0?0:(x<0?-1:1);}

  using D = long double;
  inline bool check(const P &a,const P &b,const P &c){
    if(b.S==a.S||c.S==b.S)
      return sgn(b.F-a.F)*sgn(c.S-b.S) >= sgn(c.F-b.F)*sgn(b.S-a.S);

    //return (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);
    return
      D(b.F-a.F)*sgn(c.S-b.S)/D(abs(b.S-a.S)) >=
      D(c.F-b.F)*sgn(b.S-a.S)/D(abs(c.S-b.S));
  }

  void addLine(T m,T b){
    if(!isMin) m*=-1,b*=-1;
    P line(m,b);
    if(empty()){
      H.emplace_front(line);
      return;
    }
    if(H.front().F<=m){
      if(H.front().F==m){
        if(H.front().S<=b) return;
        H.pop_front();
      }
      while(H.size()>=2&&
            check(line,H.front(),H[1])) H.pop_front();
      H.emplace_front(line);
    }else{
      assert(m<=H.back().F);
      if(H.back().F==m){
        if(H.back().S<=b) return;
        H.pop_back();
      }
      while(H.size()>=2&&
            check(H[H.size()-2],H.back(),line)) H.pop_back();
      H.emplace_back(line);
    }
  }

  inline T getY(const P &a,const T &x){
    return a.F*x+a.S;
  }

  T query(T x){
    assert(!empty());
    int l=-1,r=H.size()-1;
    while(l+1<r){
      int m=(l+r)>>1;
      if(getY(H[m],x)>=getY(H[m+1],x)) l=m;
      else r=m;
    }
    if(isMin) return getY(H[r],x);
    return -getY(H[r],x);
  }

  T queryMonotoneInc(T x){
    assert(!empty());
    while(H.size()>=2&&
          getY(H.front(),x)>=getY(H[1],x)) H.pop_front();
    if(isMin) return getY(H.front(),x);
    return -getY(H.front(),x);
  }

  T queryMonotoneDec(T x){
    assert(!empty());
    while(H.size()>=2&&
          getY(H.back(),x)>=getY(H[H.size()-2],x)) H.pop_back();
    if(isMin) return getY(H.back(),x);
    return -getY(H.back(),x);
  }
  #undef F
  #undef S
};
//END CUT HERE
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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: datastructure/convexhulltrick.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

