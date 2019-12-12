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


# :warning: string/zalgorithm.cpp
<a href="../../index.html">Back to top page</a>

* category: string
* <a href="{{ site.github.repository_url }}/blob/master/string/zalgorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-11 16:39:56 +0900




## Depends On
* :warning: <a href="../datastructure/binaryindexedtree.cpp.html">datastructure/binaryindexedtree.cpp</a>


## Verified With
* :warning: <a href="../../verify/test/yosupo/zalgorithm.test.cpp.html">test/yosupo/zalgorithm.test.cpp</a>


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
// longest common prefix of s and s[i:n]
vector<int> zalgorithm(string s){
  int n=s.size();
  vector<int> as(n,0);
  as[0]=n;
  int i=1,j=0;
  while(i<n){
    while(i+j<n&&s[j]==s[i+j]) j++;
    as[i]=j;
    if(j==0){
      i++;
      continue;
    }
    int k=1;
    while(i+k<n&&k+as[k]<j) as[i+k]=as[k],k++;
    i+=k;
    j-=k;
  }
  return as;
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../datastructure/binaryindexedtree.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed CFR432_D(){
  string s;
  cin>>s;
  vector<int> as=zalgorithm(s);
  int n=s.size();
  set<int> ss;
  BIT<int> bit(n+100,0);
  for(int i=0;i<n;i++){
    bit.add0(as[i],1);
    if(i+as[i]!=n) continue;
    ss.emplace(as[i]);
  }
  cout<<ss.size()<<endl;
  for(auto x:ss) cout<<x<<" "<<bit.query0(x,n+100)<<endl;
  return 0;
}
/*
  verified on 2019/10/28
  http://codeforces.com/problemset/problem/432/D
*/

signed main(){
  CFR432_D();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

