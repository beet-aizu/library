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


# :heavy_check_mark: test/aoj/GRL_5_D.test.cpp
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_5_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 23:51:01 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D</a>


## Depends On
* :heavy_check_mark: <a href="../../../library/datastructure/binaryindexedtree.cpp.html">datastructure/binaryindexedtree.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/fastio.cpp.html">tools/fastio.cpp</a>
* :heavy_check_mark: <a href="../../../library/tree/eulertourforedge.cpp.html">tree/eulertourforedge.cpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tree/eulertourforedge.cpp"
#include "../../datastructure/binaryindexedtree.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;
  EulerTourForEdge et(n);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int c;
      cin>>c;
      et.add_edge(i,c);
    }
  }
  et.build();

  BIT<int> bit(n*2+100);
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int v,w;
      cin>>v>>w;
      auto g=[&](int k,int d){bit.add0(k,d);};
      et.update(v,w,g);
    }
    if(t==1){
      int u;
      cin>>u;
      int res=0;
      et.query(0,u,[&](int l,int r){res+=bit.query0(l,r);});
      cout<<res<<"\n";
    }
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

