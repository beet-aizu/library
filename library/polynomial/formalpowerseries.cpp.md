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


# :heavy_check_mark: polynomial/formalpowerseries.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#89693d3333328e76f4fdeed379e8f9ea">polynomial</a>
* <a href="{{ site.github.repository_url }}/blob/master/polynomial/formalpowerseries.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-15 01:24:41+09:00




## Depends on

* :heavy_check_mark: <a href="../convolution/numbertheoretictransform.cpp.html">convolution/numbertheoretictransform.cpp</a>
* :heavy_check_mark: <a href="../mod/mint.cpp.html">mod/mint.cpp</a>
* :heavy_check_mark: <a href="../mod/sqrt.cpp.html">mod/sqrt.cpp</a>
* :heavy_check_mark: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Required by

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
* :heavy_check_mark: <a href="../../verify/test/yosupo/sqrt_of_formal_power_series.test.cpp.html">test/yosupo/sqrt_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/2744.test.cpp.html">test/yukicoder/2744.test.cpp</a>
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
template<typename T>
struct FormalPowerSeries{
  using Poly = vector<T>;
  using Conv = function<Poly(Poly, Poly)>;
  Conv conv;
  FormalPowerSeries(Conv conv):conv(conv){}

  Poly pre(const Poly &as,int deg){
    return Poly(as.begin(),as.begin()+min((int)as.size(),deg));
  }

  Poly add(Poly as,Poly bs){
    int sz=max(as.size(),bs.size());
    Poly cs(sz,T(0));
    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
    for(int i=0;i<(int)bs.size();i++) cs[i]+=bs[i];
    return cs;
  }

  Poly sub(Poly as,Poly bs){
    int sz=max(as.size(),bs.size());
    Poly cs(sz,T(0));
    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
    for(int i=0;i<(int)bs.size();i++) cs[i]-=bs[i];
    return cs;
  }

  Poly mul(Poly as,Poly bs){
    return conv(as,bs);
  }

  Poly mul(Poly as,T k){
    for(auto &a:as) a*=k;
    return as;
  }

  // F(0) must not be 0
  Poly inv(Poly as,int deg){
    assert(as[0]!=T(0));
    Poly rs({T(1)/as[0]});
    for(int i=1;i<deg;i<<=1)
      rs=pre(sub(add(rs,rs),mul(mul(rs,rs),pre(as,i<<1))),i<<1);
    return rs;
  }

  // not zero
  Poly div(Poly as,Poly bs){
    while(as.back()==T(0)) as.pop_back();
    while(bs.back()==T(0)) bs.pop_back();
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
    while(as.back()==T(0)) as.pop_back();
    return as;
  }

  // F(0) must be 1
  Poly sqrt(Poly as,int deg){
    assert(as[0]==T(1));
    T inv2=T(1)/T(2);
    Poly ss({T(1)});
    for(int i=1;i<deg;i<<=1){
      ss=pre(add(ss,mul(pre(as,i<<1),inv(ss,i<<1))),i<<1);
      for(T &x:ss) x*=inv2;
    }
    return ss;
  }

  Poly diff(Poly as){
    int n=as.size();
    Poly rs(n-1);
    for(int i=1;i<n;i++) rs[i-1]=as[i]*T(i);
    return rs;
  }

  Poly integral(Poly as){
    int n=as.size();
    Poly rs(n+1);
    rs[0]=T(0);
    for(int i=0;i<n;i++) rs[i+1]=as[i]/T(i+1);
    return rs;
  }

  // F(0) must be 1
  Poly log(Poly as,int deg){
    return pre(integral(mul(diff(as),inv(as,deg))),deg);
  }

  // F(0) must be 0
  Poly exp(Poly as,int deg){
    Poly f({T(1)});
    as[0]+=T(1);
    for(int i=1;i<deg;i<<=1)
      f=pre(mul(f,sub(pre(as,i<<1),log(f,i<<1))),i<<1);
    return f;
  }

  Poly partition(int n){
    Poly rs(n+1);
    rs[0]=T(1);
    for(int k=1;k<=n;k++){
      if(1LL*k*(3*k+1)/2<=n) rs[k*(3*k+1)/2]+=T(k%2?-1LL:1LL);
      if(1LL*k*(3*k-1)/2<=n) rs[k*(3*k-1)/2]+=T(k%2?-1LL:1LL);
    }
    return inv(rs,n+1);
  }

