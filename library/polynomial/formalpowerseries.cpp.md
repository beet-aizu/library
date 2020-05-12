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


# :question: polynomial/formalpowerseries.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#89693d3333328e76f4fdeed379e8f9ea">polynomial</a>
* <a href="{{ site.github.repository_url }}/blob/master/polynomial/formalpowerseries.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-12 17:47:27+09:00


* see: <a href="http://beet-aizu.hatenablog.com/entry/2019/09/27/224701">http://beet-aizu.hatenablog.com/entry/2019/09/27/224701</a>


## Depends on

* :question: <a href="../combinatorics/enumeration.cpp.html">combinatorics/enumeration.cpp</a>


## Required by

* :heavy_check_mark: <a href="../combinatorics/bernoulli.cpp.html">combinatorics/bernoulli.cpp</a>
* :heavy_check_mark: <a href="../combinatorics/partition.cpp.html">combinatorics/partition.cpp</a>
* :x: <a href="../combinatorics/stirling1st.cpp.html">combinatorics/stirling1st.cpp</a>
* :x: <a href="../combinatorics/stirling2nd.cpp.html">combinatorics/stirling2nd.cpp</a>
* :heavy_check_mark: <a href="interpolate.cpp.html">polynomial/interpolate.cpp</a>
* :heavy_check_mark: <a href="multieval.cpp.html">polynomial/multieval.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2985.garner.test.cpp.html">test/aoj/2985.garner.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2985.test.cpp.html">test/aoj/2985.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3072.test.cpp.html">test/aoj/3072.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/bernoulli_number.test.cpp.html">test/yosupo/bernoulli_number.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/exp_of_formal_power_series.test.cpp.html">test/yosupo/exp_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/inv_of_formal_power_series.test.cpp.html">test/yosupo/inv_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/log_of_formal_power_series.test.cpp.html">test/yosupo/log_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/multipoint_evaluation.test.cpp.html">test/yosupo/multipoint_evaluation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/partition_function.test.cpp.html">test/yosupo/partition_function.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/polynomial_interpolation.test.cpp.html">test/yosupo/polynomial_interpolation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/pow_of_formal_power_series.test.cpp.html">test/yosupo/pow_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/sqrt_of_formal_power_series.test.cpp.html">test/yosupo/sqrt_of_formal_power_series.test.cpp</a>
* :x: <a href="../../verify/test/yosupo/stirling_number_of_the_first_kind.test.cpp.html">test/yosupo/stirling_number_of_the_first_kind.test.cpp</a>
* :x: <a href="../../verify/test/yosupo/stirling_number_of_the_second_kind.test.cpp.html">test/yosupo/stirling_number_of_the_second_kind.test.cpp</a>
* :x: <a href="../../verify/test/yukicoder/0444.test.cpp.html">test/yukicoder/0444.test.cpp</a>
* :x: <a href="../../verify/test/yukicoder/2744.test.cpp.html">test/yukicoder/2744.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../combinatorics/enumeration.cpp"
#undef call_from_test

#endif

/*
 * @see http://beet-aizu.hatenablog.com/entry/2019/09/27/224701
 */
//BEGIN CUT HERE
template<typename M_>
struct FormalPowerSeries : Enumeration<M_> {
  using M = M_;
  using super = Enumeration<M>;
  using super::fact;
  using super::finv;
  using super::invs;

  using Poly = vector<M>;
  using Conv = function<Poly(Poly, Poly)>;
  Conv conv;
  FormalPowerSeries(Conv conv):conv(conv){}

  Poly pre(const Poly &as,int deg){
    return Poly(as.begin(),as.begin()+min((int)as.size(),deg));
  }

  Poly add(Poly as,Poly bs){
    int sz=max(as.size(),bs.size());
    Poly cs(sz,M(0));
    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
    for(int i=0;i<(int)bs.size();i++) cs[i]+=bs[i];
    return cs;
  }

  Poly sub(Poly as,Poly bs){
    int sz=max(as.size(),bs.size());
    Poly cs(sz,M(0));
    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
    for(int i=0;i<(int)bs.size();i++) cs[i]-=bs[i];
    return cs;
  }

  Poly mul(Poly as,Poly bs){
    return conv(as,bs);
  }

  Poly mul(Poly as,M k){
    for(auto &a:as) a*=k;
    return as;
  }

  // F(0) must not be 0
  Poly inv(Poly as,int deg){
    assert(as[0]!=M(0));
    Poly rs({M(1)/as[0]});
    for(int i=1;i<deg;i<<=1)
      rs=pre(sub(add(rs,rs),mul(mul(rs,rs),pre(as,i<<1))),i<<1);
    return rs;
  }

  // not zero
  Poly div(Poly as,Poly bs){
    while(as.back()==M(0)) as.pop_back();
    while(bs.back()==M(0)) bs.pop_back();
    if(bs.size()>as.size()) return Poly();
    reverse(as.begin(),as.end());
    reverse(bs.begin(),bs.end());
    int need=as.size()-bs.size()+1;
    Poly ds=pre(mul(as,inv(bs,need)),need);
    reverse(ds.begin(),ds.end());
    return ds;
  }

  Poly mod(Poly as,Poly bs){
    if(as==Poly(as.size(),0)) return Poly({0});
    as=sub(as,mul(div(as,bs),bs));
    if(as==Poly(as.size(),0)) return Poly({0});
    while(as.back()==M(0)) as.pop_back();
    return as;
  }

  // F(0) must be 1
  Poly sqrt(Poly as,int deg){
    assert(as[0]==M(1));
    M inv2=M(1)/M(2);
    Poly ss({M(1)});
    for(int i=1;i<deg;i<<=1){
      ss=pre(add(ss,mul(pre(as,i<<1),inv(ss,i<<1))),i<<1);
      for(M &x:ss) x*=inv2;
    }
    return ss;
  }

  Poly diff(Poly as){
    int n=as.size();
    Poly rs(n-1);
    for(int i=1;i<n;i++) rs[i-1]=as[i]*M(i);
    return rs;
  }

  Poly integral(Poly as){
    super::init(as.size()+1);
    int n=as.size();
    Poly rs(n+1);
    rs[0]=M(0);
    for(int i=0;i<n;i++) rs[i+1]=as[i]*invs[i+1];
    return rs;
  }

  // F(0) must be 1
  Poly log(Poly as,int deg){
    return pre(integral(mul(diff(as),inv(as,deg))),deg);
  }

  // F(0) must be 0
  Poly exp(Poly as,int deg){
    Poly fs({M(1)});
    as[0]+=M(1);
    for(int i=1;i<deg;i<<=1)
      fs=pre(mul(fs,sub(pre(as,i<<1),log(fs,i<<1))),i<<1);
    return fs;
  }

  // not zero
  Poly pow(Poly as,long long k,int deg){
    if(as==Poly(as.size(),M(0))) return Poly(deg,M(0));

    int cnt=0;
    while(as[cnt]==M(0)) cnt++;
    if(cnt*k>=deg) return Poly(deg,M(0));
    as.erase(as.begin(),as.begin()+cnt);
    deg-=cnt*k;

    M c=as[0];
    Poly zs(cnt*k,M(0));
    Poly rs=mul(exp(mul(log(mul(as,c.inv()),deg),M(k)),deg),c.pow(k));
    zs.insert(zs.end(),rs.begin(),rs.end());
    return pre(zs,deg+cnt*k);
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

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 172, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 281, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: polynomial/formalpowerseries.cpp: line 8: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

