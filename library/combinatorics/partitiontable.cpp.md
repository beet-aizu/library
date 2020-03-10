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


# :heavy_check_mark: combinatorics/partitiontable.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ac1ed416572b96a9f5d69740d174ef3d">combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/combinatorics/partitiontable.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-10 19:33:27+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_J.test.cpp.html">test/aoj/DPL_5_J.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_5_L.test.cpp.html">test/aoj/DPL_5_L.test.cpp</a>


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
template<typename M>
struct PartitionTable{
  vector< vector<M> > dp;
  PartitionTable(int h,int w):dp(h+1,vector<M>(w+1,0)){
    dp[0][0]=M(1);
    for(int i=0;i<=h;i++){
      for(int j=1;j<=w;j++){
        dp[i][j]=dp[i][j-1];
        if(i-j>=0) dp[i][j]+=dp[i-j][j];
      }
    }
  }
  // put n identical balls into k identical boxes
  M operator()(int n,int k){return dp[n][k];}

  // put n identical balls into some boxes
  M operator()(int n){return dp[n][n];}
};
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
#line 2 "combinatorics/partitiontable.cpp"
#include <iostream>

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

//BEGIN CUT HERE
template<typename M>
struct PartitionTable{
  vector< vector<M> > dp;
  PartitionTable(int h,int w):dp(h+1,vector<M>(w+1,0)){
    dp[0][0]=M(1);
    for(int i=0;i<=h;i++){
      for(int j=1;j<=w;j++){
        dp[i][j]=dp[i][j-1];
        if(i-j>=0) dp[i][j]+=dp[i-j][j];
      }
    }
  }
  // put n identical balls into k identical boxes
  M operator()(int n,int k){return dp[n][k];}

  // put n identical balls into some boxes
  M operator()(int n){return dp[n][n];}
};
//END CUT HERE

#ifndef call_from_test
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

