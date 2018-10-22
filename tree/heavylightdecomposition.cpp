#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct HLDecomposition {
  int n,pos;
  vector<vector<int> > G;
  vector<int> vid, head, sub, par, dep, inv, type;
  
  HLDecomposition(){}
  HLDecomposition(int n):
    n(n),pos(0),G(n),vid(n,-1),head(n),sub(n,1),
    par(n,-1),dep(n,0),inv(n),type(n){}
  
  void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }

  void build(vector<int> rs={0}) {
    int c=0;
    for(int r:rs){
      dfs_sz(r);
      head[r]=r;
      dfs_hld(r,c++);
    }
  }
  
  void dfs_sz(int v) {
    for(int &u:G[v]){
      if(u==par[v]) continue;
      par[u]=v;
      dep[u]=dep[v]+1;
      dfs_sz(u);      
      sub[v]+=sub[u];      
      if(sub[u]>sub[G[v][0]]) swap(u,G[v][0]);
    }
  }

  void dfs_hld(int v,int c) {
    vid[v]=pos++;
    inv[vid[v]]=v;
    type[v]=c;
    for(int u:G[v]){
      if(u==par[v]) continue;
      head[u]=(u==G[v][0]?head[v]:u);
      dfs_hld(u,c);
    }    
  }
  
  // for_each(vertex)
  // [l,r] <- attention!!  
  template<typename F>
  void for_each(int u, int v, const F& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      f(max(vid[head[v]],vid[u]),vid[v]);
      if(head[u]!=head[v]) v=par[head[v]];
      else break;
    }
  }

  template<typename T,typename Q,typename F>
  T for_each(int u,int v,T ti,const Q &q,const F &f){
    T l=ti,r=ti;
    while(1){
      if(vid[u]>vid[v]){
        swap(u,v);
        swap(l,r);
      }
      l=f(l,q(max(vid[head[v]],vid[u]),vid[v]));
      if(head[u]!=head[v]) v=par[head[v]];
      else break;
    }
    return f(l,r);
  }
  
  // for_each(edge)
  // [l,r] <- attention!!
  template<typename F>
  void for_each_edge(int u, int v,const F& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]!=head[v]){
        f(vid[head[v]],vid[v]);
        v=par[head[v]];
      }else{
        if(u!=v) f(vid[u]+1,vid[v]);
        break;
      }
    }
  }
  
  int lca(int u,int v){
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]==head[v]) return u;
      v=par[head[v]];
    }
  }

  int distance(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
  }
};
//END CUT HERE



struct BiconectedGraph{
  typedef pair<int,int> P;
  int n;
  vector<vector<int> > G,C,T;
  vector<int> ord,low,belong;
  vector<P> B;
  BiconectedGraph(){}
  BiconectedGraph(int sz):n(sz),G(sz),C(sz),T(sz){}
  
  void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
  }

  void input(int m,int offset=0){
    int a,b;
    for(int i=0;i<m;i++){
      cin>>a>>b;
      add_edge(a+offset,b+offset);
    }
  }
  
  bool is_bridge(int u,int v){
    if(ord[u]>ord[v]) swap(u,v);
    return ord[u]<low[v];
  }
  
  void dfs(int v,int p,int &k){
    ord[v]=low[v]=k;
    ++k;
    for(int u:G[v]){
      if(u==p) continue;
      if(ord[u]>=0){
        low[v]=min(low[v],ord[u]);
      }else{
        dfs(u,v,k);
        low[v]=min(low[v],low[u]);
      }
      if(is_bridge(u,v)) B.push_back(P(u,v));
    }
  }
  
  void fill_component(int c,int v){
    C[c].push_back(v);
    belong[v]=c;
    for(int u:G[v]){
      if(belong[u]>=0||is_bridge(u,v)) continue;
      fill_component(c,u);
    }
  }
  
  void add_component(int v,int &k){
    if(belong[v]>=0) return;
    fill_component(k++,v);
  }
  
  int build(){
    int k=0;
    ord.resize(n);
    low.resize(n);
    belong.resize(n);
    fill(ord.begin(),ord.end(),-1);
    fill(belong.begin(),belong.end(),-1);
    for(int v=0;v<n;v++){
      if(ord[v]>=0) continue;
      dfs(v,-1,k);
    }
    k=0;
    for(int i=0;i<(int)B.size();i++){
      add_component(B[i].first,k);
      add_component(B[i].second,k);
    }
    for(int v=0;v<n;v++) add_component(v,k);
    for(int i=0;i<(int)B.size();i++){
      int u=belong[B[i].first],v=belong[B[i].second];
      T[u].push_back(v);
      T[v].push_back(u);
    }
    return k;
  }
};


