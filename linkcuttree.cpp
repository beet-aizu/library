#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
template<typename T,typename E>
struct LinkCutTree{
  struct Node{
    Node *l,*r,*p;
    size_t cnt;
    int idx;
    bool rev;
    T val,dat;
    E laz;
    Node():cnt(0){}
    Node(int idx,T val,E laz):
      cnt(1),idx(idx),rev(0),val(val),dat(val),laz(laz){l=r=p=nullptr;}
    bool is_root(){
      return !p||(p->l!=this&&p->r!=this);
    }
  };
  
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  using P = function<E(E,size_t)>;
  F f;
  G g;
  H h;
  P p;
  T ti;
  E ei;
  
  const size_t LIM = 1e6;
  vector<Node> pool;
  size_t ptr;
  
  LinkCutTree(F f,G g,H h,P p,T ti,E ei):
    f(f),g(g),h(h),p(p),ti(ti),ei(ei),pool(LIM),ptr(0){}
  
  inline Node* create(){
    return &pool[ptr++];
  }
  
  inline Node* create(int idx,T v){
    return &(pool[ptr++]=Node(idx,v,ei));
  }

  void propagate(Node *t,E v){
    t->laz=h(t->laz,v);
    t->val=g(t->val,v);
    t->dat=g(t->dat,p(v,t->cnt));
  }

  void toggle(Node *t){
    swap(t->l,t->r);
    t->rev^=1;
  }

  void eval(Node *t){
    if(t->laz!=ei){
      if(t->l) propagate(t->l,t->laz);
      if(t->r) propagate(t->r,t->laz);
      t->laz=ei;
    }
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
  }

  void update(Node *t){
    t->cnt=1;
    t->dat=t->val;
    if(t->l) t->cnt+=t->l->cnt,t->dat=f(t->l->dat,t->dat);
    if(t->r) t->cnt+=t->r->cnt,t->dat=f(t->dat,t->r->dat);
  }

  void rotR(Node *t){
    Node *x=t->p,*y=x->p;
    if((x->l=t->r)) t->r->p=x;
    t->r=x;x->p=t;
    update(x);update(t);
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
      update(y);
    }
  }
  
  void rotL(Node *t){
    Node *x=t->p,*y=x->p;
    if((x->r=t->l)) t->l->p=x;
    t->l=x;x->p=t;
    update(x);update(t);
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
      update(y);
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
      c->r=rp;
      update(c);
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
  }

  void cut(Node *c){
    expose(c);
    Node *par=c->l;
    c->l=nullptr;
    par->p=nullptr;
  }

  void evert(Node *t){
    expose(t);
    toggle(t);
    eval(t);
  }

  Node *lca(Node *a,Node *b){
    expose(a);
    return expose(b);
  }

  void set_propagate(Node *t,E v){
    expose(t);
    propagate(t,v);
    eval(t);
  }
};

signed GRL_5_C(){
  int n;
  cin>>n;
  using LCT = LinkCutTree<int,int>;
  LCT::F f=[](int a,int b){return min(a,b);};
  LCT::P p=[](int a,size_t b){b++;return a;};
  LCT lc(f,f,f,p,0,0);

  vector<LCT::Node*> v(n);
  for(int i=0;i<n;i++) v[i]=lc.create(i,0);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int c;
      cin>>c;
      lc.link(v[i],v[c]);
    }
  }
  
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int a,b;
    cin>>a>>b;
    cout<<lc.lca(v[a],v[b])->idx<<endl;
  }
  
  return 0;
}

signed GRL_5_D(){
  int n;
  cin>>n;
  using LCT = LinkCutTree<int,int>;
  LCT::F f=[](int a,int b){return a+b;};
  LCT::P p=[](int a,size_t b){b++;return a;};
  LCT lc(f,f,f,p,0,0);

  vector<LCT::Node*> v(n);
  for(int i=0;i<n;i++) v[i]=lc.create(i,0);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int c;
      cin>>c;
      lc.link(v[i],v[c]);
    }
  }
  
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int a,b;
      cin>>a>>b;
      lc.expose(v[a]);
      v[a]->val=f(v[a]->val,b);
    }
    if(t==1){
      int a;
      cin>>a;
      lc.expose(v[a]);
      cout<<v[a]->dat<<endl;
    }
  }
  
  return 0;
}

signed GRL_5_E(){
  int n;
  cin>>n;
  using LCT = LinkCutTree<Int,Int>;
  LCT::F f=[](Int a,Int b){return a+b;};
  LCT::P p=[](Int a,size_t b){return a*b;};
  LCT lc(f,f,f,p,0,0);

  vector<LCT::Node*> v(n);
  for(int i=0;i<n;i++) v[i]=lc.create(i,0);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int c;
      cin>>c;
      lc.link(v[i],v[c]);
    }
  }
  
  int q;
  cin>>q;
  Int c=0;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int a,b;
      cin>>a>>b;
      lc.set_propagate(v[a],b);
      c+=b;
    }
    if(t==1){
      int a;
      cin>>a;
      lc.expose(v[a]);
      cout<<v[a]->dat-c<<endl;
    }
  }
  
  return 0;
}

signed main(){
  //GRL_5_C();
  //GRL_5_D();
  GRL_5_E();
  return 0;
}
