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


# :heavy_check_mark: graph/lowlink.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/lowlink.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-19 22:42:36+09:00




## Depends on

* :heavy_check_mark: <a href="../datastructure/unionfindtree.cpp.html">datastructure/unionfindtree.cpp</a>
* :heavy_check_mark: <a href="../mod/enumeration.cpp.html">mod/enumeration.cpp</a>
* :heavy_check_mark: <a href="../mod/mint.cpp.html">mod/mint.cpp</a>
* :heavy_check_mark: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0377.test.cpp.html">test/aoj/0377.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0415.test.cpp.html">test/aoj/0415.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_3_A.test.cpp.html">test/aoj/GRL_3_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_3_B.test.cpp.html">test/aoj/GRL_3_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct LowLink{
  int n,pos;
  vector<int> ord,low,par,blg,num;
  vector<vector<int> > G,C,T;
  vector<vector<pair<int, int> > > E;

  vector<int> ap;
  vector<pair<int, int> > bs,cand;

  LowLink(int n):n(n),pos(0),ord(n,-1),low(n),
                 par(n,-1),blg(n,-1),num(n,1),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  bool is_bridge(int u,int v){
    if(ord[u]>ord[v]) swap(u,v);
    return ord[u]<low[v];
  }

  void dfs(int v){
    ord[v]=low[v]=pos++;
    for(int u:G[v]){
      if(u==par[v]) continue;
      if(ord[u]<ord[v])
        cand.emplace_back(min(u,v),max(u,v));
      if(~ord[u]){
        low[v]=min(low[v],ord[u]);
        continue;
      }
      par[u]=v;
      dfs(u);
      num[v]+=num[u];
      low[v]=min(low[v],low[u]);
      if(is_bridge(u,v)) bs.emplace_back(u,v);
      if(low[u]>=ord[v]){
        E.emplace_back();
        while(1){
          auto e=cand.back();
          cand.pop_back();
          E.back().emplace_back(e);
          if(make_pair(min(u,v),max(u,v))==e) break;
        }
      }
    }
  }

  void fill_component(int v){
    C[blg[v]].emplace_back(v);
    for(int u:G[v]){
      if(~blg[u]||is_bridge(u,v)) continue;
      blg[u]=blg[v];
      fill_component(u);
    }
  }

  void add_component(int v,int &k){
    if(~blg[v]) return;
    blg[v]=k++;
    C.emplace_back();
    fill_component(v);
  }

  int build(){
    for(int i=0;i<n;i++)
      if(ord[i]<0) dfs(i);

    vector<int> cnt(n,0);
    for(int i=0;i<n;i++){
      int p=par[i];
      if(p<0) continue;
      if(par[p]<0) cnt[p]++;
      else if(ord[p]<=low[i]) ap.emplace_back(p);
    }

    for(int i=0;i<n;i++)
      if(cnt[i]>1) ap.emplace_back(i);

    sort(ap.begin(),ap.end());
    ap.erase(unique(ap.begin(),ap.end()),ap.end());

    int k=0;
    for(int i=0;i<n;i++) add_component(i,k);

    T.assign(k,vector<int>());
    for(auto e:bs){
      int u=blg[e.first],v=blg[e.second];
      T[u].emplace_back(v);
      T[v].emplace_back(u);
    }
    return k;
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../datastructure/unionfindtree.cpp"
#include "../mod/mint.cpp"
#include "../mod/enumeration.cpp"
#undef call_from_test


//INSERT ABOVE HERE
signed ARC045_D(){
  int n;
  cin>>n;
  vector<int> xs(2*n+1),ys(2*n+1);
  for(int i=0;i<2*n+1;i++) cin>>xs[i]>>ys[i];

  vector<vector<int> > R(2*n+2),C(2*n+2);
  for(int i=0;i<2*n+1;i++) R[xs[i]].emplace_back(i);
  for(int i=0;i<2*n+1;i++) C[ys[i]].emplace_back(i);

  UnionFind uf(2*n+1);
  for(auto &v:R)
    for(auto u:v) uf.unite(v[0],u);
  for(auto &v:C)
    for(auto u:v) uf.unite(v[0],u);

  vector<int> vs;
  for(int i=0;i<2*n+1;i++){
    if(uf.find(i)!=i) continue;
    if(uf.size(i)&1) vs.emplace_back(i);
  }
  assert(!vs.empty());

  if(vs.size()>1u){
    for(int i=0;i<2*n+1;i++) cout<<"NG\n";
    cout<<flush;
    return 0;
  }

  LowLink G(2*n+1);
  auto add_edge=
    [&](auto &V)->void{
      for(auto &v:V){
        if(v.empty()) continue;
        if(!uf.same(vs[0],v[0])) continue;
        if(v.size()>0u) for(auto u:v) G.add_edge(v[0],u);
        if(v.size()>1u) for(auto u:v) G.add_edge(v[1],u);
      }
    };
  add_edge(R);
  add_edge(C);

  G.build();
  auto ap=G.ap;

  vector<int> ans(2*n+1,0);
  for(int i=0;i<2*n+1;i++)
    if(uf.same(vs[0],i)) ans[i]=1;

  for(int v:ap){
    if(!uf.same(vs[0],v)) continue;
    for(int u:G.G[v]){
      if(G.par[u]!=v) continue;
      if(~G.par[v]&&G.ord[v]>G.low[u]) continue;
      if(G.num[u]&1) ans[v]=0;
    }
  }

  for(int i=0;i<2*n+1;i++) cout<<(ans[i]?"OK\n":"NG\n");
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/25
  https://atcoder.jp/contests/arc045/tasks/arc045_d
*/


signed ARC062_F(){
  int n,m,k;
  cin>>n>>m>>k;

  using P = pair<int, int>;
  map<P, int> idx;

  LowLink G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.add_edge(a,b);
    idx[P(a,b)]=idx[P(b,a)]=i;
  }

  G.build();

  UnionFind uf(m);
  for(auto vs:G.E)
    for(auto p:vs) uf.unite(idx[p],idx[vs[0]]);

  vector<set<int>> cnt(m);
  for(auto vs:G.E){
    for(auto p:vs){
      cnt[uf.find(idx[p])].emplace(p.first);
      cnt[uf.find(idx[p])].emplace(p.second);
    }
  }

  using M = Mint<int>;
  using E = Enumeration<M>;
  E::init(1000);

  auto calc1=
    [&](int x)->M{
      M res{0};

      for(int i=0;i<x;i++)
        res+=M(k).pow(__gcd(i,x));

      res*=E::Invs(x);
      return res;
    };

  M ans{1};
  for(int i=0;i<m;i++){
    if(uf.find(i)!=i) continue;
    if(uf.size(i)< (int)cnt[i].size()) ans*=M(k).pow(uf.size(i));
    if(uf.size(i)==(int)cnt[i].size()) ans*=calc1(uf.size(i));
    if(uf.size(i)> (int)cnt[i].size()) ans*=E::H(uf.size(i),k);
  }
  cout<<ans.v<<endl;
  return 0;
}
/*
  verified on 2020/02/19
  https://atcoder.jp/contests/arc062/tasks/arc062_d
*/


signed main(){
  //ARC045_D();
  //ARC062_F();
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: graph/lowlink.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

