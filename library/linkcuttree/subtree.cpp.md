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


# :heavy_check_mark: linkcuttree/subtree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e406bcf916b254ab0f908ae657d2d754">linkcuttree</a>
* <a href="{{ site.github.repository_url }}/blob/master/linkcuttree/subtree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-07 13:27:51+09:00




## Depends on

* :heavy_check_mark: <a href="base.cpp.html">linkcuttree/base.cpp</a>
* :heavy_check_mark: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/3120.test.cpp.html">test/aoj/3120.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp.html">test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp.html">test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Ap>
struct NodeBase{
  using A = Ap;
  NodeBase *l,*r,*p;
  bool rev;
  A val,dat,sum;
  NodeBase(){}
  NodeBase(A val,A dat,A sum):
    rev(0),val(val),dat(dat),sum(sum){
    l=r=p=nullptr;}
};

template<typename Np, size_t LIM>
struct SubTree : LinkCutTreeBase<Np, LIM>{
  using super = LinkCutTreeBase<Np, LIM>;
  using Node = Np;
  using A = typename Node::A;

  SubTree():super(){}

  Node* create(A val){
    return super::create(Node(val,A(),val));
  }

  inline void toggle(Node *t){
    swap(t->l,t->r);
    t->rev^=1;
  }

  inline Node* eval(Node *t){
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
    return t;
  }

  inline A resolve(Node *t){
    return t?t->sum:A();
  }

  inline void pushup(Node *t){
    if(t==nullptr) return;
    t->sum=t->val+t->dat;
    t->sum+=resolve(t->l);
    t->sum+=resolve(t->r);
  }

  using super::splay;

  Node* expose(Node *t){
    Node *rp=nullptr;
    for(Node *c=t;c;c=c->p){
      splay(c);
      c->dat+=resolve(c->r);
      c->r=rp;
      c->dat-=resolve(c->r);
      pushup(c);
      rp=c;
    }
    splay(t);
    return rp;
  }

  A query(Node *t){
    expose(t);
    return t->sum;
  }

  void set_val(Node *t,A a){
    expose(t);
    t->val=a;
    pushup(t);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#undef call_from_test

//INSERT ABOVE HERE

// sum of square
signed CFR564_E(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> modv(n),modt(n);
  vector<int> cs(n);

  for(int i=0;i<n;i++){
    cin>>cs[i];
    cs[i]--;
    modv[cs[i]].emplace_back(i);
    modt[cs[i]].emplace_back(0);
  }

  vector<vector<int> > G(n+1);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  G[n].emplace_back(0);

  for(int i=1;i<=m;i++){
    int v,x;
    cin>>v>>x;
    v--;x--;
    modv[cs[v]].emplace_back(v);
    modt[cs[v]].emplace_back(i);
    cs[v]=x;
    modv[cs[v]].emplace_back(v);
    modt[cs[v]].emplace_back(i);
  }

  using ll = long long;
  struct A{
    ll sz1,sz2;
    A():sz1(0),sz2(){}
    A(ll sz1,ll sz2):sz1(sz1),sz2(sz2){}
    A operator+(const A &a)const{
      return A(sz1+a.sz1,sz2+a.sz2);
    };
    A& operator+=(const A &a){
      sz1+=a.sz1;
      sz2+=a.sz1*a.sz1;
      return (*this);
    }
    A& operator-=(const A &a){
      sz1-=a.sz1;
      sz2-=a.sz1*a.sz1;
      return (*this);
    }
  };

  using Node = NodeBase<A>;
  constexpr size_t LIM = 1e6;
  using LCT = SubTree<Node, LIM>;
  LCT lct;

  for(int i=0;i<n+1;i++) lct.create(A(1,0));

  vector<int> par(n+1,0);
  {
    using P = pair<int, int>;
    queue<P> q;
    q.emplace(n,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      par[v]=p;
      if(~p) lct.link(lct[p],lct[v]);
      for(int u:G[v])
        if(u!=p) q.emplace(u,v);
    }
  }

  vector<ll> delta(m+1,0);
  vector<int> color(n+1,0);

  for(int c=0;c<n;c++){
    ll lst=(ll)n*n,cur=(ll)n*n;
    delta[0]+=lst;

    if(modv[c].empty()) continue;
    for(int i=0;i<(int)modv[c].size();i++){
      int v=modv[c][i];
      color[v]^=1;
      if(color[v]){
        cur-=lct.query(lct.root(lct[v])).sz2;
        lct.cut(lct[v]);
        cur+=lct.query(lct.root(lct[par[v]])).sz2;
        cur+=lct.query(lct[v]).sz2;
      }else{
        cur-=lct.query(lct.root(lct[par[v]])).sz2;
        cur-=lct.query(lct[v]).sz2;
        lct.link(lct[par[v]],lct[v]);
        cur+=lct.query(lct.root(lct[v])).sz2;
      }
      if(i+1==(int)modv[c].size()||modt[c][i]!=modt[c][i+1]){
        delta[modt[c][i]]+=cur-lst;
        lst=cur;
      }
    }

    for(int i=0;i<(int)modv[c].size();i++){
      int v=modv[c][i];
      if(!color[v]) continue;
      color[v]^=1;
      lct.link(lct[par[v]],lct[v]);
    }
  }

  ll ans=(ll)n*n*n;
  for(int i=0;i<=m;i++){
    ans-=delta[i];
    cout<<ans<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2020/01/06
  https://codeforces.com/contest/1172/problem/E
*/

// test root
signed NIKKEI2019_QUAL_E(){
  int n,m;
  cin>>n>>m;
  vector<int> xs(n);
  for(int i=0;i<n;i++) cin>>xs[i];
  using T = tuple<int, int, int>;
  vector<T> vt;
  for(int i=0;i<m;i++){
    int a,b,y;
    cin>>a>>b>>y;
    a--;b--;
    vt.emplace_back(y,a,b);
  }
  sort(vt.begin(),vt.end());

  using ll = long long;
  using Node = NodeBase<ll>;
  constexpr size_t LIM = 1e6;
  using LCT = SubTree<Node, LIM>;
  LCT lct;

  for(int i=0;i<n;i++) lct.create(xs[i]);

  using P = pair<int, int>;
  set<P> es;
  for(auto t:vt){
    int a,b;
    tie(ignore,a,b)=t;
    if(lct.is_connected(lct[a],lct[b])) continue;
    lct.evert(lct[b]);
    lct.link(lct[a],lct[b]);
    es.emplace(a,b);
  }

  int ans=0;
  reverse(vt.begin(),vt.end());
  for(auto t:vt){
    int y,a,b;
    tie(y,a,b)=t;
    auto rt=lct.root(lct[a]);
    ll sum=lct.query(rt);
    if(sum>=y) continue;
    ans++;
    if(es.count(P(a,b))){
      lct.evert(lct[a]);
      lct.cut(lct[b]);
    }
  }

  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2020/01/06
  https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_e
*/

signed main(){
  //CFR564_E();
  //NIKKEI2019_QUAL_E();
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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: linkcuttree/base.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

