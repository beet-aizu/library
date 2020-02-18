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


# :warning: tree/construct_from_distances_to_farthest_vertex.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/construct_from_distances_to_farthest_vertex.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 15:04:21+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
vector< vector<int> >
construct_from_distances_to_farthest_vertex(vector<int> ds){
  int n=ds.size();
  vector<vector<int>> G(n),NG;
  for(int d:ds) if(d>=n) return NG;

  vector<int> ts(n,0);
  vector<queue<int>> qs(n);
  for(int i=0;i<n;i++){
    ts[ds[i]]++;
    qs[ds[i]].emplace(i);
  }

  int dm=*max_element(ds.begin(),ds.end());

  for(int i=0;i<(dm+1)/2;i++)
    if(ts[dm-i]<2) return NG;

  if(ts[dm/2+(dm&1)]!=1+(dm&1)) return NG;

  for(int d:ds)
    if(d<(dm+1)/2) return NG;

  auto add_edge=
    [&](int x,int y){
      G[x].emplace_back(y);
      G[y].emplace_back(x);
    };

  vector<int> xs(n),ys(n);
  for(int i=0;i<(dm+1)/2;i++){
    xs[dm-i]=qs[dm-i].front();qs[dm-i].pop();
    ys[dm-i]=qs[dm-i].front();qs[dm-i].pop();
    if(i){
      add_edge(xs[dm-i+1],xs[dm-i]);
      add_edge(ys[dm-i+1],ys[dm-i]);
    }
  }

  if(dm&1){
    add_edge(xs[dm/2+1],ys[dm/2+1]);
  }else{
    xs[dm/2]=qs[dm/2].front();qs[dm/2].pop();
    add_edge(xs[dm/2+1],xs[dm/2]);
    add_edge(ys[dm/2+1],xs[dm/2]);
  }

  for(int i=0;i<n;i++){
    if(!G[i].empty()) continue;
    add_edge(i,xs[ds[i]-1]);
  }
  return G;
}
//END CUT HERE
#ifndef call_from_test
class TreeDistanceConstruction {
public:
  vector<int> construct(vector<int> ds) {
    auto G=construct_from_distances_to_farthest_vertex(ds);
    if(G.empty()) return {};
    vector<int> bs;
    for(int i=0;i<(int)G.size();i++)
      for(int j:G[i])
        if(i<j) bs.emplace_back(i),bs.emplace_back(j);
    return bs;
  }
};
/*
  verified on 2019/12/10
  https://vjudge.net/problem/TopCoder-14468
*/
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: tree/construct_from_distances_to_farthest_vertex.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

