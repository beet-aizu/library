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


# :warning: segtree/basic/dual.cpp
* category: segtree/basic


[Back to top page](../../../index.html)



## Verified
* :heavy_check_mark: [test/aoj/2359.test.cpp](../../../verify/test/aoj/2359.test.cpp.html)
* :heavy_check_mark: [test/aoj/3112.test.cpp](../../../verify/test/aoj/3112.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_D.test.cpp](../../../verify/test/aoj/DSL_2_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_E.test.cpp](../../../verify/test/aoj/DSL_2_E.test.cpp.html)


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template <typename E>
struct SegmentTree{
  using H = function<E(E,E)>;
  int n,height;
  H h;
  E ei;
  vector<E> laz;

  SegmentTree(H h,E ei):h(h),ei(ei){}

  void init(int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    laz.assign(2*n,ei);
  }

  inline void propagate(int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    laz[k]=ei;
  }

  inline void thrust(int k){
    for(int i=height;i;i--) propagate(k>>i);
  }

  void update(int a,int b,E x){
    thrust(a+=n);
    thrust(b+=n-1);
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
  }

  E get_val(int a){
    thrust(a+=n);
    return laz[a];
  }

  void set_val(int a,E x){
    thrust(a+=n);
    laz[a]=x;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif

```
{% endraw %}

[Back to top page](../../../index.html)

