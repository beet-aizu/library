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


# :heavy_check_mark: graph/independentset.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/independentset.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-26 22:59:22+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2948.test.cpp.html">test/aoj/2948.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/maximum_independent_set.test.cpp.html">test/yosupo/maximum_independent_set.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct IndependentSet{
  int n;
  vector<int> deg,used,dead,pre,ans;
  vector<vector<int> > G;

  IndependentSet(int n):
    n(n),deg(n),used(n,0),dead(n,0),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  int res,cnt,alive;
  void dfs(){
    if(cnt+alive<=res) return;

    int v=-1;
    for(int i=0;i<n;i++){
      if(used[i]||dead[i]) continue;
      if(deg[i]<=1){
        v=i;
        break;
      }
      if(v<0||deg[v]<deg[i]) v=i;
    }
    if(v<0) return;

    if(deg[v]!=1){
      dead[v]=1;
      alive--;
      for(int u:G[v]) deg[u]--;

      dfs();

      dead[v]=0;
      alive++;
      for(int u:G[v]) deg[u]++;
    }
    {
      used[v]=1;
      alive--;
      for(int u:G[v])
        if(0==dead[u]++) alive-=!used[u];
      cnt++;
      if(res<cnt) pre=used;
      res=max(res,cnt);

      dfs();

      used[v]=0;
      alive++;
      for(int u:G[v])
        if(--dead[u]==0) alive+=!used[u];
      cnt--;
    }
  }

  int build(){
    for(int i=0;i<n;i++) deg[i]=G[i].size();
    res=0,cnt=0,alive=n;
    dfs();
    for(int i=0;i<n;i++)
      if(pre[i]) ans.emplace_back(i);
    return res;
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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: graph/independentset.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

