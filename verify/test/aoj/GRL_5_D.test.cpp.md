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

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_5_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-05 21:59:12+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D</a>


## Depends on

* :question: <a href="../../../library/datastructure/binaryindexedtree.cpp.html">datastructure/binaryindexedtree.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/fastio.cpp.html">tools/fastio.cpp</a>
* :heavy_check_mark: <a href="../../../library/tree/eulertourforedge.cpp.html">tree/eulertourforedge.cpp</a>


## Code

<a id="unbundled"></a>
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

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_5_D.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "test/aoj/../../tools/fastio.cpp"

#line 3 "test/aoj/../../tools/fastio.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 1 "test/aoj/../../tree/eulertourforedge.cpp"

#line 3 "test/aoj/../../tree/eulertourforedge.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
class EulerTourForEdge{
private:
  vector<int> ds,us,dep,btm;

  void dfs(int v,int p,int d){
    dep[v]=d;
    for(int u:G[v]){
      if(u==p) continue;
      ds[u]=btm.size();
      btm.emplace_back(u);
      dfs(u,v,d+1);
      us[u]=btm.size();
      btm.emplace_back(u);
    }
  }
public:
  vector< vector<int> > G;

  EulerTourForEdge(){}
  EulerTourForEdge(int n):
    ds(n),us(n),dep(n),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build(int r=0){
    btm.clear();
    ds[r]=btm.size();
    btm.emplace_back(r);
    dfs(r,-1,0);
    us[r]=btm.size();
    btm.emplace_back(r);
  }

  int child(int u,int v){
    return dep[u]<dep[v]?v:u;
  }

  int bottom(int e){
    return btm[e];
  }

  // lca(u, v) must be u or v
  template<typename F>
  void query(int u,int v,F f){
    if(dep[u]>dep[v]) swap(u,v);
    f(ds[u]+1,ds[v]+1);
  }

  template<typename T,typename G>
  void update(int v,T x,G g){
    g(ds[v], x);
    g(us[v],-x);
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 1 "test/aoj/../../datastructure/binaryindexedtree.cpp"

#line 3 "test/aoj/../../datastructure/binaryindexedtree.cpp"
using namespace std;
#endif
/*
 * @docs docs/binaryindexedtree.md
 */
//BEGIN CUT HERE
template<typename T>
struct BIT{
  int n;
  vector<T> bit;
  // 1-indexed
  BIT(int n_):n(n_+1),bit(n+1,0){}

  T sum(int i){
    T s(0);
    for(int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }

  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }

  // [l, r)
  T query(int l,int r){
    return sum(r-1)-sum(l-1);
  }

  int lower_bound(int w){
    if(w<=0) return 0;
    int x=0,r=1;
    while(r<n) r<<=1;
    for(int k=r;k>0;k>>=1){
      if(x+k<=n&&bit[x+k]<w){
        w-=bit[x+k];
        x+=k;
      }
    }
    return x+1;
  }

  // 0-indexed
  T sum0(int i){return sum(i+1);}
  void add0(int i,T a){add(i+1,a);}
  T query0(int l,int r){return sum(r)-sum(l);}
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 10 "test/aoj/GRL_5_D.test.cpp"
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

