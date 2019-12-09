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


# :heavy_check_mark: test/aoj/geometry/CGL_7_D.test.cpp


[Back to top page](../../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D)


## Dependencies
* :heavy_check_mark: [geometry/geometry.cpp](../../../../library/geometry/geometry.cpp.html)


## Code
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

#define ERROR "0.000001"

//getCrossPointCL
signed main(){
  Circle c;
  int q;
  cin>>c>>q;
  while(q--){
    Line l;
    cin>>l;
    auto pp=getCrossPointCL(c,l);
    if(pp.size()==1u) pp.emplace_back(pp[0]);
    if(pp[1]<pp[0]) swap(pp[0],pp[1]);
    cout<<pp[0]<<" "<<pp[1]<<endl;
  }
  return 0;
}

```

[Back to top page](../../../../index.html)

