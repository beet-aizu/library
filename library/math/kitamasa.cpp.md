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


# :heavy_check_mark: math/kitamasa.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/kitamasa.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-21 18:49:40+09:00




## Depends on

* :heavy_check_mark: <a href="../mod/mint.cpp.html">mod/mint.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0168.test.cpp.html">test/aoj/0168.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/104.test.cpp.html">test/yukicoder/104.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1973.test.cpp.html">test/yukicoder/1973.test.cpp</a>


## Code

<a id="unbundled"></a>
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
  VR cs;
  vector<VR> rs;
  int m;

  Kitamasa(const VR &C)
    :cs(C),rs(1),m(C.size()){
    rs[0].assign(2*m+1,R::add_identity());
    rs[0][1]=R::mul_identity();
  }

  VR merge(const VR &xs,const VR &ys){
    VR zs(2*m+1,R::add_identity());
    for(int i=1;i<=m;i++)
      for(int j=1;j<=m;j++)
        zs[i+j]=zs[i+j]+(xs[i]*ys[j]);

    for(int i=2*m;i>m;zs[i--]=R::add_identity())
      for(int j=1;j<=m;j++)
        zs[i-j]=zs[i-j]+(cs[m-j]*zs[i]);
    return zs;
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

  vector<M> as(k),cs(k);
  for(int i=0;i<k;i++) scanf("%u",&as[i].v);
  for(int i=0;i<k;i++) scanf("%u",&cs[k-(i+1)].v);
  Kitamasa<M> v(cs);

  printf("%u\n",v.calc(as,--m).v);
  return 0;
}
/*
  verified on 2019/12/10
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: math/kitamasa.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

