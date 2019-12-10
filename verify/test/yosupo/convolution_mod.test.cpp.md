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
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/convolution_mod.test.cpp">View this file on GitHub</a> (Last commit date: 2019-12-09 23:51:01 +0900)


* see: <a href="https://judge.yosupo.jp/problem/convolution_mod">https://judge.yosupo.jp/problem/convolution_mod</a>


## Dependencies
* :heavy_check_mark: <a href="../../../library/convolution/numbertheoretictransform.cpp.html">convolution/numbertheoretictransform.cpp</a>
* :heavy_check_mark: <a href="../../../library/mod/mint.cpp.html">mod/mint.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/fastio.cpp.html">tools/fastio.cpp</a>


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

<a href="../../../index.html">Back to top page</a>

