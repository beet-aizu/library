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


# :heavy_check_mark: test/aoj/geometry/CGL_2_D.test.cpp
<a href="../../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/geometry/CGL_2_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-12 16:34:45 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D</a>


## Depends On
* :heavy_check_mark: <a href="../../../../library/geometry/geometry.cpp.html">geometry/geometry.cpp</a>
* :heavy_check_mark: <a href="../../../../library/tools/precision.cpp.html">tools/precision.cpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#include "../../../tools/precision.cpp"
#undef call_from_test

#define ERROR "0.00000001"

//distanceSS
signed main(){
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    Point p0,p1,p2,p3;
    cin>>p0>>p1>>p2>>p3;
    cout<<getDistanceSS(Segment(p0,p1),Segment(p2,p3))<<endl;
  }
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

