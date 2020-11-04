#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct Array{
  struct Node{
    Node *l,*r,*p;
    size_t cnt;
    bool rev;
    T val;
    Node(T val):
      cnt(1),rev(0),val(val){l=r=p=nullptr;}
  };

  static inline size_t count(const Node *t){
    return t?t->cnt:0;
  }

  inline void toggle(Node *t){
    swap(t->l,t->r);
    t->rev^=1;
  }

  inline bool dirty(Node *t){
    return t->rev;
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
    return t;
  }

  inline T reflect(Node *t){
    assert(t);
    return t->val;
  }

  void dump(typename vector<Node>::iterator it,Node* const t,bool rev){
    if(!count(t)) return;

    Node *l=t->l,*r=t->r;
    if(rev) swap(l,r);
    rev^=t->rev;

    dump(it,l,rev);
    *(it+count(l))=Node(t->val);
    dump(it+count(l)+1,r,rev);
  }

  vector<Node> dump(Node* t){
    assert(t!=nullptr);
    vector<Node> vs(count(t),*t);
    dump(vs.begin(),t,false);
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
