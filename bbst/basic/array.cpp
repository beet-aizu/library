#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;

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
  NodeBase():cnt(0),rev(0){l=r=p=nullptr;}
  NodeBase(T val):
    cnt(1),rev(0),val(val){l=r=p=nullptr;}
};

template<typename Node, size_t LIM>
struct Array : BBSTBase<Node, LIM>{
  using T = typename Node::T;
  using super = BBSTBase<Node, LIM>;

  Array():super(){}

  using super::count;

  Node* recalc(Node *a){
    a->cnt=count(a->l)+1+count(a->r);
    return a;
  }

  void toggle(Node *a){
    swap(a->l,a->r);
    a->rev^=1;
  }

  // remove "virtual" for optimization
  virtual Node* eval(Node* a){
    if(a->rev){
      if(a->l) toggle(a->l);
      if(a->r) toggle(a->r);
      a->rev=false;
    }
    return recalc(a);
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

  void dump(Node* a,typename vector<T>::iterator it){
    if(!count(a)) return;
    if(a->rev){
      if(a->l) toggle(a->l);
      if(a->r) toggle(a->r);
      a->rev=false;
    }
    dump(a->l,it);
    *(it+count(a->l))=a->val;
    dump(a->r,it+count(a->l)+1);
  }

  vector<T> dump(Node* a){
    vector<T> vs(count(a));
    dump(a,vs.begin());
    return vs;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
