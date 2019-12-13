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


# :heavy_check_mark: test/yosupo/suffixarray.test.cpp
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/suffixarray.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 23:51:01 +0900


* see: <a href="https://judge.yosupo.jp/problem/suffixarray">https://judge.yosupo.jp/problem/suffixarray</a>


## Depends On
* :heavy_check_mark: <a href="../../../library/string/suffixarray.cpp.html">string/suffixarray.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/fastio.cpp.html">tools/fastio.cpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../string/suffixarray.cpp"
#undef call_from_test

signed main(){
  string s;
  cin>>s;

  SuffixArray sa(s);
  for(int i=0;i<(int)s.size();i++){
    if(i) cout<<" ";
    cout<<sa[i+1];
  }
  cout<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

