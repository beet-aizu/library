#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
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
  S flip;
  T ti;
  E ei;

  const size_t LIM = 1e6;
  vector<Node> pool;
  size_t ptr;


  LinkCutTree(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei),pool(LIM),ptr(0){
    flip=[](T a){return a;};
  }

  LinkCutTree(F f,G g,H h,S flip,T ti,E ei):
    f(f),g(g),h(h),flip(flip),ti(ti),ei(ei),pool(LIM),ptr(0){}

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
    t->dat=flip(t->dat);
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
#ifndef call_from_test
//INSERT ABOVE HERE
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



signed YUKI_650(){
  cin.tie(0);
  ios::sync_with_stdio(0);

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
      cout<<ans.a<<" "<<ans.b<<" "<<ans.c<<" "<<ans.d<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/08
  https://yukicoder.me/problems/no/650
*/

signed SPOJ_DYNACON1(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,m;
  cin>>n>>m;
  using LCT = LinkCutTree<int, int>;
  auto f=[](int a,int b){return a+b;};
  LCT lct(f,f,f,0,0);
  vector<LCT::Node* > vs(n);
  for(int i=0;i<n;i++) vs[i]=lct.create(i,0);
  for(int i=0;i<m;i++){
    string s;
    int a,b;
    cin>>s>>a>>b;
    a--;b--;
    if(s=="add"s){
      lct.evert(vs[b]);
      lct.link(vs[a],vs[b]);
    }
    if(s=="rem"s){
      auto v=lct.lca(vs[a],vs[b])==vs[a]?vs[b]:vs[a];
      lct.cut(v);
    }
    if(s=="conn"s)
      cout<<(lct.is_connected(vs[a],vs[b])?"YES\n":"NO\n");
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/08
  https://www.spoj.com/problems/DYNACON1/
*/

signed main(){
  //YUKI_650();
  //SPOJ_DYNACON1();
  return 0;
}
#endif
