#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T,size_t X>
struct BinaryTrie{
  struct Node{
    size_t cnt;
    Node *p,*l,*r;
    Node(Node* p):cnt(0),p(p){l=r=nullptr;}
  };
  
  T acc;
  Node *root;
  BinaryTrie():acc(0){root=emplace(nullptr);}

  void dfs(Node *a){
    if(!a) return;
    dfs(a->l);dfs(a->r);
    delete(a);
  }
  
  inline Node* emplace(Node* p){
    return new Node(p);
  }

  inline size_t count(Node* a){
    return a?a->cnt:0;
  }
  
  void add(const T b,size_t k=1){
    const T nb=b^acc;
    Node* a=root;
    for(int i=X-1;i>=0;i--){
      bool f=(nb>>i)&1;
      if(!f&&!a->l) a->l=emplace(a);
      if( f&&!a->r) a->r=emplace(a);
      a=f?a->r:a->l;
    }
    a->cnt+=k;    
    while((a=a->p)) a->cnt=count(a->l)+count(a->r);    
  }

  inline void update(const T b){acc^=b;}

  Node* find(const T b){
    const T nb=b^acc;
    Node* a=root;
    for(int i=X-1;i>=0;i--){
      bool f=(nb>>i)&1;
      a=f?a->r:a->l;
      if(!a) return a;
    }
    return a;
  }

  Node* check(Node *a){
    if(!a||count(a)) return a;
    delete(a);
    return nullptr;
  }

  void sub(Node* a,size_t k=1){
    assert(a&&a->cnt>=k);
    a->cnt-=k;
    while((a=a->p)){
      a->l=check(a->l);
      a->r=check(a->r);
      a->cnt=count(a->l)+count(a->r);
    }
  }
  
  Node* xmax(const T b){
    assert(count(root));
    const T nb=b^acc;
    Node* a=root;    
    for(int i=X-1;i>=0;i--){
      bool f=(nb>>i)&1;
      if(!a->l||!a->r) a=a->l?a->l:a->r;
      else a=f?a->l:a->r;
    }
    return a;
  }

  Node* xmin(const T b){
    return xmax(~b&((T(1)<<X)-1));
  }

  Node* ge(Node *a,int i){
    if(!a) return a;
    Node *l=a->l,*r=a->r;
    if((acc>>i)&1) swap(l,r);
    if(l||r) return ge(l?l:r,i+1);
    return a;
  }
  
  Node* next(Node* a,int i){
    if(!(a->p)) return nullptr;
    Node *l=a->p->l,*r=a->p->r;
    if((acc>>(i+1))&1) swap(l,r);
    if(a==l&&r) return ge(r,i);
    return next(a->p,i+1);
  }
  
  Node* lower_bound(const T b){
    const T nb=b^acc;
    Node* a=root;
    for(int i=X-1;i>=0;i--){
      bool f=(nb>>i)&1;
      if(!f&&a->l){a=a->l;continue;}
      if( f&&a->r){a=a->r;continue;}
      if((b>>i)&1) return next(a,i);
      return ge(a,i);
    }
    return a;
  }

  Node* upper_bound(const T b){
    return lower_bound(b+1);
  }
  
  T val(Node* a){
    T res(0);
    for(int i=0;i<(int)X;i++){
      assert(a->p);
      res|=(T(a==a->p->r)<<i);
      a=a->p;
    }
    return res^acc;
  }

  Node* find_by_order(size_t k){
    Node *a=root;
    if(count(a)<=k) return nullptr;
    for(int i=X-1;i>=0;i--){
      bool f=(acc>>i)&1;
      if(count(f?a->r:a->l)<=k){
        k-=count(f?a->r:a->l);
        a=f?a->l:a->r;
      }else{
        a=f?a->r:a->l;
      }
    }
    return a;
  }
  
