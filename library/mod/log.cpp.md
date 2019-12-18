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


# :heavy_check_mark: mod/log.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ad148a3ca8bd0ef3b48c52454c493ec5">mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/mod/log.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 21:19:27 +0900




## Depends on

* :heavy_check_mark: <a href="../math/extgcd.cpp.html">math/extgcd.cpp</a>
* :heavy_check_mark: <a href="../math/kitamasa.cpp.html">math/kitamasa.cpp</a>
* :warning: <a href="mint.cpp.html">mod/mint.cpp</a>
* :heavy_check_mark: <a href="../tools/chminmax.cpp.html">tools/chminmax.cpp</a>
* :warning: <a href="../tools/drop.cpp.html">tools/drop.cpp</a>
* :warning: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/discrete_logarithm_mod.test.cpp.html">test/yosupo/discrete_logarithm_mod.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// find x s.t. a^x = b (x >= 0)
template<typename T>
T mod_log(T a,T b,T mod){
  using ll = long long;
  ll g=1;
  {
    ll m=mod;
    while(m){
      g=(ll)g*a%mod;
      m>>=1;
    }
  }
  g=__gcd(g,(ll)mod);
  ll c=0,t=1;
  while(t%g){
    if(t==b) return c;
    t=t*a%mod;
    c++;
  }
  // not found
  if(b%g) return mod;
  t/=g;b/=g;
  const ll n=mod/g;
  ll h=0,gs=1;
  while(h*h<n){
    gs=gs*a%n;
    ++h;
  }
  unordered_map<ll, ll> bs;
  {
    ll s=0,e=b;
    while(s<h){
      e=e*a%n;
      bs[e]=++s;
    }
  }
  {
    ll s=0,e=t;
    while(s<n){
      e=e*gs%n;
      s+=h;
      if(bs.count(e))
        return c+s-bs[e];
    }
  }
  // not found
  return mod;
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "mint.cpp"
#include "../tools/chminmax.cpp"
#include "../math/kitamasa.cpp"
#include "../math/extgcd.cpp"
#include "../tools/drop.cpp"
#include "../tools/fastio.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed CFR536_F(){
  const int MOD = 998244353;
  using M = Mint<int, MOD>;
  using P = Mint<int, MOD-1>;

  int k;
  cin>>k;

  vector<P> bs(k);
  for(int i=0;i<k;i++){
    int b;
    cin>>b;
    bs[i]=P(b);
  }

  int n,m;
  cin>>n>>m;

  reverse(bs.begin(),bs.end());
  Kitamasa<P> ktms(bs);
  vector<P> as(k,0);
  as[k-1]=1;

  int v=ktms.calc(as,--n).v;
  int h=mod_log(3,m,MOD)%(MOD-1);

  if(v!=0||h!=0){
    int g=__gcd(v,h);
    v/=g;
    h/=g;
  }

  if(h!=0&&__gcd(v,MOD-1)!=1){
    cout<<-1<<endl;
    return 0;
  }

  cout<<M(3).pow((long long)h*mod_inverse(v,MOD-1))<<endl;
  return 0;
}
/*
  verified on 2019/10/24
  https://codeforces.com/contest/1106/problem/F
*/

signed BBC002_F(){
  using ll = long long;
  ll n,p;
  cin>>n>>p;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];
  ll x;
  cin>>x;
  if(x==1) drop(0);

  ll s=1;
  for(ll a:as) s=s*a%p;

  const ll INF = 1e18;
  ll ans=INF;
  ll v=1;
  for(int i=0;i<n;i++){
    ll y=x*mod_inverse(v,p)%p;
    ll t=mod_log(s,y,p);
    if(t!=p) chmin(ans,t*n+i);
    v*=as[i];
    v%=p;
  }

  if(ans==INF) drop("Fracture");
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/10/24
  https://www.hackerrank.com/contests/bbc002/challenges/bbc002-f/problem
*/

signed main(){
  //CFR536_F();
  //BBC002_F();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 175, in main
    subcommand_run(paths=[], jobs=parsed.jobs)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 72, in subcommand_run
    onlinejudge_verify.verify.main(paths, marker=marker, timeout=timeout, jobs=jobs)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 71, in main
    exec_command([cxx, *cxxflags, '-I', '.', '-o', shlex.quote(str(directory / 'a.out')), shlex.quote(str(path))])
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 26, in exec_command
    subprocess.check_call(command)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/subprocess.py", line 364, in check_call
    raise CalledProcessError(retcode, cmd)
subprocess.CalledProcessError: Command '['g++', '-std=c++17', '-O2', '-Wall', '-g', '-I', '.', '-o', '.verify-helper/cache/16dac329c1e113b662496f1e7b48d8fa/a.out', 'test/aoj/DPL_5_J.test.cpp']' returned non-zero exit status 1.

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 339, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 119, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: mod/log.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

