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


# :heavy_check_mark: convolution/numbertheoretictransform.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a9595c1c24c33b16056d2ad07e71682d">convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/convolution/numbertheoretictransform.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-26 23:10:12+09:00




## Depends on

* :heavy_check_mark: <a href="../mod/mint.cpp.html">mod/mint.cpp</a>


## Required by

* :heavy_check_mark: <a href="garner.cpp.html">convolution/garner.cpp</a>
* :heavy_check_mark: <a href="../mod/factorial.cpp.html">mod/factorial.cpp</a>
* :heavy_check_mark: <a href="../polynomial/formalpowerseries.cpp.html">polynomial/formalpowerseries.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2560.test.cpp.html">test/aoj/2560.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2959.test.cpp.html">test/aoj/2959.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2977.test.cpp.html">test/aoj/2977.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2985.garner.test.cpp.html">test/aoj/2985.garner.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3072.test.cpp.html">test/aoj/3072.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3074.test.cpp.html">test/aoj/3074.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/bernoulli_number.test.cpp.html">test/yosupo/bernoulli_number.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/convolution_mod.test.cpp.html">test/yosupo/convolution_mod.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/convolution_mod_1000000007.garner.test.cpp.html">test/yosupo/convolution_mod_1000000007.garner.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/exp_of_formal_power_series.test.cpp.html">test/yosupo/exp_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/inv_of_formal_power_series.test.cpp.html">test/yosupo/inv_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/log_of_formal_power_series.test.cpp.html">test/yosupo/log_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/multipoint_evaluation.test.cpp.html">test/yosupo/multipoint_evaluation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/partition_function.test.cpp.html">test/yosupo/partition_function.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/polynomial_interpolation.test.cpp.html">test/yosupo/polynomial_interpolation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/sqrt_of_formal_power_series.test.cpp.html">test/yosupo/sqrt_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1504.test.cpp.html">test/yukicoder/1504.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../mod/mint.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
constexpr int bmds(int x){
  const int v[] = {1012924417, 924844033, 998244353,
                   897581057, 645922817};
  return v[x];
}
constexpr int brts(int x){
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}

template<int X>
struct NTT{
  static constexpr int md = bmds(X);
  static constexpr int rt = brts(X);
  using M = Mint<int, md>;
  vector< vector<M> > rts,rrts;

  void ensure_base(int n){
    if((int)rts.size()>=n) return;
    rts.resize(n);rrts.resize(n);
    for(int i=1;i<n;i<<=1){
      if(!rts[i].empty()) continue;
      M w=M(rt).pow((md-1)/(i<<1));
      M rw=w.inv();
      rts[i].resize(i);rrts[i].resize(i);
      rts[i][0]=M(1);rrts[i][0]=M(1);
      for(int k=1;k<i;k++){
        rts[i][k]=rts[i][k-1]*w;
        rrts[i][k]=rrts[i][k-1]*rw;
      }
    }
  }

  void ntt(vector<M> &as,bool f){
    int n=as.size();
    assert((n&(n-1))==0);
    ensure_base(n);

    for(int i=0,j=1;j+1<n;j++){
      for(int k=n>>1;k>(i^=k);k>>=1);
      if(i>j) swap(as[i],as[j]);
    }

    for(int i=1;i<n;i<<=1){
      for(int j=0;j<n;j+=i*2){
        for(int k=0;k<i;k++){
          M z=as[i+j+k]*(f?rrts[i][k]:rts[i][k]);
          as[i+j+k]=as[j+k]-z;
          as[j+k]+=z;
        }
      }
    }

    if(f){
      M tmp=M(n).inv();
      for(int i=0;i<n;i++) as[i]*=tmp;
    }
  }

  vector<M> multiply(vector<M> as,vector<M> bs){
    int need=as.size()+bs.size()-1;
    int sz=1;
    while(sz<need) sz<<=1;
    as.resize(sz,M(0));
    bs.resize(sz,M(0));

    ntt(as,0);ntt(bs,0);
    for(int i=0;i<sz;i++) as[i]*=bs[i];
    ntt(as,1);

    as.resize(need);
    return as;
  }

  vector<int> multiply(vector<int> as,vector<int> bs){
    vector<M> am(as.size()),bm(bs.size());
    for(int i=0;i<(int)am.size();i++) am[i]=M(as[i]);
    for(int i=0;i<(int)bm.size();i++) bm[i]=M(bs[i]);
    vector<M> cm=multiply(am,bm);
    vector<int> cs(cm.size());
    for(int i=0;i<(int)cs.size();i++) cs[i]=cm[i].v;
    return cs;
  }
};
template<int X> constexpr int NTT<X>::md;
template<int X> constexpr int NTT<X>::rt;
//END CUT HERE
#ifndef call_from_test
signed main(){
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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: mod/mint.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

