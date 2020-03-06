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


# :heavy_check_mark: math/totient_table.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/totient_table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-06 19:54:22+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2286.test.cpp.html">test/aoj/2286.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1665.test.cpp.html">test/yukicoder/1665.test.cpp</a>


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
vector<int> totient_table(int n){
  vector<int> ts(n+1);
  iota(ts.begin(),ts.end(),0);
  for(int i=2;i<=n;i++){
    if(ts[i]!=i) continue;
    for(int j=i;j<=n;j+=i) ts[j]=ts[j]/i*(i-1);
  }
  return ts;
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
#line 2 "math/totient_table.cpp"
#include <iostream>

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
vector<int> totient_table(int n){
  vector<int> ts(n+1);
  iota(ts.begin(),ts.end(),0);
  for(int i=2;i<=n;i++){
    if(ts[i]!=i) continue;
    for(int j=i;j<=n;j+=i) ts[j]=ts[j]/i*(i-1);
  }
  return ts;
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

