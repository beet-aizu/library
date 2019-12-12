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


# :heavy_check_mark: test/yosupo/bernoulli_number.test.cpp
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/bernoulli_number.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 23:51:01 +0900


* see: <a href="https://judge.yosupo.jp/problem/bernoulli_number">https://judge.yosupo.jp/problem/bernoulli_number</a>


## Depends On
* :heavy_check_mark: <a href="../../../library/convolution/numbertheoretictransform.cpp.html">convolution/numbertheoretictransform.cpp</a>
* :warning: <a href="../../../library/mod/mint.cpp.html">mod/mint.cpp</a>
* :heavy_check_mark: <a href="../../../library/polynomial/formalpowerseries.cpp.html">polynomial/formalpowerseries.cpp</a>
* :warning: <a href="../../../library/tools/fastio.cpp.html">tools/fastio.cpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../polynomial/formalpowerseries.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;

  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  auto ps=FPS.bernoulli(n);
  for(int i=0;i<=n;i++){
    if(i) cout<<" ";
    cout<<ps[i];
  }
  cout<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

