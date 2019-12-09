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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/geometry/CGL_1_C.test.cpp


[Back to top page](../../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C)


## Dependencies
* :heavy_check_mark: [geometry/geometry.cpp](../../../../library/geometry/geometry.cpp.html)


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

//CCW
signed main(){
  Point p0,p1;
  cin>>p0>>p1;
  int q;
  cin>>q;
  while(q--){
    Point p2;
    cin>>p2;
    int t=ccw(p0,p1,p2);
    if(t==CCW_COUNTER_CLOCKWISE) cout<<"COUNTER_CLOCKWISE"<<endl;
    if(t==CCW_CLOCKWISE) cout<<"CLOCKWISE"<<endl;
    if(t==CCW_ONLINE_BACK) cout<<"ONLINE_BACK"<<endl;
    if(t==CCW_ONLINE_FRONT) cout<<"ONLINE_FRONT"<<endl;
    if(t==CCW_ON_SEGMENT) cout<<"ON_SEGMENT"<<endl;
  }
  return 0;
}

```
{% endraw %}

[Back to top page](../../../../index.html)

