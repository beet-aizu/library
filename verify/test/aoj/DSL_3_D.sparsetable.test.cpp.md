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


# :heavy_check_mark: test/aoj/DSL_3_D.sparsetable.test.cpp
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_3_D.sparsetable.test.cpp">View this file on GitHub</a> (Last commit date: 2019-12-09 23:51:01 +0900)


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D</a>


## Dependencies
* :heavy_check_mark: <a href="../../../library/datastructure/sparsetable.cpp.html">datastructure/sparsetable.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/fastio.cpp.html">tools/fastio.cpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../datastructure/sparsetable.cpp"
#undef call_from_test

signed main(){
  int n,l;
  cin>>n>>l;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto f=[](int a,int b){return min(a,b);};
  SparseTable<int> st(f);
  st.build(as);

  for(int i=0;i+l<=n;i++){
    if(i) cout<<" ";
    cout<<st.query(i,i+l);
  }
  cout<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

