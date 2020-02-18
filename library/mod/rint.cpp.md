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


# :heavy_check_mark: mod/rint.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ad148a3ca8bd0ef3b48c52454c493ec5">mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/mod/rint.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 18:22:28+09:00




## Required by

* :heavy_check_mark: <a href="factorial.cpp.html">mod/factorial.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0422.test.cpp.html">test/aoj/0422.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1504.test.cpp.html">test/yukicoder/1504.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct Rint{
  static T mod;
  static void set_mod(T nmod){mod=nmod;}

  T v;
  Rint():v(0){}
  Rint(signed v):v(v){}
  Rint(long long t){v=t%mod;if(v<0) v+=mod;}

  Rint pow(long long k){
    Rint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }

  static Rint add_identity(){return Rint(0);}
  static Rint mul_identity(){return Rint(1);}

  Rint inv(){return pow(mod-2);}

  Rint& operator+=(Rint a){v+=a.v;if(v>=mod)v-=mod;return *this;}
  Rint& operator-=(Rint a){v+=mod-a.v;if(v>=mod)v-=mod;return *this;}
  Rint& operator*=(Rint a){v=1LL*v*a.v%mod;return *this;}
  Rint& operator/=(Rint a){return (*this)*=a.inv();}

  Rint operator+(Rint a) const{return Rint(v)+=a;}
  Rint operator-(Rint a) const{return Rint(v)-=a;}
  Rint operator*(Rint a) const{return Rint(v)*=a;}
  Rint operator/(Rint a) const{return Rint(v)/=a;}

  Rint operator-() const{return v?Rint(mod-v):Rint(v);}

  bool operator==(const Rint a)const{return v==a.v;}
  bool operator!=(const Rint a)const{return v!=a.v;}
  bool operator <(const Rint a)const{return v <a.v;}
};
template<typename T> T Rint<T>::mod;
template<typename T>
ostream& operator<<(ostream &os,Rint<T> m){os<<m.v;return os;}
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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: mod/rint.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

