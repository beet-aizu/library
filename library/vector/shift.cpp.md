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


# :heavy_check_mark: vector/shift.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6ba8844da718b4a65f60dbfd0d92d6ef">vector</a>
* <a href="{{ site.github.repository_url }}/blob/master/vector/shift.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 17:56:15+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2359.test.cpp.html">test/aoj/2359.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#endif
//BEGIN CUT HERE
template<typename T>
vector<T> shift(vector<T> vs,vector<T> as){
  assert(vs.size()==as.size());
  for(int i=0;i<(int)vs.size();i++) vs[i]+=as[i];
  return vs;
}
template<typename T>
vector<T> shift(vector<T> vs,T a){
  return shift(vs,vector<T>(vs.size(),a));
}

template<typename T, typename ...Ts>
vector<T> near(vector<T> vs,Ts... ts){
  vector<T> rs;
  rs.reserve(vs.size()*sizeof...(ts));
  auto append=[&](auto a){
    auto ws=shift(vs,a);
    for(auto w:ws) rs.emplace_back(w);
  };
  initializer_list<int>{(void(append(ts)),0)...};
  return rs;
}
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
#line 2 "vector/shift.cpp"

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#endif
//BEGIN CUT HERE
template<typename T>
vector<T> shift(vector<T> vs,vector<T> as){
  assert(vs.size()==as.size());
  for(int i=0;i<(int)vs.size();i++) vs[i]+=as[i];
  return vs;
}
template<typename T>
vector<T> shift(vector<T> vs,T a){
  return shift(vs,vector<T>(vs.size(),a));
}

template<typename T, typename ...Ts>
vector<T> near(vector<T> vs,Ts... ts){
  vector<T> rs;
  rs.reserve(vs.size()*sizeof...(ts));
  auto append=[&](auto a){
    auto ws=shift(vs,a);
    for(auto w:ws) rs.emplace_back(w);
  };
  initializer_list<int>{(void(append(ts)),0)...};
  return rs;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

