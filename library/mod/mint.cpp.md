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

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ad148a3ca8bd0ef3b48c52454c493ec5">mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/mod/mint.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 16:09:50+09:00




## Required by

* :warning: <a href="../convolution/fastwalshhadamardtransform.cpp.html">convolution/fastwalshhadamardtransform.cpp</a>
* :heavy_check_mark: <a href="../convolution/garner.cpp.html">convolution/garner.cpp</a>
* :heavy_check_mark: <a href="../convolution/numbertheoretictransform.cpp.html">convolution/numbertheoretictransform.cpp</a>
* :heavy_check_mark: <a href="../graph/lowlink.cpp.html">graph/lowlink.cpp</a>
* :heavy_check_mark: <a href="../graph/maximalmatching.cpp.html">graph/maximalmatching.cpp</a>
* :heavy_check_mark: <a href="../linearalgebra/squarematrix.cpp.html">linearalgebra/squarematrix.cpp</a>
* :heavy_check_mark: <a href="../linearalgebra/tree_theorem.cpp.html">linearalgebra/tree_theorem.cpp</a>
* :heavy_check_mark: <a href="../math/kitamasa.cpp.html">math/kitamasa.cpp</a>
* :heavy_check_mark: <a href="enumeration.cpp.html">mod/enumeration.cpp</a>
* :heavy_check_mark: <a href="factorial.cpp.html">mod/factorial.cpp</a>
* :heavy_check_mark: <a href="../polynomial/berlekampmassey.cpp.html">polynomial/berlekampmassey.cpp</a>
* :heavy_check_mark: <a href="../polynomial/formalpowerseries.cpp.html">polynomial/formalpowerseries.cpp</a>
* :heavy_check_mark: <a href="../polynomial/hash.cpp.html">polynomial/hash.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0314.test.cpp.html">test/aoj/0314.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1300.test.cpp.html">test/aoj/1300.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1630.test.cpp.html">test/aoj/1630.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2222.test.cpp.html">test/aoj/2222.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2397.test.cpp.html">test/aoj/2397.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2405.test.cpp.html">test/aoj/2405.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2560.test.cpp.html">test/aoj/2560.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2951.test.cpp.html">test/aoj/2951.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2959.test.cpp.html">test/aoj/2959.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2971.test.cpp.html">test/aoj/2971.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2977.test.cpp.html">test/aoj/2977.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2983.test.cpp.html">test/aoj/2983.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2985.garner.test.cpp.html">test/aoj/2985.garner.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2985.test.cpp.html">test/aoj/2985.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3072.test.cpp.html">test/aoj/3072.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3074.test.cpp.html">test/aoj/3074.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_A.test.cpp.html">test/aoj/DPL_5_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_B.test.cpp.html">test/aoj/DPL_5_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_C.test.cpp.html">test/aoj/DPL_5_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_D.test.cpp.html">test/aoj/DPL_5_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_E.test.cpp.html">test/aoj/DPL_5_E.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_F.test.cpp.html">test/aoj/DPL_5_F.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_G.test.cpp.html">test/aoj/DPL_5_G.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_H.test.cpp.html">test/aoj/DPL_5_H.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_I.test.cpp.html">test/aoj/DPL_5_I.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_J.test.cpp.html">test/aoj/DPL_5_J.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_K.test.cpp.html">test/aoj/DPL_5_K.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_L.test.cpp.html">test/aoj/DPL_5_L.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/bernoulli_number.test.cpp.html">test/yosupo/bernoulli_number.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/convolution_mod.test.cpp.html">test/yosupo/convolution_mod.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/convolution_mod_1000000007.garner.test.cpp.html">test/yosupo/convolution_mod_1000000007.garner.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/convolution_mod_1000000007.test.cpp.html">test/yosupo/convolution_mod_1000000007.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/exp_of_formal_power_series.test.cpp.html">test/yosupo/exp_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/inv_of_formal_power_series.test.cpp.html">test/yosupo/inv_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/log_of_formal_power_series.test.cpp.html">test/yosupo/log_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/matrix_det.test.cpp.html">test/yosupo/matrix_det.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/multipoint_evaluation.test.cpp.html">test/yosupo/multipoint_evaluation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/partition_function.test.cpp.html">test/yosupo/partition_function.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/point_set_range_composite.test.cpp.html">test/yosupo/point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/polynomial_interpolation.test.cpp.html">test/yosupo/polynomial_interpolation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/queue_operate_all_composite.test.cpp.html">test/yosupo/queue_operate_all_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/range_affine_range_sum.test.cpp.html">test/yosupo/range_affine_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/sqrt_of_formal_power_series.test.cpp.html">test/yosupo/sqrt_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/104.test.cpp.html">test/yukicoder/104.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1504.test.cpp.html">test/yukicoder/1504.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1973.test.cpp.html">test/yukicoder/1973.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/22.test.cpp.html">test/yukicoder/22.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/2744.test.cpp.html">test/yukicoder/2744.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/3211.test.cpp.html">test/yukicoder/3211.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/444.test.cpp.html">test/yukicoder/444.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
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

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: mod/mint.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

