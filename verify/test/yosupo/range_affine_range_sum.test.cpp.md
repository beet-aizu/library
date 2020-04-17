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


# :heavy_check_mark: test/yosupo/range_affine_range_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/range_affine_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-12 17:02:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/mod/mint.cpp.html">mod/mint.cpp</a>
* :heavy_check_mark: <a href="../../../library/segtree/basic/chien.cpp.html">segtree/basic/chien.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../segtree/basic/chien.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using M = Mint<int, 998244353>;
  using T = pair<M, M>;
  using E = pair<M, M>;
  auto f=[](T a,T b){return T(a.first+b.first,a.second+b.second);};
  auto g=[](T a,E b){return T(a.first*b.first+a.second*b.second,a.second);};
  auto h=[](E a,E b){return E(a.first*b.first,a.second*b.first+b.second);};
  T ti(0,0);
  E ei(1,0);
  SegmentTree<T, E> seg(f,g,h,ti,ei);

  int n,q;
  cin>>n>>q;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];
  vector<T> vt;
  for(int i=0;i<n;i++) vt.emplace_back(as[i],1);
  seg.build(vt);

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int l,r,b,c;
      cin>>l>>r>>b>>c;
      seg.update(l,r,T(M(b),M(c)));
    }
    if(t==1){
      int l,r;
      cin>>l>>r;
      cout<<seg.query(l,r).first<<"\n";
    }
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/range_affine_range_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 2 "mod/mint.cpp"

#ifndef call_from_test
#line 5 "mod/mint.cpp"
using namespace std;
#endif

//BEGIN CUT HERE
template<typename T,T MOD = 1000000007>
struct Mint{
  static constexpr T mod = MOD;
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}

  Mint pow(long long k){
    Mint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }

  static Mint add_identity(){return Mint(0);}
  static Mint mul_identity(){return Mint(1);}

  Mint inv(){return pow(MOD-2);}

  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}

  Mint operator+(Mint a) const{return Mint(v)+=a;}
  Mint operator-(Mint a) const{return Mint(v)-=a;}
  Mint operator*(Mint a) const{return Mint(v)*=a;}
  Mint operator/(Mint a) const{return Mint(v)/=a;}

  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}

  static Mint comb(long long n,int k){
    Mint num(1),dom(1);
    for(int i=0;i<k;i++){
      num*=Mint(n-i);
      dom*=Mint(i+1);
    }
    return num/dom;
  }
};
template<typename T,T MOD> constexpr T Mint<T, MOD>::mod;
template<typename T,T MOD>
ostream& operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}
//END CUT HERE
#ifndef call_from_test

//INSERT ABOVE HERE
signed ABC127_E(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int h,w,k;
  cin>>h>>w>>k;
  using M = Mint<int>;

  M ans{0};
  for(int d=1;d<h;d++)
    ans+=M(d)*M(h-d)*M(w)*M(w);

  for(int d=1;d<w;d++)
    ans+=M(d)*M(w-d)*M(h)*M(h);

  ans*=M::comb(h*w-2,k-2);
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/06/12
  https://atcoder.jp/contests/abc127/tasks/abc127_e
*/

signed main(){
  //ABC127_E();
  return 0;
}
#endif
#line 1 "segtree/basic/chien.cpp"

#line 3 "segtree/basic/chien.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
template <typename T,typename E>
struct SegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  int n,height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei){}

  void init(int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    dat.assign(2*n,ti);
    laz.assign(2*n,ei);
  }

  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  inline T reflect(int k){
    return laz[k]==ei?dat[k]:g(dat[k],laz[k]);
  }

  inline void propagate(int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    dat[k]=reflect(k);
    laz[k]=ei;
  }

  inline void thrust(int k){
    for(int i=height;i;i--) propagate(k>>i);
  }

  inline void recalc(int k){
    while(k>>=1)
      dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
  }

  void update(int a,int b,E x){
    if(a>=b) return;
    thrust(a+=n);
    thrust(b+=n-1);
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
    recalc(a);
    recalc(b);
  }

  void set_val(int a,T x){
    thrust(a+=n);
    dat[a]=x;laz[a]=ei;
    recalc(a);
  }

  T query(int a,int b){
    if(a>=b) return ti;
    thrust(a+=n);
    thrust(b+=n-1);
    T vl=ti,vr=ti;
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,reflect(l++));
      if(r&1) vr=f(reflect(--r),vr);
    }
    return f(vl,vr);
  }

  template<typename C>
  int find(int st,C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=f(acc,reflect(k));
      return check(acc)?k-n:-1;
    }
    propagate(k);
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

signed CFR569_C(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  vector<int> as(n),bs(m);
  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<m;i++) cin>>bs[i];

  auto f=[](int a,int b){return max(a,b);};
  auto g=[](int a,int b){return a+b;};
  int ti=0,ei=0;
  SegmentTree<int, int> seg(f,g,g,ti,ei);

  const int sz = 1<<20;
  seg.build(vector<int>(sz,0));

  for(int i=0;i<n;i++) seg.update(sz-as[i],sz,+1);
  for(int i=0;i<m;i++) seg.update(sz-bs[i],sz,-1);

  int q;
  cin>>q;
  auto check=[](int d){return d>0;};
  for(int i=0;i<q;i++){
    int t,k,v;
    cin>>t>>k>>v;
    k--;
    if(t==1){
      seg.update(sz-as[k],sz,-1);
      as[k]=v;
      seg.update(sz-as[k],sz,+1);
    }
    if(t==2){
      seg.update(sz-bs[k],sz,+1);
      bs[k]=v;
      seg.update(sz-bs[k],sz,-1);
    }
    int pos=seg.find(0,check);
    cout<<(pos<0?pos:sz-pos)<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/28
  https://codeforces.com/contest/1179/problem/C
*/

signed main(){
  CFR569_C();
  return 0;
}
#endif
#line 9 "test/yosupo/range_affine_range_sum.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using M = Mint<int, 998244353>;
  using T = pair<M, M>;
  using E = pair<M, M>;
  auto f=[](T a,T b){return T(a.first+b.first,a.second+b.second);};
  auto g=[](T a,E b){return T(a.first*b.first+a.second*b.second,a.second);};
  auto h=[](E a,E b){return E(a.first*b.first,a.second*b.first+b.second);};
  T ti(0,0);
  E ei(1,0);
  SegmentTree<T, E> seg(f,g,h,ti,ei);

  int n,q;
  cin>>n>>q;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];
  vector<T> vt;
  for(int i=0;i<n;i++) vt.emplace_back(as[i],1);
  seg.build(vt);

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int l,r,b,c;
      cin>>l>>r>>b>>c;
      seg.update(l,r,T(M(b),M(c)));
    }
    if(t==1){
      int l,r;
      cin>>l>>r;
      cout<<seg.query(l,r).first<<"\n";
    }
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

