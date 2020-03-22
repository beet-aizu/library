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


# :heavy_check_mark: test/aoj/DPL_3_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_3_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-12 17:40:23+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/algorithm/largestrectangle.cpp.html">algorithm/largestrectangle.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../algorithm/largestrectangle.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  using ll = long long;
  vector<ll> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];

  cout<<largestrectangle(vs)<<endl;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_3_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 2 "algorithm/largestrectangle.cpp"

#ifndef call_from_test
#line 5 "algorithm/largestrectangle.cpp"
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
#line 8 "test/aoj/DPL_3_C.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  using ll = long long;
  vector<ll> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];

  cout<<largestrectangle(vs)<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

