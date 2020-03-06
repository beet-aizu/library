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


# :x: test/aoj/GRL_5_A.linkcuttree.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_5_A.linkcuttree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-06 19:09:15+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/linkcuttree/base.cpp.html">linkcuttree/base.cpp</a>
* :heavy_check_mark: <a href="../../../library/linkcuttree/farthest.cpp.html">linkcuttree/farthest.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/chminmax.cpp.html">tools/chminmax.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/farthest.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using Node = NodeBase<int>;
  constexpr size_t LIM = 2e6 + 200;
  using LCT = Farthest<Node, LIM>;
  LCT lct;

  vector<LCT::Node*> vs(1e5+100);
  vector<LCT::Node*> es(1e5+100);

  int n;
  cin>>n;
  for(int i=0;i<n;i++) vs[i]=lct.create(0);

  for(int i=1;i<n;i++){
    int s,t,w;
    cin>>s>>t>>w;
    es[i]=lct.create(w);
    lct.evert(vs[s]);
    lct.evert(vs[t]);
    lct.link(es[i],vs[s]);
    lct.link(es[i],vs[t]);
  }

  int ans=0;
  for(int i=0;i<n;i++){
    lct.evert(vs[i]);
    chmax(ans,vs[i]->ld);
  }

  cout<<ans<<endl;
  return 0;
}

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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: linkcuttree/base.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
