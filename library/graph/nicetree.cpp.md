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


# :heavy_check_mark: graph/nicetree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/nicetree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-21 01:02:30+09:00




## Depends on

* :heavy_check_mark: <a href="../tools/chminmax.cpp.html">tools/chminmax.cpp</a>
* :heavy_check_mark: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2405.test.cpp.html">test/aoj/2405.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct NiceTree{
  vector< vector<int> > G;
  vector< set<int> > ex;
  vector<int> buff;
  NiceTree(int n):G(n),ex(n),buff(n){}

  void add_edge(int u,int v){
    if(u>v) swap(u,v);
    if(ex[u].count(v)) return;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
    ex[u].emplace(v);
  }

  enum Type{LEAF, JOIN, INTRODUCE, FORGET};
  struct Node{
    int type,is_root;
    Node():type(-1),is_root(1){}

    // index for G
    vector<int> bag;
    void add_vertex(int v){bag.emplace_back(v);}

    // index for T
    vector<int> child;
    void add_child(int v){child.emplace_back(v);}
  };

  vector<Node> T;
  void to_nice(){
    for(auto &vs:T){
      sort(vs.bag.begin(),vs.bag.end());
      for(int c:vs.child) T[c].is_root=0;
    }

    stack<int> st;
    for(int i=0;i<(int)T.size();i++)
      if(T[i].is_root) st.emplace(i);

    while(!st.empty()){
      int v=st.top();st.pop();

      while(T[v].child.size()>2){
        Node r;
        r.add_child(T[v].child.back());
        T[v].child.pop_back();
        r.add_child(T[v].child.back());
        T[v].child.pop_back();
        r.bag=T[v].bag;
        T[v].add_child(T.size());
        T.emplace_back(r);
      }

      if(T[v].child.size()==2){
        for(auto &u:T[v].child){
          if(T[u].bag!=T[v].bag){
            Node r;
            r.add_child(u);
            r.bag=T[v].bag;
            u=T.size();
            T.emplace_back(r);
          }
        }
        T[v].type=JOIN;
      }

      if(T[v].child.size()==1){
        int &u=T[v].child[0];
        vector<int> latte,malta;
        auto &ps=T[v].bag;
        auto &qs=T[u].bag;
        set_difference(ps.begin(),ps.end(),qs.begin(),qs.end(),
                       back_inserter(latte));
        set_difference(qs.begin(),qs.end(),ps.begin(),ps.end(),
                       back_inserter(malta));
        if(latte.size()+malta.size()>1){
          Node r;
          r.add_child(u);
          r.bag=T[v].bag;
          if(!latte.empty()){
            r.bag.erase(find(r.bag.begin(),r.bag.end(),latte.back()));
          }else{
            r.bag.emplace_back(malta.back());
          }
          u=T.size();
          T.emplace_back(r);
        }
        if(T[v].bag.size()<T[u].bag.size()) T[v].type=FORGET;
        if(T[v].bag.size()>T[u].bag.size()) T[v].type=INTRODUCE;
      }

      if(T[v].child.empty()){
        if(T[v].bag.size()>1){
          Node r;
          r.bag=T[v].bag;
          r.bag.pop_back();
          T[v].type=INTRODUCE;
          T[v].add_child(T.size());
          T.emplace_back(r);
        }else{
          T[v].type=LEAF;
        }
      }

      for(auto &u:T[v].child)
        st.emplace(u);
    }

    for(auto &vs:T)
      for(int c:vs.child) T[c].is_root=0;
  }

  // root = 0 (if connected)
  void build(){
    int n=G.size();
    if(n<=3){
      Node r;
      for(int i=0;i<n;i++) r.add_vertex(i);
      T=vector<Node>({r});
      return to_nice();
    }

    vector<int> deg(n);
    queue<int> que;
    for(int i=0;i<n;i++){
      deg[i]=G[i].size();
      if(deg[i]<=2) que.emplace(i);
    }

    vector<int> used(n,-1);
    T.emplace_back();
    while(!que.empty()){
      int v=que.front();que.pop();
      if(deg[v]>2||used[v]!=-1) continue;
      Node r;
      r.add_vertex(v);

      int p=-1,q=-1;
      for(int u:G[v]){
        if(used[u]==-1){
          (p==-1?p:q)=u;
          r.add_vertex(u);
        }else if(used[u]>=0){
          r.add_child(used[u]);
          used[u]=-2;
        }
      }

      if(deg[v]==0){
        used[v]=T.size();
        T.emplace_back(r);
        continue;
      }

      if(q==-1){
        deg[p]--;
      }else{
        if(p>q) swap(p,q);
        if(!ex[p].count(q)){
          add_edge(p,q);
        }else{
          deg[p]--;
          deg[q]--;
        }
      }
      for(int u:G[v])
        if(deg[u]<=2) que.emplace(u);
      deg[v]=0;
      used[v]=T.size();
      T.emplace_back(r);
    }

    for(int i=0;i<n;i++){
      if(deg[i]>0){
        T={};
        return;
      }
    }

    T.front()=T.back();T.pop_back();
    to_nice();
  }

  template<typename F1,typename F2,typename F3,typename F4>
  void dfs(int v,F1 &leaf,F2 &join,F3 &introduce,F4 &forget){
    const auto &chd=T[v].child;
    for(int u:chd) dfs(u,leaf,join,introduce,forget);

    if(T[v].type==LEAF){
      leaf(v);
      return;
    }
    if(T[v].type==JOIN){
      join(v);
      return;
    }

    const auto &bag=T[v].bag;
    for(int i=0;i<(int)bag.size();i++)
      buff[bag[i]]=1<<i;

    const auto &chd_bag=T[chd[0]].bag;
    int dif=0;
    for(int b:bag) dif^=b;
    for(int b:chd_bag) dif^=b;

    if(T[v].type==INTRODUCE){
      introduce(v,dif);
      return;
    }
    if(T[v].type==FORGET){
      forget(v,dif);
      return;
    }
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../tools/chminmax.cpp"
#undef call_from_test

signed CSA_SPECIAL_MVC(){
  int n,m;
  cin>>n>>m;
  NiceTree G(n);
  using P = pair<int, int>;
  set<P> es;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.add_edge(a,b);
    es.emplace(a,b);
    es.emplace(b,a);
  }

  G.build();
  auto &T=G.T;
  auto &buff=G.buff;

  vector< vector<int> > dps(T.size());

  const int INF = 1e9;
  auto base=
    [&](int v){
      const auto &bag=T[v].bag;
      auto &dp=dps[v];
      dp.assign(1<<bag.size(),-INF);
    };

  auto leaf=
    [&](int v){
      base(v);
      auto &dp=dps[v];
      dp[0]=0;
      dp[1]=1;
    };

  auto join=
    [&](int v){
      base(v);
      const auto &chd=T[v].child;
      auto &dp=dps[v];
      for(int i=0;i<(int)dp.size();i++)
        chmax(dp[i],dps[chd[0]][i]+dps[chd[1]][i]-__builtin_popcount(i));
    };

  auto introduce=
    [&](int v,int add){
      base(v);

      const auto &chd=T[v].child;
      const auto &chd_bag=T[chd[0]].bag;
      const auto &pr=dps[chd[0]];

      auto &dp=dps[v];
      for(int i=0;i<(int)pr.size();i++){
        int bit=0,valid=1;
        for(int j=0;j<(int)chd_bag.size();j++){
          if((~i>>j)&1) continue;
          bit|=buff[chd_bag[j]];
          valid&=!es.count(P(chd_bag[j],add));
        }
        assert(!(bit&buff[add]));
        if(valid) chmax(dp[bit|buff[add]],pr[i]+1);
        chmax(dp[bit],pr[i]);
      }
    };

  auto forget=
    [&](int v,int rmv){
      base(v);

      const auto &chd=T[v].child;
      const auto &chd_bag=T[chd[0]].bag;
      const auto &pr=dps[chd[0]];

      auto &dp=dps[v];
      for(int i=0;i<(int)pr.size();i++){
        int bit=0;
        for(int j=0;j<(int)chd_bag.size();j++){
          if((~i>>j)&1) continue;
          if(rmv!=chd_bag[j]) bit|=buff[chd_bag[j]];
        }
        chmax(dp[bit],pr[i]);
      }
    };

  int ans=n;
  for(int i=0;i<(int)T.size();i++){
    if(!T[i].is_root) continue;
    G.dfs(i,leaf,join,introduce,forget);
    ans-=*max_element(dps[i].begin(),dps[i].end());
  }
  cout<<ans<<endl;
  return 0;
}
/*
  verified 2020/02/21
  https://csacademy.com/contest/archive/task/special-mvc/statement/
*/

signed main(){
  CSA_SPECIAL_MVC();
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: graph/nicetree.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

