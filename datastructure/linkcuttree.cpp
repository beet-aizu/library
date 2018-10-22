#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T,typename E>
struct LinkCutTree{
  struct Node{
    Node *l,*r,*p;
    size_t sz;// tree size (only for root)
    int idx;
    bool rev;
    T val,dat;
    E laz;
    Node():sz(1){}
    Node(int idx,T val,E laz):
      sz(1),idx(idx),rev(0),val(val),dat(val),laz(laz){l=r=p=nullptr;}
    bool is_root(){
      return !p||(p->l!=this&&p->r!=this);
    }
  };
  
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  using S = function<T(T)>;
  F f;
  G g;
  H h;
  S s;
  T ti;
  E ei;
  
  const size_t LIM = 1e6;
  vector<Node> pool;
  size_t ptr;
  
  
  LinkCutTree(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei),pool(LIM),ptr(0){
    s=[](T a){return a;};
  }
  
  LinkCutTree(F f,G g,H h,S s,T ti,E ei):
    f(f),g(g),h(h),s(s),ti(ti),ei(ei),pool(LIM),ptr(0){}
  
  inline Node* create(){
    return &pool[ptr++];
  }
  
  inline Node* create(int idx,T v){
    return &(pool[ptr++]=Node(idx,v,ei));
  }

  void propagate(Node *t,E v){
    t->laz=h(t->laz,v);
    t->val=g(t->val,v);
    t->dat=g(t->dat,v);
  }

  void toggle(Node *t){
    swap(t->l,t->r);
    t->dat=s(t->dat);
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

  void recalc(Node *t){
    t->dat=t->val;
    if(t->l) t->dat=f(t->l->dat,t->dat);
    if(t->r) t->dat=f(t->dat,t->r->dat);
  }

  void rotR(Node *t){
    Node *x=t->p,*y=x->p;    
    x->sz-=t->sz;
    t->sz+=x->sz;
    if((x->l=t->r)) t->r->p=x,x->sz+=x->l->sz; 
    t->r=x;x->p=t;
    recalc(x);recalc(t);
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
      recalc(y);
    }
  }
  
  void rotL(Node *t){
    Node *x=t->p,*y=x->p;
    x->sz-=t->sz;
    t->sz+=x->sz;
    if((x->r=t->l)) t->l->p=x,x->sz+=x->r->sz;
    t->l=x;x->p=t;
    recalc(x);recalc(t);
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
      recalc(y);
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
      recalc(c);
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
    par->sz+=c->sz;
  }

