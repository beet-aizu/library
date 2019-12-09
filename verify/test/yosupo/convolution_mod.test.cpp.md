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


# :heavy_check_mark: test/yosupo/convolution_mod.test.cpp


[Back to top page](../../../index.html)

* see: [https://judge.yosupo.jp/problem/convolution_mod](https://judge.yosupo.jp/problem/convolution_mod)


## Dependencies
* :heavy_check_mark: [convolution/numbertheoretictransform.cpp](../../../library/convolution/numbertheoretictransform.cpp.html)
* :heavy_check_mark: [mod/mint.cpp](../../../library/mod/mint.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](../../../library/tools/fastio.cpp.html)


## Code
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#undef call_from_test

signed main(){
  int n,m;
  cin>>n>>m;
  NTT<2> ntt;
  using M = decltype(ntt)::M;
  vector<M> as(n),bs(m);
  for(int i=0;i<n;i++) cin>>as[i].v;
  for(int i=0;i<m;i++) cin>>bs[i].v;
  auto cs=ntt.multiply(as,bs);
  for(int i=0;i<(int)cs.size();i++){
    if(i) cout<<" ";
    cout<<cs[i];
  }
  cout<<endl;
  return 0;
}

```
{% endraw %}

[Back to top page](../../../index.html)

