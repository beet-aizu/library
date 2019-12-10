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


# :warning: test/aoj/DPL_3_B.test.cpp


<a href="../../../index.html">Back to top page</a>

* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B</a>


## Dependencies
* :warning: <a href="../../../library/algorithm/largestrectangle.cpp.html">algorithm/largestrectangle.cpp</a>
* :warning: <a href="../../../library/tools/chminmax.cpp.html">tools/chminmax.cpp</a>
* :warning: <a href="../../../library/tools/fastio.cpp.html">tools/fastio.cpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tools/chminmax.cpp"
#include "../../algorithm/largestrectangle.cpp"
#undef call_from_test

signed main(){
  int h,w;
  cin>>h>>w;

  vector< vector<int> > cs(h,vector<int>(w));
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin>>cs[i][j];

  int res=0;
  vector<int> dp(w,0);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)
      dp[j]=cs[i][j]==0?dp[j]+1:0;
    chmax(res,largestrectangle(dp));
  }

  cout<<res<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