template <typename T,typename E>
struct SegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  int n;
  F f;
  G g;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(int n_,F f,G g,T ti):
    f(f),g(g),ti(ti){
    init(n_);
  }
  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }
  void build(int n_, vector<T> v){
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  void update(int k,E a){
    k+=n;
    dat[k]=g(dat[k],a);
    while(k){
      k>>=1;
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
    }
  }
  inline T query(int a,int b){
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }
  template<typename C>
  int find(int a,int b,C &check,int k,int l,int r){
    if(!check(dat[k])||r<=a||b<=l) return -1;
    if(k>=n) return k-n;
    int m=(l+r)>>1;
    int vl=find(a,b,check,(k<<1)|0,l,m);
    if(~vl) return vl;
    return find(a,b,check,(k<<1)|1,m,r);
  }
  template<typename C>
  int find(int a,int b,C &check){
    return find(a,b,check,1,0,n);
  }
};


template <typename T,typename E>
struct Chien{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  int n,height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  Chien(int n_,F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei){init(n_);}
  void init(int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    dat.assign(2*n,ti);
    laz.assign(2*n,ei);
  }
  void build(int n_, vector<T> v){
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  T reflect(int k){
    return g(dat[k],laz[k]);
  }
  inline void eval(int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    dat[k]=reflect(k);
    laz[k]=ei;
  }
  void update(int a,int b,E x){
    a+=n;b+=n-1;
    for(int i=height;i;i--) eval(a>>i);
    for(int i=height;i;i--) eval(b>>i);
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
    while(a>>=1)
      dat[a]=f(reflect((a<<1)|0),reflect((a<<1)|1));
    while(b>>=1)
      dat[b]=f(reflect((b<<1)|0),reflect((b<<1)|1));
  }
  T query(int a,int b){
    a+=n;b+=n-1;
    for(int i=height;i;i--) eval(a>>i);
    for(int i=height;i;i--) eval(b>>i);
    T vl=ti,vr=ti;
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,reflect(l++));
      if(r&1) vr=f(reflect(--r),vr);
    }
    return f(vl,vr);
  }
};

//INSERT ABOVE HERE

signed AOJ_GRL5C(){
  int n;
  cin>>n;
  HLDecomposition lca(n);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int c;
      cin>>c;
      lca.add_edge(i,c);
    }
  }
  lca.build();
  int q;
  cin>>q;
  while(q--){
    int u,v;
    cin>>u>>v;
    cout<<lca.lca(u,v)<<endl;
  }
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=jp
*/


signed YUKI_529(){
  int n,e,q;
  scanf("%d %d %d",&n,&e,&q);
  
  BiconectedGraph big(n);
  big.input(e,-1);

  int E=0,V=big.build();
  HLDecomposition hl(V);
  for(int i=0;i<V;i++)
    for(int j:big.T[i])
      if(i<j) hl.add_edge(i,j),E++;
  
  hl.build();
  SegmentTree<int,int> rmq(V,
                           [](int a,int b){return max(a,b);},
                           [](int a,int b){a++;return b;},
                           -1);
  vector<priority_queue<int> > pq(V);
  map<int,int> m;
  int num=0;
  for(int i=0;i<q;i++){
    int d;
    scanf("%d",&d);
    if(d==1){
      int u,w;
      scanf("%d %d",&u,&w);
      u--;
      u=big.belong[u];
      u=hl.vid[u];
      m[w]=u;
      if(pq[u].empty()||pq[u].top()<w) rmq.update(u,w);
      pq[u].push(w);
      num++;
    }
    if(d==2){
      int s,t;
      scanf("%d %d",&s,&t);
      s--;t--;
      s=big.belong[s];
      t=big.belong[t];
      auto f=[&](int l, int r)->int{return rmq.query(l, r + 1);};
      int ans=hl.for_each(s, t, -1, f, rmq.f);
      printf("%d\n",ans);
      if(~ans){
        int k=m[ans];
        pq[k].pop();
        rmq.update(k,(!pq[k].empty()?pq[k].top():-1));		 
        num--;
      }
    }
  }
  return 0;
}

