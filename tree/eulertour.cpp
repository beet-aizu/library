#include<bits/stdc++.h>
using namespace std;
using Int = signed;
//BEGIN CUT HERE
struct EulerTour{
  int n,pos;
  vector<vector<int> > G;
  vector<int> ls,rs;
  
  EulerTour(){}
  EulerTour(int n):n(n),G(n),ls(n),rs(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void dfs(int v,int p){
    ls[v]=pos++;
    for(int u:G[v])
      if(u!=p) dfs(u,v);
    rs[v]=pos;
  }
  
  void build(int r=0){
    pos=0;
    dfs(r,-1);
  }
  
};
//END CUT HERE


struct LowestCommonAncestor{
  int n,h;
  vector<vector<int> > G,par;
  vector<int> dep;
  LowestCommonAncestor(){}
  LowestCommonAncestor(int n):n(n),G(n),dep(n){
    h=1;
    while((1<<h)<=n) h++;
    par.assign(h,vector<int>(n,-1));
  }

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  
  void dfs(int v,int p,int d){
    par[0][v]=p;
    dep[v]=d;
    for(int u:G[v])
      if(u!=p) dfs(u,v,d+1);
  }
  
  void build(int r=0){
    dfs(r,-1,0);
    for(int k=0;k+1<h;k++){
      for(int v=0;v<n;v++){
        if(par[k][v]<0) par[k+1][v]=-1;
        else par[k+1][v]=par[k][par[k][v]];
      }
    }
  }
  
  int lca(int u,int v){
    if(dep[u]>dep[v]) swap(u,v);
    for(int k=0;k<h;k++){
      if((dep[v]-dep[u])>>k&1){
        v=par[k][v];
      }
    }
    if(u==v) return u;
    for(int k=h-1;k>=0;k--){
      if(par[k][u]!=par[k][v]){
        u=par[k][u];
        v=par[k][v];
      }
    }
    return par[0][u];
  }

  int distance(int u,int v){
    return dep[u]+dep[v]-dep[lca(u,v)]*2;
  }
};


template<typename T> 
struct BIT{
  int n;
  vector<T> bit;
  //1-indexed
  BIT():n(-1){}
  BIT(int n_,T d):n(n_),bit(n_+1,d){}
  
