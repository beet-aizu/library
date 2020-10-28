#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "base.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Ep>
struct NodeBase{
  using E = Ep;
  NodeBase *l,*r,*p;
  size_t cnt;
  bool rev;
  E val,laz;
  NodeBase(E val,E laz):
    cnt(1),rev(0),val(val),laz(laz){l=r=p=nullptr;}
};

template<typename Node, size_t LIM>
struct Dual : BBSTBase<Node, LIM, Dual<Node, LIM>>{
  using super = BBSTBase<Node, LIM, Dual>;
  using E = typename Node::E;
  using H = function<E(E, E)>;

  H h;
  E ei;

  Dual(H h,E ei):h(h),ei(ei){}

  void propagate(Node *t,E x){
    t->val=h(t->val,x);
    t->laz=h(t->laz,x);
  }

  void toggle(Node *t){
    swap(t->l,t->r);
    t->rev^=1;
  }

  Node* eval(Node* t){
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
  Node* pushup(Node *t){
    t->cnt=count(t->l)+1+count(t->r);
    return t;
  }

  Node* init(int n){
    return build(vector<Node>(n,Node(ei,ei)));
  }

  using super::merge;
  using super::split;

  Node* update(Node *a,size_t l,size_t r,E x){
    auto s=split(a,l);
    auto t=split(s.second,r-l);
    auto u=eval(t.first);
    propagate(u,x);
    return merge(s.first,merge(u,t.second));
  }

  Node* set_val(Node *a,size_t k,E x){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) a->l=set_val(a->l,k,x);
    if(k>num) a->r=set_val(a->r,k-(num+1),x);
    if(k==num) a->val=x;
    return pushup(a);
  }

  E get_val(Node *a,size_t k){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) return get_val(a->l,k);
    if(k>num) return get_val(a->r,k-(num+1));
    return a->val;
  }
};
//END CUT HERE
//INSERT ABOVE HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
