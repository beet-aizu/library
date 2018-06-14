#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
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

  bool is_connected(Node *a,Node *b){
    expose(a);
    while(a->l) a=a->l;
    expose(b);
    while(b->l) b=b->l;
    return a==b;
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

//END CUT HERE
//INSERT ABOVE HERE

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
/*
  verified on 2018/06/14
  https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
*/

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
/*
  verified on 2018/06/14
  https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D
*/


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
/*
  verified on 2018/06/14
  https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E
*/

signed JOISC2013_DAY4_3(){
  int n,q;
  scanf("%d %d",&n,&q);
  
  using LCT = LinkCutTree<int, int>;
  auto f=[](int a,int b){return a+b;};
  auto p=[](int a,size_t b){b++;return a;};
  LCT lct(f,f,f,p,0,0);
  vector<LCT::Node*> vs(n);
  for(int i=0;i<n;i++) vs[i]=lct.create(i,0);

  for(int i=0;i<q;i++){
    int t,a,b=0;
    scanf("%d %d",&t,&a);
    if(t!=2) scanf("%d",&b);
    a--;b--;
    if(t==1) lct.link(vs[b],vs[a]);
    if(t==2) lct.cut(vs[a]);
    if(t==3){
      if(!lct.is_connected(vs[a],vs[b])) puts("-1");
      else printf("%d\n",lct.lca(vs[a],vs[b])->idx+1);
    }
  }
  return 0;
}

/*
  verified on 2018/06/14
  https://beta.atcoder.jp/contests/joisc2013-day4/tasks/joisc2013_spaceships
*/

signed AOJ_2450(){
  int n,q;
  scanf("%d %d",&n,&q);

  using T = tuple<int,int,int,int,int,int,int>;
  using P = pair<int,int>;
  using LCT = LinkCutTree<T, P>;

  vector<vector<int> > G(n); 
  T d1(-1,-1,-1,-1,-1,-1,-1);
  P d0(-1,-114514);
  
  vector<LCT::Node* > vs(n);
  vector<int> ps(n,-1);
  auto con=[&](int a,int b){return ps[a]==b||ps[b]==a;};
  
  auto f=[&](T a,T b){
    if(a>b) swap(a,b);
    
    if(get<0>(a)<0) return b;
    if(con(get<0>(a),get<1>(b))) swap(a,b);
   
    int al,ar,as,ava,avi,avl,avr;
    tie(al,ar,as,ava,avi,avl,avr)=a;
    int bl,br,bs,bva,bvi,bvl,bvr;
    tie(bl,br,bs,bva,bvi,bvl,bvr)=b;
    
    if(!con(ar,bl)){
      if(con(ar,br)){
	swap(bl,br);
	swap(bvl,bvr);
      }else if(con(al,bl)){
	swap(al,ar);
	swap(avl,avr);
      }else{
	return d1;
      }
    }
    int cl=al,cr=br,cs=as+bs;
    int cva=ava+bva,cvi=max(avi,bvi),cvl=avl,cvr=bvr;
    cvi=max(cvi,avr+bvl);
    cvl=max(cvl,ava+bvl);
    cvr=max(cvr,avr+bva);
    
    return T(cl,cr,cs,cva,cvi,cvl,cvr);
  };
  
  auto g=[&](T a,P p){
    if(p==d0) return a;
    int al,ar,as,ava,avi,avl,avr;
    tie(al,ar,as,ava,avi,avl,avr)=a;
    int v=p.first,b=p.second;
    if(~v) al=ar=v,as=1;
    if(b>=0) return T(al,ar,as,b*as,b*as,b*as,b*as);
    return T(al,ar,as,b*as,b,b,b);
  };
  
  auto h=[&](P a,P b){a.first++;return b;};
  auto p=[&](P a,size_t b){b++;return a;};
  LCT lct(f,g,h,p,d1,d0);
  
  
  vector<int> w(n);
  for(int i=0;i<n;i++) scanf("%d",&w[i]);
  for(int i=0;i<n;i++) vs[i]=lct.create(i,g(d1,P(i,w[i])));
  
  for(int i=0;i<n-1;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  for(int i=0;i<n;i++)
    sort(G[i].begin(),G[i].end());

  {
    queue<P> q;
    q.emplace(0,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      if(~p) lct.link(vs[p],vs[v]);
      ps[v]=p;
      for(int u:G[v]){
	if(u==p) continue;
	q.emplace(u,v);
      }
    }
  }
  
  while(q--){
    int t,a,b,c;
    scanf("%d %d %d %d",&t,&a,&b,&c);
    a--;b--;
    if(t==1){
      lct.evert(vs[a]);
      lct.set_propagate(vs[b],P(-1,c));      
    }
    if(t==2){
      lct.evert(vs[a]);
      lct.expose(vs[b]);
      int vva,vvi,vvl,vvr;
      tie(ignore,ignore,ignore,vva,vvi,vvl,vvr)=vs[b]->dat;
      printf("%d\n",max({vva,vvi,vvl,vvr}));
    }
  }
  
  return 0;
}

/*
  verified on 2018/06/14
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450
*/

signed AOJ_0367(){
  int n,k;
  cin>>n>>k;
  
  vector<vector<int> > G(n); 
  vector<map<Int, Int> > m(n);
  for(Int i=0;i<n-1;i++){
    Int a,b,c;
    cin>>a>>b>>c;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
    m[a][b]=m[b][a]=c;
  }
  
  vector<Int> w(n,0);
  vector<int> ps(n,-1);
  using T = tuple<Int, Int, Int>;
  auto mget=[&](Int a,Int b){
	      if(ps[a]!=b&&ps[b]!=a) return 0LL;
	      Int res=w[a]+w[b]+m[a][b];
	      if(res%k) return res;
	      return 0LL;
	    };
  
  auto f=[&](T a,T b){
	   if(a>b) swap(a,b);
	   Int al,ar,av;
	   tie(al,ar,av)=a;
	   Int bl,br,bv;
	   tie(bl,br,bv)=b;
	   if(al<0||ar<0) return b;
	   Int cl,cr,cv=av+bv;
	   if(m[al].count(bl)){
	     cl=ar;cr=br;
	     cv+=mget(al,bl);
	   }else if(m[al].count(br)){
	     cl=ar;cr=bl;
	     cv+=mget(al,br);
	   }else if(m[ar].count(bl)){
	     cl=al;cr=br;
	     cv+=mget(ar,bl);
	   }else if(m[ar].count(br)){
	     cl=al;cr=bl;
	     cv+=mget(ar,br);
	   }else{
	     cl=cr=cv=-1;
	   }
	   return T(cl,cr,cv);
	 };
  
  auto g=[&](T a,Int b){b++;return a;};
  auto h=[&](Int a,Int b){b++;return a;};
  auto p=[&](Int a,size_t b){b++;return a;};
  
  using LCT = LinkCutTree<T, Int>;
  LCT lct(f,g,h,p,T(-1,-1,0),0);  
  vector<LCT::Node* > vs(n);
  for(Int i=0;i<n;i++) vs[i]=lct.create(i,T(i,i,0));
  
  {
    using P = pair<Int, Int>;
    queue<P> q;
    q.emplace(0,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      if(~p) lct.link(vs[p],vs[v]);
      ps[v]=p;
      for(int u:G[v]){
	if(u==p) continue;
	q.emplace(u,v);
      }
    } 
  }
  
  Int q;
  cin>>q;
  while(q--){
    string op;
    cin>>op;
    if(op=="add"){
      Int x,d;
      cin>>x>>d;
      lct.expose(vs[x]);
      w[x]+=d;
      lct.update(vs[x]);
    }
    if(op=="send"){
      Int s,t;
      cin>>s>>t;
      lct.evert(vs[s]);
      lct.expose(vs[t]);
      cout<<get<2>(vs[t]->dat)<<endl;
    }
  }  
  
  return 0;
}

/*
  verified on 2018/06/14
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0367
*/



signed main(){
  //GRL_5_C();
  //GRL_5_D();
  //GRL_5_E();
  //JOISC2013_DAY4_3();
  //AOJ_2450();
  AOJ_0367();
  return 0;
}
