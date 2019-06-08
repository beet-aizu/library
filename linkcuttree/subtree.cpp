#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename A>
struct LinkCutTree{
  struct Node{
    Node *l,*r,*p;
    int idx;
    bool rev;
    A val;
    Node(){}
    Node(int idx,A val):
      idx(idx),rev(0),val(val){l=r=p=nullptr;}
    bool is_root(){
      return !p||(p->l!=this&&p->r!=this);
    }
  };
  A ai;
  const size_t LIM = 1e6;
  vector<Node> pool;
  size_t ptr;
    
  LinkCutTree(A ai):ai(ai),pool(LIM),ptr(0){}
  
  inline Node* create(){
    return &pool[ptr++];
  }
  
  inline Node* create(int idx,A val){
    return &(pool[ptr++]=Node(idx,val));
  }

  void toggle(Node *t){
    swap(t->l,t->r);
    t->rev^=1;
  }

  void eval(Node *t){
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
  }

  void rotR(Node *t){
    Node *x=t->p,*y=x->p;
    x->val-=t->val;
    t->val+=x->val;
    if((x->l=t->r)) t->r->p=x,x->val+=x->l->val; 
    t->r=x;x->p=t;
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
    }
  }
  
  void rotL(Node *t){
    Node *x=t->p,*y=x->p;
    x->val-=t->val;
    t->val+=x->val;
    if((x->r=t->l)) t->l->p=x,x->val+=x->r->val;
    t->l=x;x->p=t;
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
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
    par->val+=c->val;
  }

  void cut(Node *c){
    expose(c);
    Node *par=c->l;
    c->l=nullptr;
    par->p=nullptr;
    c->val-=par->val;
  }

  void evert(Node *t){
    expose(t);
    toggle(t);
    eval(t);
  }

  bool is_connected(Node *a,Node *b){
    expose(a);
    while(a->l) a=a->l;
    expose(b);
    while(b->l) b=b->l;
    return expose(a)==expose(b);
  }

  Node *lca(Node *a,Node *b){
    expose(a);
    return expose(b);
  }
  
  A query(Node *t){
    expose(t);
    return t->val;
  }

  void add(Node *t,A a){
    expose(t);
    t->val+=a;    
  }
  
  void sub(Node *t,A a){
    expose(t);
    t->val-=a;    
  }
};

//END CUT HERE


template<typename T> 
struct BIT{
  int n;
  vector<T> bit;
  //1-indexed
  BIT():n(-1){}
  BIT(int n_,T d):n(n_),bit(n_+1,d){}
  
  T sum(int i){
    T s=bit[0];
    for(int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }
  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }
};

//INSERT ABOVE HERE
signed UNIVERSITYCODESPRINT03_G(){
  using ll = long long;
  int n;  
  scanf("%d",&n);
  BIT<ll> bit(1e6+100,0);
  vector<int> a(n),b(n),c(n);

  vector<unordered_map<int,vector<int> > > G(n);
  vector<unordered_map<int,int > > R(n);
  
  using P =  pair<int,int>;  
  vector<P> edges;

  int sz=0;
  auto add_edge=[&](int x,int e){
                  edges.push_back(P(x,e));
                  if(!R[a[x]].count(e)) R[a[x]][e]=sz++;
                  if(!R[b[x]].count(e)) R[b[x]][e]=sz++;
                  G[a[x]][e].emplace_back(b[x]);
                  G[b[x]][e].emplace_back(a[x]);
                };
  
  for(int i=0;i+1<n;i++){
    scanf("%d %d %d",&a[i],&b[i],&c[i]);
    a[i]--;b[i]--;
    add_edge(i,c[i]);
  }

  int Q;
  scanf("%d",&Q);
  vector<int> T(Q),A(Q),B(Q);
  for(int i=0;i<Q;i++){
    scanf("%d",&T[i]);
    int t=T[i]; 
    if(t==1){
      scanf("%d %d",&A[i],&B[i]);
      int x=A[i],e=B[i];
      x--;
      add_edge(x,e);
    }
    if(t==2){
      scanf("%d %d",&A[i],&B[i]);
    }
    if(t==3){
      scanf("%d",&A[i]);
    }
  }
  
  using LCT = LinkCutTree<int>;
  LCT lct(0);

  vector<LCT::Node*> vs(sz);
  for(int i=0;i<sz;i++) vs[i]=lct.create(i,1);

  vector<int> used(sz,0),ps(sz);
  auto calc=[](ll x)->ll{return x*(x-1)/2;};
  
  for(int i=0;i<n;i++){
    for(auto x:R[i]){
      if(used[x.second]) continue;
      int c=x.first;      
      queue<P> q;
      q.emplace(i,-1);
      used[R[i][c]]=1;      
      ps[R[i][c]]=-1;
      while(!q.empty()){
        int v,p;
        tie(v,p)=q.front();q.pop();
        if(~p) lct.link(vs[R[p][c]],vs[R[v][c]]);
        for(int u:G[v][c]){
          if(u==p||used[R[u][c]]) continue;
          q.emplace(u,v);	  
          used[R[u][c]]=1;
          ps[R[u][c]]=R[v][c];
        }
      }
      bit.add(c,calc(lct.query(vs[R[i][c]])));
    }
  }

  auto cut=[&](int x,int e){
             int p=R[a[x]][e],q=R[b[x]][e];
             if(ps[q]!=p) swap(p,q);
             bit.add(e,-calc(lct.query(vs[p])));
	     
             lct.cut(vs[q]);
	     
             bit.add(e,calc(lct.query(vs[p])));
             bit.add(e,calc(lct.query(vs[q])));
           };

  auto con=[&](int x,int e){
             int p=R[a[x]][e],q=R[b[x]][e];
             if(ps[q]!=p) swap(p,q);
             bit.add(e,-calc(lct.query(vs[p])));
             bit.add(e,-calc(lct.query(vs[q])));

             lct.link(vs[p],vs[q]);
	     
             bit.add(e,calc(lct.query(vs[p])));
           };    
  
  sort(edges.begin(),edges.end());
  edges.erase(unique(edges.begin(),edges.end()),edges.end());
  for(auto p:edges){
    int x=p.first,e=p.second;
    if(c[x]!=e) cut(x,e);
  }
  
  for(int i=0;i<Q;i++){
    int t=T[i];
    if(t==1){
      int x=A[i],e=B[i];
      x--;
      if(c[x]==e) continue;      
      cut(x,c[x]);
      con(x,e);
      c[x]=e;
    }
    if(t==2){
      int l=A[i],r=B[i];
      printf("%lld\n",bit.sum(r)-bit.sum(l-1));
    }
    if(t==3){
      int x=A[i];
      x--;
      int p=R[a[x]][c[x]];
      printf("%lld\n",calc(lct.query(vs[p])));
    }
  }  
  return 0;
}
/*
  verified on 2018/08/22
  https://www.hackerrank.com/contests/university-codesprint-3/challenges/simple-tree-counting
*/
signed main(){
  UNIVERSITYCODESPRINT03_G();
  return 0;
}
