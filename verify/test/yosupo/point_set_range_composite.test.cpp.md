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


# :heavy_check_mark: test/yosupo/point_set_range_composite.test.cpp


[Back to top page](../../../index.html)

* see: [https://judge.yosupo.jp/problem/point_set_range_composite](https://judge.yosupo.jp/problem/point_set_range_composite)


## Dependencies
* :heavy_check_mark: [mod/mint.cpp](../../../library/mod/mint.cpp.html)
* :heavy_check_mark: [segtree/basic/ushi.cpp](../../../library/segtree/basic/ushi.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](../../../library/tools/fastio.cpp.html)


## Code
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/mint.cpp"
#include "../../segtree/basic/ushi.cpp"
#undef call_from_test

signed main(){
  using M = Mint<int, 998244353>;
  int n,q;
  cin>>n>>q;

  vector<int> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];

  struct T{
    M a,b;
    T(M a,M b):a(a),b(b){}
  };

  auto f=[&](T x,T y){return T(x.a*y.a,x.b*y.a+y.b);};
  T ti(M(1),M(0));
  SegmentTree<T> seg(f,ti);
  vector<T> vt;
  for(int i=0;i<n;i++) vt.emplace_back(as[i],bs[i]);
  seg.build(vt);

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int p,c,d;
      cin>>p>>c>>d;
      seg.set_val(p,T(M(c),M(d)));
    }
    if(t==1){
      int l,r,x;
      cin>>l>>r>>x;
      T res=seg.query(l,r);
      cout<<res.a*M(x)+res.b<<"\n";
    }
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

[Back to top page](../../../index.html)

