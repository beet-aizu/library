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


# :warning: graph/voronoiminimumspanningtree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/voronoiminimumspanningtree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 23:51:01+09:00




## Depends on

* :heavy_check_mark: <a href="kruskal.cpp.html">graph/kruskal.cpp</a>
* :heavy_check_mark: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct VoronoiMST{
  int n;
  using E = pair<int, T>;
  using P = pair<T, int>;
  vector<vector<E> > G;
  VoronoiMST(vector<T> &x){
    n=x.size();
    G.assign(n<<1,vector<E>());
    for(int i=0;i<n;i++) G[i].emplace_back(n+i,x[i]);
  }
  void add_edge(int u,int v,T c){
    G[u+n].emplace_back(v+n,c);
    G[v+n].emplace_back(u+n,c);
  }
  vector<vector<E> > build(){
    priority_queue<P, vector<P>, greater<P> > pq;
    const T INF = numeric_limits<T>::max();
    vector<T> dist(n<<1,INF);
    vector<int> from(n<<1,-1);
    for(int i=0;i<n;i++){
      dist[i]=0;from[i]=i;
      pq.emplace(dist[i],i);
    }
    while(!pq.empty()){
      T d;
      int v;
      tie(d,v)=pq.top();pq.pop();
      if(dist[v]<d) continue;
      for(E e:G[v]){
        int u=e.first;
        T c=e.second;
        if(dist[u]<=dist[v]+c) continue;
        dist[u]=dist[v]+c;
        from[u]=from[v];
        pq.emplace(dist[u],u);
      }
    }
    vector<vector<E> > H(n);
    for(int v=0;v<(n<<1);v++){
      for(E e:G[v]){
        int u=e.first;
        T c=e.second;
        if(from[v]==from[u]) continue;
        int x=from[v],y=from[u];
        T z=dist[v]+dist[u]+c;
        H[x].emplace_back(y,z);
        H[y].emplace_back(x,z);
      }
    }
    return H;
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "kruskal.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed CF17FINAL_J(){
  using ll = long long;
  int n;
  cin>>n;
  vector<ll> x(n);
  for(int i=0;i<n;i++) cin>>x[i];
  VoronoiMST<ll> vo(x);
  for(int i=1;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    vo.add_edge(a,b,c);
  }
  auto G=vo.build();
  Kruskal<ll> ks(n);
  for(int v=0;v<n;v++){
    for(auto e:G[v]){
      int u=e.first;
      ll c=e.second;
      if(v<u) ks.add_edge(v,u,c);
    }
  }
  cout<<ks.build()<<endl;
  return 0;
}
/*
  verified on 2019/10/25
  https://atcoder.jp/contests/cf17-final/tasks/cf17_final_j
*/

signed KEYENCE2019_E(){
  using ll = long long;

  int n,d;
  cin>>n>>d;
  vector<ll> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  VoronoiMST<ll> vo(a);
  for(int i=1;i<n;i++){
    vo.add_edge(i-1,i,d);
  }
  auto G=vo.build();
  Kruskal<ll> ks(n);
  for(int v=0;v<n;v++){
    for(auto e:G[v]){
      int u=e.first;
      ll c=e.second;
      if(v<u) ks.add_edge(v,u,c);
    }
  }
  cout<<ks.build()<<endl;
  return 0;
}
/*
  verified on 2019/10/25
  https://atcoder.jp/contests/keyence2019/tasks/keyence2019_e
*/

signed main(){
  //CF17FINAL_J();
  //KEYENCE2019_E();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: graph/voronoiminimumspanningtree.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

