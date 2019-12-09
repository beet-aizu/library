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


# :heavy_check_mark: test/aoj/DSL_3_D.cartesiantree.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D)


## Dependencies
* :heavy_check_mark: [datastructure/cartesiantree.cpp](../../../library/datastructure/cartesiantree.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](../../../library/tools/fastio.cpp.html)
* :heavy_check_mark: [tree/lca.cpp](../../../library/tree/lca.cpp.html)


## Code
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../datastructure/cartesiantree.cpp"
#include "../../tree/lca.cpp"
#undef call_from_test

signed main(){
  int n,l;
  cin>>n>>l;

  vector<int> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];

  CartesianTree ct;
  int r=ct.build(vs);

  LCA lca(n);
  for(int i=0;i<n;i++)
    if(~ct.P[i]) lca.add_edge(i,ct.P[i]);
  lca.build(r);

  for(int i=0;i+l<=n;i++){
    if(i) cout<<" ";
    cout<<vs[lca.lca(i,i+l-1)];
  }
  cout<<endl;
  return 0;
}

```

[Back to top page](../../../index.html)

