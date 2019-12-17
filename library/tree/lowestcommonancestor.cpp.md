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


# :heavy_check_mark: tree/lowestcommonancestor.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/lowestcommonancestor.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-09 10:45:08 +0900




## Required by

* :heavy_check_mark: <a href="eulertourforvertex.cpp.html">tree/eulertourforvertex.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_C.lowestcommonancestor.test.cpp.html">test/aoj/GRL_5_C.lowestcommonancestor.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/lca.test.cpp.html">test/yosupo/lca.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
struct LowestCommonAncestor{
  int n,h;
  vector< vector<int> > G,par;
  vector<int> dep;
  LowestCommonAncestor(){}
  LowestCommonAncestor(int n):n(n),G(n),dep(n){
    h=1;
    while((1<<h)<=n) h++;
    par.assign(h,vector<int>(n,-1));
  }

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void dfs(int v,int p,int d){
    par[0][v]=p;
    dep[v]=d;
    for(int u:G[v])
      if(u!=p) dfs(u,v,d+1);
  }

  void build(int r=0){
    dfs(r,-1,0);
    for(int k=0;k+1<h;k++)
      for(int v=0;v<n;v++)
        if(~par[k][v])
          par[k+1][v]=par[k][par[k][v]];
  }

  int lca(int u,int v){
    if(dep[u]>dep[v]) swap(u,v);
    for(int k=0;k<h;k++)
      if((dep[v]-dep[u])>>k&1)
        v=par[k][v];

    if(u==v) return u;

    for(int k=h-1;k>=0;k--)
      if(par[k][u]!=par[k][v])
        u=par[k][u],v=par[k][v];

    return par[0][u];
  }

  int distance(int u,int v){
    return dep[u]+dep[v]-dep[lca(u,v)]*2;
  }
};
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
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 173, in main
    subcommand_run(paths=[])
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 70, in subcommand_run
    onlinejudge_verify.verify.main(paths, marker=marker, timeout=timeout)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 87, in main
    exec_command(command)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 26, in exec_command
    subprocess.check_call(command)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/subprocess.py", line 364, in check_call
    raise CalledProcessError(retcode, cmd)
subprocess.CalledProcessError: Command '['oj', 'test', '-c', '.verify-helper/cache/c36a49005ac83bc17634badc8dd1bcb9/a.out', '-d', '.verify-helper/cache/c36a49005ac83bc17634badc8dd1bcb9/test', '-e', '\'"1e-8"\'']' returned non-zero exit status 2.

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 345, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 125, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: tree/lowestcommonancestor.cpp: line 6: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