  void cut(Node *c){
    expose(c);
    Node *par=c->l;
    c->l=nullptr;
    par->p=nullptr;
    c->sz-=par->sz;
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
  
  T query(Node *t){
    expose(t);
    return t->dat;
  }

  void update(Node *t,E v){
    expose(t);
    propagate(t,v);
    eval(t);
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
  
  int lower_bound(int w){
    if(w<=0) return 0;
    int x=0,r=1;
    while(r<n) r<<=1;
    for(int k=r;k>0;k>>=1){
      if(x+k<=n&&bit[x+k]<w){
        w-=bit[x+k];
        x+=k;
      }
    }
    return x+1;
  }
  
  T sum0(int i){
    return sum(i+1);
  }
  void add0(int i,T a){
    add(i+1,a);
  }

  T query(int l,int r){
    return sum(r-1)-sum(l-1);
  }

  T query0(int l,int r){
    return sum(r)-sum(l);
  }
};

//INSERT ABOVE HERE

signed GRL_5_C(){
  int n;
  cin>>n;
  using LCT = LinkCutTree<int,int>;
  LCT::F f=[](int a,int b){return min(a,b);};
  LCT lc(f,f,f,0,0);

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
  LCT lc(f,f,f,0,0);

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
  using P = pair<Int, Int>;
  using LCT = LinkCutTree<P, Int>;
  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,int b){return P(a.first+b*a.second,a.second);};
  auto h=[](Int a,Int b){return a+b;};
  
  LCT lc(f,g,h,P(0,0),0);

  vector<LCT::Node*> v(n);
  for(int i=0;i<n;i++) v[i]=lc.create(i,P(0,1));
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
      lc.update(v[a],b);
      c+=b;
    }
    if(t==1){
      int a;
      cin>>a;
      lc.expose(v[a]);
      cout<<(v[a]->dat).first-c<<endl;
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
  LCT lct(f,f,f,0,0);
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

  using T = tuple<int,int,int,int,int>;
  using P = pair<int,int>;
  
  T ti(-1,-1,-1,-1,-1);
  P ei(-1,-114514);
  
  auto f=[&](T a,T b){
           int as,ava,avi,avl,avr;
           tie(as,ava,avi,avl,avr)=a;
           int bs,bva,bvi,bvl,bvr;
           tie(bs,bva,bvi,bvl,bvr)=b;
           int cs=as+bs;
           int cva=ava+bva,cvi=max(avi,bvi),cvl=avl,cvr=bvr;
           cvi=max(cvi,avr+bvl);
           cvl=max(cvl,ava+bvl);
           cvr=max(cvr,avr+bva);
           return T(cs,cva,cvi,cvl,cvr);
         };
  
  auto g=[&](T a,P p){
           if(p==ei) return a;
           int as,ava,avi,avl,avr;
           tie(as,ava,avi,avl,avr)=a;
           int v=p.first,b=p.second;
           if(~v) as=1;
           if(b>=0) return T(as,b*as,b*as,b*as,b*as);
           return T(as,b*as,b,b,b);
         };
  
  auto h=[&](P a,P b){a.first++;return b;};
  auto s=
    [&](T a){      
      int as,ava,avi,avl,avr;
      tie(as,ava,avi,avl,avr)=a;
      swap(avl,avr);
      return T(as,ava,avi,avl,avr);
    };
  
  
  using LCT = LinkCutTree<T, P>;
  vector<LCT::Node* > vs(n);
  vector<int> ps(n,-1);
  
  LCT lct(f,g,h,s,ti,ei);
  
  vector<int> w(n);
  for(int i=0;i<n;i++) scanf("%d",&w[i]);
  for(int i=0;i<n;i++) vs[i]=lct.create(i,g(ti,P(i,w[i])));
  
  vector<vector<int> > G(n); 
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
      lct.update(vs[b],P(-1,c));      
    }
    if(t==2){
      lct.evert(vs[a]);      
      int vva,vvi,vvl,vvr;
      tie(ignore,vva,vvi,vvl,vvr)=lct.query(vs[b]);
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
  scanf("%d %d",&n,&k);
  
  vector<vector<int> > G(n); 
  vector<unordered_map<Int, Int> > m(n);
  for(Int i=0;i<n-1;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
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
           Int al,ar,av;
           tie(al,ar,av)=a;
           Int bl,br,bv;
           tie(bl,br,bv)=b;
           return T(al,br,av+bv+mget(ar,bl));
         };
  
  auto g=[&](T a,Int b){b++;return a;};
  auto h=[&](Int a,Int b){b++;return a;};
  auto s=[&](T a){
           Int al,ar,av;
           tie(al,ar,av)=a;
           return T(ar,al,av);
         };
  
  using LCT = LinkCutTree<T, Int>;
  LCT lct(f,g,h,s,T(-1,-1,0),0);  
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
  
  char buf[10];
  int q;
  scanf("%d",&q);
  while(q--){
    scanf("%s",buf);
    string op(buf);
    if(op=="add"){
      int x,d;      
      scanf("%d %d",&x,&d);
      lct.expose(vs[x]);
      w[x]+=d;
      lct.recalc(vs[x]);
    }
    if(op=="send"){
      int s,t;
      scanf("%d %d",&s,&t);
      lct.evert(vs[s]);
      printf("%lld\n",get<2>(lct.query(vs[t])));
    }
  }  
  return 0;
}

/*
  verified on 2018/06/14
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0367
*/



struct M{
  Int a,b,c,d;
  M():a(1),b(0),c(0),d(1){}
  M(Int a,Int b,Int c,Int d):a(a),b(b),c(c),d(d){}
  //M(const M &v):a(v.a),b(v.b),c(v.c),d(v.d){}
  bool operator!=(const M &x)const{
    return a!=x.a||b!=x.b||c!=x.c||d!=x.d;
  }
  bool operator==(const M &x)const{
    return !(*this!=x);
  }
};

signed YUKI_650(){
  const int MOD=1e9+7;
  using M2 = pair<M, M>;
  using LCT = LinkCutTree<M2, M2>;
  auto f=[MOD](M x,M y){
           M r(0,0,0,0);
           r.a=x.a*y.a+x.b*y.c;
           r.b=x.a*y.b+x.b*y.d;
           r.c=x.c*y.a+x.d*y.c;
           r.d=x.c*y.b+x.d*y.d;	   
           r.a%=MOD;r.b%=MOD;r.c%=MOD;r.d%=MOD;
           return r;
         };
  auto f2=[&](M2 x,M2 y){
            return M2(f(x.first,y.first),f(y.second,x.second));
          };
  auto g=[](M2 x,M2 y){x.first.a++;return y;};
  auto s=[](M2 x){swap(x.first,x.second);return x;};
  
  int n;
  cin>>n;
  vector<vector<int> > G(n);
  vector<int> X,Y;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    X.emplace_back(a);
    Y.emplace_back(b);
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  M ti=M();
  M ei(-1,-1,-1,-1);
  LCT lct(f2,g,g,s,M2(ti,ti),M2(ei,ei));

  
  vector<LCT::Node*> vs(n*2-1);
  for(int i=0;i<(int)vs.size();i++) vs[i]=lct.create(i,M2(ti,ti));
  
  vector<map<int, int> > rev(n);
  int idx=n;
  {
    using P = pair<int, int>;
    queue<P> q;
    q.emplace(0,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      if(~p){
        lct.link(vs[p],vs[idx]);
        lct.link(vs[idx],vs[v]);
        rev[p][v]=rev[v][p]=idx++;
      }
      for(int u:G[v])
        if(u!=p) q.emplace(u,v);
    }
  }
  
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    char c;
    cin>>c;
    if(c=='x'){
      Int v,a,b,c,d;
      cin>>v>>a>>b>>c>>d;
      int z=rev[X[v]][Y[v]];
      lct.expose(vs[z]);
      vs[z]->val=M2(M(a,b,c,d),M(a,b,c,d));      
      lct.recalc(vs[z]);
    }
    if(c=='g'){
      Int x,y;
      cin>>x>>y;
      lct.evert(vs[x]);      
      M ans=lct.query(vs[y]).first;
      cout<<ans.a<<" "<<ans.b<<" "<<ans.c<<" "<<ans.d<<endl;
    }
  }
  