  size_t order_of_key(const T b){
    Node *a=root;
    size_t res=0;
    for(int i=X-1;i>=0;i--){      
      Node *l=a->l,*r=a->r;
      if((acc>>i)&1) swap(l,r);
      bool f=(b>>i)&1;
      if(f) res+=count(l); 
      a=f?r:l;
      if(!a) break;
    }
    return res;
  }
};
//END CUT HERE

signed JAG2013SUMMERWARMINGUP_F(){
  int n;
  scanf("%d",&n);
  vector<int> a(n);
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  vector<int> s(n+1,0);
  for(int i=0;i<n;i++) s[i+1]=s[i]^a[i];
  BinaryTrie<int, 30> bt;
  using ull = unsigned long long;
  map<ull, int> r;
  bt.add(0);
  r[(ull)bt.find(0)]=0;
  int ans=-1,idx=-1,idy=-1;
  for(int i=0;i<n;i++){
    int k=r[(ull)bt.xmax(a[i])];
    int res=s[i+1]^s[k];
    if(ans<res||(ans==res&&idx>k)){
      ans=res;
      idx=k;
      idy=i;
    }
    bt.update(a[i]);
    bt.add(0);
    if(!r.count((ull)bt.find(0))) r[(ull)bt.find(0)]=i+1;
  }
  printf("%d %d %d\n",ans,idx+1,idy+1);
  return 0;
}
/*
  verified on 2018/10/24
  https://beta.atcoder.jp/contests/jag2013summer-warmingup/tasks/icpc2013summer_warmingUp_f
*/

signed ARC033_C(){
  int q;
  scanf("%d",&q);
  BinaryTrie<int, 30> bt;
  while(q--){
    int t,x;
    scanf("%d %d",&t,&x);
    if(t==1) bt.add(x);
    if(t==2){
      auto k=bt.find_by_order(x-1);
      printf("%d\n",bt.val(k));
      bt.sub(k);
    }
  }
  return 0;
}

/*
  verified on 2018/10/24
  https://beta.atcoder.jp/contests/arc033/tasks/arc033_3
*/

signed AOJ_DSL2B(){
  int n,q;
  scanf("%d %d",&n,&q);
  BinaryTrie<int, 30> bt;
  for(int i=0;i<q;i++){
    int c,x,y;
    scanf("%d %d %d",&c,&x,&y);
    if(c) printf("%zd\n",bt.order_of_key(y+1)-bt.order_of_key(x));
    else bt.add(x,y);
  }
  return 0;
}

/*
  verified on 2018/10/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp
*/

signed CFR470_C(){
  int n;
  scanf("%d",&n);
  vector<int> a(n),p(n);
  for(Int i=0;i<n;i++) scanf("%d",&a[i]);
  for(Int i=0;i<n;i++) scanf("%d",&p[i]);

  BinaryTrie<int, 30> bt;
  for(int i=0;i<n;i++) bt.add(p[i]);
  
  for(Int i=0;i<n;i++){
    if(i) printf(" ");
    auto k=bt.xmin(a[i]);
    printf("%d",a[i]^bt.val(k));
    bt.sub(k);
  }
  puts("");
  return 0;
}
/*
  verified on 2018/10/24
  http://codeforces.com/contest/947/problem/C
*/

signed CFR477_C(){
  Int n;
  scanf("%lld",&n);
  vector<Int> b(n);
  for(Int i=0;i<n;i++) scanf("%lld",&b[i]);
  
  BinaryTrie<Int, 61> bt;
  for(Int i=0;i<n;i++) bt.add(b[i]);
  
  Int z=0;
  auto apply=[&](Int a){
               z^=a;
               bt.update(a);
             };

  vector<Int> ans;
  Int x=bt.val(bt.xmin(0));
  
  ans.emplace_back(x);
  bt.sub(bt.find(x));
  apply(x);

  for(Int i=1;i<n;i++){
    if(bt.val(bt.xmax(0))<=x){
      printf("No\n");
      return 0; 
    }
    auto nxt=bt.upper_bound(x);
    Int y=bt.val(nxt);
    
    ans.emplace_back(y^z);
    bt.sub(nxt);
    apply(x^y);
    x=y;    
  }
  
  printf("Yes\n");
  for(Int i=0;i<n;i++){
    if(i) printf(" ");
    printf("%lld",ans[i]);
  }
  puts("");
  return 0;
}
/*
  verified on 2018/10/24
  http://codeforces.com/contest/966/problem/C
*/


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
  
  int lca(int u,int v){
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]==head[v]) return u;
      v=par[head[v]];
    }
  }
  
  Int la(Int v,Int k){
    while(1){
      Int u=head[v];
      if(vid[v]-k>=vid[u]) return inv[vid[v]-k];
      k-=vid[v]-vid[u]+1;
      v=par[u];
    }
  }

  int distance(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
  }
};

