#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Vertex, typename Cluster, size_t N>
struct TopTree{
  enum Type { Compress, Rake, Edge };
  struct Node{
    Vertex* vs[2];
    Cluster dat;
    Node* p;
    Node* q;
    Node* ch[2];
    bool rev,guard;
    Type type;
    Node(){p=q=nullptr;rev=guard=false;}
  };

  inline static array<Vertex, 2*N> pool_vertex;
  inline static size_t ptr_vertex = 0;

  inline static array<Node, 4*N> pool_node;
  inline static size_t ptr_node = 0;

  Cluster id;

  template<typename ...Args>
  inline Vertex* create(Args ...args){
    auto t=&pool_vertex[ptr_vertex++];
    auto dummy=&pool_vertex[ptr_vertex++];
    *t=Vertex(forward<Args>(args)...);
    link(t,id,dummy);
    return t;
  }

  Node* recycle=nullptr;
  inline void dispose_node(Node* t){
    t->p=recycle;
    recycle=t;
  }

  inline Node* get_new_node(){
    if(recycle) return new(exchange(recycle,recycle->p)) Node;
    return &(pool_node[ptr_node++]);
  }

  inline Node* edge(Vertex* u,Cluster w,Vertex* v){
    auto t=get_new_node();
    t->vs[0]=u;t->vs[1]=v;t->dat=w;
    t->type=Type::Edge;
    return pushup(t);
  }

  inline Node* compress(Node* l,Node* r){
    auto t=get_new_node();
    t->ch[0]=l;t->ch[1]=r;
    t->type=Type::Compress;
    return pushup(t);
  }

  inline Node* rake(Node* l,Node* r){
    auto t=get_new_node();
    t->ch[0]=l;t->ch[1]=r;
    t->type=Type::Rake;
    return pushup(t);
  }

  int parent_dir(Node* t){
    Node* p=t->p;
    if(!p) return -1;
    if(p->guard) return -1;
    if(p->ch[0]==t) return 0;
    if(p->ch[1]==t) return 1;
    return -1;
  }

  int parent_dir_ignore_guard(Node* t){
    Node* p=t->p;
    if(!p) return -1;
    if(p->ch[0]==t) return 0;
    if(p->ch[1]==t) return 1;
    return -1;
  }

  inline Node* pushup(Node* const t){
    Node* const l=t->ch[0];
    Node* const r=t->ch[1];

    if(t->type==Type::Compress){
      assert(l->vs[1]==r->vs[0]);
      t->vs[0]=l->vs[0];
      t->vs[1]=r->vs[1];

      Cluster lf=l->dat;
      if(t->q){
        assert(l->vs[1]==t->q->vs[1]);
        lf=Cluster::rake(l->dat,t->q->dat);
      }
      t->dat=Cluster::compress(lf,r->vs[0],r->dat);

      l->vs[1]->handle=t;
    }

    if(t->type==Type::Rake){
      propagate(t);
      assert(l->vs[1]==r->vs[1]);
      t->vs[0]=l->vs[0];
      t->vs[1]=l->vs[1];
      t->dat=Cluster::rake(l->dat,r->dat);
    }else{
      if(!t->p){
        t->vs[0]->handle=t;
        t->vs[1]->handle=t;
      }else if(t->p->type==Type::Compress){
        if(parent_dir(t)==-1)
          t->vs[0]->handle=t;
      }else if(t->p->type==Type::Rake){
        t->vs[0]->handle=t;
      }
    }
    return t;
  }

  inline void toggle(Node* t){
    if(t->type==Type::Edge){
      swap(t->vs[0],t->vs[1]);
      t->dat.toggle();
    }else if(t->type==Type::Compress){
      swap(t->vs[0],t->vs[1]);
      t->dat.toggle();
      t->rev^=true;
    }else if(t->type==Type::Rake){
    }else abort();
  }

  inline void propagate(Node* t){
    if(t->type==Type::Compress){
      if(t->rev){
        assert(t->ch[0] and t->ch[1]);
        swap(t->ch[0],t->ch[1]);
        toggle(t->ch[0]);
        toggle(t->ch[1]);
        t->rev=false;
      }
    }
  }

