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


# :heavy_check_mark: math/linearfunction.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/linearfunction.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 20:43:58+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/dynamic_tree_vertex_set_path_composite.toptree.test.cpp.html">test/yosupo/dynamic_tree_vertex_set_path_composite.toptree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// a * x + b
template<typename T>
struct LinearFunction{
  T a,b;
  LinearFunction():a(0),b(0){}
  LinearFunction(T a,T b):a(a),b(b){}

  using LF = LinearFunction;
  static LF add_identity(){return LF(T(0),T(0));}
  static LF mul_identity(){return LF(T(1),T(0));}
  LF& operator+=(const LF &o){
    a+=o.a;b+=o.b;
    return *this;
  }
  LF& operator*=(const LF &o){
    a=a*o.a;
    b=b*o.a+o.b;
    return *this;
  }
  LF operator+(const LF &o)const{return LF(*this)+=o;}
  LF operator*(const LF &o)const{return LF(*this)*=o;}

  T operator()(T x) const{return a*x+b;}
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
#line 2 "math/linearfunction.cpp"

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// a * x + b
template<typename T>
struct LinearFunction{
  T a,b;
  LinearFunction():a(0),b(0){}
  LinearFunction(T a,T b):a(a),b(b){}

  using LF = LinearFunction;
  static LF add_identity(){return LF(T(0),T(0));}
  static LF mul_identity(){return LF(T(1),T(0));}
  LF& operator+=(const LF &o){
    a+=o.a;b+=o.b;
    return *this;
  }
  LF& operator*=(const LF &o){
    a=a*o.a;
    b=b*o.a+o.b;
    return *this;
  }
  LF operator+(const LF &o)const{return LF(*this)+=o;}
  LF operator*(const LF &o)const{return LF(*this)*=o;}

  T operator()(T x) const{return a*x+b;}
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

<a href="../../index.html">Back to top page</a>

