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


# :heavy_check_mark: math/linearcongruence.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/linearcongruence.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 21:19:27 +0900




## Depends on

* :heavy_check_mark: <a href="extgcd.cpp.html">math/extgcd.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2659.test.cpp.html">test/aoj/2659.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2970.test.cpp.html">test/aoj/2970.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "extgcd.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T>
pair<T, T> linear_congruence(const vector<T> &A,
                             const vector<T> &B,
                             const vector<T> &M){
  T x=0,m=1;
  for(int i=0;i<(int)A.size();i++){
    T a=A[i]*m,b=B[i]-A[i]*x,d=__gcd(M[i],a);
    if(b%d!=0) return make_pair(0,-1);
    T t=b/d*mod_inverse(a/d,M[i]/d)%(M[i]/d);
    x=x+m*t;
    m*=M[i]/d;
  }
  return make_pair((x%m+m)%m,m);
}
//END CUT HERE
#ifndef call_from_test

int is_prime(int x){
  if(x<=1) return 0;
  for(int i=2;i*i<=x;i++)
    if(x%i==0) return 0;
  return 1;
}

signed DDCC2018QUALB_D(){
  using ll = long long;
  const int n = 30;
  vector<ll> A,B,M;

  vector<ll> xs(n+1);
  for(int i=2;i<=n;i++){
    cin>>xs[i];
    if(!is_prime(i-1)) continue;
    A.emplace_back(1);
    B.emplace_back(xs[i]%(i-1));
    M.emplace_back(i-1);
  }
  auto p=linear_congruence(A,B,M);
  if(p.second<int(0)){
    cout<<"invalid"s<<endl;
    return 0;
  }
  ll LIM=1e12;
  ll res=p.first,dif=p.second;
  while(res<=LIM){
    int flg=1;
    for(int i=2;i<=n;i++){
      ll sum=0,tmp=res;
      while(tmp>int(0)){
        sum+=tmp%i;
        tmp/=int(i);
      }
      flg&=(sum==xs[i]);
    }
    if(flg){
      cout<<res<<endl;
      return 0;
    }
    res+=dif;
  }
  cout<<"invalid"s<<endl;
  return 0;
}
/*
   verified on 2019/10/25
   https://atcoder.jp/contests/ddcc2019-qual/tasks/ddcc2018_qual_d
*/

signed YUKI_186(){
  using ll = long long;
  vector<ll> A(3,1),B(3),M(3);
  for(int i=0;i<3;i++) cin>>B[i]>>M[i];
  auto p=linear_congruence(A,B,M);
  if(p.second==-1) cout<<-1<<endl;
  else cout<<(p.first?p.first:p.second)<<endl;
  return 0;
}
/*
   verified on 2019/10/25
   https://yukicoder.me/problems/no/186
*/

//INSERT ABOVE HERE
signed main(){
  //DDCC2018QUALB_D();
  //YUKI_186();
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
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 150, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 52, in _resolve
    raise BundleError(path, -1, "no such header")
onlinejudge_verify.bundle.BundleError: extgcd.cpp: line -1: no such header

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