  Poly bernoulli(int n){
    Poly rs(n+1,1);
    for(int i=1;i<=n;i++) rs[i]=rs[i-1]/T(i+1);
    rs=inv(rs,n+1);
    T tmp(1);
    for(int i=1;i<=n;i++){
      tmp*=T(i);
      rs[i]*=tmp;
    }
    return rs;
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../mod/mint.cpp"
#include "../convolution/numbertheoretictransform.cpp"
#include "../mod/sqrt.cpp"
#include "../tools/fastio.cpp"
#undef call_from_test

//INSERT ABOVE HERE

signed HAPPYQUERY_E(){
  int n,m,q;
  cin>>n>>m>>q;
  vector<int> ls(q),rs(q);
  for(int i=0;i<q;i++) cin>>ls[i]>>rs[i],ls[i]--;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  if(as==vector<int>(n,0)){
    for(int i=0;i<m;i++){
      if(i) cout<<" ";
      cout<<0;
    }
    cout<<endl;
    return 0;
  }

  vector<int> cs(n-m+1,0);
  for(int l:ls) cs[l]++;

  NTT<0> ntt;
  using M = NTT<0>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  vector<M> ps(as.size()),qs(cs.size());
  for(int i=0;i<(int)ps.size();i++) ps[i]=M(as[i]);
  for(int i=0;i<(int)qs.size();i++) qs[i]=M(cs[i]);

  auto bs=FPS.div(ps,qs);
  for(int i=0;i<m;i++){
    if(i) cout<<" ";
    cout<<bs[i];
  }
  cout<<endl;
  return 0;
}
/*
  verified on 2019/09/17
  https://www.hackerrank.com/contests/happy-query-contest/challenges/array-restoring
*/

signed CFR250_E(){
  int n,m;
  cin>>n>>m;
  vector<int> cs(n);
  for(int i=0;i<n;i++) cin>>cs[i];

  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  const int deg=1<<18;
  vector<M> as(deg,0);
  as[0]=M(1);
  for(int c:cs) as[c]-=M(4);

  auto bs=FPS.sqrt(as,deg);
  bs[0]+=M(1);

  vector<M> vs({2});

  auto ans=FPS.mul(vs,FPS.inv(bs,deg));
  for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
  cout<<flush;

  return 0;
}
/*
  verified on 2019/09/17
  https://codeforces.com/contest/438/problem/E
*/

signed LOJ_150(){
  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  int n,k;
  cin>>n>>k;

  vector<M> F(n+1);
  for(int i=0;i<=n;i++) cin>>F[i].v;

  const int deg = 1<<17;
  auto as=FPS.log(FPS.mul(F,F[0].inv()),deg);
  auto bs=FPS.exp(FPS.mul(as,M((ntt.md-1)/2)),deg);
  M s(mod_sqrt(F[0].v,ntt.md)[0]);
  auto cs=FPS.integral(FPS.mul(bs,s.inv()));
  auto ds=FPS.exp(cs,deg);
  auto es=FPS.sub(F,ds);
  es[0]+=M(2);
  es[0]-=F[0];
  auto fs=FPS.log(es,deg);
  fs[0]+=M(1);
  auto gs=FPS.log(fs,deg);
  auto hs=FPS.mul(gs,M(k));
  auto is=FPS.exp(hs,deg);
  auto G=FPS.diff(is);

  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<G[i];
  }
  cout<<endl;
  return 0;
}
/*
  verified on 2019/09/17
  https://loj.ac/problem/150
*/

signed CODECHEF_PSUM(){
  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  int n,s,k;
  cin>>n>>s>>k;
  vector<int> cs(n),vs(n);
  for(int i=0;i<n;i++) cin>>cs[i]>>vs[i];

  const int deg = 1<<11;
  vector< vector<M> > dp(s+1,vector<M>(deg,0));
  dp[0][0]=M(1);

  auto nx=dp;
  for(int i=0;i<n;i++){
    auto ps=FPS.exp(vector<M>({M(0),M(vs[i])}),deg);
    for(int j=0;j+cs[i]<=s;j++){
      auto rs=FPS.mul(ps,dp[j]);
      for(int l=0;l<deg;l++) nx[j+cs[i]][l]+=rs[l];
    }
    dp=nx;
  }

  M ans{0};
  for(int i=1;i<=s;i++) ans+=dp[i][k];
  for(int i=1;i<=k;i++) ans*=M(i);
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/09/24
  https://www.codechef.com/problems/PSUM
*/

signed main(){
  //HAPPYQUERY_E();
  //CFR250_E();
  //LOJ_150();
  //CODECHEF_PSUM();
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: polynomial/formalpowerseries.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

