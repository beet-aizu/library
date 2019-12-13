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


# :heavy_check_mark: math/extgcd.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/extgcd.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-22 00:53:43 +0900




## Required By
* :heavy_check_mark: <a href="linearcongruence.cpp.html">math/linearcongruence.cpp</a>
* :heavy_check_mark: <a href="../mod/log.cpp.html">mod/log.cpp</a>


## Verified With
* :heavy_check_mark: <a href="../../verify/test/aoj/2659.test.cpp.html">test/aoj/2659.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2970.test.cpp.html">test/aoj/2970.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/NTL_1_E.test.cpp.html">test/aoj/NTL_1_E.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
template<typename T>
T extgcd(T a,T b,T& x,T& y){
  T d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}

template<typename T>
T mod_inverse(T a,T mod){
  T x,y;
  extgcd(a,mod,x,y);
  return (x%mod+mod)%mod;
}
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

