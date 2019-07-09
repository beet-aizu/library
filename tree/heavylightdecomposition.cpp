#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
class HLD {
private:
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

  void dfs_hld(int v,int c,int &pos) {
    vid[v]=pos++;
    inv[vid[v]]=v;
    type[v]=c;
    for(int u:G[v]){
      if(u==par[v]) continue;
      head[u]=(u==G[v][0]?head[v]:u);
      dfs_hld(u,c,pos);
    }
  }

public:
  vector<vector<int> > G;
  vector<int> vid, head, sub, par, dep, inv, type;

  HLD(int n):
    G(n),vid(n,-1),head(n),sub(n,1),
    par(n,-1),dep(n,0),inv(n),type(n){}

  void add_edge(int u,int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build(vector<int> rs={0}) {
    int c=0,pos=0;
    for(int r:rs){
      dfs_sz(r);
      head[r]=r;
      dfs_hld(r,c++,pos);
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

  // for_each(vertex)
  // [l, r) <- attention!!
  template<typename F>
  void for_each(int u, int v, const F& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      f(max(vid[head[v]],vid[u]),vid[v]+1);
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
      l=f(l,q(max(vid[head[v]],vid[u]),vid[v]+1));
      if(head[u]!=head[v]) v=par[head[v]];
      else break;
    }
    return f(l,r);
  }

  // for_each(edge)
  // [l, r) <- attention!!
  template<typename F>
  void for_each_edge(int u, int v,const F& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]!=head[v]){
        f(vid[head[v]],vid[v]+1);
        v=par[head[v]];
      }else{
        if(u!=v) f(vid[u]+1,vid[v]+1);
        break;
      }
    }
  }
};
//END CUT HERE
template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(F f,T ti):f(f),ti(ti){}
  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }
  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  void set_val(int k,T x){
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }
  T query(int a,int b){
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }
  template<typename C>
  int find(int st,C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=f(acc,dat[k]);
      return check(acc)?k-n:-1;
    }
    int m=(l+r)>>1;
    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);
    if(st<=l&&!check(f(acc,dat[k]))){
      acc=f(acc,dat[k]);
      return -1;
    }
    int vl=find(st,check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return find(st,check,acc,(k<<1)|1,m,r);
  }
  template<typename C>
  int find(int st,C &check){
    T acc=ti;
    return find(st,check,acc,1,0,n);
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
  Chien(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei){}

  void init(int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    dat.assign(2*n,ti);
    laz.assign(2*n,ei);
  }
  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  inline T reflect(int k){
    return laz[k]==ei?dat[k]:g(dat[k],laz[k]);
  }
  inline void eval(int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    dat[k]=reflect(k);
    laz[k]=ei;
  }
  inline void thrust(int k){
    for(int i=height;i;i--) eval(k>>i);
  }
  inline void recalc(int k){
    while(k>>=1)
      dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
  }
  void update(int a,int b,E x){
    thrust(a+=n);
    thrust(b+=n-1);
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
    recalc(a);
    recalc(b);
  }
  void set_val(int a,T x){
    thrust(a+=n);
    dat[a]=x;laz[a]=ei;
    recalc(a);
  }
  T query(int a,int b){
    thrust(a+=n);
    thrust(b+=n-1);
    T vl=ti,vr=ti;
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,reflect(l++));
      if(r&1) vr=f(reflect(--r),vr);
    }
    return f(vl,vr);
  }

  template<typename C>
  int find(int st,C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=f(acc,reflect(k));
      return check(acc)?k-n:-1;
    }
    eval(k);
    int m=(l+r)>>1;
    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);
    if(st<=l&&!check(f(acc,dat[k]))){
      acc=f(acc,dat[k]);
      return -1;
    }
    int vl=find(st,check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return find(st,check,acc,(k<<1)|1,m,r);
  }
  template<typename C>
  int find(int st,C &check){
    T acc=ti;
    return find(st,check,acc,1,0,n);
  }
};


struct LowLink{
  int n,pos;
  vector<int> ord,low,par,blg,num;
  vector<vector<int> > G,C,T;
  vector<vector<pair<int, int> > > E;

  vector<int> ap;
  vector<pair<int, int> > bs,cand;

  LowLink(int n):n(n),pos(0),ord(n,-1),low(n),
                 par(n,-1),blg(n,-1),num(n,1),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  bool is_bridge(int u,int v){
    if(ord[u]>ord[v]) swap(u,v);
    return ord[u]<low[v];
  }

  void dfs(int v){
    ord[v]=low[v]=pos++;
    for(int u:G[v]){
      if(u==par[v]) continue;
      if(ord[u]<ord[v])
        cand.emplace_back(min(u,v),max(u,v));
      if(~ord[u]){
        low[v]=min(low[v],ord[u]);
        continue;
      }
      par[u]=v;
      dfs(u);
      num[v]+=num[u];
      low[v]=min(low[v],low[u]);
      if(is_bridge(u,v)) bs.emplace_back(u,v);
      if(low[u]>=ord[v]){
        E.emplace_back();
        while(1){
          auto e=cand.back();
          cand.pop_back();
          E.back().emplace_back(e);
          if(make_pair(min(u,v),max(u,v))==e) break;
        }
      }
    }
  }