  return 0;
}
/*
  verified on 2018/06/14
  https://yukicoder.me/problems/no/650
*/


signed UNIVERSITYCODESPRINT03_G(){
  int n;  
  scanf("%d",&n);
  BIT<Int> bit(1e6+100,0);
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
  
  using LCT = LinkCutTree<int, int>;
  auto f=[](int a,int b){return a+b;};
  LCT lct(f,f,f,0,0);

  vector<LCT::Node*> vs(sz);
  for(int i=0;i<sz;i++) vs[i]=lct.create(i,1);

  vector<int> used(sz,0),ps(sz);
  auto calc=[](Int x)->Int{return x*(x-1)/2;};
  
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
      lct.expose(vs[R[i][c]]);
      bit.add(c,calc(vs[R[i][c]]->sz));
    }
  }

  auto cut=[&](int x,int e){
             int p=R[a[x]][e],q=R[b[x]][e];
             if(ps[q]!=p) swap(p,q);
             lct.expose(vs[p]);
             bit.add(e,-calc(vs[p]->sz));
	     
             lct.cut(vs[q]);
	     
             lct.expose(vs[p]);
             lct.expose(vs[q]);
             bit.add(e,calc(vs[p]->sz));
             bit.add(e,calc(vs[q]->sz));
           };

  auto con=[&](int x,int e){
             int p=R[a[x]][e],q=R[b[x]][e];
             if(ps[q]!=p) swap(p,q);
             lct.expose(vs[p]);
             lct.expose(vs[q]);
             bit.add(e,-calc(vs[p]->sz));
             bit.add(e,-calc(vs[q]->sz));
	     
             lct.link(vs[p],vs[q]);
	     
             lct.expose(vs[p]);
             bit.add(e,calc(vs[p]->sz));
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
      lct.expose(vs[p]);
      printf("%lld\n",calc(vs[p]->sz));
    }
  }
  
  return 0;
}
/*
  verified on 2018/08/22
  https://www.hackerrank.com/contests/university-codesprint-3/challenges/simple-tree-counting
*/

signed main(){
  //GRL_5_C();
  //GRL_5_D();
  //GRL_5_E();
  //JOISC2013_DAY4_3();
  AOJ_2450();
  //AOJ_0367();
  //YUKI_650();
  //UNIVERSITYCODESPRINT03_G();
  return 0;
}
