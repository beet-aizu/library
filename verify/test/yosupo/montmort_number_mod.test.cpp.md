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


# :heavy_check_mark: test/yosupo/montmort_number_mod.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/montmort_number_mod.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-05 21:02:53+09:00


* see: <a href="https://judge.yosupo.jp/problem/montmort_number_mod">https://judge.yosupo.jp/problem/montmort_number_mod</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/mod/montmort.cpp.html">mod/montmort.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/montmort.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  Montmort<int> mm(n,m);
  for(int i=1;i<=n;i++){
    if(i) cout<<" ";
    cout<<mm[i];
  }
  cout<<endl;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/montmort_number_mod.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "mod/montmort.cpp"

#line 3 "mod/montmort.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
// number of permutations with p_i != i
template<typename T>
struct Montmort{
  using ll = long long;
  vector<T> dp;

  Montmort(int n,int mod):dp(n+1,0){
    for(int k=2;k<=n;k++){
      dp[k]=(ll)dp[k-1]*k%mod;
      if(~k&1) dp[k]+=1;
      else dp[k]+=mod-1;
      if(dp[k]>=mod) dp[k]-=mod;
    }
  }

  T operator[](int n){return dp[n];}
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 8 "test/yosupo/montmort_number_mod.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  Montmort<int> mm(n,m);
  for(int i=1;i<=n;i++){
    if(i) cout<<" ";
    cout<<mm[i];
  }
  cout<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

