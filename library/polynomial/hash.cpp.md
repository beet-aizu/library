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


# :heavy_check_mark: polynomial/hash.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#89693d3333328e76f4fdeed379e8f9ea">polynomial</a>
* <a href="{{ site.github.repository_url }}/blob/master/polynomial/hash.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 16:09:50+09:00




## Depends on

* :heavy_check_mark: <a href="../mod/mint.cpp.html">mod/mint.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/1630.test.cpp.html">test/aoj/1630.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2971.test.cpp.html">test/aoj/2971.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../mod/mint.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T,typename M1,typename M2,typename M3>
struct PolynomialHash{
  struct V{
    M1 v1;
    M2 v2;
    M3 v3;
    V(){}
    V(int x):v1(x),v2(x),v3(x){}
    V(long long x):v1(x),v2(x),v3(x){}
    V(M1 v1,M2 v2,M3 v3):v1(v1),v2(v2),v3(v3){}

    V& operator+=(V a){v1+=a.v1;v2+=a.v2;v3+=a.v3;;return *this;}
    V& operator-=(V a){v1-=a.v1;v2-=a.v2;v3-=a.v3;;return *this;}
    V& operator*=(V a){v1*=a.v1;v2*=a.v2;v3*=a.v3;;return *this;}
    V& operator/=(V a){v1/=a.v1;v2/=a.v2;v3/=a.v3;;return *this;}

    V operator+(V a) const{return V(*this)+=a;}
    V operator-(V a) const{return V(*this)-=a;}
    V operator*(V a) const{return V(*this)*=a;}
    V operator/(V a) const{return V(*this)/=a;}

    tuple<M1, M2, M3> norm() const{return make_tuple(v1,v2,v3);}

    bool operator==(const V a)const{return norm()==a.norm();}
    bool operator!=(const V a)const{return norm()!=a.norm();}
    bool operator <(const V a)const{return norm() <a.norm();}
  };
  const T BASE = 1777771;

  vector<M1> po1,op1;
  vector<M2> po2,op2;
  vector<M3> po3,op3;

  template<typename M>
  void init(int n,vector<M>& po,vector<M>& op){
    po.assign(n+1,1);
    op.assign(n+1,1);
    M x(BASE);
    M y=M(x).inv();
    for(int i=1;i<=(int)n;i++) po[i]=po[i-1]*x;
    for(int i=1;i<=(int)n;i++) op[i]=op[i-1]*y;
  }

  PolynomialHash(size_t n){
    init(n,po1,op1);
    init(n,po2,op2);
    init(n,po3,op3);
  }

  V build(const vector<T> &v){
    int n=v.size();
    M1 r1;M2 r2;M3 r3;
    for(int i=0;i<n;i++){
      r1+=M1(v[i])*po1[i];
      r2+=M2(v[i])*po2[i];
      r3+=M3(v[i])*po3[i];
    }
    return V(r1,r2,r3);
  }

  V term(size_t x,T k){
    M1 a1=po1[x]*M1((long long)k);
    M2 a2=po2[x]*M2((long long)k);
    M3 a3=po3[x]*M3((long long)k);
    return V(a1,a2,a3);
  }
};
//END CUT HERE
#ifndef call_from_test

