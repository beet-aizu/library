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


# :heavy_check_mark: tree/eulertourforvertex.cpp
<a href="../../index.html">Back to top page</a>

* category: tree
* <a href="{{ site.github.repository_url }}/blob/master/tree/eulertourforvertex.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 23:51:01 +0900




## Depends On
* :heavy_check_mark: <a href="../datastructure/binaryindexedtree.cpp.html">datastructure/binaryindexedtree.cpp</a>
* :heavy_check_mark: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>
* :heavy_check_mark: <a href="../tools/fixpoint.cpp.html">tools/fixpoint.cpp</a>
* :heavy_check_mark: <a href="lowestcommonancestor.cpp.html">tree/lowestcommonancestor.cpp</a>


## Verified With
* :heavy_check_mark: <a href="../../verify/test/aoj/2871.test.cpp.html">test/aoj/2871.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html">test/yosupo/vertex_add_subtree_sum.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
class EulerTourForVertex{
private:
  vector<int> ls,rs;
  int pos;

  void dfs(int v,int p){
    ls[v]=pos++;
    for(int u:G[v])
      if(u!=p) dfs(u,v);
    rs[v]=pos;
  }
public:
  vector<vector<int> > G;

  EulerTourForVertex(){}
  EulerTourForVertex(int n):ls(n),rs(n),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build(int r=0){
    pos=0;
    dfs(r,-1);
  }

  int idx(int v){return ls[v];}

  template<typename F>
  void exec(int v,F f){
    f(ls[v],rs[v]);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../tools/fixpoint.cpp"
#include "../datastructure/binaryindexedtree.cpp"
#include "lowestcommonancestor.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed CFR483_E(){
  int n;
  cin>>n;
  LowestCommonAncestor lca(n);
  EulerTourForVertex et(n);
  for(int i=1;i<n;i++){
    int p;
    cin>>p;
    p--;
    lca.add_edge(p,i);
    et.add_edge(p,i);
  }
  lca.build();
  et.build();

  int m;
  cin>>m;
  vector<int> as(m),bs(m);
  for(int i=0;i<m;i++) cin>>as[i]>>bs[i];

  int q;
  cin>>q;
  vector<int> us(q),vs(q);
  for(int i=0;i<q;i++) cin>>us[i]>>vs[i];

  const int LG = 20;
  vector<vector<int> > dp(LG,vector<int>(n,n));
  for(int i=0;i<n;i++) dp[0][i]=i;

  auto check=
    [&](int &a,int b){
      if(a==n||lca.dep[a]>lca.dep[b]) a=b;
    };

  vector<vector<int> > oth(n);
  auto G=et.G;
  for(int i=0;i<m;i++){
    as[i]--;bs[i]--;
    int c=lca.lca(as[i],bs[i]);
    check(dp[0][as[i]],c);
    check(dp[0][bs[i]],c);
    if(bs[i]!=c) oth[as[i]].emplace_back(bs[i]);
    if(as[i]!=c) oth[bs[i]].emplace_back(as[i]);
  }

  MFP([&](auto dfs,int v,int p)->void{
        for(int u:G[v]){
          if(u==p) continue;
          dfs(u,v);
          check(dp[0][v],dp[0][u]);
        }
      })(0,-1);

  for(int k=1;k<LG;k++)
    for(int i=0;i<n;i++)
      check(dp[k][i],dp[k-1][dp[k-1][i]]);

  auto count=
    [&](int x,int y)->int{
      if(lca.dep[dp[LG-1][x]]>lca.dep[y]) return -1;
      int res=0;
      for(int i=LG-1;i>=0;i--){
        if(lca.dep[dp[i][x]]<=lca.dep[y]) continue;
        res+=1<<i;
        x=dp[i][x];
      }
      if(lca.dep[x]>lca.dep[y]){
        res++;
        x=dp[0][x];
      }
      assert(lca.dep[x]<=lca.dep[y]);
      return res;
    };

  auto climb=
    [&](int x,int d)->int{
      for(int i=0;i<LG;i++)
        if((d>>i)&1) x=dp[i][x];
      return x;
    };

  vector<int> ans(q),red(q,0);
  using P = pair<int, int>;
  vector< vector<P> > idx(n);
  for(int i=0;i<q;i++){
    us[i]--;vs[i]--;
    if(lca.dep[us[i]]<lca.dep[vs[i]]) swap(us[i],vs[i]);
    int c=lca.lca(us[i],vs[i]);
    if(vs[i]==c){
      ans[i]=count(us[i],vs[i]);
      continue;
    }
    int x=count(us[i],c);
    int y=count(vs[i],c);
    if(x<0||y<0){
      ans[i]=-1;
      continue;
    }
    ans[i]=x+y;
    int f=climb(us[i],x-1);
    int g=climb(vs[i],y-1);
    idx[f].emplace_back(i,g);
    idx[g].emplace_back(i,f);
  }

  BIT<int> bit(n+10,0);
  MFP([&](auto dfs,int v,int p)->void{
        int sz=idx[v].size();
        vector<int> cur(sz);
        for(int i=0;i<sz;i++){
          int op=idx[v][i].second;
          et.exec(op,[&](int l,int r){cur[i]=bit.query0(l,r);});
        }
        for(int u:oth[v]) bit.add0(et.idx(u),1);
        for(int u:G[v])
          if(u!=p) dfs(u,v);

        for(int i=0;i<sz;i++){
          int k=idx[v][i].first;
          int op=idx[v][i].second;
          et.exec(op,[&](int l,int r){red[k]|=cur[i]<bit.query0(l,r);});
        }
      })(0,-1);

  for(int i=0;i<q;i++){
    if(red[i]) ans[i]--;
    if(ans[i]<0) ans[i]=-1;
    cout<<ans[i]<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/25
  http://codeforces.com/contest/983/problem/E
*/

signed main(){
  CFR483_E();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

