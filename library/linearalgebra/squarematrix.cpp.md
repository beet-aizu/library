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
    - Last commit date: 2020-03-06 20:39:01+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2397.test.cpp.html">test/aoj/2397.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2432.test.cpp.html">test/aoj/2432.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3074.test.cpp.html">test/aoj/3074.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/0831.test.cpp.html">test/yukicoder/0831.test.cpp</a>


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
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "linearalgebra/squarematrix.cpp"

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
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

