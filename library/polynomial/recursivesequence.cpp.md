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


# :heavy_check_mark: polynomial/recursivesequence.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#89693d3333328e76f4fdeed379e8f9ea">polynomial</a>
* <a href="{{ site.github.repository_url }}/blob/master/polynomial/recursivesequence.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 13:36:32+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/4271.test.cpp.html">test/yukicoder/4271.test.cpp</a>


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
// add recursive sequence
template<typename T>
struct RecursiveSequence{
  vector<vector<int>> add,sub;
  RecursiveSequence(int n):add(n),sub(n+1){}

  // add a_0, ..., a_{r-l-1} to [l, r)
  void query(int l,int r){
    add[l].emplace_back(0);
    sub[r].emplace_back(r-l);
  }

  // a_i = \sum_{k} c_k a_{i-k}
  vector<T> build(vector<T> as,vector<T> cs){
    assert(as.size()==cs.size());
    int n=add.size();
    int k=as.size();

    reverse(cs.begin(),cs.end());
    as.resize(n+k);
    for(int i=0;i<n;i++)
      for(int j=0;j<k;j++)
        as[i+k]+=as[i+j]*cs[j];

    vector<T> ss(n+k,T(0));
    for(int i=0;i<n;i++){
      for(int l:add[i])
        for(int j=0;j<k;j++)
          ss[i+j]+=as[l+j];

      for(int l:sub[i])
        for(int j=0;j<k;j++)
          ss[i+j]-=as[l+j];

      for(int j=0;j<k;j++)
        ss[i+k]+=ss[i+j]*cs[j];
    }
    ss.resize(n);
    return ss;
  }
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
#line 2 "polynomial/recursivesequence.cpp"

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#endif
//BEGIN CUT HERE
// add recursive sequence
template<typename T>
struct RecursiveSequence{
  vector<vector<int>> add,sub;
  RecursiveSequence(int n):add(n),sub(n+1){}

  // add a_0, ..., a_{r-l-1} to [l, r)
  void query(int l,int r){
    add[l].emplace_back(0);
    sub[r].emplace_back(r-l);
  }

  // a_i = \sum_{k} c_k a_{i-k}
  vector<T> build(vector<T> as,vector<T> cs){
    assert(as.size()==cs.size());
    int n=add.size();
    int k=as.size();

    reverse(cs.begin(),cs.end());
    as.resize(n+k);
    for(int i=0;i<n;i++)
      for(int j=0;j<k;j++)
        as[i+k]+=as[i+j]*cs[j];

    vector<T> ss(n+k,T(0));
    for(int i=0;i<n;i++){
      for(int l:add[i])
        for(int j=0;j<k;j++)
          ss[i+j]+=as[l+j];

      for(int l:sub[i])
        for(int j=0;j<k;j++)
          ss[i+j]-=as[l+j];

      for(int j=0;j<k;j++)
        ss[i+k]+=ss[i+j]*cs[j];
    }
    ss.resize(n);
    return ss;
  }
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

