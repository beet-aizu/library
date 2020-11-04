#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T, typename F, typename Flip>
struct Ushi{
  F f;
  Flip flip;
  T ti;

  Ushi(F f,Flip flip,T ti):f(f),flip(flip),ti(ti){}

  struct Node{
    Node *l,*r,*p;
    size_t cnt;
    bool rev;
    T val,dat;
    Node(T val):
      cnt(1),rev(0),val(val),dat(val){l=r=p=nullptr;}
  };

  static inline size_t count(const Node *t){
    return t?t->cnt:0;
  }

  inline void toggle(Node *t){
    swap(t->l,t->r);
    t->val=flip(t->val);
    t->dat=flip(t->dat);
    t->rev^=1;
  }

  inline Node* eval(Node* t){
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
    return t;
  }

  inline Node* pushup(Node *t){
    t->cnt=count(t->l)+1+count(t->r);
    t->dat=t->val;
    if(t->l) t->dat=f(t->l->dat,t->dat);
    if(t->r) t->dat=f(t->dat,t->r->dat);
    return t;
  }

  inline T reflect(Node *t){
    return t?t->dat:ti;
  }
};

//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
