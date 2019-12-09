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


# :heavy_check_mark: test/aoj/DSL_1_B.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B)


## Dependencies
* :heavy_check_mark: [datastructure/weightedunionfindtree.cpp](../../../library/datastructure/weightedunionfindtree.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](../../../library/tools/fastio.cpp.html)


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../datastructure/weightedunionfindtree.cpp"
#undef call_from_test

int main(){
  int n,q;
  cin>>n>>q;
  WeightedUnionFind<int> wuf(n);

  for(int i=0;i<q;i++){
    int t,x,y,z;
    cin>>t>>x>>y;
    if(t){
      if(wuf.same(x,y)) cout<<wuf.diff(x,y)<<"\n";
      else cout<<"?\n";
    }else{
      cin>>z;
      wuf.unite(x,y,z);
    }
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

[Back to top page](../../../index.html)

