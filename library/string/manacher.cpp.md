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


# :heavy_check_mark: string/manacher.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/manacher.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-06 20:39:01+09:00


* see: <a href="https://snuke.hatenablog.com/entry/2014/12/02/235837">https://snuke.hatenablog.com/entry/2014/12/02/235837</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2934.test.cpp.html">test/aoj/2934.test.cpp</a>


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
/*
 * @see https://snuke.hatenablog.com/entry/2014/12/02/235837
 */
//BEGIN CUT HERE
vector<int> manacher(string s){
  int n=s.size();
  vector<int> vs(n);
  for(int i=0,j=0;i<n;){
    while(i-j>=0&&i+j<n&&s[i-j]==s[i+j]) j++;
    vs[i]=j;
    int k=1;
    while(i-k>=0&&i+k<n&&k+vs[i-k]<j) vs[i+k]=vs[i-k],k++;
    i+=k;j-=k;
  }
  return vs;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/manacher.cpp"
#include <iostream>

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
/*
 * @see https://snuke.hatenablog.com/entry/2014/12/02/235837
 */
//BEGIN CUT HERE
vector<int> manacher(string s){
  int n=s.size();
  vector<int> vs(n);
  for(int i=0,j=0;i<n;){
    while(i-j>=0&&i+j<n&&s[i-j]==s[i+j]) j++;
    vs[i]=j;
    int k=1;
    while(i-k>=0&&i+k<n&&k+vs[i-k]<j) vs[i+k]=vs[i-k],k++;
    i+=k;j-=k;
  }
  return vs;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

