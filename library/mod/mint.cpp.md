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


# :heavy_check_mark: mod/mint.cpp
* category: mod


[Back to top page](../../index.html)



## Required
* :heavy_check_mark: [convolution/arbitrarymodconvolution.cpp](../convolution/arbitrarymodconvolution.cpp.html)
* :heavy_check_mark: [convolution/arbitrarymodconvolution_with_garner.cpp](../convolution/arbitrarymodconvolution_with_garner.cpp.html)
* :warning: [convolution/fastwalshhadamardtransform.cpp](../convolution/fastwalshhadamardtransform.cpp.html)
* :heavy_check_mark: [convolution/numbertheoretictransform.cpp](../convolution/numbertheoretictransform.cpp.html)
* :heavy_check_mark: [graph/lowlink.cpp](../graph/lowlink.cpp.html)
* :heavy_check_mark: [graph/maximalmatching.cpp](../graph/maximalmatching.cpp.html)
* :heavy_check_mark: [linearalgebra/squarematrix.cpp](../linearalgebra/squarematrix.cpp.html)
* :heavy_check_mark: [linearalgebra/tree_theorem.cpp](../linearalgebra/tree_theorem.cpp.html)
* :heavy_check_mark: [linkcuttree/path.cpp](../linkcuttree/path.cpp.html)
* :warning: [math/kitamasa.cpp](../math/kitamasa.cpp.html)
* :heavy_check_mark: [mod/enumeration.cpp](enumeration.cpp.html)
* :heavy_check_mark: [mod/log.cpp](log.cpp.html)
* :heavy_check_mark: [polynomial/formalpowerseries.cpp](../polynomial/formalpowerseries.cpp.html)
* :heavy_check_mark: [polynomial/hash.cpp](../polynomial/hash.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/0314.test.cpp](../../verify/test/aoj/0314.test.cpp.html)
* :heavy_check_mark: [test/aoj/1630.test.cpp](../../verify/test/aoj/1630.test.cpp.html)
* :heavy_check_mark: [test/aoj/2222.test.cpp](../../verify/test/aoj/2222.test.cpp.html)
* :heavy_check_mark: [test/aoj/2397.test.cpp](../../verify/test/aoj/2397.test.cpp.html)
* :heavy_check_mark: [test/aoj/2560.test.cpp](../../verify/test/aoj/2560.test.cpp.html)
* :heavy_check_mark: [test/aoj/2959.test.cpp](../../verify/test/aoj/2959.test.cpp.html)
* :heavy_check_mark: [test/aoj/2971.test.cpp](../../verify/test/aoj/2971.test.cpp.html)
* :heavy_check_mark: [test/aoj/2977.test.cpp](../../verify/test/aoj/2977.test.cpp.html)
* :heavy_check_mark: [test/aoj/2983.test.cpp](../../verify/test/aoj/2983.test.cpp.html)
* :heavy_check_mark: [test/aoj/2985.garner.test.cpp](../../verify/test/aoj/2985.garner.test.cpp.html)
* :heavy_check_mark: [test/aoj/2985.test.cpp](../../verify/test/aoj/2985.test.cpp.html)
* :heavy_check_mark: [test/aoj/3072.test.cpp](../../verify/test/aoj/3072.test.cpp.html)
* :heavy_check_mark: [test/aoj/3074.test.cpp](../../verify/test/aoj/3074.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_A.test.cpp](../../verify/test/aoj/DPL_5_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_B.test.cpp](../../verify/test/aoj/DPL_5_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_C.test.cpp](../../verify/test/aoj/DPL_5_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_D.test.cpp](../../verify/test/aoj/DPL_5_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_E.test.cpp](../../verify/test/aoj/DPL_5_E.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_F.test.cpp](../../verify/test/aoj/DPL_5_F.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_G.test.cpp](../../verify/test/aoj/DPL_5_G.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_H.test.cpp](../../verify/test/aoj/DPL_5_H.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_I.test.cpp](../../verify/test/aoj/DPL_5_I.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_J.test.cpp](../../verify/test/aoj/DPL_5_J.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_K.test.cpp](../../verify/test/aoj/DPL_5_K.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_L.test.cpp](../../verify/test/aoj/DPL_5_L.test.cpp.html)
* :heavy_check_mark: [test/yosupo/bernoulli_number.test.cpp](../../verify/test/yosupo/bernoulli_number.test.cpp.html)
* :heavy_check_mark: [test/yosupo/convolution_mod.test.cpp](../../verify/test/yosupo/convolution_mod.test.cpp.html)
* :heavy_check_mark: [test/yosupo/exp_of_formal_power_series.test.cpp](../../verify/test/yosupo/exp_of_formal_power_series.test.cpp.html)
* :heavy_check_mark: [test/yosupo/inv_of_formal_power_series.test.cpp](../../verify/test/yosupo/inv_of_formal_power_series.test.cpp.html)
* :heavy_check_mark: [test/yosupo/log_of_formal_power_series.test.cpp](../../verify/test/yosupo/log_of_formal_power_series.test.cpp.html)
* :heavy_check_mark: [test/yosupo/matrix_det.test.cpp](../../verify/test/yosupo/matrix_det.test.cpp.html)
* :heavy_check_mark: [test/yosupo/partition_function.test.cpp](../../verify/test/yosupo/partition_function.test.cpp.html)
* :heavy_check_mark: [test/yosupo/point_set_range_composite.test.cpp](../../verify/test/yosupo/point_set_range_composite.test.cpp.html)


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
template<typename T,T MOD = 1000000007>
struct Mint{
  static constexpr T mod = MOD;
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}

  Mint pow(long long k){
    Mint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }

  static Mint add_identity(){return Mint(0);}
  static Mint mul_identity(){return Mint(1);}

  Mint inv(){return pow(MOD-2);}

  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}

  Mint operator+(Mint a) const{return Mint(v)+=a;}
  Mint operator-(Mint a) const{return Mint(v)-=a;}
  Mint operator*(Mint a) const{return Mint(v)*=a;}
  Mint operator/(Mint a) const{return Mint(v)/=a;}

  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}

  static Mint comb(long long n,int k){
    Mint num(1),dom(1);
    for(int i=0;i<k;i++){
      num*=Mint(n-i);
      dom*=Mint(i+1);
    }
    return num/dom;
  }
};
template<typename T,T MOD> constexpr T Mint<T, MOD>::mod;
template<typename T,T MOD>
ostream& operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed ABC127_E(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int h,w,k;
  cin>>h>>w>>k;
  using M = Mint<int>;

  M ans{0};
  for(int d=1;d<h;d++)
    ans+=M(d)*M(h-d)*M(w)*M(w);

  for(int d=1;d<w;d++)
    ans+=M(d)*M(w-d)*M(h)*M(h);

  ans*=M::comb(h*w-2,k-2);
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/06/12
  https://atcoder.jp/contests/abc127/tasks/abc127_e
*/

signed main(){
  //ABC127_E();
  return 0;
}
#endif

```
{% endraw %}

[Back to top page](../../index.html)

