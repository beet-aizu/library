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


# :heavy_check_mark: test/yosupo/matrix_det.test.cpp


[Back to top page](../../../index.html)

* see: [https://judge.yosupo.jp/problem/matrix_det](https://judge.yosupo.jp/problem/matrix_det)


## Dependencies
* :heavy_check_mark: [linearalgebra/matrix.cpp](../../../library/linearalgebra/matrix.cpp.html)
* :heavy_check_mark: [mod/mint.cpp](../../../library/mod/mint.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](../../../library/tools/fastio.cpp.html)


## Code
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/mint.cpp"
#include "../../linearalgebra/matrix.cpp"
#undef call_from_test

signed main(){
  using M = Mint<int, 998244353>;
  using Mat = Matrix<M>;
  int n;
  cin>>n;

  Mat A(n,n);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>A[i][j].v;

  cout<<A.determinant()<<endl;
  return 0;
}

```

[Back to top page](../../../index.html)

