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


# :heavy_check_mark: test/aoj/ALDS1_14_C.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C)


## Dependencies
* :heavy_check_mark: [string/rectanglehash.cpp](../../../library/string/rectanglehash.cpp.html)
* :heavy_check_mark: [string/rollinghash.cpp](../../../library/string/rollinghash.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](../../../library/tools/fastio.cpp.html)


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../string/rollinghash.cpp"
#include "../../string/rectanglehash.cpp"
#undef call_from_test

signed main(){
  int h,w;
  cin>>h>>w;
  vector<string> ss(h);
  for(int i=0;i<h;i++) cin>>ss[i];

  int r,c;
  cin>>r>>c;
  vector<string> ts(r);
  for(int i=0;i<r;i++) cin>>ts[i];

  const int MOD = 1e9+7;
  const int B1 = 1777771;
  const int B2 = 1e8+7;
  auto srh=rectangle_hash<int, MOD, B1, B2>(ss,r,c);
  auto trh=rectangle_hash<int, MOD, B1, B2>(ts,r,c);

  for(int i=0;i<h-r+1;i++)
    for(int j=0;j<w-c+1;j++)
      if(srh[i][j]==trh[0][0]) cout<<i<<" "<<j<<"\n";

  return 0;
}

```
{% endraw %}

[Back to top page](../../../index.html)