//INSERT ABOVE HERE
signed KUPC2018_M(){
  using ll = long long;
  int n;
  scanf("%d",&n);
  HLDecomposition hld(n);
  for(int i=1;i<n;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    a--;b--;
    hld.add_edge(a,b);
  }
  hld.build();

  using T = BinaryTrie<int, 31>;
  using E = pair<int, ll>;

  struct SegmentTree{
    int n;
    vector<T> dat;
    SegmentTree(int n_){
      n=1;
      while(n<n_) n<<=1;
      dat=vector<T>(n*2);
      for(int i=0;i<n*2;i++) dat[i]=T();
    }
    void reset(){
      for(int i=0;i<n*2;i++) dat[i].dfs(dat[i].root);
    }
    void update(int a,int b,E x){
      for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
        if(l&1) dat[l++].add(x.first,x.second);
        if(r&1) dat[--r].add(x.first,x.second);
      }
    }
    ll query(int k,E x){
      ll res=0;
      k+=n;
      while(k){
        dat[k].update(x.first);
        res+=dat[k].order_of_key(x.second+1);
        dat[k].update(x.first);
        k>>=1;
      }
      return res;
    }
  };
  
  int q;
  scanf("%d",&q);

  vector<int> type(q),vs(q),xs(q),ks(q),ys(q),zs(q);
  vector<ll> ans(q);
  for(int i=0;i<q;i++){
    scanf("%d",&type[i]);
    if(type[i]==1) scanf("%d %d %d",&vs[i],&xs[i],&ks[i]);      
    if(type[i]==2) scanf("%d %d %d",&vs[i],&ys[i],&zs[i]);
    if(type[i]==3) scanf("%d",&vs[i]);
    vs[i]--;
  }
  
  const int UKU = 8;
  for(int uku=0;uku<UKU;uku++){
    SegmentTree seg(n);
    int rt=0;
    for(int i=0;i<q;i++){
      if(type[i]==1&&(i%UKU)==uku){
        int v=vs[i],x=xs[i],k=ks[i];
        if(rt==v){	
          seg.update(0,n,E(x,k));
        }else if(hld.lca(rt,v)==v){
          int u=hld.la(rt,hld.distance(rt,v)-1);
          int l=hld.vid[u],r=hld.vid[u]+hld.sub[u];
          seg.update(0,l,E(x,k));
          seg.update(r,n,E(x,k));
        }else{	
          int l=hld.vid[v],r=hld.vid[v]+hld.sub[v];
          seg.update(l,r,E(x,k));
        }
      }
      if(type[i]==2){
        int v=vs[i],y=ys[i],z=zs[i];
        ans[i]+=seg.query(hld.vid[v],E(y,z));
      }
      if(type[i]==3){
        rt=vs[i];
      }
    }
    seg.reset();
  }
  
  for(int i=0;i<q;i++)
    if(type[i]==2) printf("%lld\n",ans[i]);
  return 0;
}
/*
  verified on 2018/10/24
  https://beta.atcoder.jp/contests/kupc2018/tasks/kupc2018_m
*/

signed main(){
  //JAG2013SUMMERWARMINGUP_F();
  //ARC033_C();
  //AOJ_DSL2B();
  //CFR470_C();
  //CFR477_C();
  //KUPC2018_M();
  return 0;
}