  T sum(int i){
    T s=0;
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


template <typename T,typename E>
struct SegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  using P = function<E(E,size_t)>;
  int n;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  P p;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(int n_,F f,G g,H h,T ti,E ei,
              P p=[](E a,size_t b){b++;return a;}):
    f(f),g(g),h(h),ti(ti),ei(ei),p(p){
    init(n_);
  }
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.assign(2*n-1,ti);
    laz.assign(2*n-1,ei);
  }
  void build(int n_, vector<T> v){
    for(int i=0;i<n_;i++) dat[i+n-1]=v[i];
    for(int i=n-2;i>=0;i--)
      dat[i]=f(dat[i*2+1],dat[i*2+2]);
  }
  inline void eval(int len,int k){
    if(laz[k]==ei) return;
    if(k*2+1<n*2-1){
      laz[k*2+1]=h(laz[k*2+1],laz[k]);
      laz[k*2+2]=h(laz[k*2+2],laz[k]);
    }
    dat[k]=g(dat[k],p(laz[k],len));
    laz[k]=ei;
  }
  T update(int a,int b,E x,int k,int l,int r){
    eval(r-l,k);
    if(r<=a||b<=l) return dat[k];
    if(a<=l&&r<=b){
      laz[k]=h(laz[k],x);
      return g(dat[k],p(laz[k],r-l));
    }
    return dat[k]=f(update(a,b,x,k*2+1,l,(l+r)/2),
                    update(a,b,x,k*2+2,(l+r)/2,r));
  }
  T update(int a,int b,E x){
    return update(a,b,x,0,0,n);
  }
  T query(int a,int b,int k,int l,int r){
    eval(r-l,k);
    if(r<=a||b<=l) return ti;
    if(a<=l&&r<=b) return dat[k];
    T vl=query(a,b,k*2+1,l,(l+r)/2);
    T vr=query(a,b,k*2+2,(l+r)/2,r);
    return f(vl,vr);
  }
  T query(int a,int b){
    return query(a,b,0,0,n);
  }
  void update(int k,T x){
    query(k,k+1);//evaluate
    k+=n-1;
    dat[k]=x;
    while(k){
      k=(k-1)/2;
      dat[k]=f(dat[k*2+1],dat[k*2+2]);
    }
  }
};

//INSERT ABOVE HERE
signed CFR483_E(){
  int n;
  scanf("%d",&n);
  LowestCommonAncestor lca(n);
  EulerTour et(n);
  for(int i=1;i<n;i++){
    int p;
    scanf("%d",&p);
    lca.add_edge(p-1,i);
    et.add_edge(p-1,i);
  }
  lca.build(0);
  et.build(0);

  int m;
  scanf("%d",&m);
  vector<int> a(m),b(m);
  for(int i=0;i<m;i++) scanf("%d %d",&a[i],&b[i]);
  
  int q;
  scanf("%d",&q);
  vector<int> u(q),v(q);
  for(int i=0;i<q;i++) scanf("%d %d",&u[i],&v[i]);

  const int LG = 20;
  vector<vector<int> > dp(LG,vector<int>(n,n));
  for(int i=0;i<n;i++) dp[0][i]=i;

  auto check=[&](int &a,int b){
               if(a==n||lca.dep[a]>lca.dep[b]) a=b;
             };
  
  vector<vector<int> > oth(n);
  auto G=et.G;
  for(int i=0;i<m;i++){
    a[i]--;b[i]--;
    int c=lca.lca(a[i],b[i]);
    check(dp[0][a[i]],c);
    check(dp[0][b[i]],c);
    if(b[i]!=c) oth[a[i]].emplace_back(b[i]);
    if(a[i]!=c) oth[b[i]].emplace_back(a[i]);
  }

  function<void(int,int)> dfs=[&](int v,int p){
                                for(int u:G[v]){
                                  if(u==p) continue;
                                  dfs(u,v);
                                  check(dp[0][v],dp[0][u]);
                                }
                              };
  dfs(0,-1);
  
  for(int k=1;k<LG;k++)
    for(int i=0;i<n;i++)
      check(dp[k][i],dp[k-1][dp[k-1][i]]);
  
  auto count=[&](int x,int y)->int{
               if(lca.dep[dp[LG-1][x]]>lca.dep[y]) return -1;
               int res=0;
               for(int i=LG-1;i>=0;i--){
                 if(lca.dep[dp[i][x]]<=lca.dep[y]) continue;
                 res+=1<<i;
                 x=dp[i][x];
               }
               if(lca.dep[x]>lca.dep[y]){
                 res++;
                 x=dp[0][x];
               }
               assert(lca.dep[x]<=lca.dep[y]);
               return res;
             };

  auto climb=[&](int x,int d)->int{
               for(int i=0;i<LG;i++)
                 if((d>>i)&1) x=dp[i][x];
               return x;
             };
  
  vector<int> ans(q),red(q,0);
  using P = pair<int, int>;
  vector<vector<P> > idx(n);
  for(int i=0;i<q;i++){
    u[i]--;v[i]--;
    if(lca.dep[u[i]]<lca.dep[v[i]]) swap(u[i],v[i]);
    int c=lca.lca(u[i],v[i]);    
    if(v[i]==c){
      ans[i]=count(u[i],v[i]);
      continue;
    }
    int x=count(u[i],c);
    int y=count(v[i],c);
    if(x<0||y<0){
      ans[i]=-1;
      continue;
    }
    ans[i]=x+y;
    int f=climb(u[i],x-1);
    int g=climb(v[i],y-1);
    idx[f].emplace_back(i,g);
    idx[g].emplace_back(i,f);
  }
  
  BIT<int> bit(n+10,0);
  function<void(int,int)> dfs2=[&](int v,int p){
                                 int sz=idx[v].size();
                                 vector<int> cur(sz);
                                 for(int i=0;i<sz;i++){
                                   int op=idx[v][i].second;
                                   cur[i]=bit.query0(et.ls[op],et.rs[op]);
                                 }
                                 for(int u:oth[v]) bit.add0(et.ls[u],1);    
                                 for(int u:G[v])
                                   if(u!=p) dfs2(u,v);
    
                                 for(int i=0;i<sz;i++){
                                   int k=idx[v][i].first;
                                   int op=idx[v][i].second;
                                   red[k]|=(cur[i]<bit.query0(et.ls[op],et.rs[op]));
                                 }
                               };
  dfs2(0,-1);
  
  for(int i=0;i<q;i++){
    if(red[i]) ans[i]--;
    if(ans[i]<0) ans[i]=-1;
    printf("%d\n",ans[i]);
  }
  return 0;
}
/*
  verified on 2018/05/18
  http://codeforces.com/contest/983/problem/E
*/

signed AOJ_2871(){
  Int n,q;
  cin>>n>>q;
  EulerTour et(n);
  for(int i=1;i<n;i++){
    int p;
    cin>>p;
    et.add_edge(p-1,i);
  }
  et.build(0);
  
  vector<char> c(n);
  for(Int i=0;i<n;i++) cin>>c[i];

  vector<Int> v(n);
  for(Int i=0;i<n;i++) v[et.ls[i]]=c[i]=='G';
  SegmentTree<Int, Int>::F f=[](Int a,Int b){return a+b;};
  SegmentTree<Int, Int>::G g=[](Int a,Int b){return b?b-a:a;};
  SegmentTree<Int, Int>::H h=[](Int a,Int b){return a^b;};
  SegmentTree<Int, Int>::P p=[](Int a,Int b){return a*b;};

  SegmentTree<Int, Int> seg(n,f,g,h,0,0,p);
  seg.build(n,v);

  for(Int i=0;i<q;i++){
    Int x;
    cin>>x;
    x--;
    seg.update(et.ls[x],et.rs[x],1);
    Int y=seg.query(0,n);
    cout<<(y*2>n?"broccoli":"cauliflower")<<endl;
  }
  return 0;
}
/*
  verified on 2018/05/18
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2871
*/

signed main(){
  //CFR483_E();
  AOJ_2871();
  return 0;
}
