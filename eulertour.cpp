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

signed main(){
  CFR483_E();
  return 0;
}
