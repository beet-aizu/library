#ifndef call_from_test

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../basic/base.cpp"
#include "base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Tp>
struct NodeBase{
  using T = Tp;
  NodeBase *l,*r,*p;
  size_t cnt;
  bool rev;
  T val,dat;
  NodeBase(T val):
    cnt(1),rev(0),val(val),dat(val){l=r=p=nullptr;}
};

template<typename Node, size_t LIM>
struct PersistentUshi :
  PersistentBase<Node, LIM, PersistentUshi<Node, LIM>>{
  using super = PersistentBase<Node, LIM, PersistentUshi>;
  using T = typename Node::T;
  using F = function<T(T, T)>;
  using S = function<T(T)>;

  F f;
  S flip;
  T ti;

  PersistentUshi(F f,S flip,T ti):
    f(f),flip(flip),ti(ti){}

  PersistentUshi(F f,T ti):PersistentUshi(f,[](T a){return a;},ti){}

  using super::toggle;
  inline void toggle(Node *t){
    swap(t->l,t->r);
    t->val=flip(t->val);
    t->dat=flip(t->dat);
    t->rev^=1;
  }

  using super::clone;
  inline Node* eval(Node* t){
    t=clone(t);
    if(t->rev){
      t->l=clone(t->l);
      t->r=clone(t->r);

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

  T query(Node *&a,size_t l,size_t r){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=t.first;
    T res=query(u);
    a=merge(s.first,merge(u,t.second));
    return res;
  }

  T get_val(Node *a,size_t k){
    return super::find_by_order(a,k)->val;
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
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
