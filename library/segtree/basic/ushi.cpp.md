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


# :warning: segtree/basic/ushi.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d554a8ac704505de7b361b88fc36eeb2">segtree/basic</a>
* <a href="{{ site.github.repository_url }}/blob/master/segtree/basic/ushi.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 13:36:48 +0900




## Required by

* :warning: <a href="../../linearalgebra/squarematrix.cpp.html">linearalgebra/squarematrix.cpp</a>
* :heavy_check_mark: <a href="../../tree/heavylightdecomposition.cpp.html">tree/heavylightdecomposition.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2644.test.cpp.html">test/aoj/2644.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_A.test.cpp.html">test/aoj/DSL_2_A.test.cpp</a>
* :warning: <a href="../../../verify/test/yosupo/point_set_range_composite.test.cpp.html">test/yosupo/point_set_range_composite.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;

  SegmentTree(){}
  SegmentTree(F f,T ti):f(f),ti(ti){}

  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }

  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  void set_val(int k,T x){
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }

  T query(int a,int b){
    if(a>=b) return ti;
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }

  template<typename C>
  int find(int st,C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=f(acc,dat[k]);
      return check(acc)?k-n:-1;
    }
    int m=(l+r)>>1;
    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);
    if(st<=l&&!check(f(acc,dat[k]))){
      acc=f(acc,dat[k]);
      return -1;
    }
    int vl=find(st,check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return find(st,check,acc,(k<<1)|1,m,r);
  }
  template<typename C>
  int find(int st,C &check){
    T acc=ti;
    return find(st,check,acc,1,0,n);
  }
};
//END CUT HERE
#ifndef call_from_test

signed ARC038_C(){
  int n;
  scanf("%d",&n);
  vector<int> cs(n),as(n);
  for(int i=1;i<n;i++) scanf("%d %d",&cs[i],&as[i]);

  const int INF = 1e9;
  auto f=[](int a,int b){return min(a,b);};
  SegmentTree<int> seg(f,INF);
  seg.build(vector<int>(n,-1));

  vector<int> dp(n);
  dp[0]=0;
  seg.set_val(0,0);
  for(int i=1;i<n;i++){
    auto check=[&](int x){return x<i-cs[i];};
    dp[i]=seg.find(0,check);
    seg.set_val(dp[i],max(seg.query(dp[i],dp[i]+1),i));
  }

  int ans=0;
  for(int i=1;i<n;i++)
    if(as[i]&1) ans^=dp[i];

  puts(ans?"First":"Second");
  return 0;
}
/*
  verified on 2019/06/26
  https://atcoder.jp/contests/arc038/tasks/arc038_c
*/

signed KUPC2013_D(){
  int n;
  scanf("%d",&n);
  vector<int> as(n+2,0);
  for(int i=1;i<=n;i++) scanf("%d",&as[i]);

  const int INF = 1.1e9;
  auto f=[](int a,int b){return min(a,b);};
  SegmentTree<int> seg(f,INF);
  seg.build(as);

  using P = pair<int, int>;
  set<P> sp;
  for(int k=0;k<2;k++){
    for(int i=1;i<=n;i++){
      auto check=[&](int x){return x<as[i];};
      int l=seg.find(i,check);
      sp.emplace(k?n+2-l:l,as[i]);
    }
    reverse(as.begin(),as.end());
    seg.build(as);
  }

  printf("%d\n",(int)sp.size()/2);
  return 0;
}
/*
  verified on 2019/06/26
  https://atcoder.jp/contests/kupc2013/tasks/kupc2013_d
*/

signed ABC130_D(){
  using ll = long long;
  ll n,k;
  cin>>n>>k;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto f=[](ll a,ll b){return a+b;};
  SegmentTree<ll> seg(f,0);
  seg.build(as);

  ll ans=0;
  auto check=[&](ll d){return d>=k;};
  for(int i=0;i<n;i++){
    int idx=seg.find(i,check);
    if(~idx) ans+=n-idx;
  }

  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/06/26
  https://atcoder.jp/contests/abc130/tasks/abc130_d
*/

signed main(){
  //ARC038_C();
  //KUPC2013_D();
  //ABC130_D();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 345, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 125, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: segtree/basic/ushi.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

