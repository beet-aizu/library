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


# :warning: string/rollinghash.cpp
* category: string


<a href="../../index.html">Back to top page</a>



## Required
* :heavy_check_mark: <a href="palindromictree.cpp.html">string/palindromictree.cpp</a>


## Verified
* :heavy_check_mark: <a href="../../verify/test/aoj/1312.test.cpp.html">test/aoj/1312.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2292.test.cpp.html">test/aoj/2292.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2444.test.cpp.html">test/aoj/2444.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_14_B.test.cpp.html">test/aoj/ALDS1_14_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_14_C.test.cpp.html">test/aoj/ALDS1_14_C.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T,T MOD,T B>
struct RollingHash{
  using ll = long long;
  vector<T> hash,po;
  RollingHash(){}
  RollingHash(vector<T> vs){init(vs);}
  RollingHash(string &s){
    vector<T> vs;
    for(char c:s) vs.emplace_back(c);
    init(vs);
  }
  void init(vector<T> vs){
    int n=vs.size();
    hash.assign(n+1,0);
    po.assign(n+1,1);
    for(int i=0;i<n;i++){
      hash[i+1]=((ll)hash[i]*B+vs[i])%MOD;
      po[i+1]=(ll)po[i]*B%MOD;
    }
  }
  //S[l, r)
  T find(int l,int r){
    T res=(ll)hash[r]+MOD-(ll)hash[l]*po[r-l]%MOD;
    return res>=MOD?res-MOD:res;
  }
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

