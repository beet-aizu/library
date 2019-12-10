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


# :warning: math/kitamasa.cpp
<a href="../../index.html">Back to top page</a>

* category: math
* <a href="{{ site.github.repository_url }}/blob/master/math/kitamasa.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-26 15:31:15 +0900




## Dependencies
* :heavy_check_mark: <a href="../mod/mint.cpp.html">mod/mint.cpp</a>


## Required
* :heavy_check_mark: <a href="../mod/log.cpp.html">mod/log.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename R>
struct Kitamasa{
  using VR = vector<R>;
  VR c;
  vector<VR> rs;
  int m;

  Kitamasa(const VR &C)
    :c(C),rs(1),m(c.size()){
    rs[0].assign(2*m+1,R::add_identity());
    rs[0][1]=R::mul_identity();
  }

  VR merge(const VR &x,const VR &y){
    VR z(2*m+1,R::add_identity());
    for(int i=1;i<=m;i++)
      for(int j=1;j<=m;j++)
        z[i+j]=z[i+j]+(x[i]*y[j]);

    for(int i=2*m;i>m;z[i--]=R::add_identity())
      for(int j=1;j<=m;j++)
        z[i-j]=z[i-j]+(c[m-j]*z[i]);
    return z;
  }

  R calc(const VR &A,long long n){
    assert((int)A.size()==m);
    VR res(rs[0]);
    for(int i=0;n;i++,n>>=1){
      if(i>=(int)rs.size())
        rs.emplace_back(merge(rs[i-1],rs[i-1]));
      if(~n&1) continue;
      res=merge(res,rs[i]);
    }
    R ans=R::add_identity();
    for(int i=1;i<=m;i++) ans=ans+(res[i]*A[i-1]);
    return ans;
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../mod/mint.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed TDPC_F(){
  using ll = long long;
  int n;
  ll k;
  scanf("%d %lld",&n,&k);

  using M = Mint<int>;
  vector<M> a(n,1),c(n,1);
  Kitamasa<M> fib(c);

  printf("%d\n",fib.calc(a,--k).v);
  return 0;
}
/*
  verified on 2019/10/24
  https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci
*/

signed ABC009_D(){
  int k,m;
  scanf("%d %d",&k,&m);

  struct M{
    uint32_t v;
    M(){*this=add_identity();}
    M(uint32_t v):v(v){}
    M operator+(const M &a)const{return M(v^a.v);}
    M operator*(const M &a)const{return M(v&a.v);}
    static M add_identity(){return M(0);}
    static M mul_identity(){return M(~0u);}
  };

  vector<M> a(k),c(k);
  for(int i=0;i<k;i++) scanf("%u",&a[i].v);
  for(int i=0;i<k;i++) scanf("%u",&c[k-(i+1)].v);
  Kitamasa<M> v(c);

  printf("%u\n",v.calc(a,--m).v);
  return 0;
}
/*
  verified on 2018/10/24
  https://atcoder.jp/contests/abc009/tasks/abc009_4
*/

signed main(){
  //TDPC_F();
  //ABC009_D();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

