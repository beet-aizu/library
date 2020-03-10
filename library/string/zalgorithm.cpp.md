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


# :heavy_check_mark: string/zalgorithm.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/zalgorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-15 17:46:50+09:00




## Required by

* :heavy_check_mark: <a href="run.cpp.html">string/run.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/runenumerate.test.cpp.html">test/yosupo/runenumerate.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/zalgorithm.test.cpp.html">test/yosupo/zalgorithm.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// longest common prefix of s and s[i:n]
template<typename T>
vector<int> zalgorithm(vector<T> vs){
  int n=vs.size();
  vector<int> as(n+1,0);
  as[0]=n;
  int i=1,j=0;
  while(i<n){
    while(i+j<n&&vs[j]==vs[i+j]) j++;
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
vector<int> zalgorithm(string s){
  return zalgorithm(vector<char>(s.begin(),s.end()));
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
#line 1 "string/zalgorithm.cpp"

#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// longest common prefix of s and s[i:n]
template<typename T>
vector<int> zalgorithm(vector<T> vs){
  int n=vs.size();
  vector<int> as(n+1,0);
  as[0]=n;
  int i=1,j=0;
  while(i<n){
    while(i+j<n&&vs[j]==vs[i+j]) j++;
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
vector<int> zalgorithm(string s){
  return zalgorithm(vector<char>(s.begin(),s.end()));
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

