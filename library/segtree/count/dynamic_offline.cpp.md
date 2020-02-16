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


# :heavy_check_mark: segtree/count/dynamic_offline.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8c0b38b9c664244572b7839d3b5c6123">segtree/count</a>
* <a href="{{ site.github.repository_url }}/blob/master/segtree/count/dynamic_offline.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 21:51:08+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2842.test.cpp.html">test/aoj/2842.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/rectangle_sum.test.cpp.html">test/yosupo/rectangle_sum.test.cpp</a>


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
struct RangeCount{
  struct BIT{
    vector<T> dat;
    BIT(){}
    BIT(int n){dat.assign(++n,0);}
    T sum(int k){
      T res=0;
      for(;k;k-=k&-k) res+=dat[k];
      return res;
    }
    void add(int k,T v){
      for(++k;k<(int)dat.size();k+=k&-k) dat[k]+=v;
    }
  };
  int n;
  vector< vector<int> > val;
  vector<BIT> dat;
  RangeCount(){}
  RangeCount(int n_){
    n=1;
    while(n<n_) n<<=1;
    val.assign(n<<1,vector<int>());
    dat.reserve(n<<1);
  }
  void preupdate(int a,int x){
    a+=n;
    while(a){
      val[a].emplace_back(x);
      a>>=1;
    }
  }
  void build(){
    for(int i=0;i<n*2;i++){
      auto &v=val[i];
      sort(v.begin(),v.end());
      v.erase(unique(v.begin(),v.end()),v.end());
      dat.emplace_back(v.size());
    }
  }
  void update(int a,int x,T z){
    a+=n;
    while(a){
      auto &v=val[a];
      int k=lower_bound(v.begin(),v.end(),x)-v.begin();
      dat[a].add(k,z);
      a>>=1;
    }
  }
  T calc(int k,int x,int y){
    auto &v=val[k];
    int p=lower_bound(v.begin(),v.end(),x)-v.begin();
    int q=lower_bound(v.begin(),v.end(),y)-v.begin();
    return dat[k].sum(q)-dat[k].sum(p);
  }
  // [a, b) * [x, y)
  T query(int a,int b,int x,int y){
    T res=0;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
      if(l&1) res+=calc(l++,x,y);
      if(r&1) res+=calc(--r,x,y);
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed YUKI_743(){
  int n,m;
  scanf("%d %d",&n,&m);
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) scanf("%d %d",&a[i],&b[i]);

  RangeCount<int> seg(m);

  for(int i=0;i<n;i++){
    if(a[i]>b[i]) swap(a[i],b[i]);
    seg.preupdate(a[i],b[i]);
  }

  seg.build();

  long long ans=0;
  for(int i=0;i<n;i++){
    ans+=seg.query(0,a[i],a[i],b[i]);
    ans+=seg.query(a[i],b[i],b[i],m);
    seg.update(a[i],b[i],1);
  }

  printf("%lld\n",ans);
  return 0;
}

signed ABC106_D(){
  int n,m,q;
  scanf("%d %d %d",&n,&m,&q);
  vector<int> x(m),y(m);
  for(int i=0;i<m;i++) scanf("%d %d",&x[i],&y[i]);

  RangeCount<int> seg(n+1);
  for(int i=0;i<m;i++) seg.preupdate(x[i],y[i]);
  seg.build();
  for(int i=0;i<m;i++) seg.update(x[i],y[i],1);

  for(int i=0;i<q;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",seg.query(a,b+1,a,b+1));
  }
  return 0;
}

//END CUT HERE
signed main(){
  ABC106_D();
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: segtree/count/dynamic_offline.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

