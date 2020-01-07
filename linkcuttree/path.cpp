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
  bool rev;
  T val,dat;
  E laz;
  NodeBase(){}
  NodeBase(T val,E laz):
    rev(0),val(val),dat(val),laz(laz){
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

  Node* create(T val){
    return super::create(Node(val,ei));
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

  inline Node* eval(Node *t){
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
    return t;
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

// test edge folding
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

  for(int i=0;i<n*2-1;i++) lct.create(ti2);

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
        lct.link(lct[p],lct[idx]);
        lct.link(lct[idx],lct[v]);
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
      lct.expose(lct[z]);
      SM sm;
      sm[0][0]=a;sm[0][1]=b;
      sm[1][0]=c;sm[1][1]=d;
      lct[z]->val=SM2(sm,sm);
      lct.pushup(lct[z]);
    }
    if(c=='g'){
      int x,y;
      cin>>x>>y;
      lct.evert(lct[x]);
      SM ans=lct.query(lct[y]).first;
      cout<<ans[0][0]<<" "<<ans[0][1]<<" ";
      cout<<ans[1][0]<<" "<<ans[1][1]<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2020/01/06
  https://yukicoder.me/problems/no/650
*/

// test dynamic tree
signed SPOJ_DYNACON1(){
  int n,m;
  cin>>n>>m;
  using Node = NodeBase<int, int>;
  constexpr size_t LIM = 1e6;
  using LCT = Path<Node, LIM>;

  auto f=[](int a,int b){return a+b;};
  LCT lct(f,f,f,0,0);
  for(int i=0;i<n;i++) lct.create(0);

  for(int i=0;i<m;i++){
    string s;
    int a,b;
    cin>>s>>a>>b;
    a--;b--;
    if(s=="add"s){
      lct.evert(lct[b]);
      lct.link(lct[a],lct[b]);
    }
    if(s=="rem"s){
      auto v=lct.lca(lct[a],lct[b])==lct[a]?lct[b]:lct[a];
      lct.cut(v);
    }
    if(s=="conn"s)
      cout<<(lct.is_connected(lct[a],lct[b])?"YES\n":"NO\n");
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2020/01/06
  https://www.spoj.com/problems/DYNACON1/
*/

signed main(){
  //YUKI_650();
  //SPOJ_DYNACON1();
  return 0;
}
#endif
