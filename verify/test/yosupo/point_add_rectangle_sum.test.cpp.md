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


# :heavy_check_mark: test/yosupo/point_add_rectangle_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/point_add_rectangle_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-16 17:52:25+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_add_rectangle_sum">https://judge.yosupo.jp/problem/point_add_rectangle_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/segtree/count/dynamic_offline.cpp.html">segtree/count/dynamic_offline.cpp</a>
* :heavy_check_mark: <a href="../../../library/vector/compress.cpp.html">vector/compress.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../vector/compress.cpp"
#include "../../segtree/count/dynamic_offline.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  vector<int> xs(n+q),ys(n+q),ws(n+q);
  for(int i=0;i<n;i++)
    cin>>xs[i]>>ys[i]>>ws[i];

  vector<int> ts(q);
  vector<int> ls(q),ds(q),rs(q),us(q);
  for(int i=0;i<q;i++){
    cin>>ts[i];
    if(ts[i]==0) cin>>xs[n+i]>>ys[n+i]>>ws[n+i];
    if(ts[i]==1) cin>>ls[i]>>ds[i]>>rs[i]>>us[i];
  }

  auto vs=compress(xs);
  auto idx=
    [&](int x){return lower_bound(vs.begin(),vs.end(),x)-vs.begin();};

  using ll = long long;
  RangeCount<ll> seg(vs.size());

  for(int i=0;i<n;i++)
    seg.preupdate(idx(xs[i]),ys[i]);

  for(int i=0;i<q;i++)
    if(ts[i]==0) seg.preupdate(idx(xs[n+i]),ys[n+i]);

  seg.build();

  for(int i=0;i<n;i++)
    seg.update(idx(xs[i]),ys[i],ws[i]);

  for(int i=0;i<q;i++){
    if(ts[i]==0) seg.update(idx(xs[n+i]),ys[n+i],ws[n+i]);
    if(ts[i]==1) cout<<seg.query(idx(ls[i]),idx(rs[i]),ds[i],us[i])<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/point_add_rectangle_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 2 "vector/compress.cpp"

#ifndef call_from_test
#line 5 "vector/compress.cpp"
using namespace std;
#endif

//BEGIN CUT HERE
template<typename V>
V compress(V vs){
  sort(vs.begin(),vs.end());
  vs.erase(unique(vs.begin(),vs.end()),vs.end());
  return vs;
}
template<typename T>
map<T, int> dict(const vector<T> &vs){
  map<T, int> res;
  for(int i=0;i<(int)vs.size();i++)
    res[vs[i]]=i;
  return res;
}
map<char, int> dict(const string &s){
  return dict(vector<char>(s.begin(),s.end()));
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
#line 1 "segtree/count/dynamic_offline.cpp"

#line 3 "segtree/count/dynamic_offline.cpp"
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
#line 9 "test/yosupo/point_add_rectangle_sum.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  vector<int> xs(n+q),ys(n+q),ws(n+q);
  for(int i=0;i<n;i++)
    cin>>xs[i]>>ys[i]>>ws[i];

  vector<int> ts(q);
  vector<int> ls(q),ds(q),rs(q),us(q);
  for(int i=0;i<q;i++){
    cin>>ts[i];
    if(ts[i]==0) cin>>xs[n+i]>>ys[n+i]>>ws[n+i];
    if(ts[i]==1) cin>>ls[i]>>ds[i]>>rs[i]>>us[i];
  }

  auto vs=compress(xs);
  auto idx=
    [&](int x){return lower_bound(vs.begin(),vs.end(),x)-vs.begin();};

  using ll = long long;
  RangeCount<ll> seg(vs.size());

  for(int i=0;i<n;i++)
    seg.preupdate(idx(xs[i]),ys[i]);

  for(int i=0;i<q;i++)
    if(ts[i]==0) seg.preupdate(idx(xs[n+i]),ys[n+i]);

  seg.build();

  for(int i=0;i<n;i++)
    seg.update(idx(xs[i]),ys[i],ws[i]);

  for(int i=0;i<q;i++){
    if(ts[i]==0) seg.update(idx(xs[n+i]),ys[n+i],ws[n+i]);
    if(ts[i]==1) cout<<seg.query(idx(ls[i]),idx(rs[i]),ds[i],us[i])<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

