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


# :warning: tools/drop.cpp
* category: tools


[Back to top page](../../index.html)



## Required
* :heavy_check_mark: [mod/log.cpp](../mod/log.cpp.html)
* :heavy_check_mark: [polynomial/formalpowerseries.cpp](../polynomial/formalpowerseries.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/2359.test.cpp](../../verify/test/aoj/2359.test.cpp.html)
* :heavy_check_mark: [test/aoj/2934.test.cpp](../../verify/test/aoj/2934.test.cpp.html)
* :heavy_check_mark: [test/aoj/2970.test.cpp](../../verify/test/aoj/2970.test.cpp.html)
* :heavy_check_mark: [test/aoj/2971.test.cpp](../../verify/test/aoj/2971.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_1_B.test.cpp](../../verify/test/aoj/GRL_1_B.test.cpp.html)


## Code
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  int a,b,c,d,e,k;
  cin>>a>>b>>c>>d>>e>>k;
  vector<int> vs({a,b,c,d,e});
  for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
      if(abs(vs[i]-vs[j])>k) drop(":(");
  drop("Yay!"s);
  return 0;
}
/*
  verified on 2019/07/08
  https://atcoder.jp/contests/abc123/tasks/abc123_a
*/
#endif

```

[Back to top page](../../index.html)

