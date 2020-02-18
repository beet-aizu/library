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


# :warning: tree/sack.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/sack.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-23 16:53:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Sack{
  using F = function<void(int)>;
  int n;
  vector<int> sz,hvy,big;
  vector<vector<int> > G,Q;
  F expand,shrink,query,reset;

  Sack(int n,F expand,F shrink,F query,F reset):
    sz(n,1),hvy(n,-1),big(n,0),G(n),Q(n),
    expand(expand),shrink(shrink),
    query(query),reset(reset){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void add_query(int v,int k){
    Q[v].emplace_back(k);
    sz[v]++;
  }

  void build(int v=0,int p=-1){
    for(int u:G[v]){
      if(u==p) continue;
      build(u,v);
      if(hvy[v]<0||sz[hvy[v]]<sz[u]) hvy[v]=u;
      sz[v]+=sz[u];
    }
  }

  void add(int v,int p,int x){
    if(x==1) expand(v);
    else shrink(v);
    for(int u:G[v])
      if(u!=p&&!big[u]) add(u,v,x);
  }

  void dfs(int v=0,int p=-1,bool k=0){
    for(int u:G[v])
      if(u!=p&&u!=hvy[v]) dfs(u,v,0);
    if(~hvy[v]){
      dfs(hvy[v],v,1);
      big[hvy[v]]=1;
    }
    add(v,p,1);
    for(int k:Q[v]) query(k);
    if(~hvy[v]) big[hvy[v]]=0;
    if(!k) add(v,p,0),reset(v);
  }

};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed ECR002_E(){
  using ll = long long;
  int n;
  scanf("%d",&n);
  vector<int> c(n);
  for(int i=0;i<n;i++) scanf("%d",&c[i]);
  vector<int> cnt(n+1,0);
  vector<ll> ans(n,0);
  int mx=0;
  ll res=0;
  auto expand=
    [&](int v){
      cnt[c[v]]++;
      if(mx<cnt[c[v]]){
        mx=cnt[c[v]];
        res=0;
      }
      if(mx==cnt[c[v]]) res+=c[v];
    };
  auto shrink=[&](int v){cnt[c[v]]--;};
  auto query =[&](int v){ans[v]=res;};
  auto reset =[&](int v){(void)v;mx=res=0;};
  Sack sc(n,expand,shrink,query,reset);
  for(int i=1;i<n;i++){
    int x,y;
    scanf("%d %d",&x,&y);
    x--;y--;
    sc.add_edge(x,y);
  }
  sc.build();
  for(int i=0;i<n;i++) sc.add_query(i,i);
  sc.dfs();
  for(int i=0;i<n;i++){
    if(i) printf(" ");
    printf("%lld",ans[i]);
  }
  puts("");
  return 0;
}
/*
  verified on 2019/11/23
  http://codeforces.com/contest/600/problem/E
*/

signed CFR316_D(){
  int n,q;
  scanf("%d %d",&n,&q);

  vector<int> c(n),dep(n);
  vector<int> vs(q),hs(q),ans(q);
  vector<int> cnt(n+1,0),odd(n+1,0);

  auto flip=
    [&](int v){
      odd[dep[v]]-=(cnt[dep[v]]>>c[v])&1;
      cnt[dep[v]]^=(1<<c[v]);
      odd[dep[v]]+=(cnt[dep[v]]>>c[v])&1;
    };

  auto query =[&](int k){ans[k]=odd[hs[k]]<=1;};
  auto reset =[&](int v){(void)v;};

  Sack sc(n,flip,flip,query,reset);
  for(int i=1;i<n;i++){
    int p;
    scanf("%d",&p);
    p--;
    sc.add_edge(p,i);
  }
  sc.build();

  {
    auto &G=sc.G;
    function<void(int,int,int)> dfs=
      [&](int v,int p,int d){
        dep[v]=d;
        for(int u:G[v]){
          if(u==p) continue;
          dfs(u,v,d+1);
        }
      };
    dfs(0,-1,1);
  }

  char* buf = new char[500500];
  scanf("%s",buf);
  for(int i=0;i<n;i++) c[i]=buf[i]-'a';

  for(int i=0;i<q;i++){
    scanf("%d %d",&vs[i],&hs[i]);
    vs[i]--;
    sc.add_query(vs[i],i);
  }

  sc.dfs();
  for(int i=0;i<q;i++)
    puts(ans[i]?"Yes":"No");
  return 0;
}
/*
  verified on 2019/11/23
  http://codeforces.com/contest/570/problem/D
*/

signed CFR130_E(){
  int n;
  scanf("%d",&n);

  vector<int> dep(n),rs;
  vector<int> vs,hs,ans;
  vector<int> cnt(n+1,0);

  auto expand=[&](int v){cnt[dep[v]]++;};
  auto shrink=[&](int v){cnt[dep[v]]--;};
  auto query =[&](int k){ans[k]=cnt[dep[vs[k]]+hs[k]]-1;};
  auto reset =[&](int v){(void)v;};

  Sack sc(n,expand,shrink,query,reset);
  for(int i=0;i<n;i++){
    int p;
    scanf("%d",&p);
    p--;
    if(~p) sc.add_edge(p,i);
    else rs.emplace_back(i);
  }
  sc.build();

  vector<vector<int> > ps(20,vector<int>(n,-1));
  {
    auto &G=sc.G;
    function<void(int,int,int)> dfs=
      [&](int v,int p,int d){
        ps[0][v]=p;
        dep[v]=d;
        for(int u:G[v]){
          if(u==p) continue;
          dfs(u,v,d+1);
        }
      };
    for(int r:rs) dfs(r,-1,1);
  }

  int q;
  scanf("%d",&q);
  vs.assign(q,0);
  hs.assign(q,0);
  ans.assign(q,0);

  for(int k=0;k+1<20;k++)
    for(int i=0;i<n;i++)
      ps[k+1][i]=ps[k][i]<0?-1:ps[k][ps[k][i]];

  auto calc=[&](int v,int k){
              for(int i=0;~v&&i<20;i++)
                if((k>>i)&1) v=ps[i][v];
              return v;
            };

  for(int i=0;i<q;i++){
    scanf("%d %d",&vs[i],&hs[i]);
    vs[i]--;
    vs[i]=calc(vs[i],hs[i]);
    if(~vs[i]) sc.add_query(vs[i],i);
  }

  for(int r:rs) sc.dfs(r,-1,0);
  for(int i=0;i<q;i++){
    if(i) printf(" ");
    printf("%d",ans[i]);
  }
  puts("");
  return 0;
}
/*
  verified on 2019/11/23
  https://codeforces.com/contest/208/problem/E
*/

signed main(){
  //ECR002_E();
  //CFR316_D();
  //CFR130_E();
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: tree/sack.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

