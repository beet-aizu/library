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


# :heavy_check_mark: test/aoj/ALDS1_9_C.test.cpp
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_9_C.test.cpp">View this file on GitHub</a> (Last commit date: 2019-10-21 19:29:29 +0900)


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C</a>


## Dependencies
* :heavy_check_mark: <a href="../../../library/datastructure/skewheap.cpp.html">datastructure/skewheap.cpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/skewheap.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using Heap=SkewHeap<int, int>;
  auto g=[](int a,int b){return a+b;};
  auto c=[](int a,int b){return a<b;};
  int INF = -1;
  Heap heap(g,g,c,INF,0);
  auto base=heap.push(0);

  string s;
  while(cin>>s,s!="end"){
    int x;
    if(s=="insert"){
      cin>>x;
      base=heap.meld(base,heap.push(x));
    }
    if(s=="extract"){
      x=heap.top(base);
      base=heap.pop(base);
      cout<<x<<"\n";
    }
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

