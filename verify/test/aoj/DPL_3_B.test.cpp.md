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


# :heavy_check_mark: test/aoj/DPL_3_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_3_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-06 19:09:15+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/algorithm/largestrectangle.cpp.html">algorithm/largestrectangle.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/chminmax.cpp.html">tools/chminmax.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../algorithm/largestrectangle.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

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

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_3_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 3 "test/aoj/../../tools/chminmax.cpp"

#ifndef call_from_test
#line 6 "test/aoj/../../tools/chminmax.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 3 "test/aoj/../../algorithm/largestrectangle.cpp"

#ifndef call_from_test
#line 6 "test/aoj/../../algorithm/largestrectangle.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
T largestrectangle(vector<T> &v){
  int n=v.size();
  T res=0;
  using P = pair<int, T>;
  stack<P> sp;
  sp.emplace(-1,T(0));
  for(int i=0;i<n;i++){
    int j=i;
    while(sp.top().second>v[i]){
      j=sp.top().first;
      res=max(res,(i-j)*sp.top().second);
      sp.pop();
    }
    if(sp.top().second<v[i]) sp.emplace(j,v[i]);
  }
  while(!sp.empty()){
    res=max(res,(n-sp.top().first)*sp.top().second);
    sp.pop();
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
#line 9 "test/aoj/DPL_3_B.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

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

