#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Node, size_t LIM>
struct LinkCutTreeBase{
  static array<Node, LIM> pool;
  size_t ptr;

  LinkCutTreeBase():ptr(0){}

  inline Node* create(){
    return &pool[ptr++];
  }

  inline Node* create(Node v){
    return &(pool[ptr++]=v);
  }

  inline size_t idx(Node *t){
    return t-&pool[0];
  }

  Node* operator[](size_t k){
    return &(pool[k]);
  }

  virtual void toggle(Node *t) = 0;
  virtual void eval(Node *t) = 0;
  virtual void pushup(Node *t) = 0;

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
    return !t->p||(t->p->l!=t&&t->p->r!=t);
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

  virtual Node* expose(Node *t){
    Node *rp=nullptr;
    for(Node *c=t;c;c=c->p){
      splay(c);
      c->r=rp;
      pushup(c);
      rp=c;
    }
    splay(t);
    return rp;
  }

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
    t=t->l;
    while(t&&t->r){
      eval(t);
      t=t->r;
    }
    if(t) splay(t);
    return t;
  }

  Node *root(Node *t){
    expose(t);
    while(t->l){
      eval(t);
      t=t->l;
    }
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
template<typename Node, size_t LIM>
array<Node, LIM> LinkCutTreeBase<Node, LIM>::pool;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
