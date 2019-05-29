#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
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
//END CUT HERE

struct UnionFind{
  int n,num;
  vector<int> r,p;
  UnionFind(){}
  UnionFind(int sz):n(sz),num(sz),r(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}
  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
    num--;
  }
  int size(int x){
    return r[find(x)];
  }
  int count() const{
    return num;
  }
};

template<typename T,T MOD = 1000000007>
struct Mint{
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}

  Mint pow(long long k){
    Mint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }
  
  static Mint add_identity(){return Mint(0);}
  static Mint mul_identity(){return Mint(1);}
  
  Mint inv(){return pow(MOD-2);}
  
  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}
  
  Mint operator+(Mint a) const{return Mint(v)+=a;};
  Mint operator-(Mint a) const{return Mint(v)-=a;};
  Mint operator*(Mint a) const{return Mint(v)*=a;};
  Mint operator/(Mint a) const{return Mint(v)/=a;};

  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}
};


template<typename M>
struct Enumeration{
  static vector<M> fact,finv,invs;
  
  static void init(int n){
    int m=fact.size();
    if(n<m) return;
    
    fact.resize(n+1,1);
    finv.resize(n+1,1);
    invs.resize(n+1,1);
    
    if(m==0) m=1;
    for(int i=m;i<=n;i++) fact[i]=fact[i-1]*M(i);
    finv[n]=M(1)/fact[n];
    for(int i=n;i>=m;i--) finv[i-1]=finv[i]*M(i);
    for(int i=m;i<=n;i++) invs[i]=finv[i]*fact[i-1];
  }
  
  static M C(int n,int k){
    if(n<k||k<0) return M(0);
    init(n);
    return fact[n]*finv[n-k]*finv[k];
  }
  
  static M H(int n,int k){
    if(n<0||k<0) return M(0);
    if(!n&&!k) return M(1);
    init(n+k-1);
    return C(n+k-1,k);
  }
};
template<typename M>
vector<M> Enumeration<M>::fact = vector<M>();
template<typename M>
vector<M> Enumeration<M>::finv = vector<M>();
template<typename M>
vector<M> Enumeration<M>::invs = vector<M>();

//INSERT ABOVE HERE
signed GRL_3_A(){
  int n,m;
  scanf("%d %d",&n,&m);
  LowLink G(n);
  for(int i=0;i<m;i++){
    int u,v;
    scanf("%d %d",&u,&v);
    G.add_edge(u,v);
  }
  G.build();
  auto ap=G.ap;
  sort(ap.begin(),ap.end());
  for(int v:ap) printf("%d\n",v);
  return 0;
}
/*
  verified on 2019/05/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=jp
*/

signed GRL_3_B(){
  int n,m;
  scanf("%d %d",&n,&m);
  
  LowLink G(n);
  for(int i=0;i<m;i++){
    int u,v;
    scanf("%d %d",&u,&v);
    G.add_edge(u,v);
  }
  G.build();
  
  auto bs=G.bs;
  for(auto &e:bs)
    if(e.first>e.second) swap(e.first, e.second);
  
  sort(bs.begin(),bs.end());
  for(auto e:bs) printf("%d %d\n",e.first, e.second);
  
  return 0;
}
/*
  verified on 2019/05/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B&lang=jp
*/

signed AOJ_0377(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  int n,m;
  cin>>n>>m;
  LowLink bg(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    bg.add_edge(a,b);
  }
  int k=bg.build();
  auto& G=bg.T;
  
  vector<int> c(k);
  for(int i=0;i<k;i++) c[i]=bg.C[i].size();
  vector<vector<int> > dp(2,vector<int>(k,0));
  vector<int> used(k,0);
  function<void(int,int)> dfs=[&](int v,int p){
    if(used[v]) return;
    used[v]=1;
    dp[0][v]=0;
    dp[1][v]=c[v];
    for(int u:G[v]){
      if(u==p) continue;
      dfs(u,v);
      dp[0][v]+=max(dp[0][u],dp[1][u]);
      dp[1][v]+=dp[0][u];
    }
    return;
  };
  int ans=0;
  for(int i=0;i<k;i++){
    if(used[i]) continue;
    dfs(i,-1);
    ans+=max(dp[0][i],dp[1][i]);
  }
  cout<<ans<<endl;
  return 0;
}