template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed CODEFLYER2018_F(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  const int MAX = 2020;
  using BS = bitset<MAX>;

  int h,w,q;
  cin>>h>>w>>q;

  vector<string> s(h);
  for(int i=0;i<h;i++) cin>>s[i];

  vector<BS> rs(h),cs(w);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      rs[i][j]=(s[i][j]=='#');
      cs[j][i]=(s[i][j]=='#');
    }
  }

  auto conv=
    [&](BS &v,int k){
      vector<int> a(k);
      for(int i=0;i<k;i++) a[i]=v[i];
      return a;
    };

  using M1 = Mint<int, int(1e9+7)>;
  using M2 = Mint<int, int(1e9+9)>;
  using M3 = Mint<int, int(1e8+7)>;

  PolynomialHash<int, M1, M2, M3> ph(MAX);
  using V = decltype(ph)::V;

  vector<V> vrs(h),vcs(w);
  vector<int> tmp(w,1);
  V ri=ph.build(tmp);
  tmp.assign(h,1);
  V ci=ph.build(tmp);

  for(int i=0;i<h;i++){
    auto v=conv(rs[i],w);
    vrs[i]=ph.build(v);
    if(rs[i][0]) vrs[i]=ri-vrs[i];
  }

  for(int j=0;j<w;j++){
    auto v=conv(cs[j],h);
    vcs[j]=ph.build(v);
    if(cs[j][0]) vcs[j]=ci-vcs[j];
  }

  map<V, set<int> > mrs, mcs;
  for(int i=0;i<h;i++) mrs[vrs[i]].emplace(i);
  for(int j=0;j<w;j++) mcs[vcs[j]].emplace(j);

  auto print=[&](string s){cout<<s<<"\n";};

  auto check=
    [&](){
      int a1=-1,b1=-1,c1=-1,d1=-1;
      int a2=-1,b2=-1,c2=-1,d2=-1;

      int A,B,C,D;

      {
        auto latte=mrs.begin();
        set<int> &s=latte->second;
        latte++;
        set<int> &t=latte->second;
        if(*--s.end()-*s.begin()+1==(int)s.size()){
          a1=*s.begin();
          b1=*--s.end();
        }
        if(*--t.end()-*t.begin()+1==(int)t.size()){
          a2=*t.begin();
          b2=*--t.end();
        }
        A=*s.begin();
        B=*t.begin();
      }
      if(a1<0&&a2<0){
        print("No");
        return;
      }

      {
        auto latte=mcs.begin();
        set<int> &s=latte->second;
        latte++;
        set<int> &t=latte->second;
        if(*--s.end()-*s.begin()+1==(int)s.size()){
          c1=*s.begin();
          d1=*--s.end();
        }
        if(*--t.end()-*t.begin()+1==(int)t.size()){
          c2=*t.begin();
          d2=*--t.end();
        }
        C=*s.begin();
        D=*t.begin();
      }

      if(c1<0&&c2<0){
        print("No");
        return;
      }

      {
        int flg=0;
        if(~c1){
          BS r=rs[A]^rs[B];
          r>>=c1;
          int k=r.count();
          r>>=(d1-c1+1);
          k-=r.count();
          flg|=(d1-c1+1)==k;
        }
        if(~c1){
          BS r=rs[A]^~rs[B];
          r>>=c1;
          int k=r.count();
          r>>=(d1-c1+1);
          k-=r.count();
          flg|=(d1-c1+1)==k;
        }
        if(~c2){
          BS r=rs[A]^rs[B];
          r>>=c2;
          int k=r.count();
          r>>=(d2-c2+1);
          k-=r.count();
          flg|=(d2-c2+1)==k;
        }
        if(~c2){
          BS r=rs[A]^~rs[B];
          r>>=c2;
          int k=r.count();
          r>>=(d2-c2+1);
          k-=r.count();
          flg|=(d2-c2+1)==k;
        }
        if(!flg){
          print("No");
          return;
        }
      }

      {
        int flg=0;
        if(~a1){
          BS r=cs[C]^cs[D];
          r>>=a1;
          int k=r.count();
          r>>=(b1-a1+1);
          k-=r.count();
          flg|=(b1-a1+1)==k;
        }
        if(~a1){
          BS r=cs[C]^~cs[D];
          r>>=a1;
          int k=r.count();
          r>>=(b1-a1+1);
          k-=r.count();
          flg|=(b1-a1+1)==k;
        }
        if(~a2){
          BS r=cs[C]^cs[D];
          r>>=a2;
          int k=r.count();
          r>>=(b2-a2+1);
          k-=r.count();
          flg|=(b2-a2+1)==k;
        }
        if(~a2){
          BS r=cs[C]^~cs[D];
          r>>=a2;
          int k=r.count();
          r>>=(b2-a2+1);
          k-=r.count();
          flg|=(b2-a2+1)==k;
        }
        if(!flg){
          print("No");
          return;
        }
      }

      print("Yes");
    };

  auto calc=
    [&](){
      if(mrs.size()>2u||mcs.size()>2u){
        print("No");
        return;
      }
      if(mrs.size()==1u||mcs.size()==1u){
        print("Yes");
        return;
      }

      if(mrs.size()==2u||mcs.size()==2u){
        check();
        return;
      }
      print("No");
    };

  calc();

  for(int i=1;i<q;i++){
    int r,c;
    cin>>r>>c;
    r--;c--;

    mrs[vrs[r]].erase(r);
    if(mrs[vrs[r]].empty()) mrs.erase(vrs[r]);
    mcs[vcs[c]].erase(c);
    if(mcs[vcs[c]].empty()) mcs.erase(vcs[c]);

    if(rs[r][0]) vrs[r]=ri-vrs[r];
    if(cs[c][0]) vcs[c]=ci-vcs[c];

    if(rs[r][c]){
      vrs[r]-=ph.term(c,1);
      vcs[c]-=ph.term(r,1);
    }else{
      vrs[r]+=ph.term(c,1);
      vcs[c]+=ph.term(r,1);
    }

    rs[r][c].flip();
    cs[c][r].flip();

    if(rs[r][0]) vrs[r]=ri-vrs[r];
    if(cs[c][0]) vcs[c]=ci-vcs[c];

    mrs[vrs[r]].emplace(r);
    mcs[vcs[c]].emplace(c);

    calc();
  }

  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/15
  https://atcoder.jp/contests/bitflyer2018-final/tasks/bitflyer2018_final_f
