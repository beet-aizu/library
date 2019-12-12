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


# :warning: test/aoj/GRL_6_B.test.cpp
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_6_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-08 11:49:04 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B</a>


## Depends On
* :warning: <a href="../../../library/flow/primaldual.cpp.html">flow/primaldual.cpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../flow/primaldual.cpp"
#undef call_from_test

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int v,e,f;
  cin>>v>>e>>f;

  PrimalDual<int, int> G(v);
  for(int i=0;i<e;i++){
    int u,v,c,d;
    cin>>u>>v>>c>>d;
    G.add_edge(u,v,c,d);
  }
  int ok=0;
  int res=G.flow(0,v-1,f,ok);
  cout<<(ok?res:-1)<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

