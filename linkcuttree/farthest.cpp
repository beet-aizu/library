#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE

template<typename T>
struct LinkCutTree{
  struct Node{
    Node *l,*r,*p;
    int idx;
    bool rev;
    T val,ld,rd,smd;
    multiset<T> td;
    Node(){}
    Node(int idx,T val):
      idx(idx),rev(0),val(val){
      l=r=p=nullptr;
      ld=rd=smd=val;
      td.emplace(0);
    }
    bool is_root(){
      return !p||(p->l!=this&&p->r!=this);
    }
  };
  const size_t LIM = 1e6+10;
  vector<Node> pool;
  size_t ptr;

  LinkCutTree():pool(LIM),ptr(0){}

  inline Node* create(){
    return &pool[ptr++];
  }

  inline Node* create(int idx,T val){
    return &(pool[ptr++]=Node(idx,val));
  }

  void toggle(Node *t){
    swap(t->l,t->r);
    swap(t->ld,t->rd);
    t->rev^=1;
  }

  void eval(Node *t){
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
  }

  inline void pushup(Node *t){
    if(t==nullptr) return;
    t->smd=t->val;
    if(t->l) t->smd+=t->l->smd;
    if(t->r) t->smd+=t->r->smd;

    T lld=t->l?t->l->ld:0;
    T rrd=t->r?t->r->rd:0;

    T lsmd=t->l?t->l->smd:0;
    T rsmd=t->r?t->r->smd:0;

    t->ld=max(lld,lsmd+t->val+*(t->td).rbegin());
    if(t->r) t->ld=max(t->ld,lsmd+t->val+t->r->ld);

    t->rd=max(rrd,rsmd+t->val+*(t->td).rbegin());
    if(t->l) t->rd=max(t->rd,rsmd+t->val+t->l->rd);
  }

  void rotR(Node *t){
    Node *x=t->p,*y=x->p;
    if((x->l=t->r)) t->r->p=x;
    t->r=x;x->p=t;
    pushup(x);
    pushup(t);
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
    pushup(x);
    pushup(t);
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
      pushup(y);
    }
  }

  void splay(Node *t){
    eval(t);
    while(!t->is_root()){
      Node *q=t->p;
      if(q->is_root()){
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

  Node* expose(Node *t){
    Node *rp=nullptr;
    for(Node *c=t;c;c=c->p){
      splay(c);
      if(c->r) c->td.emplace(c->r->ld);
      c->r=rp;
      if(c->r) c->td.erase(c->td.find(c->r->ld));
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

  Node *root(Node *t){
    expose(t);
    while(t->l) t=t->l;
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
//END CUT HERE
//INSERT ABOVE HERE
signed TKPPC2015_J(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;
  using LCT = LinkCutTree<ll>;

  LCT lct;
  vector<LCT::Node*> vs;
  vector<LCT::Node*> es;
  vs.reserve(5e5+100);
  es.reserve(5e5+100);

  int num=0;
  vs.emplace_back(lct.create(num,0));
  es.emplace_back(lct.create(num,0));
  num++;

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t,a,c;
    cin>>t>>a>>c;
    if(t==1){
      vs.emplace_back(lct.create(num,0));
      es.emplace_back(lct.create(num,c));
      lct.link(vs[a],es[num]);
      lct.link(es[num],vs[num]);
      num++;
    }
    if(t==2){
      lct.expose(es[a]);
      es[a]->val=c;
      lct.pushup(es[a]);
    }
    if(t==3){
      lct.evert(vs[a]);
      cout<<(vs[a]->ld)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/14
  https://atcoder.jp/contests/tkppc/tasks/tkppc2015_j
*/
signed main(){
  TKPPC2015_J();
  return 0;
}
