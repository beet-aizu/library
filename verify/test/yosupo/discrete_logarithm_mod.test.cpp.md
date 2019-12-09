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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/yosupo/discrete_logarithm_mod.test.cpp


[Back to top page](../../../index.html)

* see: [https://judge.yosupo.jp/problem/discrete_logarithm_mod](https://judge.yosupo.jp/problem/discrete_logarithm_mod)


## Dependencies
* :heavy_check_mark: [mod/log.cpp](../../../library/mod/log.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](../../../library/tools/fastio.cpp.html)


## Code
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/log.cpp"
#undef call_from_test

signed main(){
  int t;
  cin>>t;
  while(t--){
    int x,y,m;
    cin>>x>>y>>m;
    int l=mod_log(x,y,m);
    if(l==m) l=-1;
    cout<<l<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

[Back to top page](../../../index.html)