*/

using M1 = Mint<int, int(1e9+7)>;
using M2 = Mint<int, int(1e9+9)>;
using M3 = Mint<int, int(1e8+7)>;

PolynomialHash<int, M1, M2, M3> ph(2000);
using V = decltype(ph)::V;

struct Point{
  V x,y;
  Point(){}
  Point(V x,V y):x(x),y(y){}
};

using Vector = Point;

Point getP(){
  int x,y;
  cin>>x>>y;
  return Point(V((long long)x),V((long long)y));
}

signed JAG2018SUMMER_DAY2_F(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  Point d=getP();

  vector<Point> a(n),b(n),c(n);
  for(int i=0;i<n;i++){
    a[i]=getP();
    b[i]=getP();
    c[i]=getP();
  }

  for(int i=0;i<n;i++){
    if(c[i].x==d.x&&c[i].y==d.y) drop(i);

    if(a[i].x==b[i].x&&c[i].x==d.x) drop(i);

    if(a[i].x==b[i].x){
      V nx=a[i].x;
      V ny=c[i].y;
      ny+=(nx-c[i].x)/(d.x-c[i].x)*(d.y-c[i].y);
      d=Point(nx,ny);
      continue;
    }

    if(c[i].x==d.x){
      V nx=c[i].x;
      V ny=a[i].y;
      ny+=(nx-a[i].x)/(b[i].x-a[i].x)*(b[i].y-a[i].y);
      d=Point(nx,ny);
      continue;
    }

    V al=(b[i].y-a[i].y)/(b[i].x-a[i].x);
    V bt=(d.y-c[i].y)/(d.x-c[i].x);

    if(al==bt) drop(i);

    V nx=al*a[i].x;
    nx-=bt*c[i].x;
    nx-=a[i].y;
    nx+=c[i].y;
    nx/=al-bt;

    V ny=al*nx;
    ny-=al*a[i].x;
    ny+=a[i].y;

    d=Point(nx,ny);
  }
  cout<<n<<endl;
  return 0;
}
/*
  verified on 2019/10/15
  https://atcoder.jp/contests/jag2018summer-day2/tasks/jag2018summer_day2_f
*/


signed main(){
  //CODEFLYER2018_F();
  //JAG2018SUMMER_DAY2_F();
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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: mod/mint.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