  void set_toggle(Node* v){
    toggle(v);propagate(v);
  }

  void pushdown(Node* t){
    if(!t) return;
    pushdown(t->p);
    propagate(t);
  }

  void rotate(Node* t,Node* x,size_t dir){
    Node* y=x->p;
    int par=parent_dir_ignore_guard(x);
    propagate(t->ch[dir]);
    x->ch[dir^1]=t->ch[dir];
    t->ch[dir]->p=x;
    t->ch[dir]=x;
    x->p=t;
    t->p=y;
    if(~par) y->ch[par]=t;
    else if(y and y->type==Type::Compress) y->q=t;
    pushup(x);pushup(t);
    if(y and !y->guard) pushup(y);
  }

  void splay(Node* t){
    assert(t->type!=Type::Edge);
    propagate(t);

    while(~parent_dir(t)){
      Node* q=t->p;
      if(q->type!=t->type) break;
      if(~parent_dir(q) and q->p and q->p->type==q->type){
        Node* r=q->p;
        if(r->p) propagate(r->p);
        propagate(r);propagate(q);propagate(t);
        int qt_dir=parent_dir(t);
        int rq_dir=parent_dir(q);
        if(rq_dir==qt_dir){
          rotate(q,r,rq_dir^1);
          rotate(t,q,qt_dir^1);
        }else{
          rotate(t,q,qt_dir^1);
          rotate(t,r,rq_dir^1);
        }
      }else{
        if(q->p) propagate(q->p);
        propagate(q);propagate(t);
        int qt_dir=parent_dir(t);
        rotate(t,q,qt_dir^1);
      }
    }
  }

  Node* expose(Node* t){
    pushdown(t);
    while(true){
      assert(t->type!=Type::Rake);
      if(t->type==Type::Compress) splay(t);
      Node* n=nullptr;
      {
        Node* p=t->p;
        if(!p) break;
        if(p->type==Type::Rake){
          propagate(p);
          splay(p);
          n=p->p;
        }
        if(p->type==Type::Compress){
          propagate(p);
          if(p->guard and ~parent_dir_ignore_guard(t)) break;
          n=p;
        }
      }
      splay(n);
      int dir=parent_dir_ignore_guard(n);
      if(dir==-1 or n->p->type==Type::Rake) dir=0;

      Node* const c=n->ch[dir];
      if(dir==1){
        set_toggle(c);
        set_toggle(t);
      }
      int n_dir=parent_dir(t);
      if(~n_dir){
        Node* const r=t->p;
        propagate(c);
        propagate(r);
        r->ch[n_dir]=c;
        c->p=r;
        n->ch[dir]=t;
        t->p=n;
        pushup(c);pushup(r);
        pushup(t);pushup(n);
        splay(r);
      }else{
        propagate(c);
        n->q=c;
        c->p=n;
        n->ch[dir]=t;
        t->p=n;
        pushup(c);pushup(t);pushup(n);
      }
      if(t->type==Type::Edge) t=n;
    }
    return t;
  }

  Node* expose(Vertex* v){
    return expose((Node*)(v->handle));
  }

  void soft_expose(Vertex* u,Vertex* v){
    pushdown((Node*)u->handle);
    pushdown((Node*)v->handle);
    Node* rt=expose(u);

    if(u->handle==v->handle){
      if(rt->vs[1]==u or rt->vs[0]==v)
        set_toggle(rt);
      return;
    }

    rt->guard=true;
    Node* soft=expose(v);
    rt->guard=false;

    pushup(rt);
    if(parent_dir(soft)==0) set_toggle(rt);
  }

  void bring(Node* rt){
    Node* rk=rt->q;
    if(!rk){
      Node* ll=rt->ch[0];
      dispose_node(ll->p);
      ll->p=nullptr;
      pushup(ll);
    }else if(rk->type==Type::Compress or rk->type==Type::Edge){
      Node* nr=rk;
      set_toggle(nr);
      rt->ch[1]=nr;
      nr->p=rt;
      rt->q=nullptr;

      pushup(nr);pushup(rt);
    }else if(rk->type==Type::Rake){
      propagate(rk);
      while(rk->ch[1]->type==Type::Rake){
        propagate(rk->ch[1]);
        rk=rk->ch[1];
      }
      pushdown(rk);

      rt->guard=true;
      splay(rk);
      rt->guard=false;

      Node* ll=rk->ch[0];
      Node* rr=rk->ch[1];
      propagate(ll);
      set_toggle(rr);

      rt->ch[1]=rr;
      rr->p=rt;

      rt->q=ll;
      ll->p=rt;

      dispose_node(rk);
      pushup(ll);pushup(rr);pushup(rt);
    }
  }

