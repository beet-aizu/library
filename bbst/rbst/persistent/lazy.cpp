#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../basic/base.cpp"
#include "base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Tp, typename Ep>
struct NodeBase{
  using T = Tp;
  using E = Ep;
  NodeBase *l,*r,*p;
  size_t cnt;
  bool rev;
  T val,dat;
  E laz;
  NodeBase(T val,E laz):
    cnt(1),rev(0),val(val),dat(val),laz(laz){l=r=p=nullptr;}
};

template<typename Node, size_t LIM>
struct PersistentLazy :
  PersistentBase<Node, LIM, PersistentLazy<Node, LIM>>{
  using super = PersistentBase<Node, LIM, PersistentLazy>;

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

  PersistentLazy(F f,G g,H h,S flip,T ti,E ei):
    f(f),g(g),h(h),flip(flip),ti(ti),ei(ei){}

  PersistentLazy(F f,G g,H h,T ti,E ei):
    PersistentLazy(f,g,h,[](T a){return a;},ti,ei){}

  inline void propagate(Node *t,E v){
    t->laz=h(t->laz,v);
    t->val=g(t->val,v);
    t->dat=g(t->dat,v);
  }

  inline void toggle(Node *t){
    swap(t->l,t->r);
    t->val=flip(t->val);
    t->dat=flip(t->dat);
    t->rev^=1;
  }

  using super::clone;
  inline Node* eval(Node* t){
    t=clone(t);

    if(t->laz!=ei or t->rev){
      t->l=clone(t->l);
      t->r=clone(t->r);
    }

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

  using super::count;
  inline Node* pushup(Node *t){
    t->cnt=count(t->l)+1+count(t->r);
    t->dat=t->val;
    if(t->l) t->dat=f(t->l->dat,t->dat);
    if(t->r) t->dat=f(t->dat,t->r->dat);
    return t;
  }

  using super::merge;
  using super::split;

  T query(const Node *a){
    return a?a->dat:ti;
  }

  T query(Node *a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=t.first;
    return query(u);
  }

  Node* update(Node *a,size_t l,size_t r,E v){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=eval(t.first);
    propagate(u,v);
    return merge(s.first,merge(u,t.second));
  }

  T get_val(Node *a,size_t k){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) return get_val(a->l,k);
    if(k>num) return get_val(a->r,k-(num+1));
    return a->val;
  }

  Node* set_val(Node *a,size_t k,T val){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) a->l=set_val(a->l,k,val);
    if(k>num) a->r=set_val(a->r,k-(num+1),val);
    if(k==num) a->val=val;
    return pushup(a);
  }
};
//END CUT HERE
//INSERT ABOVE HERE
signed ARC030_D(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  using ll = long long;
  using P = pair<ll, ll>;
  vector<P> vp(n,P(0,1));
  for(int i=0;i<n;i++) cin>>vp[i].first;

  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,ll b){return P(a.first+b*a.second,a.second);};
  auto h=[](ll a,ll b){return a+b;};

  using Node = NodeBase<P, ll>;
  constexpr size_t LIM = 6e6;
  PersistentLazy<Node, LIM> G(f,g,h,P(0,0),0);

  vector<Node> vs;
  for(auto v:vp) vs.emplace_back(v,0);
  auto rt=G.build(vs);

  for(int i=0;i<q;i++){
    int t;
    cin>>t;

    if(t==1){
      int a,b,v;
      cin>>a>>b>>v;
      a--;
      rt=G.update(rt,a,b,v);
    }

    if(t==2){
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      a--;c--;
      auto s=G.split(rt,a);
      auto t=G.split(s.second,b-a);
      auto u=G.split(rt,c);
      auto v=G.split(u.second,d-c);

      rt=G.merge(G.merge(s.first,v.first),t.second);
    }

    if(t==3){
      int a,b;
      cin>>a>>b;
      a--;
      cout<<G.query(rt,a,b).first<<'\n';
    }

    if(G.almost_full()) rt=G.rebuild(rt);
  }
  return 0;
}
/*
  verified on 2020/10/28
  https://atcoder.jp/contests/arc030/tasks/arc030_4
*/

signed main(){
  ARC030_D();
  return 0;
}