/*
  verified on 2019/05/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0377
*/

signed ARC045_D(){
  cin.tie(0);
  ios::sync_with_stdio(0);
    
  int n;
  cin>>n;
  vector<int> xs(2*n+1),ys(2*n+1);
  for(int i=0;i<2*n+1;i++) cin>>xs[i]>>ys[i];

  vector<vector<int> > R(2*n+2),C(2*n+2);
  for(int i=0;i<2*n+1;i++) R[xs[i]].emplace_back(i);
  for(int i=0;i<2*n+1;i++) C[ys[i]].emplace_back(i);

  UnionFind uf(2*n+1);
  for(auto &v:R)
    for(auto u:v) uf.unite(v[0],u);
  for(auto &v:C)
    for(auto u:v) uf.unite(v[0],u);

  vector<int> vs;
  for(int i=0;i<2*n+1;i++){
    if(uf.find(i)!=i) continue;
    if(uf.size(i)&1) vs.emplace_back(i);
  }
  assert(!vs.empty());
  
  if(vs.size()>1u){
    for(int i=0;i<2*n+1;i++) cout<<"NG\n";
    cout<<flush;
    return 0;    
  }
  
  LowLink G(2*n+1);
  auto add_edge=
    [&](auto &V)->void{
      for(auto &v:V){
        if(v.empty()) continue;
        if(!uf.same(vs[0],v[0])) continue;
        if(v.size()>0u) for(auto u:v) G.add_edge(v[0],u);
        if(v.size()>1u) for(auto u:v) G.add_edge(v[1],u);
      }
    };
  add_edge(R);
  add_edge(C);

  G.build();
  auto ap=G.ap; 
  
  vector<int> ans(2*n+1,0);
  for(int i=0;i<2*n+1;i++)
    if(uf.same(vs[0],i)) ans[i]=1;

  for(int v:ap){
    if(!uf.same(vs[0],v)) continue;
    for(int u:G.G[v]){
      if(G.par[u]!=v) continue;    
      if(~G.par[v]&&G.ord[v]>G.low[u]) continue;     
      if(G.num[u]&1) ans[v]=0;
    }
  }
  
  for(int i=0;i<2*n+1;i++) cout<<(ans[i]?"OK\n":"NG\n");
  cout<<flush;
  return 0;
}
/*
  verified on 2019/05/29
  https://atcoder.jp/contests/arc045/tasks/arc045_d
*/


signed ARC062_F(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  int n,m,k;
  cin>>n>>m>>k;

  using P = pair<int, int>;
  map<P, int> idx;
  
  LowLink G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.add_edge(a,b);
    idx[P(a,b)]=idx[P(b,a)]=i;
  }

  G.build();
  
  UnionFind uf(m);
  for(auto vs:G.E)
    for(auto p:vs) uf.unite(idx[p],idx[vs[0]]);  

  vector<set<int>> cnt(m);  
  for(auto vs:G.E){
    for(auto p:vs){
      cnt[uf.find(idx[p])].emplace(p.first);     
      cnt[uf.find(idx[p])].emplace(p.second);
    }
  }
  
  using M = Mint<int>;
  using E = Enumeration<M>;
  E::init(1000);
  
  auto calc1=
    [&](int x)->M{     
      M res{0};
      
      for(int i=0;i<x;i++)
        res+=M(k).pow(__gcd(i,x));
      
      res*=E::invs[x];
      return res;
    };

  M ans{1};
  for(int i=0;i<m;i++){
    if(uf.find(i)!=i) continue;
    if(uf.size(i)< (int)cnt[i].size()) ans*=M(k).pow(uf.size(i));
    if(uf.size(i)==(int)cnt[i].size()) ans*=calc1(uf.size(i));
    if(uf.size(i)> (int)cnt[i].size()) ans*=E::H(k,uf.size(i));
  }  
  cout<<ans.v<<endl;
  return 0;
}
/*
  verified on 2019/05/29
  https://atcoder.jp/contests/arc062/tasks/arc062_d
*/


signed main(){
  //GRL_3_A();
  //GRL_3_B();
  //AOJ_0377();
  //ARC045_D();  
  //ARC062_F();
  return 0;
}
