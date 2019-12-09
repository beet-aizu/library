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


# :warning: math/factorize.cpp
* category: math


[Back to top page](../../index.html)



## Required
* :heavy_check_mark: [algorithm/mo.cpp](../algorithm/mo.cpp.html)
* :heavy_check_mark: [mod/enumeration.cpp](../mod/enumeration.cpp.html)
* :heavy_check_mark: [mod/order.cpp](../mod/order.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/3062.test.cpp](../../verify/test/aoj/3062.test.cpp.html)
* :heavy_check_mark: [test/aoj/NTL_1_A.test.cpp](../../verify/test/aoj/NTL_1_A.test.cpp.html)


## Code
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
template<typename T>
map<T, int> factorize(T x){
  map<T, int> res;
  for(int i=2;i*i<=x;i++){
    while(x%i==0){
      x/=i;
      res[i]++;
    }
  }
  if(x!=1) res[x]++;
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  int a,b;
  cin>>a>>b;
  map<int, int> m;
  for(int i=b+1;i<=a;i++){
    auto x=factorize(i);
    for(auto p:x) m[p.first]+=p.second;
  }
  const Int MOD = 1e9+7;
  Int ans=1;
  for(auto p:m) (ans*=(p.second+1))%=MOD;
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2018/01/29
  https://atcoder.jp/contests/arc034/tasks/arc034_3
*/
#endif

```

[Back to top page](../../index.html)

