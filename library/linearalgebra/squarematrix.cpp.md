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


# :heavy_check_mark: linearalgebra/squarematrix.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#1bbf1d9f5340fa94bf2c5fb5ce73a5f5">linearalgebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/linearalgebra/squarematrix.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-26 23:42:22+09:00




## Depends on

* :heavy_check_mark: <a href="../mod/mint.cpp.html">mod/mint.cpp</a>
* :heavy_check_mark: <a href="../segtree/basic/ushi.cpp.html">segtree/basic/ushi.cpp</a>
* :heavy_check_mark: <a href="../tools/compress.cpp.html">tools/compress.cpp</a>
* :heavy_check_mark: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2397.test.cpp.html">test/aoj/2397.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3074.test.cpp.html">test/aoj/3074.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/831.test.cpp.html">test/yukicoder/831.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename R, size_t N>
struct SquareMatrix{
  typedef array<R, N> arr;
  typedef array<arr, N> mat;
  mat dat;

  SquareMatrix(){
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<N;j++)
        dat[i][j]=R::add_identity();
  }

  bool operator==(const SquareMatrix& a) const{
    return dat==a.dat;
  }

  size_t size() const{return N;}
  arr& operator[](size_t k){return dat[k];}
  const arr& operator[](size_t k) const {return dat[k];}

  static SquareMatrix add_identity(){return SquareMatrix();}
  static SquareMatrix mul_identity(){
    SquareMatrix res;
    for(size_t i=0;i<N;i++) res[i][i]=R::mul_identity();
    return res;
  }

  SquareMatrix operator*(const SquareMatrix &B) const{
    SquareMatrix res;
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<N;j++)
        for(size_t k=0;k<N;k++)
          res[i][j]=res[i][j]+(dat[i][k]*B[k][j]);
    return res;
  }

  SquareMatrix operator+(const SquareMatrix &B) const{
    SquareMatrix res;
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<N;j++)
        res[i][j]=dat[i][j]+B[i][j];
    return res;
  }

  SquareMatrix pow(long long n) const{
    SquareMatrix a=*this,res=mul_identity();
    while(n){
      if(n&1) res=res*a;
      a=a*a;
      n>>=1;
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../tools/compress.cpp"
#include "../mod/mint.cpp"
#include "../segtree/basic/ushi.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed YAHOO2019_FINAL_D(){
  using ll = long long;
  using M = Mint<int>;
  using MM = SquareMatrix<M, 2>;

  int n,q;
  cin>>n>>q;
  vector<ll> ts(q),ls(q),rs(q),ps(q);
  for(ll i=0;i<q;i++){
    cin>>ts[i];
    if(ts[i]==1) cin>>ps[i];
    if(ts[i]==2) cin>>ls[i]>>rs[i];
  }
  vector<ll> vs;
  for(ll i=0;i<q;i++){
    if(ts[i]==1){
      vs.emplace_back(ps[i]);
      vs.emplace_back(ps[i]+1);
      vs.emplace_back(ps[i]+2);
      vs.emplace_back(ps[i]+3);
    }
    if(ts[i]==2){
      vs.emplace_back(ls[i]);
      vs.emplace_back(ls[i]+1);
      vs.emplace_back(rs[i]);
      vs.emplace_back(rs[i]+1);
    }
  }
  vs.emplace_back(0);
  vs.emplace_back(n+1);
  vs=compress(vs);
  auto ms=dict(vs);

  MM A;
  A[0][0]=M(1);A[0][1]=M(1);
  A[1][0]=M(1);A[1][1]=M(0);

  vector<MM> vt(vs.size()-1,A);
  for(ll i=0;i+1<(ll)vs.size();i++){
    vt[i]=A.pow(vs[i+1]-vs[i]);
  }

  MM I=MM::mul_identity();
  auto f=[&](MM a,MM b){return b*a;};
  SegmentTree<MM> seg(f,I);
  seg.build(vt);

  vector<int> used(vs.size(),0);
  for(ll i=0;i<q;i++){
    if(ts[i]==1){
      ll k=ms[ps[i]];
      used[k]^=1;
      MM B;
      for(ll j=k;j<=k+2;j++){
        if(used[j]){
          B[0][0]=M(0);B[0][1]=M(0);
          B[1][0]=M(1);B[1][1]=M(0);
        }else{
          B[0][0]=M(!used[j-1]);B[0][1]=M(!used[j-2]);
          B[1][0]=M(1);B[1][1]=M(0);
        }
        seg.set_val(j,B);
      }
    }
    if(ts[i]==2){
      ll l=ms[ls[i]],r=ms[rs[i]];
      if(used[l]){
        cout<<0<<"\n";
        continue;
      }
      auto B=seg.query(l+1,r+1);
      cout<<B[0][0].v<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/29
  https://atcoder.jp/contests/yahoo-procon2019-final/tasks/yahoo_procon2019_final_d
*/

signed DDCC2019_FINAL_D(){
  string s;
  cin>>s;

  struct M{
    uint32_t v;
    M(){*this=add_identity();}
    M(uint32_t v):v(v){}
    M operator+(const M &a)const{return M(v+a.v);}
    M operator*(const M &a)const{return M(v*a.v);}
    static M add_identity(){return M(0);}
    static M mul_identity(){return M(1);}
  };

  using SM = SquareMatrix<M, 6>;

  auto f=[](SM a,SM b){return a*b;};
  SM ti=SM::mul_identity();
  SegmentTree<SM> seg(f,ti);
  vector<SM> vt(s.size(),ti);
  for(int i=0;i<(int)s.size();i++){
    if(s[i]=='D') vt[i][0][1]=1;
    if(s[i]=='I') vt[i][1][2]=1;
    if(s[i]=='S') vt[i][2][3]=1;
    if(s[i]=='C') vt[i][3][4]=1;
    if(s[i]=='O') vt[i][4][5]=1;
  }
  seg.build(vt);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;
    cout<<seg.query(l,r)[0][5].v<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/29
  https://atcoder.jp/contests/ddcc2019-final/tasks/ddcc2019_final_d
*/

signed main(){
  //YAHOO2019_FINAL_D();
  //DDCC2019_FINAL_D();
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: linearalgebra/squarematrix.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

