#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
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
  T val;
  NodeBase(T val):
    cnt(1),rev(0),val(val){l=r=p=nullptr;}
};

template<typename Node, size_t LIM>
struct Array : BBSTBase<Node, LIM, Array<Node, LIM>>{
  using super = BBSTBase<Node, LIM, Array>;
  using T = typename Node::T;

  void toggle(Node *t){
    swap(t->l,t->r);
    t->rev^=1;
  }

  Node* eval(Node* t){
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

  using super::find_by_order;

  Node* set_val(Node *a,size_t k,T val){
    auto b=find_by_order(a,k);
    b->val=val;
    return b;
  }

  T get_val(Node *a,size_t k){
    return find_by_order(a,k)->val;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
