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


# :heavy_check_mark: linkcuttree/path.cpp
<a href="../../index.html">Back to top page</a>

* category: linkcuttree
* <a href="{{ site.github.repository_url }}/blob/master/linkcuttree/path.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 23:51:01 +0900




## Dependencies
* :heavy_check_mark: <a href="../linearalgebra/squarematrix.cpp.html">linearalgebra/squarematrix.cpp</a>
* :heavy_check_mark: <a href="base.cpp.html">linkcuttree/base.cpp</a>
* :heavy_check_mark: <a href="../mod/mint.cpp.html">mod/mint.cpp</a>
* :heavy_check_mark: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Verified
* :heavy_check_mark: <a href="../../verify/test/aoj/0367.linkcuttree.test.cpp.html">test/aoj/0367.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2450.linkcuttree.test.cpp.html">test/aoj/2450.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_D.linkcuttree.test.cpp.html">test/aoj/GRL_5_D.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_E.linkcuttree.test.cpp.html">test/aoj/GRL_5_E.linkcuttree.test.cpp</a>


## Code
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
template<typename Tp,typename Ep>
struct NodeBase{
  using T = Tp;
  using E = Ep;
  NodeBase *l,*r,*p;
  int idx;
  bool rev;
  T val,dat;
  E laz;
  NodeBase(){}
  NodeBase(int idx,T val,E laz):
    idx(idx),rev(0),val(val),dat(val),laz(laz){
    l=r=p=nullptr;}
};

template<typename Np, size_t LIM>
struct Path : LinkCutTreeBase<Np, LIM>{
  using super = LinkCutTreeBase<Np, LIM>;
  using Node = Np;
  using T = typename Node::T;
  using E = typename Node::E;

  using F = function<T(T, T)>;
  using G = function<T(T, E)>;
  using H = function<E(E, E)>;
  using S = function<T(T)>;
  F f;
  G g;
  H h;
  S flip;
  T ti;
  E ei;

  Path(F f,G g,H h,T ti,E ei):
    super(),f(f),g(g),h(h),ti(ti),ei(ei){
    flip=[](T a){return a;};
  }

  Path(F f,G g,H h,S flip,T ti,E ei):
    super(),f(f),g(g),h(h),flip(flip),ti(ti),ei(ei){}

  Node* create(int idx,T val){
    return super::create(Node(idx,val,ei));
  }

  inline void propagate(Node *t,E v){
    t->laz=h(t->laz,v);
    t->val=g(t->val,v);
    t->dat=g(t->dat,v);
  }

  inline void toggle(Node *t){
    swap(t->l,t->r);
    t->dat=flip(t->dat);
    t->rev^=1;
  }

  inline void eval(Node *t){
    if(t->laz!=ei){
      if(t->l) propagate(t->l,t->laz);
      if(t->r) propagate(t->r,t->laz);
      t->laz=ei;
    }
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
  }

  inline void pushup(Node *t){
    t->dat=t->val;
    if(t->l) t->dat=f(t->l->dat,t->dat);
    if(t->r) t->dat=f(t->dat,t->r->dat);
  }

  using super::expose;

  T query(Node *t){
    expose(t);
    return t->dat;
  }

  void update(Node *t,E v){
    expose(t);
    propagate(t,v);
    eval(t);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../mod/mint.cpp"
#include "../linearalgebra/squarematrix.cpp"
#undef call_from_test

//INSERT ABOVE HERE

signed YUKI_650(){
  using M = Mint<int>;
  using SM = SquareMatrix<M, 2>;
  using SM2 = pair<SM, SM>;
  using Node = NodeBase<SM2, SM2>;
  constexpr size_t LIM = 1e6;
  using LCT = Path<Node, LIM>;

  auto f=[](SM2 x,SM2 y){return SM2(x.first*y.first,y.second*x.second);};
  auto g=[](SM2 x,SM2 y){(void)x;return y;};
  auto flip=[](SM2 x){swap(x.first,x.second);return x;};

  SM ti=SM::mul_identity();
  SM ei=SM::mul_identity();
  SM2 ti2(ti,ti),ei2(ei,ei);
  LCT lct(f,g,g,flip,ti2,ei2);

  int n;
  cin>>n;
  vector< vector<int> > G(n);
  vector<int> X,Y;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    X.emplace_back(a);
    Y.emplace_back(b);
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  vector<LCT::Node*> vs(n*2-1);
  for(int i=0;i<(int)vs.size();i++)
    vs[i]=lct.create(i,ti2);

  vector< map<int, int> > rev(n);
  int idx=n;
  {
    using P = pair<int, int>;
    queue<P> q;
    q.emplace(0,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      if(~p){
        lct.link(vs[p],vs[idx]);
        lct.link(vs[idx],vs[v]);
        rev[p][v]=rev[v][p]=idx++;
      }
      for(int u:G[v])
        if(u!=p) q.emplace(u,v);
    }
  }

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    char c;
    cin>>c;
    if(c=='x'){
      int v,a,b,c,d;
      cin>>v>>a>>b>>c>>d;
      int z=rev[X[v]][Y[v]];
      lct.expose(vs[z]);
      SM sm;
      sm[0][0]=a;sm[0][1]=b;
      sm[1][0]=c;sm[1][1]=d;
      vs[z]->val=SM2(sm,sm);
      lct.pushup(vs[z]);
    }
    if(c=='g'){
      int x,y;
      cin>>x>>y;
      lct.evert(vs[x]);
      SM ans=lct.query(vs[y]).first;
      cout<<ans[0][0]<<" "<<ans[0][1]<<" ";
      cout<<ans[1][0]<<" "<<ans[1][1]<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/25
  https://yukicoder.me/problems/no/650
*/

signed SPOJ_DYNACON1(){
  int n,m;
  cin>>n>>m;
  using Node = NodeBase<int, int>;
  constexpr size_t LIM = 1e6;
  using LCT = Path<Node, LIM>;

  auto f=[](int a,int b){return a+b;};
  LCT lct(f,f,f,0,0);
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

signed main(){
  //YUKI_650();
  //SPOJ_DYNACON1();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

