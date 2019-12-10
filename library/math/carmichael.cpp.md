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


# :heavy_check_mark: math/carmichael.cpp
<a href="../../index.html">Back to top page</a>

* category: math
* <a href="{{ site.github.repository_url }}/blob/master/math/carmichael.cpp">View this file on GitHub</a> (Last commit date: 2019-10-15 21:27:34 +0900)




## Verified
* :heavy_check_mark: <a href="../../verify/test/aoj/2720.test.cpp.html">test/aoj/2720.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
// min m s.t. a^m = 1 mod n (a, n are coprime)
template<typename T>
T carmichael_lambda(T n){
  auto lcm=[](auto a,auto b){return a/__gcd(a,b)*b;};
  T res=1;
  if(n%8==0) n/=2;
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      T tmp=i-1;
      for(n/=i;n%i==0;n/=i) tmp*=i;
      res=lcm(res,tmp);
    }
  }
  if(n!=1) res=lcm(res,n-1);
  return res;
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

