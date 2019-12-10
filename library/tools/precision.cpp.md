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


# :warning: tools/precision.cpp
* category: tools


<a href="../../index.html">Back to top page</a>



## Verified
* :warning: <a href="../../verify/test/aoj/2294.test.cpp.html">test/aoj/2294.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2309.tarjan.test.cpp.html">test/aoj/2309.tarjan.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2309.test.cpp.html">test/aoj/2309.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2975.test.cpp.html">test/aoj/2975.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/3049.test.cpp.html">test/aoj/geometry/3049.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;
//END CUT HERE
#ifndef call_from_test
signed main(){
  Int n;
  cin>>n;
  vector<double> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  cout<<(a.back()-a.front())/(n-1)<<endl;
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

