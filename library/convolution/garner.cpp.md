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


# :heavy_check_mark: convolution/garner.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a9595c1c24c33b16056d2ad07e71682d">convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/convolution/garner.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-23 19:42:36+09:00




## Depends on

* :heavy_check_mark: <a href="numbertheoretictransform.cpp.html">convolution/numbertheoretictransform.cpp</a>
* :heavy_check_mark: <a href="../mod/mint.cpp.html">mod/mint.cpp</a>


## Required by

* :heavy_check_mark: <a href="../mod/factorial.cpp.html">mod/factorial.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2985.garner.test.cpp.html">test/aoj/2985.garner.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/convolution_mod_1000000007.garner.test.cpp.html">test/yosupo/convolution_mod_1000000007.garner.test.cpp</a>
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
#include "numbertheoretictransform.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
struct Garner{
  using ll = long long;
  static NTT<0> ntt0;
  static NTT<1> ntt1;
  static NTT<2> ntt2;

  static constexpr int pow(int a,int b,int md){
    int res=1;
    a=a%md;
    while(b){
      if(b&1) res=(ll)res*a%md;
      a=(ll)a*a%md;
      b>>=1;
    }
    return res;
  }

  static constexpr int inv(int x,int md){
    return pow(x,md-2,md);
  }

  inline void garner(int &c0,int c1,int c2,int m01,int MOD){
    static constexpr int r01=inv(ntt0.md,ntt1.md);
    static constexpr int r02=inv(ntt0.md,ntt2.md);
    static constexpr int r12=inv(ntt1.md,ntt2.md);

    c1=(ll)(c1-c0)*r01%ntt1.md;
    if(c1<0) c1+=ntt1.md;

    c2=(ll)(c2-c0)*r02%ntt2.md;
    c2=(ll)(c2-c1)*r12%ntt2.md;
    if(c2<0) c2+=ntt2.md;

    c0%=MOD;
    c0+=(ll)c1*ntt0.md%MOD;
    if(c0>=MOD) c0-=MOD;
    c0+=(ll)c2*m01%MOD;
    if(c0>=MOD) c0-=MOD;
  }

  inline void garner(vector< vector<int> > &cs,int MOD){
    int m01 =(ll)ntt0.md*ntt1.md%MOD;
    int sz=cs[0].size();
    for(int i=0;i<sz;i++) garner(cs[0][i],cs[1][i],cs[2][i],m01,MOD);
  }

  vector<int> multiply(vector<int> as,vector<int> bs,int MOD){
    vector< vector<int> > cs(3);
    cs[0]=ntt0.multiply(as,bs);
    cs[1]=ntt1.multiply(as,bs);
    cs[2]=ntt2.multiply(as,bs);
    size_t sz=as.size()+bs.size()-1;
    for(auto& v:cs) v.resize(sz);
    garner(cs,MOD);
    return cs[0];
  }

  template<typename T>
  decltype(auto) multiply(vector<T> am,
                          vector<T> bm){
    vector<int> as(am.size()),bs(bm.size());
    for(int i=0;i<(int)as.size();i++) as[i]=am[i].v;
    for(int i=0;i<(int)bs.size();i++) bs[i]=bm[i].v;
    vector<int> cs=multiply(as,bs,T::mod);
    vector<T> cm(cs.size());
    for(int i=0;i<(int)cm.size();i++) cm[i]=T(cs[i]);
    return cm;
  }
};
NTT<0> Garner::ntt0;
NTT<1> Garner::ntt1;
NTT<2> Garner::ntt2;
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

