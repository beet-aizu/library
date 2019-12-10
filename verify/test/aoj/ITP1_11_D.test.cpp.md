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


# :heavy_check_mark: test/aoj/ITP1_11_D.test.cpp
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ITP1_11_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-22 15:00:51 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D</a>


## Dependencies
* :heavy_check_mark: <a href="../../../library/tools/dice.cpp.html">tools/dice.cpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/dice.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  vector<Die> ds(n);
  for(int j=0;j<n;j++)
    for(int i=0;i<6;i++)
      cin>>ds[j].s[i];

  bool ff=true;
  for(int i=0;i<n;i++){
    auto vd=makeDice(ds[i]);
    for(int j=0;j<i;j++){
      bool f=false;
      for(auto d:vd) f|=d==ds[j];
      ff&=!f;
    }
  }

  cout<<(ff?"Yes":"No")<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

