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


# :heavy_check_mark: algorithm/monotoneminima.cpp
<a href="../../index.html">Back to top page</a>

* category: algorithm
* <a href="{{ site.github.repository_url }}/blob/master/algorithm/monotoneminima.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-29 13:38:48 +0900




## Verified With
* :heavy_check_mark: <a href="../../verify/test/aoj/2603.test.cpp.html">test/aoj/2603.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
namespace MonotoneMinima{
  template<typename T,typename F>
  void induce(int l,int r,int a,int b,vector<int> &dp,F dist){
    if(l==r) return;
    int m=(l+r)>>1;
    int &idx=(dp[m]=a);
    T res=dist(m,idx);
    for(int i=a;i<b;i++){
      T tmp=dist(m,i);
      if(tmp<res) res=tmp,idx=i;
    }
    induce<T>(l,m,a,idx+1,dp,dist);
    induce<T>(m+1,r,idx,b,dp,dist);
  }

  // p < q -> argmin f(p, *) < argmin f(q, *)
  template<typename T,typename F>
  vector<int> args(int n,int m,F dist){
    vector<int> dp(n,-1);
    induce<T>(0,n,0,m,dp,dist);
    return dp;
  }
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed COLOPL2018FINAL_C(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n;
  cin>>n;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto dist=[&](int i,int j){return as[j]+(ll)(i-j)*(i-j);};
  auto res=MonotoneMinima::args<ll>(n,n,dist);

  for(int i=0;i<n;i++) cout<<dist(i,res[i])<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/29
  https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
*/
signed main(){
  //COLOPL2018FINAL_C();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

