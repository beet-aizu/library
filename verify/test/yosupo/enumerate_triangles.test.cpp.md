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


# :heavy_check_mark: test/yosupo/enumerate_triangles.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/enumerate_triangles.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-07 17:24:05+09:00


* see: <a href="https://judge.yosupo.jp/problem/enumerate_triangles">https://judge.yosupo.jp/problem/enumerate_triangles</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/triangle.cpp.html">graph/triangle.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/triangle.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n,m;
  cin>>n>>m;
  vector<ll> xs(n);
  for(int i=0;i<n;i++) cin>>xs[i];

  Triangle G(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    G.add_edge(u,v);
  }

  const ll mod = 998244353;
  ll ans=0;
  auto f=[&](int x,int y,int z){
    ans+=xs[x]*xs[y]%mod*xs[z]%mod;
    ans%=mod;
  };
  G.build(f);

  cout<<ans<<endl;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/enumerate_triangles.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 2 "graph/triangle.cpp"

#ifndef call_from_test
#line 5 "graph/triangle.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
struct Triangle{
  // if not simple, use vector<set<int>>
  vector<vector<int>> G;
  Triangle(int n):G(n){}
  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  template<typename F>
  void build(F f){
    int n=G.size();

    vector<int> ord(n),rev(n);
    auto cmp=[&](int i,int j){return G[i].size()>G[j].size();};
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),cmp);
    for(int i=0;i<n;i++) rev[ord[i]]=i;

    vector<vector<int>> H(n);
    for(int i=0;i<n;i++)
      for(int j:G[i])
        if(rev[i]<rev[j]) H[i].emplace_back(j);

    vector<int> used(n,0);
    // x->y->z
    for(int x:ord){
      for(int z:H[x]) used[z]=1;
      for(int y:H[x])
        for(int z:H[y])
          if(used[z]) f(x,y,z);
      for(int z:H[x]) used[z]=0;
    }
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
#line 8 "test/yosupo/enumerate_triangles.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n,m;
  cin>>n>>m;
  vector<ll> xs(n);
  for(int i=0;i<n;i++) cin>>xs[i];

  Triangle G(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    G.add_edge(u,v);
  }

  const ll mod = 998244353;
  ll ans=0;
  auto f=[&](int x,int y,int z){
    ans+=xs[x]*xs[y]%mod*xs[z]%mod;
    ans%=mod;
  };
  G.build(f);

  cout<<ans<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

