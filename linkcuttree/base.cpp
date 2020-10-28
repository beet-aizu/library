#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Node, size_t LIM, typename Impl>
struct LinkCutTreeBase{
  alignas(Node) static char pool[sizeof(Node) * LIM];
  static Node* ptr;
  static size_t size;

  template<typename... Args>
  inline Node* create(Args&&... args){
    return new (ptr+size++) Node(std::forward<Args>(args)...);
  }

  inline size_t idx(Node *t){return t-ptr;}
  Node* operator[](size_t k){return ptr+k;}

  inline void toggle(Node *t){
    static_cast<Impl*>(this)->toggle(t);
  }

  inline Node* eval(Node *t){
    return static_cast<Impl*>(this)->eval(t);
  }

  inline void pushup(Node *t){
    static_cast<Impl*>(this)->pushup(t);
  }

  inline Node* expose(Node *t){
    return static_cast<Impl*>(this)->expose(t);
  }

  void rotR(Node *t){
    Node *x=t->p,*y=x->p;
    if((x->l=t->r)) t->r->p=x;
    t->r=x;x->p=t;
    pushup(x);pushup(t);
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
      pushup(y);
    }
  }

  void rotL(Node *t){
    Node *x=t->p,*y=x->p;
    if((x->r=t->l)) t->l->p=x;
    t->l=x;x->p=t;
    pushup(x);pushup(t);
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
      pushup(y);
    }
  }

  // for splay tree (not original tree)
  bool is_root(Node *t){
    return !t->p or (t->p->l!=t and t->p->r!=t);
  }

  void splay(Node *t){
    eval(t);
    while(!is_root(t)){
      Node *q=t->p;
      if(is_root(q)){
        eval(q);eval(t);
        if(q->l==t) rotR(t);
        else rotL(t);
      }else{
        auto *r=q->p;
        eval(r);eval(q);eval(t);
        if(r->l==q){
          if(q->l==t) rotR(q),rotR(t);
          else rotL(t),rotR(t);
        }else{
          if(q->r==t) rotL(q),rotL(t);
          else rotR(t),rotL(t);
        }
      }
    }
  }

  // c must be root on LCT
  void link(Node *par,Node *c){
    expose(c);
    expose(par);
    c->p=par;
    par->r=c;
    pushup(par);
  }

  void cut(Node *c){
    expose(c);
    Node *par=c->l;
    c->l=nullptr;
    pushup(c);
    par->p=nullptr;
  }

  void evert(Node *t){
    expose(t);
    toggle(t);
    eval(t);
  }

  Node *parent(Node *t){
    expose(t);
    if(!(t->l)) return nullptr;
    t=eval(t->l);
    while(t->r) t=eval(t->r);
    splay(t);
    return t;
  }

  Node *root(Node *t){
    expose(t);
    while(t->l) t=eval(t->l);
    splay(t);
    return t;
  }

  bool is_connected(Node *a,Node *b){
    return root(a)==root(b);
  }

  Node *lca(Node *a,Node *b){
    expose(a);
    return expose(b);
  }
};
template<typename Node, size_t LIM, typename Impl>
alignas(Node) char LinkCutTreeBase<Node, LIM, Impl>::pool[];
template<typename Node, size_t LIM, typename Impl>
Node* LinkCutTreeBase<Node, LIM, Impl>::ptr=
  (Node*)LinkCutTreeBase<Node, LIM, Impl>::pool;
template<typename Node, size_t LIM, typename Impl>
size_t LinkCutTreeBase<Node, LIM, Impl>::size=0;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
