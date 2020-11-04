#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T, typename E,
         typename F, typename G, typename H, typename Flip>
struct Lazy{
  F f;
  G g;
  H h;
  Flip flip;
  T ti;
  E ei;

  Lazy(F f,G g,H h,Flip flip,T ti,E ei):
    f(f),g(g),h(h),flip(flip),ti(ti),ei(ei){}

  struct Node{
    Node *l,*r,*p;
    size_t cnt;
    bool rev;
    T val,dat;
    E laz;
    Node(T val,E laz):
      cnt(1),rev(0),val(val),dat(val),laz(laz){l=r=p=nullptr;}
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

  inline bool dirty(Node *t){
    return t->rev or t->laz!=ei;
  }

  inline void propagate(Node *t,E v){
    t->laz=h(t->laz,v);
    t->val=g(t->val,v);
    t->dat=g(t->dat,v);
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
    t->dat=t->val;
    if(t->l) t->dat=f(t->l->dat,t->dat);
    if(t->r) t->dat=f(t->dat,t->r->dat);
    return t;
  }

  inline T get_val(Node *t){
    assert(t);
    return t->val;
  }

  inline T reflect(Node *t){
    assert(t);
    return t->dat;
  }

  void dump(typename vector<Node>::iterator it,
            const Node* t,bool rev,E laz){
    if(!count(t)) return;

    Node *l=t->l,*r=t->r;
    if(rev) swap(l,r);
    rev^=t->rev;

    dump(it,l,rev,h(laz,t->laz));
    *(it+count(l))=Node(g(t->val,laz),ei);
    dump(it+count(l)+1,r,rev,h(laz,t->laz));
  }

  vector<Node> dump(Node* t){
    assert(t!=nullptr);
    vector<Node> vs(count(t),*t);
    dump(vs.begin(),t,false,ei);
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
