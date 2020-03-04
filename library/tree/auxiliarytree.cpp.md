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
    - Last commit date: 2020-03-04 20:21:28+09:00




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
//BEGIN CUT HERE
struct AuxiliaryTree : EulerTourForVertex{
  using super = EulerTourForVertex;
  LowestCommonAncestor lca;
  AuxiliaryTree(){}
  AuxiliaryTree(int n):super(n),lca(n){}

  void build(int r=0){
    super::build(r);
    lca.G=super::G;
    lca.build(r);
  }

  using super::idx;
  decltype(auto) query(vector<int> &vs){
    assert(!vs.empty());
    sort(vs.begin(),vs.end(),
         [&](int a,int b){return idx(a)<idx(b);});

    map<int, vector<int>> H;

    int k=vs.size();
    stack<int> st;
    st.emplace(vs[0]);
    H[vs[0]];
    for(int i=0;i+1<k;i++){
      int w=lca.lca(vs[i],vs[i+1]);
      if(w!=vs[i]){
        int l=st.top();st.pop();
        while(!st.empty()&&lca.dep[w]<lca.dep[st.top()]){
          H[st.top()].emplace_back(l);
          l=st.top();st.pop();
        }
        if(st.empty()||st.top()!=w){
          st.emplace(w);
          vs.emplace_back(w);
        }
        H[w].emplace_back(l);
      }
      st.emplace(vs[i+1]);
      H[vs[i+1]];
    }

    while(st.size()>1){
      int c=st.top();st.pop();
      H[st.top()].emplace_back(c);
    }

    return make_pair(st.top(),H);
  }
};
//END CUT HERE
#ifndef call_from_test

signed main(){
  int n;
  cin>>n;

  AuxiliaryTree G(n);
  vector<map<int, int>> ws(n);
  for(int i=1;i<n;i++){
    int u,v,w;
    cin>>u>>v>>w;
    G.add_edge(u,v);
    ws[u][v]=ws[v][u]=w;
  }
  G.build();

  using ll = long long;
  vector<ll> dep(n,-1);
  queue<int> que;
  dep[0]=0;
  que.emplace(0);
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int u:G.G[v]){
      if(~dep[u]) continue;
      dep[u]=dep[v]+ws[v][u];
      que.emplace(u);
    }
  }

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int k;
    cin>>k;
    vector<int> vs(k);
    for(int j=0;j<k;j++) cin>>vs[j];

    auto H=G.query(vs).second;
    ll ans=0;
    for(int v:vs)
      for(int u:H[v])
        ans+=dep[u]-dep[v];

    cout<<ans<<"\n";
  }
  cout<<flush;
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 68, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: tree/eulertourforvertex.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

