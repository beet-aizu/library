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
    - Last commit date: 2019-12-09 23:51:01 +0900




## Depends on

* :heavy_check_mark: <a href="../datastructure/binaryindexedtree.cpp.html">datastructure/binaryindexedtree.cpp</a>
* :heavy_check_mark: <a href="base.cpp.html">linkcuttree/base.cpp</a>
* :warning: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Verified with

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
  int idx;
  bool rev;
  A val,dat,sum;
  NodeBase(){}
  NodeBase(int idx,A val,A dat,A sum):
    idx(idx),rev(0),val(val),dat(dat),sum(sum){
    l=r=p=nullptr;}
};

template<typename Np, size_t LIM>
struct SubTree : LinkCutTreeBase<Np, LIM>{
  using super = LinkCutTreeBase<Np, LIM>;
  using Node = Np;
  using A = typename Node::A;

  SubTree():super(){}

  Node* create(int idx,A val){
    return super::create(Node(idx,val,A(),val));
  }

  inline void toggle(Node *t){
    swap(t->l,t->r);
    t->rev^=1;
  }

  inline void eval(Node *t){
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
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
#include "../datastructure/binaryindexedtree.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed UNIVERSITYCODESPRINT03_G(){
  using ll = long long;
  int n;
  cin>>n;
  BIT<ll> bit(1e6+100);
  vector<int> as(n),bs(n),cs(n);

  vector<unordered_map<int, vector<int> > > G(n);
  vector<unordered_map<int, int > > R(n);

  using P =  pair<int,int>;
  vector<P> edges;

  int sz=0;
  auto add_edge=[&](int x,int e){
                  edges.push_back(P(x,e));
                  if(!R[as[x]].count(e)) R[as[x]][e]=sz++;
                  if(!R[bs[x]].count(e)) R[bs[x]][e]=sz++;
                  G[as[x]][e].emplace_back(bs[x]);
                  G[bs[x]][e].emplace_back(as[x]);
                };

  for(int i=0;i+1<n;i++){
    cin>>as[i]>>bs[i]>>cs[i];
    as[i]--;bs[i]--;
    add_edge(i,cs[i]);
  }

  int Q;
  cin>>Q;
  vector<int> T(Q),A(Q),B(Q);
  for(int i=0;i<Q;i++){
    cin>>T[i];
    int t=T[i];
    if(t==1){
      cin>>A[i]>>B[i];
      int x=A[i],e=B[i];
      x--;
      add_edge(x,e);
    }
    if(t==2){
      cin>>A[i]>>B[i];
    }
    if(t==3){
      cin>>A[i];
    }
  }

  using Node = NodeBase<int>;
  constexpr size_t LIM = 1e6;
  using LCT = SubTree<Node, LIM>;
  LCT lct;

  vector<LCT::Node*> vs(sz);
  for(int i=0;i<sz;i++) vs[i]=lct.create(i,1);

  vector<int> used(sz,0),ps(sz);
  auto calc=[](ll x)->ll{return x*(x-1)/2;};

  for(int i=0;i<n;i++){
    for(auto x:R[i]){
      if(used[x.second]) continue;
      int c=x.first;
      queue<P> q;
      q.emplace(i,-1);
      used[R[i][c]]=1;
      ps[R[i][c]]=-1;
      while(!q.empty()){
        int v,p;
        tie(v,p)=q.front();q.pop();
        if(~p) lct.link(vs[R[p][c]],vs[R[v][c]]);
        for(int u:G[v][c]){
          if(u==p||used[R[u][c]]) continue;
          q.emplace(u,v);
          used[R[u][c]]=1;
          ps[R[u][c]]=R[v][c];
        }
      }
      bit.add(c,calc(lct.query(vs[R[i][c]])));
    }
  }

  auto cut=[&](int x,int e){
             int p=R[as[x]][e],q=R[bs[x]][e];
             if(ps[q]!=p) swap(p,q);
             bit.add(e,-calc(lct.query(vs[p])));

             lct.cut(vs[q]);

             bit.add(e,calc(lct.query(vs[p])));
             bit.add(e,calc(lct.query(vs[q])));
           };

  auto con=[&](int x,int e){
             int p=R[as[x]][e],q=R[bs[x]][e];
             if(ps[q]!=p) swap(p,q);
             bit.add(e,-calc(lct.query(vs[p])));
             bit.add(e,-calc(lct.query(vs[q])));

             lct.link(vs[p],vs[q]);

             bit.add(e,calc(lct.query(vs[p])));
           };

  sort(edges.begin(),edges.end());
  edges.erase(unique(edges.begin(),edges.end()),edges.end());
  for(auto p:edges){
    int x=p.first,e=p.second;
    if(cs[x]!=e) cut(x,e);
  }

  for(int i=0;i<Q;i++){
    int t=T[i];
    if(t==1){
      int x=A[i],e=B[i];
      x--;
      if(cs[x]==e) continue;
      cut(x,cs[x]);
      con(x,e);
      cs[x]=e;
    }
    if(t==2){
      int l=A[i],r=B[i];
      cout<<bit.query(l,r+1)<<"\n";
    }
    if(t==3){
      int x=A[i];
      x--;
      int p=R[as[x]][cs[x]];
      cout<<calc(lct.query(vs[p]))<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/25
  https://www.hackerrank.com/contests/university-codesprint-3/challenges/simple-tree-counting
*/

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

  vector<LCT::Node*> vs(n+1);
  for(int i=0;i<(int)vs.size();i++)
    vs[i]=lct.create(i,A(1,0));

  vector<int> par(n+1,0);
  {
    using P = pair<int, int>;
    queue<P> q;
    q.emplace(n,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      par[v]=p;
      if(~p) lct.link(vs[p],vs[v]);
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
        cur-=lct.query(lct.root(vs[v])).sz2;
        lct.cut(vs[v]);
        cur+=lct.query(lct.root(vs[par[v]])).sz2;
        cur+=lct.query(vs[v]).sz2;
      }else{
        cur-=lct.query(lct.root(vs[par[v]])).sz2;
        cur-=lct.query(vs[v]).sz2;
        lct.link(vs[par[v]],vs[v]);
        cur+=lct.query(lct.root(vs[v])).sz2;
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
      lct.link(vs[par[v]],vs[v]);
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
  verified on 2019/10/25
  https://codeforces.com/contest/1172/problem/E
*/

signed JOISC2013_DAY4_3(){
  int n,q;
  cin>>n>>q;

  using Node = NodeBase<int>;
  constexpr size_t LIM = 1e6;
  using LCT = SubTree<Node, LIM>;
  LCT lct;

  vector<LCT::Node*> vs(n);
  for(int i=0;i<n;i++) vs[i]=lct.create(i,0);

  for(int i=0;i<q;i++){
    int t,a,b=0;
    cin>>t>>a;
    if(t!=2) cin>>b;
    a--;b--;
    if(t==1) lct.link(vs[b],vs[a]);
    if(t==2) lct.cut(vs[a]);
    if(t==3){
      if(!lct.is_connected(vs[a],vs[b])) cout<<"-1\n";
      else cout<<(lct.lca(vs[a],vs[b])->idx+1)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/25
  https://atcoder.jp/contests/joisc2013-day4/tasks/joisc2013_spaceships
*/

signed SPOJ_DYNACON1(){
  int n,m;
  cin>>n>>m;

  using Node = NodeBase<int>;
  constexpr size_t LIM = 1e6;
  using LCT = SubTree<Node, LIM>;

  LCT lct;
  vector<LCT::Node*> vs(n);
  for(int i=0;i<n;i++) vs[i]=lct.create(i,0);
  for(int i=0;i<m;i++){
    string s;
    int a,b;
    cin>>s>>a>>b;
    a--;b--;
    if(s=="add"s){
      lct.evert(vs[b]);
      lct.link(vs[a],vs[b]);
    }
    if(s=="rem"s){
      auto v=lct.lca(vs[a],vs[b])==vs[a]?vs[b]:vs[a];
      lct.cut(v);
    }
    if(s=="conn"s)
      cout<<(lct.is_connected(vs[a],vs[b])?"YES\n":"NO\n");
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/25
  https://www.spoj.com/problems/DYNACON1/
*/

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

  vector<LCT::Node*> vs(n);
  for(int i=0;i<n;i++)
    vs[i]=lct.create(i,xs[i]);

  using P = pair<int, int>;
  set<P> es;
  for(auto t:vt){
    int a,b;
    tie(ignore,a,b)=t;
    if(lct.is_connected(vs[a],vs[b])) continue;
    lct.evert(vs[b]);
    lct.link(vs[a],vs[b]);
    es.emplace(a,b);
  }

  int ans=0;
  reverse(vt.begin(),vt.end());
  for(auto t:vt){
    int y,a,b;
    tie(y,a,b)=t;
    auto rt=lct.root(vs[a]);
    ll sum=lct.query(rt);
    if(sum>=y) continue;
    ans++;
    if(es.count(P(a,b))){
      lct.evert(vs[a]);
      lct.cut(vs[b]);
    }
  }

  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/10/31
  https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_e
*/

signed main(){
  //UNIVERSITYCODESPRINT03_G();
  //CFR564_E();
  //JOISC2013_DAY4_3();
  //SPOJ_DYNACON1();
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
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 173, in main
    subcommand_run(paths=[])
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 70, in subcommand_run
    onlinejudge_verify.verify.main(paths, marker=marker, timeout=timeout)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 87, in main
    exec_command(command)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 26, in exec_command
    subprocess.check_call(command)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/subprocess.py", line 364, in check_call
    raise CalledProcessError(retcode, cmd)
subprocess.CalledProcessError: Command '['oj', 'test', '-c', '.verify-helper/cache/c36a49005ac83bc17634badc8dd1bcb9/a.out', '-d', '.verify-helper/cache/c36a49005ac83bc17634badc8dd1bcb9/test', '-e', '\'"1e-8"\'']' returned non-zero exit status 2.

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 345, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 156, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 54, in _resolve
    raise BundleError(path, -1, "no such header")
onlinejudge_verify.bundle.BundleError: base.cpp: line -1: no such header

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

