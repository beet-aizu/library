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


# :warning: algorithm/parallelbinarysearch.cpp
<a href="../../index.html">Back to top page</a>

* category: algorithm
* <a href="{{ site.github.repository_url }}/blob/master/algorithm/parallelbinarysearch.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-25 17:18:18 +0900




## Dependencies
* :heavy_check_mark: <a href="../datastructure/unionfindtree.cpp.html">datastructure/unionfindtree.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
vector<int> parallelbinarysearch(int n,int q,
                                 function<void(void)> init,
                                 function<void(int)> apply,
                                 function<bool(int)> check){
  vector<vector<int> > C(q);
  vector<int> L(n,-1),R(n,q);
  bool flg=1;
  while(flg){
    flg=0;
    init();
    for(int i=0;i<n;i++)
      if(L[i]+1<R[i]) C[(L[i]+R[i])>>1].emplace_back(i);
    for(int i=0;i<q;i++){
      flg|=!C[i].empty();
      apply(i);
      for(int j:C[i]){
        if(check(j)) R[j]=i;
        else L[j]=i;
      }
      C[i].clear();
    }
  }
  return R;
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../datastructure/unionfindtree.cpp"
#undef call_from_test

signed CODETHANKSFESTIVAL2017_H(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m),b(m);
  for(int i=0;i<m;i++) cin>>a[i]>>b[i];
  int q;
  cin>>q;
  vector<int> x(q),y(q);
  for(int i=0;i<q;i++) cin>>x[i]>>y[i];

  for(int i=0;i<m;i++) a[i]--,b[i]--;
  for(int i=0;i<q;i++) x[i]--,y[i]--;

  UnionFind uf;
  auto init=[&]{uf=UnionFind(n);};
  auto apply=[&](int i){uf.unite(a[i],b[i]);};
  auto check=[&](int i){return uf.same(x[i],y[i]);};

  auto ans=parallelbinarysearch(q,m,init,apply,check);

  for(int i=0;i<q;i++)
    cout<<(ans[i]==m?-1:ans[i]+1)<<endl;

  return 0;
}
/*
  verified on 2019/10/25
  https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h
*/

signed main(){
  CODETHANKSFESTIVAL2017_H();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

