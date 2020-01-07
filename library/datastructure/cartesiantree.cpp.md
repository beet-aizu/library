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


# :heavy_check_mark: datastructure/cartesiantree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/cartesiantree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 21:09:31+09:00




## Depends on

* :heavy_check_mark: <a href="../tools/chminmax.cpp.html">tools/chminmax.cpp</a>
* :heavy_check_mark: <a href="../tree/lca.cpp.html">tree/lca.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.cartesiantree.test.cpp.html">test/aoj/DSL_3_D.cartesiantree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct CartesianTree{
  vector<int> P,L,R;

  template<typename T>
  int build(vector<T> vs){
    int n=vs.size();
    P=L=R=vector<int>(n,-1);
    int p=0;
    for(int i=1;i<n;i++){
      if(vs[p]<=vs[i]){
        R[p]=i;
        P[i]=p;
        p=i;
        continue;
      }
      while(~P[p]&&vs[i]<vs[P[p]]) p=P[p];
      P[i]=P[p];
      if(~P[i]) R[P[i]]=i;
      L[i]=p;
      P[p]=i;
      p=i;
    }
    while(~P[p]) p=P[p];
    return p;
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tree/lca.cpp"
#include "../tools/chminmax.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed SPOJ_ADAPLANT(){
  int T;
  scanf("%d",&T);
  while(T--){
    int n,l;
    scanf("%d %d",&n,&l);
    vector<int> v(n);
    for(int i=0;i<n;i++) scanf("%d",&v[i]);

    const int BS=1e9+100;
    vector<int> w(n);
    for(int i=0;i<n;i++) w[i]=BS-v[i];

    CartesianTree ct1,ct2;
    int r1=ct1.build(v);
    int r2=ct2.build(w);


    LCA lca1(n),lca2(n);
    for(int i=0;i<n;i++){
      if(~ct1.P[i]) lca1.add_edge(i,ct1.P[i]);
      if(~ct2.P[i]) lca2.add_edge(i,ct2.P[i]);
    }
    lca1.build(r1);
    lca2.build(r2);

    l++;
    chmin(l,n-1);

    int ans=0;
    for(int i=0;i+l<n;i++){
      int x=v[lca1.lca(i,i+l)];
      int y=BS-w[lca2.lca(i,i+l)];
      chmax(ans,y-x);
    }

    printf("%d\n",ans);
  }
  return 0;
}
/*
  verified on 2019/10/24
  https://www.spoj.com/problems/ADAPLANT/
*/

signed main(){
  SPOJ_ADAPLANT();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 173, in main
    subcommand_run(paths=[], jobs=parsed.jobs)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 66, in subcommand_run
    onlinejudge_verify.verify.main(paths, marker=marker, timeout=timeout, jobs=jobs)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 98, in main
    exec_command([cxx, *shlex.split(utils.CXXFLAGS), '-I', '.', '-o', shlex.quote(str(directory / 'a.out')), shlex.quote(str(path))])
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 26, in exec_command
    subprocess.check_call(command)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/subprocess.py", line 364, in check_call
    raise CalledProcessError(retcode, cmd)
subprocess.CalledProcessError: Command '['g++', '--std=c++17', '-O2', '-Wall', '-g', '-I', '.', '-o', '.verify-helper/cache/988b27744f33205dfbbff10b1fb99080/a.out', 'test/aoj/3120.test.cpp']' returned non-zero exit status 1.

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: datastructure/cartesiantree.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

