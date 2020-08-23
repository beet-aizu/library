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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-27 11:09:34+09:00


* see: <a href="https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite">https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/linkcuttree/base.cpp.html">linkcuttree/base.cpp</a>
* :heavy_check_mark: <a href="../../../library/linkcuttree/path.cpp.html">linkcuttree/path.cpp</a>
* :heavy_check_mark: <a href="../../../library/mod/mint.cpp.html">mod/mint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/path.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,q;
  cin>>n>>q;
  vector<int> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];

  using M = Mint<int, 998244353>;

  struct T{
    M a,b;
    T(int a=0,int b=0):a(a),b(b){}
    T(M a,M b):a(a),b(b){}
  };

  auto f=[&](T x,T y){return T(x.a*y.a,x.b*y.a+y.b);};

  using P = pair<T, T>;
  using Node = NodeBase<P, int>;
  auto ff=[&](P a,P b){return P(f(a.first,b.first),f(b.second,a.second));};
  auto gg=[&](P a,int){return a;};
  auto hh=[&](int a,int){return a;};
  auto flip=[&](P a){return P(a.second,a.first);};

  constexpr size_t LIM = 2e5+100;
  using LCT = Path<Node, LIM>;
  LCT lct(ff,gg,hh,flip,0);

  for(int i=0;i<n;i++) lct.create(P(T(as[i],bs[i]),T(as[i],bs[i])));

  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    lct.evert(lct[v]);
    lct.link(lct[u],lct[v]);
  }

  for(int i=0;i<q;i++){
    int t;
    cin>>t;

    if(t==0){
      int u,v,w,x;
      cin>>u>>v>>w>>x;

      lct.evert(lct[u]);
      lct.cut(lct[v]);

      lct.evert(lct[x]);
      lct.link(lct[w],lct[x]);
    }

    if(t==1){
      int p,c,d;
      cin>>p>>c>>d;
      lct.set_val(lct[p],P(T(c,d),T(c,d)));
    }

    if(t==2){
      int u,v,x;
      cin>>u>>v>>x;
      lct.evert(lct[u]);
      auto res=lct.query(lct[v]).first;
      cout<<(res.a*M(x)+res.b).v<<newl;
    }
  }
  return 0;
}

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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 399, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 398, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: linkcuttree/path.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

