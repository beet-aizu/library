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


# :heavy_check_mark: algorithm/mo.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ed469618898d75b149e5c7c4b6a1c415">algorithm</a>
* <a href="{{ site.github.repository_url }}/blob/master/algorithm/mo.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-07 20:09:06+09:00




## Depends on

* :heavy_check_mark: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>
* :heavy_check_mark: <a href="../tree/eulertourforedge.cpp.html">tree/eulertourforedge.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0425.test.cpp.html">test/aoj/0425.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Mo{
  using F = function<void(int)>;
  vector<int> ls,rs,ord;
  int n,width,nl,nr,ptr;
  F expandL,expandR;
  F shrinkL,shrinkR;

  Mo(int n,int width,F expandL,F expandR,F shrinkL,F shrinkR):
    n(n),width(width),nl(0),nr(0),ptr(0),
    expandL(expandL),expandR(expandR),
    shrinkL(shrinkL),shrinkR(shrinkR){}

  Mo(int n,int width,F expand,F shrink){
    *this=Mo(n,width,expand,expand,shrink,shrink);
  }

  void add(int l,int r){
    ls.emplace_back(l);
    rs.emplace_back(r);
  }

  void build(){
    ord.resize(ls.size());
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),
         [&](int a,int b){
           if(ls[a]/width!=ls[b]/width) return ls[a]<ls[b];
           if(rs[a]==rs[b]) return ls[a]<ls[b];
           return bool((rs[a]<rs[b])^((ls[a]/width)&1));
         });
  }

  int process(){
    if(ptr==(int)ord.size()) return -1;
    const int idx=ord[ptr++];
    while(nl>ls[idx]) expandL(--nl);
    while(nr<rs[idx]) expandR(nr++);
    while(nl<ls[idx]) shrinkL(nl++);
    while(nr>rs[idx]) shrinkR(--nr);
    return idx;
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../tree/eulertourforedge.cpp"
#undef call_from_test

//INSERT ABOVE HERE
// Mo on Tree
signed ABC133_F(){
  int n,q;
  cin>>n>>q;
  vector<int> as(n),bs(n),cs(n),ds(n);
  vector<int> xs(q),ys(q),us(q),vs(q);

  EulerTourForEdge et(n);
  for(int i=1;i<n;i++){
    cin>>as[i]>>bs[i]>>cs[i]>>ds[i];
    as[i]--;bs[i]--;
    et.add_edge(as[i],bs[i]);
  }
  et.build();

  vector<int> idx(n,0);
  for(int i=1;i<n;i++)
    idx[et.child(as[i],bs[i])]=i;

  for(int i=0;i<q;i++){
    cin>>xs[i]>>ys[i]>>us[i]>>vs[i];
    us[i]--;vs[i]--;
  }

  int all=0;
  vector<int> cnt(n),sum(n),app(n,0);
  auto exec=
    [&](int k){
      int v=et.bottom(k);
      int e=idx[v];
      app[v]^=1;
      if(app[v]){
        all+=ds[e];
        cnt[cs[e]]++;
        sum[cs[e]]+=ds[e];
      }else{
        all-=ds[e];
        cnt[cs[e]]--;
        sum[cs[e]]-=ds[e];
      }
    };
  Mo mo(n*2,400,exec,exec);

  for(int i=0;i<q;i++){
    auto f=[&](int l,int r){mo.add(min(l,r),max(l,r));};
    et.query(us[i],vs[i],f);
  }
  mo.build();

  vector<int> ans(q,0);
  for(int i=0;i<q;i++){
    int k=mo.process();
    ans[k]=all-sum[xs[k]]+cnt[xs[k]]*ys[k];
  }

  for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/11/12
  https://atcoder.jp/contests/abc133/tasks/abc133_f
*/

signed main(){
  //ABC133_F();
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algorithm/mo.cpp: line 54: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

