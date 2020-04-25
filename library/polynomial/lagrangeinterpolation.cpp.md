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


# :heavy_check_mark: polynomial/lagrangeinterpolation.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#89693d3333328e76f4fdeed379e8f9ea">polynomial</a>
* <a href="{{ site.github.repository_url }}/blob/master/polynomial/lagrangeinterpolation.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-10 20:00:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2951.test.cpp.html">test/aoj/2951.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/0022.test.cpp.html">test/yukicoder/0022.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename M>
M lagrange_interpolation(vector<M> &y,M t){
  int n=y.size()-1;
  if(t.v<=n) return y[t.v];

  vector<M> dp(n+1,1),pd(n+1,1);
  for(int i=0;i<n;i++) dp[i+1]=dp[i]*(t-M(i));
  for(int i=n;i>0;i--) pd[i-1]=pd[i]*(t-M(i));

  vector<M> fact(n+1,1),finv(n+1,1);
  for(int i=1;i<=n;i++) fact[i]=fact[i-1]*M(i);
  finv[n]=M(1)/fact[n];
  for(int i=n;i>=1;i--) finv[i-1]=finv[i]*M(i);

  M res(0);
  for(int i=0;i<=n;i++){
    M tmp=y[i]*dp[i]*pd[i]*finv[i]*finv[n-i];
    if((n-i)&1) res-=tmp;
    else res+=tmp;
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "polynomial/lagrangeinterpolation.cpp"

#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename M>
M lagrange_interpolation(vector<M> &y,M t){
  int n=y.size()-1;
  if(t.v<=n) return y[t.v];

  vector<M> dp(n+1,1),pd(n+1,1);
  for(int i=0;i<n;i++) dp[i+1]=dp[i]*(t-M(i));
  for(int i=n;i>0;i--) pd[i-1]=pd[i]*(t-M(i));

  vector<M> fact(n+1,1),finv(n+1,1);
  for(int i=1;i<=n;i++) fact[i]=fact[i-1]*M(i);
  finv[n]=M(1)/fact[n];
  for(int i=n;i>=1;i--) finv[i-1]=finv[i]*M(i);

  M res(0);
  for(int i=0;i<=n;i++){
    M tmp=y[i]*dp[i]*pd[i]*finv[i]*finv[n-i];
    if((n-i)&1) res-=tmp;
    else res+=tmp;
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

