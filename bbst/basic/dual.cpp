#ifndef call_from_test
#include<bits/stdc++.h>
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
  E dat,laz;
  NodeBase(){}
  NodeBase(E dat,E laz):
    cnt(1),rev(0),dat(dat),laz(laz){l=r=p=nullptr;}
};

template<typename Node, size_t LIM>
struct Dual : BBSTBase<Node, LIM>{
  using E = typename Node::E;
  using super = BBSTBase<Node, LIM>;
  using H = function<E(E, E)>;

  H h;
  E ei;

  Dual(H h,E ei):super(),h(h),ei(ei){}

  using super::create;
  using super::merge;
  using super::split;

  Node* build(size_t l,size_t r){
    if(l+1==r) return create(Node(ei,ei));
    size_t m=(l+r)>>1;
    return merge(build(l,m),build(m,r));
  }

  Node* init(int n){
    return build(0,n);
  }

  using super::count;
  Node* recalc(Node *a){
    a->cnt=count(a->l)+1+count(a->r);
    return a;
  }

  void propagate(Node *a,E x){
    a->dat=h(a->dat,x);
    a->laz=h(a->laz,x);
  }

  using super::toggle;
  void toggle(Node *a){
    swap(a->l,a->r);
    a->rev^=1;
  }

  // remove "virtual" for optimization
  virtual Node* eval(Node* a){
    if(a->laz!=ei){
      if(a->l) propagate(a->l,a->laz);
      if(a->r) propagate(a->r,a->laz);
      a->laz=ei;
    }
    if(a->rev){
      if(a->l) toggle(a->l);
      if(a->r) toggle(a->r);
      a->rev=false;
    }
    return recalc(a);
  }

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
    if(k==num) a->dat=x;
    return recalc(a);
  }

  E get_val(Node *a,size_t k){
    assert(k<count(a));
    a=eval(a);
    size_t num=count(a->l);
    if(k<num) return get_val(a->l,k);
    if(k>num) return get_val(a->r,k-(num+1));
    return a->dat;
  }

  void dump(Node* a,typename vector<E>::iterator it){
    if(!count(a)) return;
    a=eval(a);
    dump(a->l,it);
    *(it+count(a->l))=a->dat;
    dump(a->r,it+count(a->l)+1);
  }

  vector<E> dump(Node* a){
    vector<E> vs(count(a));
    dump(a,vs.begin());
    return vs;
  }
};
//END CUT HERE
//INSERT ABOVE HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
