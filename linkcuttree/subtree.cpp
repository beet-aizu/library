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
    A val,dat,sum;
    Node(){}
    Node(int idx,A val,A dat,A sum):
      idx(idx),rev(0),val(val),dat(dat),sum(sum){l=r=p=nullptr;}
    bool is_root(){
      return !p||(p->l!=this&&p->r!=this);
    }
  };
  A ai;
  const size_t LIM = 1e6+10;
  vector<Node> pool;
  size_t ptr;

  LinkCutTree():ai(A()),pool(LIM),ptr(0){}

  inline Node* create(){
    return &pool[ptr++];
  }

  inline Node* create(int idx,A val){
    return &(pool[ptr++]=Node(idx,val,ai,val));
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

  inline A resolve(Node *t){
    return t?t->sum:ai;
  }

  inline void pushup(Node *t){
    if(t==nullptr) return;
    t->sum=t->val+t->dat;
    t->sum+=resolve(t->l);
    t->sum+=resolve(t->r);
  }

  void rotR(Node *t){
    Node *x=t->p,*y=x->p;
    if((x->l=t->r)) t->r->p=x;
    t->r=x;x->p=t;
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
    }
    pushup(x);
    pushup(t);
    pushup(y);
  }

  void rotL(Node *t){
    Node *x=t->p,*y=x->p;
    if((x->r=t->l)) t->l->p=x;
    t->l=x;x->p=t;
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
    }
    pushup(x);
    pushup(t);
    pushup(y);
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
      c->dat+=resolve(c->r);
      c->r=rp;
      c->dat-=resolve(c->r);
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

  A query(Node *t){
    expose(t);
    return t->sum;
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
  LCT lct;

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
  verified on 2019/06/08
  https://www.hackerrank.com/contests/university-codesprint-3/challenges/simple-tree-counting
*/

signed CFR564_E(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  vector<vector<int>> modv(n),modt(n);
  vector<int> cs(n);

  for(int i=0;i<n;i++){
    cin>>cs[i];
    cs[i]--;
    modv[cs[i]].emplace_back(i);
    modt[cs[i]].emplace_back(0);
  }

  vector<vector<int> > G(n+1);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  G[n].emplace_back(0);

  for(int i=1;i<=m;i++){
    int v,x;
    cin>>v>>x;
    v--;x--;
    modv[cs[v]].emplace_back(v);
    modt[cs[v]].emplace_back(i);
    cs[v]=x;
    modv[cs[v]].emplace_back(v);
    modt[cs[v]].emplace_back(i);
  }

  using ll = long long;
  struct A{
    ll sz1,sz2;
    A():sz1(0),sz2(){}
    A(ll sz1,ll sz2):sz1(sz1),sz2(sz2){}
    A operator+(const A &a)const{
      return A(sz1+a.sz1,sz2+a.sz2);
    };
    A& operator+=(const A &a){
      sz1+=a.sz1;
      sz2+=a.sz1*a.sz1;
      return (*this);
    }
    A& operator-=(const A &a){
      sz1-=a.sz1;
      sz2-=a.sz1*a.sz1;
      return (*this);
    }
  };
  using LCT = LinkCutTree<A>;
  LCT lct;

  vector<LCT::Node*> vs(n+1);
  for(int i=0;i<(int)vs.size();i++) vs[i]=lct.create(i,A(1,0));
  vector<int> par(n+1,0);
  {
    using P = pair<int, int>;
    queue<P> q;
    q.emplace(n,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      par[v]=p;
      if(~p) lct.link(vs[p],vs[v]);
      for(int u:G[v])
        if(u!=p) q.emplace(u,v);
    }
  }

  vector<ll> delta(m+1,0);
  vector<int> color(n+1,0);

  for(int c=0;c<n;c++){
    ll lst=(ll)n*n,cur=(ll)n*n;
    delta[0]+=lst;

    if(modv[c].empty()) continue;
    for(int i=0;i<(int)modv[c].size();i++){
      int v=modv[c][i];
      color[v]^=1;
      if(color[v]){
        cur-=lct.query(lct.root(vs[v])).sz2;
        lct.cut(vs[v]);
        cur+=lct.query(lct.root(vs[par[v]])).sz2;
        cur+=lct.query(vs[v]).sz2;
      }else{
        cur-=lct.query(lct.root(vs[par[v]])).sz2;
        cur-=lct.query(vs[v]).sz2;
        lct.link(vs[par[v]],vs[v]);
        cur+=lct.query(lct.root(vs[v])).sz2;
      }
      if(i+1==(int)modv[c].size()||modt[c][i]!=modt[c][i+1]){
        delta[modt[c][i]]+=cur-lst;
        lst=cur;
      }
    }

    for(int i=0;i<(int)modv[c].size();i++){
      int v=modv[c][i];
      if(!color[v]) continue;
      color[v]^=1;
      lct.link(vs[par[v]],vs[v]);
    }
  }

  ll ans=(ll)n*n*n;
  for(int i=0;i<=m;i++){
    ans-=delta[i];
    cout<<ans<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/08
  https://codeforces.com/contest/1172/problem/E
*/

signed JOISC2013_DAY4_3(){
  int n,q;
  scanf("%d %d",&n,&q);

  using LCT = LinkCutTree<int>;
  LCT lct;
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
  verified on 2019/06/08
  https://atcoder.jp/contests/joisc2013-day4/tasks/joisc2013_spaceships
*/

signed SPOJ_DYNACON1(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,m;
  cin>>n>>m;
  using LCT = LinkCutTree<int>;
  LCT lct;
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
  //UNIVERSITYCODESPRINT03_G();
  //CFR564_E();
  //JOISC2013_DAY4_3();
  //SPOJ_DYNACON1();
  return 0;
}
