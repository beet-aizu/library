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


# :heavy_check_mark: test/aoj/DSL_2_E.bbst.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E)


## Dependencies
* :heavy_check_mark: [bbst/basic/base.cpp](../../../library/bbst/basic/base.cpp.html)
* :heavy_check_mark: [bbst/basic/dual.cpp](../../../library/bbst/basic/dual.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](../../../library/tools/fastio.cpp.html)


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../bbst/basic/base.cpp"
#include "../../bbst/basic/dual.cpp"
#undef call_from_test

signed main(){
  int n,q;
  cin>>n>>q;

  auto h=[](int a,int b){return a+b;};
  int ei=0;

  using Node = NodeBase<int>;
  constexpr size_t LIM = 1e6;
  Dual<Node, LIM> G(h,ei);

  auto rt=G.init(n);

  for(int i=0;i<q;i++){
    int tp;
    cin>>tp;
    if(tp==0){
      int s,t,x;
      cin>>s>>t>>x;
      s--;
      rt=G.update(rt,s,t,x);
    }
    if(tp==1){
      int s;
      cin>>s;
      s--;
      cout<<G.get_val(rt,s)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

[Back to top page](../../../index.html)

