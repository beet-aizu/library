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


# :warning: mod/lagrange_interpolation.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ad148a3ca8bd0ef3b48c52454c493ec5">mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/mod/lagrange_interpolation.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-18 10:44:32 +0900




## Depends on

* :warning: <a href="mint.cpp.html">mod/mint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#endif
//BEGIN CUT HERE
template<typename M>
M lagrange_interpolation(vector<M> &y,M t){
  int n=y.size()-1;
  if(t.v<=n) return y[t.v];

  vector<M> dp(n+1,1),pd(n+1,1);
  for(int i=0;i<n;i++) dp[i+1]=dp[i]*(t-M(i));
  for(int i=n;i>0;i--) pd[i-1]=pd[i]*(t-M(i));

  vector<M> fact(n+1,1),finv(n+1,1);
  for(int i=1;i<=n;i++) fact[i]=fact[i-1]*M(i);
  finv[n]=M(1)/fact[n];
  for(int i=n;i>=1;i--) finv[i-1]=finv[i]*M(i);

  M res(0);
  for(int i=0;i<=n;i++){
    M tmp=y[i]*dp[i]*pd[i]*finv[i]*finv[n-i];
    if((n-i)&1) res-=tmp;
    else res+=tmp;
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../mod/mint.cpp"
#undef call_from_test

signed ARC033_D(){
  int n;
  scanf("%d",&n);

  using M = Mint<int>;
  vector<M> y(n+1);
  for(int i=0;i<=n;i++) scanf("%d",&y[i].v);

  int t;
  scanf("%d",&t);
  printf("%d\n",lagrange_interpolation(y,M(t)).v);
  return 0;
}
/*
  verified on 2019/12/17
  https://atcoder.jp/contests/arc033/tasks/arc033_4
*/

signed YUKI_042(){
  using M = Mint<int, int(1e9+9)>;
  const int MAX = 666 * 6 + 10;
  vector<M> dp(MAX,0);
  dp[0]=M(1);

  for(int x:{1,5,10,50,100,500})
    for(int j=x;j<MAX;j++) dp[j]+=dp[j-x];

  int T;
  scanf("%d",&T);
  while(T--){
    using ll = long long;
    ll m;
    scanf("%lld",&m);
    vector<M> y(6);
    for(int i=0;i<6;i++) y[i]=dp[(m%500)+(i*500)];
    printf("%d\n",lagrange_interpolation(y,M(m/500)).v);
  }
  return 0;
}
/*
  verified on 2019/12/17
  https://yukicoder.me/problems/no/42
*/

signed main(){
  //ARC033_D();
  //YUKI_042();
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
subprocess.CalledProcessError: Command '['g++', '-std=c++17', '-O2', '-Wall', '-g', '-I', '.', '-o', '.verify-helper/cache/9a267fd1c42d1001b78ef88b806279fc/a.out', 'test/aoj/DPL_5_C.test.cpp']' returned non-zero exit status 1.

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 339, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 119, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: mod/lagrange_interpolation.cpp: line 6: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

