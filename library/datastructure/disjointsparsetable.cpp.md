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


# :heavy_check_mark: datastructure/disjointsparsetable.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/disjointsparsetable.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-26 23:22:59+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.disjointsparsetable.test.cpp.html">test/aoj/DSL_3_D.disjointsparsetable.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/staticrmq.disjointsparsetable.test.cpp.html">test/yosupo/staticrmq.disjointsparsetable.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct DisjointSparseTable{
  using F = function<T(T, T)>;
  vector< vector<T> > dat;
  vector<int> ht;
  const F f;

  DisjointSparseTable(){}
  DisjointSparseTable(F f):f(f){}

  void build(const vector<T> &vs){
    int n=vs.size(),h=1;
    while((1<<h)<=n) h++;
    dat.assign(h,vector<T>(n));
    ht.assign((1<<h)+1,0);
    for(int j=2;j<(1<<h)+1;j++) ht[j]=ht[j>>1]+1;

    for(int j=0;j<n;j++) dat[0][j]=vs[j];
    for(int i=1;i<h;i++){
      int s=1<<i;
      for(int j=0;j<n;j+=s<<1){
        int t=min(j+s,n);
        dat[i][t-1]=vs[t-1];
        for(int k=t-2;k>=j;k--) dat[i][k]=f(vs[k],dat[i][k+1]);
        if(n<=t) break;
        dat[i][t]=vs[t];
        int r=min(t+s,n);
        for(int k=t+1;k<r;k++) dat[i][k]=f(dat[i][k-1],vs[k]);
      }
    }
  }

  T query(int l,int r){
    if(l>=--r) return dat[0][l];
    return f(dat[ht[l^r]][l],dat[ht[l^r]][r]);
  }

};
//END CUT HERE
#ifndef call_from_test

// find with non-idempotent monoid
signed CODECHEF_SEGPROD(){
  int T;
  scanf("%d",&T);

  int p;
  auto f=[&](int a,int b)->int{return (long long)a*b%p;};
  DisjointSparseTable<int> dst(f);

  for(int t=1;t<=T;t++){
    int n,q;
    scanf("%d %d %d",&n,&p,&q);
    vector<int> v(n);
    for(int i=0;i<n;i++) scanf("%d",&v[i]),v[i]%=p;
    vector<int> b(q/64+2);
    for(int i=0;i<(q/64+2);i++) scanf("%d",&b[i]);

    dst.build(v);

    int x=0,l=0,r=0;
    for(int i=0;i<q;i++){
      if(i%64==0){
        l=(b[i/64]+x)%n;
        r=(b[i/64+1]+x)%n;
      }else{
        l=(l+x)%n;
        r=(r+x)%n;
      }
      if(l>r) swap(l,r);
      x=dst.query(l,r+1)+1;
      if(x>=p) x-=p;
    }
    printf("%d\n",x);
  }
  return 0;
}
/*
  verified on 2019/10/29
  https://www.codechef.com/problems/SEGPROD
*/

//INSERT ABOVE HERE
signed main(){
  //CODECHEF_SEGPROD();
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: datastructure/disjointsparsetable.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