  Node* link(Vertex* u,Cluster w,Vertex* v){
    if(!u->handle and !v->handle) return edge(u,w,v);

    Node* nnu=(Node*)u->handle;
    Node* nnv=(Node*)v->handle;
    Node* ee=edge(u,w,v);
    Node* ll=nullptr;

    assert(nnv);
    Node* vv=expose(nnv);
    propagate(vv);
    if(vv->vs[1]==v) set_toggle(vv);
    if(vv->vs[0]==v){
      Node* nv=compress(ee,vv);
      ee->p=nv;
      pushup(ee);
      vv->p=nv;
      pushup(vv);pushup(nv);
      ll=nv;
    }else{
      Node* nv=vv;
      Node* ch=nv->ch[0];
      propagate(ch);
      nv->ch[0]=ee;
      ee->p=nv;
      pushup(ee);

      Node* bt=nv->q;
      Node* rk=nullptr;
      if(bt){
        propagate(bt);
        rk=rake(bt,ch);
        bt->p=rk;
        ch->p=rk;
        pushup(bt);pushup(ch);
      }else{
        rk=ch;
      }
      nv->q=rk;
      rk->p=nv;
      pushup(rk);pushup(nv);
      ll=nv;
    }

    assert(nnu);
    Node* uu=expose(nnu);
    propagate(uu);
    if(uu->vs[0]==u) set_toggle(uu);
    if(uu->vs[1]==u){
      Node* tp=compress(uu,ll);
      uu->p=tp;
      ll->p=tp;
      pushup(uu);pushup(ll);pushup(tp);
    }else{
      Node* nu=uu;
      Node* ch=nu->ch[1];
      toggle(ch);
      propagate(ch);

      nu->ch[1]=ll;
      ll->p=nu;
      pushup(ll);

      Node* al=nu->q;
      Node* rk=nullptr;
      if(al){
        propagate(al);
        rk=rake(al,ch);
        al->p=rk;
        ch->p=rk;
        pushup(al);pushup(ch);
      }else{
        rk=ch;
      }
      nu->q=rk;
      rk->p=nu;
      pushup(rk);pushup(nu);
    }
    return ee;
  }

  void cut(Vertex* u,Vertex *v){
    soft_expose(u,v);
    Node* rt=(Node*)u->handle;
    propagate(rt);
    Node* rr=rt->ch[1];
    rr->p=nullptr;
    set_toggle(rr);
    assert(rr->ch[1]->type==Type::Edge);
    dispose_node(rr->ch[1]);
    bring(rr);bring(rt);
  }

  Node* path(Vertex* u,Vertex* v){
    assert(u!=v);
    soft_expose(u,v);
    Node* rt=(Node*)u->handle;
    propagate(rt);
    propagate(rt->ch[1]);
    return rt->ch[1]->ch[0];
  }

  void set_vertex(Vertex* u,Vertex v){
    auto t=expose(u);
    *u=v;
    pushup(t);
  }

  void set_edge(Vertex* u,Vertex* v,const Cluster &w){
    auto t=path(u,v);
    assert(t->type==Type::Edge);
    t->dat=w;
    while(t) pushup(t),t=t->p;
  }

  Cluster get_path(Vertex* u,Vertex* v){
    return path(u,v)->dat;
  }

  Cluster get_subtree(Vertex* v){
    return expose(v)->dat;
  }

  // subtree of v when p is root
  Cluster get_subtree(Vertex* p,Vertex* v){
    Node* t=path(p,v);
    Cluster res=t->p->ch[1]->dat;
    res.toggle();
    Node* rk=t->p->q;
    if(t->p->q){
      assert(rk->vs[1]==t->p->ch[1]->vs[0]);
      res=Cluster::rake(res,rk->dat);
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
