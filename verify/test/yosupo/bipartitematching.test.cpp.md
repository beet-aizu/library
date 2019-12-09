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


# :heavy_check_mark: test/yosupo/bipartitematching.test.cpp


[Back to top page](../../../index.html)

* see: [https://judge.yosupo.jp/problem/bipartitematching](https://judge.yosupo.jp/problem/bipartitematching)


## Dependencies
* :heavy_check_mark: [flow/hopcroft_karp.cpp](../../../library/flow/hopcroft_karp.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](../../../library/tools/fastio.cpp.html)


## Code
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../flow/hopcroft_karp.cpp"
#undef call_from_test

signed main(){
  int L,R,M;
  cin>>L>>R>>M;
  BiMatch G(L,R);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    G.add_edge(a,b);
  }
  cout<<G.build()<<endl;
  for(int i=0;i<L;i++){
    if(~G.match[i])
      cout<<i<<" "<<G.match[i]-L<<"\n";
  }
  cout<<flush;
  return 0;
}

```

[Back to top page](../../../index.html)

