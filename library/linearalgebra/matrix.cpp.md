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


# :heavy_check_mark: linearalgebra/matrix.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#1bbf1d9f5340fa94bf2c5fb5ce73a5f5">linearalgebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/linearalgebra/matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-29 12:01:20+09:00




## Required by

* :heavy_check_mark: <a href="tree_theorem.cpp.html">linearalgebra/tree_theorem.cpp</a>
* :heavy_check_mark: <a href="../math/tetrahedra.cpp.html">math/tetrahedra.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0314.test.cpp.html">test/aoj/0314.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1328.test.cpp.html">test/aoj/1328.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2060.test.cpp.html">test/aoj/2060.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/matrix_det.test.cpp.html">test/yosupo/matrix_det.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename K>
struct Matrix{
  typedef vector<K> arr;
  typedef vector<arr> mat;
  mat dat;

  Matrix(size_t r,size_t c):dat(r,arr(c,K())){}
  Matrix(mat dat):dat(dat){}

  size_t size() const{return dat.size();}
  bool empty() const{return size()==0;}
  arr& operator[](size_t k){return dat[k];}
  const arr& operator[](size_t k) const {return dat[k];}

  static Matrix cross(const Matrix &A,const Matrix &B){
    Matrix res(A.size(),B[0].size());
    for(int i=0;i<(int)A.size();i++)
      for(int j=0;j<(int)B[0].size();j++)
        for(int k=0;k<(int)B.size();k++)
          res[i][j]+=A[i][k]*B[k][j];
    return res;
  }

  static Matrix identity(size_t n){
    Matrix res(n,n);
    for(int i=0;i<(int)n;i++) res[i][i]=K(1);
    return res;
  }

  Matrix pow(long long n) const{
    Matrix a(dat),res=identity(size());
    while(n){
      if(n&1) res=cross(res,a);
      a=cross(a,a);
      n>>=1;
    }
    return res;
  }

  template<typename T>
  using ET = enable_if<is_floating_point<T>::value>;
  template<typename T>
  using EF = enable_if<!is_floating_point<T>::value>;

  template<typename T, typename ET<T>::type* = nullptr>
  static bool is_zero(T x){return abs(x)<1e-8;}
  template<typename T, typename EF<T>::type* = nullptr>
  static bool is_zero(T x){return x==T(0);}

  template<typename T, typename ET<T>::type* = nullptr>
  static bool compare(T x,T y){return abs(x)<abs(y);}
  template<typename T, typename EF<T>::type* = nullptr>
  static bool compare(T x,T y){(void)x;return y!=T(0);}

  // assume regularity
  static Matrix gauss_jordan(const Matrix &A,const Matrix &B){
    int n=A.size(),l=B[0].size();
    Matrix C(n,n+l);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
        C[i][j]=A[i][j];
      for(int j=0;j<l;j++)
        C[i][n+j]=B[i][j];
    }
    for(int i=0;i<n;i++){
      int p=i;
      for(int j=i;j<n;j++)
        if(compare(C[p][i],C[j][i])) p=j;
      swap(C[i],C[p]);
      if(is_zero(C[i][i])) return Matrix(0,0);
      for(int j=i+1;j<n+l;j++) C[i][j]/=C[i][i];
      for(int j=0;j<n;j++){
        if(i==j) continue;
        for(int k=i+1;k<n+l;k++)
          C[j][k]-=C[j][i]*C[i][k];
      }
    }
    Matrix res(n,l);
    for(int i=0;i<n;i++)
      for(int j=0;j<l;j++)
        res[i][j]=C[i][n+j];
    return res;
  }

  Matrix inv() const{
    Matrix B=identity(size());
    return gauss_jordan(*this,B);
  }

  static arr linear_equations(const Matrix &A,const arr &b){
    Matrix B(b.size(),1);
    for(int i=0;i<(int)b.size();i++) B[i][0]=b[i];
    Matrix tmp=gauss_jordan(A,B);
    arr res(tmp.size());
    for(int i=0;i<(int)tmp.size();i++) res[i]=tmp[i][0];
    return res;
  }

  K determinant() const{
    Matrix A(dat);
    K res(1);
    int n=size();
    for(int i=0;i<n;i++){
      int p=i;
      for(int j=i;j<n;j++)
        if(compare(A[p][i],A[j][i])) p=j;
      if(i!=p) swap(A[i],A[p]),res=-res;
      if(is_zero(A[i][i])) return K(0);
      res*=A[i][i];
      for(int j=i+1;j<n;j++) A[i][j]/=A[i][i];
      for(int j=i+1;j<n;j++)
        for(int k=i+1;k<n;k++)
          A[j][k]-=A[j][i]*A[i][k];
    }
    return res;
  }

  static K sigma(K x,long long n){
    Matrix A(2,2);
    A[0][0]=x;A[0][1]=0;
    A[1][0]=1;A[1][1]=1;
    return A.pow(n)[1][0];
  }
};
//END CUT HERE
#ifndef call_from_test
template<typename T>
struct Mint{
  static T MOD;
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

  Mint inv(){return pow(MOD-2);}

  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}

  Mint operator+(Mint a) const{return Mint(v)+=a;};
  Mint operator-(Mint a) const{return Mint(v)-=a;};
  Mint operator*(Mint a) const{return Mint(v)*=a;};
  Mint operator/(Mint a) const{return Mint(v)/=a;};

  Mint operator-(){return v?MOD-v:v;}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;};
};
template<typename T> Mint<T> abs(Mint<T> a){return a;};
template<typename T> T Mint<T>::MOD = 1e9+7;


signed ARC050_C(){
  using ll = long long;
  using M = Mint<ll>;
  using MM = Matrix<M>;
  ll a,b,m;
  scanf("%lld %lld %lld",&a,&b,&m);
  M::MOD = m;
  ll c=__gcd(a,b);
  M x=M((ll)10).pow(c);
  M ans=MM::sigma(x,a/c)*MM::sigma(M((ll)10),b);
  printf("%lld\n",ans.v);
  return 0;
}
/*
  verified on 2018/10/17
  https://atcoder.jp/contests/arc050/tasks/arc050_c
*/

signed SPOJ_MIFF(){
  int first=1;
  int n,p;
  while(scanf("%d %d",&n,&p),n){
    if(!first) puts("");
    first=0;
    using M = Mint<int>;
    M::MOD = p;
    using MM = Matrix<M>;
    MM A(n,n);
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        scanf("%d",&A[i][j].v);
    MM B=A.inv();
    if(B.empty()) puts("singular");
    else{
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(j) printf(" ");
          printf("%d",B[i][j].v);
        }
        puts("");
      }
    }
  }
  return 0;
}
/*
  verified on 2018/10/17
  https://www.spoj.com/problems/MIFF/
*/

signed SPOJ_MPOW(){
  int T;
  scanf("%d",&T);
  while(T--){
    int n,p;
    scanf("%d %d",&n,&p);
    using M = Mint<int>;
    M::MOD = 1e9+7;
    using MM = Matrix<M>;
    MM A(n,n);
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        scanf("%d",&A[i][j].v);
    MM B=A.pow(p);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(j) printf(" ");
        printf("%d",B[i][j].v);
      }
      puts("");
    }
  }
  return 0;
}
/*
  verified on 2018/10/17
  https://www.spoj.com/problems/MPOW/
*/

signed main(){
  //ARC050_C();
  //SPOJ_MIFF();
  //SPOJ_MPOW();
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: linearalgebra/matrix.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

