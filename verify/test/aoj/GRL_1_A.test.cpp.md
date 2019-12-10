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


# :heavy_check_mark: test/aoj/GRL_1_A.test.cpp
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_1_A.test.cpp">View this file on GitHub</a> (Last commit date: 2019-12-09 23:51:01 +0900)


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A</a>


## Dependencies
* :heavy_check_mark: <a href="../../../library/datastructure/radixheap.cpp.html">datastructure/radixheap.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/fastio.cpp.html">tools/fastio.cpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../datastructure/radixheap.cpp"
#undef call_from_test

signed main(){
  int n,m,r;
  cin>>n>>m>>r;

  using P = pair<int, int>;
  vector< vector<P> > G(n);
  for(int i=0;i<m;i++){
    int s,t,d;
    cin>>s>>t>>d;
    G[s].emplace_back(t,d);
  }

  const int INF = numeric_limits<int>::max();
  RadixHeap<int, int> pq;
  vector<int> dist(n,INF);
  dist[r]=0;
  pq.emplace(dist[r],r);
  while(!pq.empty()){
    P p=pq.pop();
    int v=p.second;
    if(dist[v]<p.first) continue;
    for(auto& e:G[v]){
      int u=e.first,c=e.second;
      if(dist[u]>dist[v]+c){
        dist[u]=dist[v]+c;
        pq.emplace(dist[u],u);
      }
    }
  }

  for(int i=0;i<n;i++){
    if(dist[i]==INF) cout<<"INF\n";
    else cout<<dist[i]<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