  void fill_component(int v){
    C[blg[v]].emplace_back(v);
    for(int u:G[v]){
      if(~blg[u]||is_bridge(u,v)) continue;
      blg[u]=blg[v];
      fill_component(u);
    }
  }

  void add_component(int v,int &k){
    if(~blg[v]) return;
    blg[v]=k++;
    C.emplace_back();
    fill_component(v);
  }

  int build(){
    for(int i=0;i<n;i++)
      if(ord[i]<0) dfs(i);

    vector<int> cnt(n,0);
    for(int i=0;i<n;i++){
      int p=par[i];
      if(p<0) continue;
      if(par[p]<0) cnt[p]++;
      else if(ord[p]<=low[i]) ap.emplace_back(p);
    }

    for(int i=0;i<n;i++)
      if(cnt[i]>1) ap.emplace_back(i);

    sort(ap.begin(),ap.end());
    ap.erase(unique(ap.begin(),ap.end()),ap.end());

    int k=0;
    for(int i=0;i<n;i++) add_component(i,k);

    T.assign(k,vector<int>());
    for(auto e:bs){
      int u=blg[e.first],v=blg[e.second];
      T[u].emplace_back(v);
      T[v].emplace_back(u);
    }
    return k;
  }
};

//INSERT ABOVE HERE

signed AOJ_GRL5C(){
  int n;
  cin>>n;
  HLD lca(n);
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
  verified on 2019/07/08
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=jp
*/


signed YUKI_529(){
  int n,e,q;
  scanf("%d %d %d",&n,&e,&q);

  LowLink big(n);
  for(int i=0;i<e;i++){
    int u,v;
    scanf("%d %d",&u,&v);
    u--;v--;
    big.add_edge(u,v);
  }

  int E=0,V=big.build();
  HLD hld(V);
  for(int i=0;i<V;i++)
    for(int j:big.T[i])
      if(i<j) hld.add_edge(i,j),E++;
  hld.build();

  SegmentTree<int> rmq([](int a,int b){return max(a,b);},-1);
  rmq.build(vector<int>(V,-1));

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
      u=big.blg[u];
      u=hld.vid[u];
      m[w]=u;
      if(pq[u].empty()||pq[u].top()<w) rmq.set_val(u,w);
      pq[u].push(w);
      num++;
    }
    if(d==2){
      int s,t;
      scanf("%d %d",&s,&t);
      s--;t--;
      s=big.blg[s];
      t=big.blg[t];
      auto f=[&](int l,int r){return rmq.query(l,r);};
      int ans=hld.for_each(s,t,-1,f,rmq.f);
      printf("%d\n",ans);
      if(~ans){
        int k=m[ans];
        pq[k].pop();
        rmq.set_val(k,(!pq[k].empty()?pq[k].top():-1));
        num--;
      }
    }
  }
  return 0;
}
/*
  verified on 2019/07/08
   https://yukicoder.me/problems/no/529
*/

signed AOJ_2667(){
  using ll = long long;

  int n,q;
  scanf("%d %d",&n,&q);
  HLD hld(n);
  for(int i=1;i<n;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    hld.add_edge(a,b);
  }
  hld.build();

  using P = pair<ll, ll>;
  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,ll b){return P(a.first+b*a.second,a.second);};
  auto h=[](ll a,ll b){return a+b;};
  Chien<P, ll> seg(f,g,h,P(0,0),0);
  seg.build(vector<P>(n,P(0,1)));

  for(int i=0;i<q;i++){
    int t;
    scanf("%d",&t);
    if(t==0){
      int u,v;
      scanf("%d %d",&u,&v);
      ll ans=0;
      hld.for_each_edge(u,v,[&](int l,int r){ans+=seg.query(l,r).first;});
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
  verified on 2019/07/08
   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667
*/


signed AOJ_2450(){
  int n,q;
  scanf("%d %d",&n,&q);
  HLD hld(n);
  vector<int> w(n);
  for(int i=0;i<n;i++) scanf("%d",&w[i]);
  using P = pair<int, int>;
  for(int i=0;i<n-1;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    a--;b--;
    hld.add_edge(a,b);
  }
  hld.build();

  using T = tuple<int, int, int, int, int, int, int>;

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

  auto h=[&](P a,P b){(void)a;return b;};


  Chien<T,P> seg(f,g,h,ti,ei);

  vector<T> vt(n);
  for(int i=0;i<n;i++) vt[vid[i]]=g(ti,P(i,w[i]));
  seg.build(vt);

  while(q--){
    int t,a,b,c;
    scanf("%d %d %d %d",&t,&a,&b,&c);
    a--;b--;
    if(t==1){
      hld.for_each(a,b,[&](int l,int r){seg.update(l,r,P(-1,c));});
    }
    if(t==2){
      auto ask=[&](int l,int r){return seg.query(l,r);};
      T v=hld.for_each(a,b,seg.ti,ask,f);
      int vl,vr,vs,vva,vvi,vvl,vvr;
      tie(vl,vr,vs,vva,vvi,vvl,vvr)=v;
      printf("%d\n",max({vva,vvi,vvl,vvr}));
    }
  }
  return 0;
}
/*
   verified on 2019/07/08
   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450
*/


signed main(){
  //AOJ_GRL5C();
  //YUKI_529();
  //AOJ_2667();
  //AOJ_2450();
  return 0;
};
