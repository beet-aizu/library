#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename E, typename H>
struct Dual{
  struct Node{
    Node *l,*r,*p;
    size_t cnt;
    bool rev;
    E val,laz;
    Node(E val):
      cnt(1),rev(0),val(val),laz(val){l=r=p=nullptr;}
  };

  H h;
  E ei;
  Dual(H h,E ei):h(h),ei(ei){}

  static inline size_t count(const Node *t){
    return t?t->cnt:0;
  }

  inline void toggle(Node *t){
    swap(t->l,t->r);
    t->rev^=1;
  }

  inline void propagate(Node *t,E x){
    t->val=h(t->val,x);
    t->laz=h(t->laz,x);
  }

  inline bool dirty(Node *t){
    return t->rev or t->laz!=ei;
  }

  inline Node* eval(Node* t){
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
    if(t->laz!=ei){
      if(t->l) propagate(t->l,t->laz);
      if(t->r) propagate(t->r,t->laz);
      t->laz=ei;
    }
    return t;
  }

  inline Node* pushup(Node *t){
    t->cnt=count(t->l)+1+count(t->r);
    return t;
  }

  inline E reflect(Node *t){
    assert(t);
    return h(t->val,t->laz);
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
