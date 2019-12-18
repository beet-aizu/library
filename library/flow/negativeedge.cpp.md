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


# :heavy_check_mark: flow/negativeedge.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cff5497121104c2b8e0cb41ed2083a9b">flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/flow/negativeedge.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 20:42:16 +0900




## Depends on

* :heavy_check_mark: <a href="primaldual.cpp.html">flow/primaldual.cpp</a>
* :heavy_check_mark: <a href="../tools/chminmax.cpp.html">tools/chminmax.cpp</a>
* :warning: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2230.test.cpp.html">test/aoj/2230.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2627.test.cpp.html">test/aoj/2627.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2872.test.cpp.html">test/aoj/2872.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "primaldual.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename TF,typename TC>
struct NegativeEdge{
  PrimalDual<TF, TC> G;
  vector<TF> fs;
  TC sum;
  int S,T;
  NegativeEdge(){}
  NegativeEdge(int n):G(n+2),fs(n+2,0),sum(0),S(n),T(n+1){}

  void use_edge(int u,int v,TF cap,TC cost){
    fs[u]-=cap;
    fs[v]+=cap;
    sum=sum+cost*cap;
  }

  void add_edge(int u,int v,TF cap,TC cost){
    if(cost<TC(0)){
      use_edge(u,v,cap,cost);
      swap(u,v);
      cost=-cost;
    }
    G.add_edge(u,v,cap,cost);
  }

  TC flow(int &ok){
    TF f=0;
    for(int i=0;i<S;i++){
      if(fs[i]>0){
        f+=fs[i];
        G.add_edge(S,i,+fs[i],TC(0));
      }
      if(fs[i]<0){
        G.add_edge(i,T,-fs[i],TC(0));
      }
    }
    return sum+G.flow(S,T,f,ok);
  }

  TC flow(int ts,int tt,TF tf,int &ok){
    fs[ts]+=tf;
    fs[tt]-=tf;
    return flow(ok);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../tools/chminmax.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed CFR190_B(){
  using ll = long long;

  int n,m;
  cin>>n>>m;
  vector<string> vp(n);
  vector<int> vs(n);
  for(int i=0;i<n;i++) cin>>vp[i]>>vs[i];
  vector<int> ss(m);
  for(int i=0;i<m;i++) cin>>ss[i];

  int S=n+m,T=n+m+1;
  NegativeEdge<ll, ll> G(n+m+2);

  for(int i=0;i<m;i++){
    G.add_edge(S,i,1,0);
    for(int j=0;j<n;j++){
      if(vp[j]=="ATK"){
        if(ss[i]>=vs[j]) G.add_edge(i,m+j,1,vs[j]-ss[i]);
      }
      if(vp[j]=="DEF"){
        if(ss[i]> vs[j]) G.add_edge(i,m+j,1,0);
      }
    }
  }

  auto H=G;
  for(int i=0;i<m;i++){
    G.add_edge(i,T,1,-ss[i]);
    H.add_edge(i,T,1,0);
  }

  for(int j=0;j<n;j++){
    G.use_edge(m+j,T,1,0);
    H.add_edge(m+j,T,1,0);
  }

  int ok;
  ll ans=0;
  if(n<m){
    ll gv=G.flow(S,T,m,ok);
    if(ok) chmin(ans,gv);
  }
  ll hv=H.flow(S,T,m,ok);
  if(ok) chmin(ans,hv);

  cout<<-ans<<endl;
  return 0;
}
/*
  verified on 2019/10/13
  https://codeforces.com/contest/321/problem/B
*/

signed KUPC2019_H(){
  int n,m;
  cin>>n>>m;
  NegativeEdge<int, int> G(n+2);

  int cap=1;
  for(int i=0;i<m;i++){
    int u,v,l;
    cin>>u>>v>>l;
    u--;v--;
    G.add_edge(v,u,1,l-1);
    if(l==0) cap++;
  }

  for(int i=0;i<n;i++){
    G.add_edge(n,i,cap,2);
    G.add_edge(i,n,cap,0);
  }

  int ok=0;
  cout<<-G.flow(n,n,0,ok)<<endl;
  return 0;
}
/*
  verified on 2019/10/24
  https://atcoder.jp/contests/kupc2019/tasks/kupc2019_h
*/

signed main(){
  //CFR190_B();
  KUPC2019_H();
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
onlinejudge_verify.bundle.BundleError: primaldual.cpp: line -1: no such header

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

