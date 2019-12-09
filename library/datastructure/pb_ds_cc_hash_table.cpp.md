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


# :warning: datastructure/pb_ds_cc_hash_table.cpp
* category: datastructure


[Back to top page](../../index.html)



## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T,typename U>
using gmap = cc_hash_table<T, U, hash<T> >;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed AGC023_A(){
  using ll = long long;
  int n;
  scanf("%d",&n);
  vector<ll> as(n);
  for(int i=0;i<n;i++) scanf("%lld",&as[i]);

  gmap<ll, ll> mp;
  ll ans=0,sum=0;
  mp[sum]++;
  for(int i=0;i<n;i++){
    sum+=as[i];
    ans+=mp[sum];
    mp[sum]++;
  }

  printf("%lld\n",ans);
  return 0;
}
/*
  verified on 2019/12/09
  https://atcoder.jp/contests/agc023/tasks/agc023_a
*/

signed main(){
  AGC023_A();
  return 0;
}
#endif

```
{% endraw %}

[Back to top page](../../index.html)

