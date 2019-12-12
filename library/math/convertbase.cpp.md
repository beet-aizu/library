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


# :heavy_check_mark: math/convertbase.cpp
<a href="../../index.html">Back to top page</a>

* category: math
* <a href="{{ site.github.repository_url }}/blob/master/math/convertbase.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-25 12:27:29 +0900




## Verified With
* :heavy_check_mark: <a href="../../verify/test/aoj/0233.test.cpp.html">test/aoj/0233.test.cpp</a>


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
template<typename T>
vector<T> convert_base(T x,T b){
  vector<T> res;
  T t=1,k=abs(b);
  while(x){
    res.emplace_back((x*t)%k);
    if(res.back()<0) res.back()+=k;
    x-=res.back()*t;
    x/=k;
    t*=b/k;
  }
  if(res.empty()) res.emplace_back(0);
  reverse(res.begin(),res.end());
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed ABC105_C(){
  long long p;
  cin>>p;
  auto ans=convert_base(p,-2LL);
  for(auto x:ans) cout<<x;
  cout<<endl;
  return 0;
}
/*
  verified on 2019/03/31
  https://atcoder.jp/contests/abc105/tasks/abc105_c
*/

signed YUKI_499(){
  long long p;
  cin>>p;
  auto ans=convert_base(p,7LL);
  for(auto x:ans) cout<<x;
  cout<<endl;
  return 0;
}
/*
  verified on 2019/03/31
  https://yukicoder.me/problems/no/499
*/

signed YUKI_782(){
  long long t,b;
  cin>>t>>b;
  while(t--){
    long long p;
    cin>>p;
    auto ans=convert_base(p,b);
    for(auto x:ans) cout<<x;
    cout<<endl;
  }
  return 0;
}
/*
  verified on 2019/03/31
  https://yukicoder.me/problems/no/782
*/

signed main(){
  //ABC105_C();
  //YUKI_499();
  //YUKI_782();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

