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


# :heavy_check_mark: test/yosupo/sum_of_floor_of_linear.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/sum_of_floor_of_linear.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-05 21:02:53+09:00


* see: <a href="https://judge.yosupo.jp/problem/sum_of_floor_of_linear">https://judge.yosupo.jp/problem/sum_of_floor_of_linear</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/sum_of_floor.cpp.html">math/sum_of_floor.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/sum_of_floor.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int T;
  cin>>T;
  for(int t=0;t<T;t++){
    long long n,m,a,b;
    cin>>n>>m>>a>>b;
    cout<<sum_of_floor(n,m,a,b)<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/sum_of_floor_of_linear.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "test/yosupo/../../math/sum_of_floor.cpp"

#line 3 "test/yosupo/../../math/sum_of_floor.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
// sum_{i=0}^{n-1} (ai + b) // m
// 0 <= a, b
template<typename T>
T sum_of_floor(T n,T m,T a,T b){
  T res=0;
  if(a>=m){
    res+=(n-1)*n*(a/m)/2;
    a%=m;
  }
  if(b>=m){
    res+=n*(b/m);
    b%=m;
  }
  T y=(a*n+b)/m;
  T x=y*m-b;
  if(y==0) return res;
  res+=(n-(x+a-1)/a)*y;
  res+=sum_of_floor(y,a,m,(a-x%a)%a);
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
#line 8 "test/yosupo/sum_of_floor_of_linear.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int T;
  cin>>T;
  for(int t=0;t<T;t++){
    long long n,m,a,b;
    cin>>n>>m>>a>>b;
    cout<<sum_of_floor(n,m,a,b)<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

