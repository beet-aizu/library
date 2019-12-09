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


# :warning: tools/chminmax.cpp
* category: tools


[Back to top page](../../index.html)



## Required
* :heavy_check_mark: [datastructure/cartesiantree.cpp](../datastructure/cartesiantree.cpp.html)
* :heavy_check_mark: [datastructure/convexhulltrick.cpp](../datastructure/convexhulltrick.cpp.html)
* :heavy_check_mark: [datastructure/slidingwindowaggregation.cpp](../datastructure/slidingwindowaggregation.cpp.html)
* :heavy_check_mark: [datastructure/waveletmatrix.cpp](../datastructure/waveletmatrix.cpp.html)
* :heavy_check_mark: [flow/negativeedge.cpp](../flow/negativeedge.cpp.html)
* :heavy_check_mark: [mod/log.cpp](../mod/log.cpp.html)
* :heavy_check_mark: [string/ahocorasick.cpp](../string/ahocorasick.cpp.html)
* :heavy_check_mark: [string/longestcommonprefix.cpp](../string/longestcommonprefix.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/0391.test.cpp](../../verify/test/aoj/0391.test.cpp.html)
* :heavy_check_mark: [test/aoj/0415.test.cpp](../../verify/test/aoj/0415.test.cpp.html)
* :heavy_check_mark: [test/aoj/0613.test.cpp](../../verify/test/aoj/0613.test.cpp.html)
* :heavy_check_mark: [test/aoj/1549.test.cpp](../../verify/test/aoj/1549.test.cpp.html)
* :heavy_check_mark: [test/aoj/1595.linkcuttree.test.cpp](../../verify/test/aoj/1595.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/2230.test.cpp](../../verify/test/aoj/2230.test.cpp.html)
* :heavy_check_mark: [test/aoj/2627.test.cpp](../../verify/test/aoj/2627.test.cpp.html)
* :heavy_check_mark: [test/aoj/2790.test.cpp](../../verify/test/aoj/2790.test.cpp.html)
* :heavy_check_mark: [test/aoj/2975.test.cpp](../../verify/test/aoj/2975.test.cpp.html)
* :heavy_check_mark: [test/aoj/3069.lichao.test.cpp](../../verify/test/aoj/3069.lichao.test.cpp.html)
* :heavy_check_mark: [test/aoj/3069.test.cpp](../../verify/test/aoj/3069.test.cpp.html)
* :heavy_check_mark: [test/aoj/3112.test.cpp](../../verify/test/aoj/3112.test.cpp.html)
* :heavy_check_mark: [test/aoj/ALDS1_10_C.test.cpp](../../verify/test/aoj/ALDS1_10_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_3_B.test.cpp](../../verify/test/aoj/DPL_3_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_A.linkcuttree.test.cpp](../../verify/test/aoj/GRL_5_A.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/2334.test.cpp](../../verify/test/aoj/geometry/2334.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/3049.test.cpp](../../verify/test/aoj/geometry/3049.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/3056.test.cpp](../../verify/test/aoj/geometry/3056.test.cpp.html)


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif

```
{% endraw %}

[Back to top page](../../index.html)

