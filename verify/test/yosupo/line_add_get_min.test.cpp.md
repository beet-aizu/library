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


# :heavy_check_mark: test/yosupo/line_add_get_min.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/line_add_get_min.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-05 21:15:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/line_add_get_min">https://judge.yosupo.jp/problem/line_add_get_min</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/segtree/cht/lichao.cpp.html">segtree/cht/lichao.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/compress.cpp.html">tools/compress.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/compress.cpp"
#include "../../segtree/cht/lichao.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  int n,q;
  cin>>n>>q;
  vector<ll> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];

  vector<ll> ts(q),xs(q),ys(q);
  vector<ll> ps;
  for(int i=0;i<q;i++){
    cin>>ts[i];
    if(ts[i]==0) cin>>xs[i]>>ys[i];
    if(ts[i]==1){
      cin>>xs[i];
      ps.emplace_back(xs[i]);
    }
  }

  LiChao<ll, true> seg(compress(ps));
  for(int i=0;i<n;i++) seg.addLine(as[i],bs[i]);
  for(int i=0;i<q;i++){
    if(ts[i]==0) seg.addLine(xs[i],ys[i]);
    if(ts[i]==1) cout<<seg.query(xs[i])<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/line_add_get_min.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "tools/compress.cpp"

#line 3 "tools/compress.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
template<typename V>
V compress(V v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}
template<typename T>
map<T, int> dict(const vector<T> &v){
  map<T, int> res;
  for(int i=0;i<(int)v.size();i++)
    res[v[i]]=i;
  return res;
}
map<char, int> dict(const string &v){
  return dict(vector<char>(v.begin(),v.end()));
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
#line 1 "segtree/cht/lichao.cpp"

#line 3 "segtree/cht/lichao.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
template <typename T, bool isMin>
struct LiChao{
  static constexpr T INF = numeric_limits<T>::max();
  struct Line{
    T a,b;
    Line(T a,T b):a(a),b(b){}
    T get(T x){return a*x+b;}
  };

  int n;
  vector<T> pos;
  vector<Line> dat;
  LiChao(int n){
    pos.resize(n);
    iota(pos.begin(),pos.end(),T(0));
    init(n);
  }

  LiChao(const vector<T> &pos):pos(pos){init(pos.size());}

  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    while((int)pos.size()<n)
      pos.emplace_back(T(pos.back()+1));
    dat.assign(2*n,Line(0,-INF));
  }

  void addLine(T a,T b){
    if(isMin) a=-a,b=-b;
    Line x(a,b);
    update(1,0,n-1,x);
  }

  T query(T x){
    int t=lower_bound(pos.begin(),pos.end(),x)-pos.begin();
    if(isMin) return -query(1,0,n-1,t);
    return query(1,0,n-1,t);
  }

  inline bool over(Line &a,Line &b,T lb,T ub){
    return a.get(lb)>=b.get(lb)&&a.get(ub)>=b.get(ub);
  }

  void update(int k,int l,int r,Line &x){
    T lb=pos[l],ub=pos[r];
    if(over(dat[k],x,lb,ub)) return;
    if(over(x,dat[k],lb,ub)){
      dat[k]=x;
      return;
    }
    int c=(l+r)>>1;
    if(dat[k].get(pos[c])<x.get(pos[c])) swap(dat[k],x);
    if(dat[k].get(lb)<=x.get(lb)) update((k<<1)|0,l,c,x);
    else update((k<<1)|1,c+1,r,x);
  }

  T query(int k,int l,int r,int t){
    T res=dat[k].get(pos[t]);
    if(l==r) return res;
    int c=(l+r)>>1;
    if(t<=c) return max(res,query((k<<1)|0,l,c,t));
    return max(res,query((k<<1)|1,c+1,r,t));
  }
};
template <typename T, bool isMin>
constexpr T LiChao<T, isMin>::INF;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
#line 9 "test/yosupo/line_add_get_min.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  int n,q;
  cin>>n>>q;
  vector<ll> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];

  vector<ll> ts(q),xs(q),ys(q);
  vector<ll> ps;
  for(int i=0;i<q;i++){
    cin>>ts[i];
    if(ts[i]==0) cin>>xs[i]>>ys[i];
    if(ts[i]==1){
      cin>>xs[i];
      ps.emplace_back(xs[i]);
    }
  }

  LiChao<ll, true> seg(compress(ps));
  for(int i=0;i<n;i++) seg.addLine(as[i],bs[i]);
  for(int i=0;i<q;i++){
    if(ts[i]==0) seg.addLine(xs[i],ys[i]);
    if(ts[i]==1) cout<<seg.query(xs[i])<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

