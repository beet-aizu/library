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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: datastructure/binaryindexedtree.cpp
* category: datastructure


<a href="../../index.html">Back to top page</a>



## Dependencies
* :warning: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Required
* :heavy_check_mark: <a href="../linkcuttree/subtree.cpp.html">linkcuttree/subtree.cpp</a>
* :heavy_check_mark: <a href="../string/zalgorithm.cpp.html">string/zalgorithm.cpp</a>
* :heavy_check_mark: <a href="../tree/eulertourforedge.cpp.html">tree/eulertourforedge.cpp</a>
* :heavy_check_mark: <a href="../tree/eulertourforvertex.cpp.html">tree/eulertourforvertex.cpp</a>


## Verified
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_B.test.cpp.html">test/aoj/DSL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_D.test.cpp.html">test/aoj/GRL_5_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/point_add_range_sum.test.cpp.html">test/yosupo/point_add_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_path_sum.test.cpp.html">test/yosupo/vertex_add_path_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html">test/yosupo/vertex_add_subtree_sum.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct BIT{
  int n;
  vector<T> bit;
  //1-indexed
  BIT(int n_):n(n_+1),bit(n,0){}

  T sum(int i){
    T s(0);
    for(int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }

  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }

  int lower_bound(int w){
    if(w<=0) return 0;
    int x=0,r=1;
    while(r<n) r<<=1;
    for(int k=r;k>0;k>>=1){
      if(x+k<=n&&bit[x+k]<w){
        w-=bit[x+k];
        x+=k;
      }
    }
    return x+1;
  }

  // [l, r)
  T query(int l,int r){
    return sum(r-1)-sum(l-1);
  }

  T sum0(int i){
    return sum(i+1);
  }

  void add0(int i,T a){
    add(i+1,a);
  }

  T query0(int l,int r){
    return sum(r)-sum(l);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#undef call_from_test

// lower_bound
signed ARC033_C(){
  int q;
  cin>>q;
  BIT<int> bit(2e5);
  while(q--){
    int t,x;
    cin>>t>>x;
    if(t==1) bit.add(x,1);
    if(t==2){
      int k=bit.lower_bound(x);
      bit.add(k,-1);
      cout<<k<<endl;
    }
  }
  return 0;
}
/*
  verified on 2019/11/11
  https://atcoder.jp/contests/arc033/tasks/arc033_3
*/

signed main(){
  ARC033_C();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

