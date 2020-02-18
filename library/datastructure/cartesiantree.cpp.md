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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: datastructure/cartesiantree.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

