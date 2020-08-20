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


# :heavy_check_mark: tree/auxiliarytree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/auxiliarytree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-05 18:15:30+09:00


* see: <a href="https://smijake3.hatenablog.com/entry/2019/09/15/200200">https://smijake3.hatenablog.com/entry/2019/09/15/200200</a>


## Depends on

* :heavy_check_mark: <a href="eulertourforvertex.cpp.html">tree/eulertourforvertex.cpp</a>
* :heavy_check_mark: <a href="lowestcommonancestor.cpp.html">tree/lowestcommonancestor.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/3407.test.cpp.html">test/yukicoder/3407.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "eulertourforvertex.cpp"
#include "lowestcommonancestor.cpp"
#undef call_from_test

#endif
/**
 * @see https://smijake3.hatenablog.com/entry/2019/09/15/200200
 */
//BEGIN CUT HERE
struct AuxiliaryTree : EulerTourForVertex{
  using super = EulerTourForVertex;
  LowestCommonAncestor lca;

  vector<vector<int>> T;
  AuxiliaryTree(){}
  AuxiliaryTree(int n):super(n),lca(n),T(n){}

  void build(int r=0){
    super::build(r);
    lca.G=super::G;
    lca.build(r);
  }

  void add_aux_edge(int u,int v){
    T[u].emplace_back(v);
    T[v].emplace_back(u);
  }

  using super::idx;
  void query(vector<int> &vs){
    assert(!vs.empty());
    sort(vs.begin(),vs.end(),
         [&](int a,int b){return idx(a)<idx(b);});

    map<int, vector<int>> H;

    int k=vs.size();
    stack<int> st;
    st.emplace(vs[0]);
    for(int i=0;i+1<k;i++){
      int w=lca.lca(vs[i],vs[i+1]);
      if(w!=vs[i]){
        int l=st.top();st.pop();
        while(!st.empty()&&lca.dep[w]<lca.dep[st.top()]){
          add_aux_edge(st.top(),l);
          l=st.top();st.pop();
        }
        if(st.empty()||st.top()!=w){
          st.emplace(w);
          vs.emplace_back(w);
        }
        add_aux_edge(w,l);
      }
      st.emplace(vs[i+1]);
    }

    while(st.size()>1){
      int c=st.top();st.pop();
      add_aux_edge(st.top(),c);
    }
  }

  void clear(const vector<int> &ws){
    for(int w:ws) T[w].clear();
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 309, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: tree/auxiliarytree.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

