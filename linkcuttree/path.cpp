#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "base.cpp"
#undef call_from_test

#endif
/**
 * @see https://ei1333.hateblo.jp/entry/2018/05/29/011140
 */
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
  E ei;

  Path(F f,G g,H h,E ei):
    super(),f(f),g(g),h(h),ei(ei){
    flip=[](T a){return a;};
  }

  Path(F f,G g,H h,S flip,E ei):
    super(),f(f),g(g),h(h),flip(flip),ei(ei){}

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

// test dynamic tree
signed SPOJ_DYNACON1(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  using Node = NodeBase<int, int>;
  constexpr size_t LIM = 1e6;
  using LCT = Path<Node, LIM>;

  auto f=[](int a,int b){return a+b;};
  LCT lct(f,f,f,0);
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
  verified on 2020/01/08
  https://www.spoj.com/problems/DYNACON1/
*/

signed main(){
  //SPOJ_DYNACON1();
  return 0;
}
#endif
