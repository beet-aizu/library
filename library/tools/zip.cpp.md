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


# :warning: tools/zip.cpp
<a href="../../index.html">Back to top page</a>

* category: tools
* <a href="{{ site.github.repository_url }}/blob/master/tools/zip.cpp">View this file on GitHub</a> (Last commit date: 2019-08-24 00:11:17 +0900)




## Code
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
template<typename ...Ts>
decltype(auto) zip(vector<Ts>... args){
  vector<decltype(make_tuple(args[0]...))> res;
  int n=min({args.size()...});
  res.reserve(n);
  for(int i=0;i<n;i++) res.emplace_back(args[i]...);
  return res;
}
//END CUT HERE
signed main(){
  vector<int> as({1,2,3});
  vector<string> bs({"a","b","c"});
  auto zs=zip(as,bs);
  for(auto [x,y]:zs) cout<<x<<" "<<y<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

