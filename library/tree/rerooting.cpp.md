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


# :heavy_check_mark: tree/rerooting.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/rerooting.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-26 19:55:08+09:00


* see: <a href="https://ei1333.hateblo.jp/entry/2018/12/21/004022">https://ei1333.hateblo.jp/entry/2018/12/21/004022</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/1595.test.cpp.html">test/aoj/1595.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/2085.test.cpp.html">test/yukicoder/2085.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
/*
 * @see https://ei1333.hateblo.jp/entry/2018/12/21/004022
 */
//BEGIN CUT HERE
template<typename T, typename Edge>
struct ReRooting{
  struct Node{
    int to,rev;
    Edge data;
    Node(int to,Edge data):to(to),data(data){}
    bool operator<(const Node &v)const{return to<v.to;};
  };

  using F1 = function<T(T, T)>;
  using F2 = function<T(T, Edge)>;

  vector< vector<Node> > G;
  vector< vector<T> > ld,rd;
  vector<int> lp,rp;

  const F1 f1;
  const F2 f2;
  const T id;

  ReRooting(int n,const F1 f1,const F2 f2,const T id):
    G(n),ld(n),rd(n),lp(n),rp(n),f1(f1),f2(f2),id(id){}

  void add_edge(int u,int v,Edge d,Edge e){
    G[u].emplace_back(v,d);
    G[v].emplace_back(u,e);
  }

  void add_edge(int u,int v,Edge d){add_edge(u,v,d,d);}

  // k: idx for edge (not vertex)
  T dfs(int v,int k){
    while(lp[v]!=k and lp[v]<(int)G[v].size()){
      auto &e=G[v][lp[v]];
      ld[v][lp[v]+1]=f1(ld[v][lp[v]],f2(dfs(e.to,e.rev),e.data));
      lp[v]++;
    }
    while(rp[v]!=k and rp[v]>=0){
      auto &e=G[v][rp[v]];
      rd[v][rp[v]]=f1(rd[v][rp[v]+1],f2(dfs(e.to,e.rev),e.data));
      rp[v]--;
    }
    if(k<0) return rd[v][0];
    return f1(ld[v][k],rd[v][k+1]);
  }

  int search(vector<Node> &vs,int idx){
    return lower_bound(vs.begin(),vs.end(),Node(idx,vs[0].data))-vs.begin();
  }

  vector<T> build(){
    int n=G.size();
    for(int i=0;i<n;i++){
      sort(G[i].begin(),G[i].end());
      ld[i].assign((int)G[i].size()+1,id);
      rd[i].assign((int)G[i].size()+1,id);
      lp[i]=0;
      rp[i]=(int)G[i].size()-1;
    }

    for(int i=0;i<n;i++)
      for(Node &t:G[i])
        t.rev=search(G[t.to],i);

    vector<T> res;
    for(int i=0;i<n;i++)
      res.emplace_back(dfs(i,-1));

    return res;
  }

  // p: idx for vertex
  T subtree(int v,int p){
    int k=search(G[p],v);
    assert(k<(int)G[p].size() and G[p][k].to==v);
    return f2(dfs(v,G[p][k].rev),G[p][k].data);
  }
};
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
#line 2 "tree/rerooting.cpp"

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
/*
 * @see https://ei1333.hateblo.jp/entry/2018/12/21/004022
 */
//BEGIN CUT HERE
template<typename T, typename Edge>
struct ReRooting{
  struct Node{
    int to,rev;
    Edge data;
    Node(int to,Edge data):to(to),data(data){}
    bool operator<(const Node &v)const{return to<v.to;};
  };

  using F1 = function<T(T, T)>;
  using F2 = function<T(T, Edge)>;

  vector< vector<Node> > G;
  vector< vector<T> > ld,rd;
  vector<int> lp,rp;

  const F1 f1;
  const F2 f2;
  const T id;

  ReRooting(int n,const F1 f1,const F2 f2,const T id):
    G(n),ld(n),rd(n),lp(n),rp(n),f1(f1),f2(f2),id(id){}

  void add_edge(int u,int v,Edge d,Edge e){
    G[u].emplace_back(v,d);
    G[v].emplace_back(u,e);
  }

  void add_edge(int u,int v,Edge d){add_edge(u,v,d,d);}

  // k: idx for edge (not vertex)
  T dfs(int v,int k){
    while(lp[v]!=k and lp[v]<(int)G[v].size()){
      auto &e=G[v][lp[v]];
      ld[v][lp[v]+1]=f1(ld[v][lp[v]],f2(dfs(e.to,e.rev),e.data));
      lp[v]++;
    }
    while(rp[v]!=k and rp[v]>=0){
      auto &e=G[v][rp[v]];
      rd[v][rp[v]]=f1(rd[v][rp[v]+1],f2(dfs(e.to,e.rev),e.data));
      rp[v]--;
    }
    if(k<0) return rd[v][0];
    return f1(ld[v][k],rd[v][k+1]);
  }

  int search(vector<Node> &vs,int idx){
    return lower_bound(vs.begin(),vs.end(),Node(idx,vs[0].data))-vs.begin();
  }

  vector<T> build(){
    int n=G.size();
    for(int i=0;i<n;i++){
      sort(G[i].begin(),G[i].end());
      ld[i].assign((int)G[i].size()+1,id);
      rd[i].assign((int)G[i].size()+1,id);
      lp[i]=0;
      rp[i]=(int)G[i].size()-1;
    }

    for(int i=0;i<n;i++)
      for(Node &t:G[i])
        t.rev=search(G[t.to],i);

    vector<T> res;
    for(int i=0;i<n;i++)
      res.emplace_back(dfs(i,-1));

    return res;
  }

  // p: idx for vertex
  T subtree(int v,int p){
    int k=search(G[p],v);
    assert(k<(int)G[p].size() and G[p][k].to==v);
    return f2(dfs(v,G[p][k].rev),G[p][k].data);
  }
};
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