/* 
   verified on 2017/12/31
   https://yukicoder.me/problems/no/529
*/

signed AOJ_2667(){
  int n,q;
  scanf("%d %d",&n,&q);
  HLDecomposition hld(n);
  for(int i=1;i<n;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    hld.add_edge(a,b);
  }
  hld.build();

  using P = pair<Int, Int>;
  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,Int b){return P(a.first+b*a.second,a.second);};
  auto h=[](Int a,Int b){return a+b;};
  Chien<P, Int> seg(n,f,g,h,P(0,0),0);
  seg.build(n,vector<P>(n,P(0,1)));
  
  for(int i=0;i<q;i++){
    int t;
    scanf("%d",&t);
    if(t==0){
      int u,v;
      scanf("%d %d",&u,&v);
      Int ans=0;
      hld.for_each_edge(u,v,[&](int l,int r){ans+=seg.query(l,r+1).first;});
      printf("%lld\n",ans);
    }
    if(t==1){
      int v,x;
      scanf("%d %d",&v,&x);
      seg.update(hld.vid[v]+1,hld.vid[v]+hld.sub[v],x);
    }
  }
  return 0;
}

/* 
   verified on 2018/08/14
   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667
*/


signed AOJ_2450(){
  int n,q;
  scanf("%d %d",&n,&q);
  HLDecomposition hld(n);
  vector<int> w(n);
  for(int i=0;i<n;i++) scanf("%d",&w[i]);
  using P = pair<int,int>;
  for(int i=0;i<n-1;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    a--;b--;
    hld.add_edge(a,b);
  }
  hld.build();
  
  using T = tuple<int,int,int,int,int,int,int>;
  
  T ti(-1,-1,-1,-1,-1,-1,-1);
  P ei(-1,-114514);

  auto &par=hld.par;
  auto &vid=hld.vid;;
  auto con=[&](int a,int b){
             return par[a]==b||par[b]==a;
           };
  
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
               return ti;
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
           if(p==ei) return a;
           int al,ar,as,ava,avi,avl,avr;
           tie(al,ar,as,ava,avi,avl,avr)=a;
           int v=p.first,b=p.second;
           if(~v) al=ar=v,as=1;
           if(b>=0) return T(al,ar,as,b*as,b*as,b*as,b*as);
           return T(al,ar,as,b*as,b,b,b);
         };
  auto h=[&](P a,P b){get<0>(a);return b;};


  Chien<T,P> seg(n,f,g,h,ti,ei);
  
  vector<T> vt(n);
  for(int i=0;i<n;i++) vt[vid[i]]=g(ti,P(i,w[i]));
  seg.build(n,vt);
  
  while(q--){
    int t,a,b,c;
    scanf("%d %d %d %d",&t,&a,&b,&c);
    a--;b--;
    if(t==1){
      hld.for_each(a,b,[&](int l,int r){
                         seg.update(l,r+1,P(-1,c));
                       });
    }
    if(t==2){
      auto ask=[&](int l,int r){return seg.query(l,r+1);};      
      T v=hld.for_each(a,b,seg.ti,ask,f);
      int vl,vr,vs,vva,vvi,vvl,vvr;
      tie(vl,vr,vs,vva,vvi,vvl,vvr)=v;
      printf("%d\n",max({vva,vvi,vvl,vvr}));
    }
  }
  
  return 0;
}


/* 
   verified on 2018/08/14
   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450
*/


signed main(){
  //AOJ_GRL5C();
  //YUKI_529();
  //AOJ_2667();
  AOJ_2450();
  return 0;
};
