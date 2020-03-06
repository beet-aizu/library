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


# :heavy_check_mark: convolution/convolution2D.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a9595c1c24c33b16056d2ad07e71682d">convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/convolution/convolution2D.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-06 19:27:33+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2560.test.cpp.html">test/aoj/2560.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2977.test.cpp.html">test/aoj/2977.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3074.test.cpp.html">test/aoj/3074.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T,typename Transformer>
struct Convolution2D{
  using Matrix = vector< vector<T> >;
  const Transformer tran;
  Convolution2D(Transformer tran):tran(tran){}

  void transpose(Matrix &as){
    int n=as.size(),m=as[0].size();
    Matrix cs(as);
    as.assign(m,vector<T>(n));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        as[j][i]=cs[i][j];
  }

  void transform(Matrix &as,bool f){
    for(int t=0;t<2;t++){
      for(auto &a:as) tran(a,f);
      transpose(as);
    }
  }

  Matrix multiply(Matrix as,Matrix bs){
    int nt=as.size()+bs.size()-1;
    int mt=as[0].size()+bs[0].size()-1;
    int n=1,m=1;
    while(n<nt) n<<=1;
    while(m<mt) m<<=1;
    as.resize(n);bs.resize(n);
    for(int i=0;i<n;i++){
      as[i].resize(m,T(0));
      bs[i].resize(m,T(0));
    }
    transform(as,0);transform(bs,0);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        as[i][j]*=bs[i][j];
    transform(as,1);
    return as;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "convolution/convolution2D.cpp"
#include <iostream>

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T,typename Transformer>
struct Convolution2D{
  using Matrix = vector< vector<T> >;
  const Transformer tran;
  Convolution2D(Transformer tran):tran(tran){}

  void transpose(Matrix &as){
    int n=as.size(),m=as[0].size();
    Matrix cs(as);
    as.assign(m,vector<T>(n));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        as[j][i]=cs[i][j];
  }

  void transform(Matrix &as,bool f){
    for(int t=0;t<2;t++){
      for(auto &a:as) tran(a,f);
      transpose(as);
    }
  }

  Matrix multiply(Matrix as,Matrix bs){
    int nt=as.size()+bs.size()-1;
    int mt=as[0].size()+bs[0].size()-1;
    int n=1,m=1;
    while(n<nt) n<<=1;
    while(m<mt) m<<=1;
    as.resize(n);bs.resize(n);
    for(int i=0;i<n;i++){
      as[i].resize(m,T(0));
      bs[i].resize(m,T(0));
    }
    transform(as,0);transform(bs,0);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        as[i][j]*=bs[i][j];
    transform(as,1);
    return as;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

