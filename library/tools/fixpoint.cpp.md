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


# :heavy_check_mark: tools/fixpoint.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4a931512ce65bdc9ca6808adf92d8783">tools</a>
* <a href="{{ site.github.repository_url }}/blob/master/tools/fixpoint.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-20 17:56:09 +0900




## Required by

* :heavy_check_mark: <a href="../string/ahocorasick.cpp.html">string/ahocorasick.cpp</a>
* :heavy_check_mark: <a href="../tree/eulertourforvertex.cpp.html">tree/eulertourforvertex.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0377.test.cpp.html">test/aoj/0377.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0613.test.cpp.html">test/aoj/0613.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2646.test.cpp.html">test/aoj/2646.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2790.test.cpp.html">test/aoj/2790.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/geometry/2448.test.cpp.html">test/aoj/geometry/2448.test.cpp</a>


## Code

<a id="unbundled"></a>
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
template<typename F>
struct FixPoint : F{
  FixPoint(F&& f):F(forward<F>(f)){}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) const{
    return F::operator()(*this,forward<Args>(args)...);
  }
};
template<typename F>
inline decltype(auto) MFP(F&& f){
  return FixPoint<F>{forward<F>(f)};
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  int h,w;
  cin>>h>>w;
  vector<string> st(h);
  for(int i=0;i<h;i++) cin>>st[i];

  vector<vector<int> > used(h,vector<int>(w,0));

  auto dfs=
    MFP([&](auto dfs,int y,int x)->void{
          used[y][x]=1;
          if(y  >0&&st[y-1][x]!='#'&&!used[y-1][x]) dfs(y-1,x);
          if(y+1<h&&st[y+1][x]!='#'&&!used[y+1][x]) dfs(y+1,x);
          if(x  >0&&st[y][x-1]!='#'&&!used[y][x-1]) dfs(y,x-1);
          if(x+1<w&&st[y][x+1]!='#'&&!used[y][x+1]) dfs(y,x+1);
        });

  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      if(st[i][j]=='s') dfs(i,j);

  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      if(st[i][j]=='g')
        cout<<(used[i][j]?"Yes":"No")<<endl;
  return 0;
}
/*
  https://atcoder.jp/contests/atc001/tasks/dfs_a
*/
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

