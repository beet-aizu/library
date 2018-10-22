#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct CartesianTree{
  int n;
  vector<int> P,L,R;
  CartesianTree(int n):n(n),P(n,-1),L(n,-1),R(n,-1){}

  template<typename T>
  int build(vector<T> v){
    int p=0;
    for(int i=1;i<n;i++){
      if(v[p]<=v[i]){
        R[p]=i;
        P[i]=p;
        p=i;
        continue;
      }
      while(~P[p]&&v[i]<v[P[p]]) p=P[p];
      P[i]=P[p];
      if(~P[i]) R[P[i]]=i;
      L[i]=p;
      P[p]=i;
      p=i;
    }
    while(~P[p]) p=P[p];
    return p;
  }
};
//END CUT HERE

struct LCA{
  const int lg = 12;
  const int sz = 1<<lg;
  const int ms = sz-1;
  int n;
  vector<int> P,D,E,A,B,T,ht;
  vector<vector<int> > G,dat;
  LCA(int n):
    n(n),P(n,-1),D(n),E(n*2,0),A(n*2,-1),B(n*2/lg+1),T(sz,0),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void dfs(int v,int p,int d,int &k){
    D[v]=k;
    A[k]=P[v]=p;
    E[k++]=d;
    for(int u:G[v])
      if(u!=p) dfs(u,v,d+1,k);
    A[k]=P[v];
    E[k++]=d-1;
  }

  inline int comp(int i,int j){return E[i]<E[j]?i:j;};
  inline int comp(int i,int j,int k){return comp(comp(i,j),k);};
  
  void build(int r=0){
    int k=0;
    dfs(r,-1,1,k);
    
    B[0]=1;
    for(int i=1;i<n*2;i++) B[i/lg]|=(E[i-1]<E[i])<<(i%lg);

    for(int b=0;b<sz;b++){
      int e=0,w=1,&x=T[b];
      for(int i=0;i<lg;i++){
        if((b>>i)&1) e++;
        else e--;
        if(e<w) e=w,x=i;
      }
    }

    int m=(n*2+lg-1)/lg;
    int h=1;
    while((1<<h)<m) h++;
    dat.assign(h,vector<int>(m,-1));
    ht.assign(m+1,0);
    for(int j=2;j<=m;j++) ht[j]=ht[j>>1]+1;
    
    for(int j=0;j<n*2;j++){
      if(dat[0][j/lg]<0) dat[0][j/lg]=j;
      dat[0][j/lg]=comp(dat[0][j/lg],j);
    }
    
    for(int i=1,p=1;i<h;i++,p<<=1)
      for(int j=0;j<m;j++)
        dat[i][j]=comp(dat[i-1][j],dat[i-1][min(j+p,m-1)]);
  }

  inline int cs(int a,int b){
    int l=b-a;
    return comp(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])]);
  }

  inline int es(int i,int l,int r){
    int x=r-i*lg+1,y=l-i*lg;
    int b=(((B[i]|(ms<<x))>>y)|(ms<<(lg-y)))&ms;
    return l+T[b];
  }
  
  inline int ls(int i,int l){
    int k=l-i*lg;
    int b=((B[i]>>k)|(ms<<(lg-k)))&ms;
    return l+T[b];
  }

  inline int rs(int j,int r){
    int k=r-j*lg+1;
    int b=(B[j]|(ms<<k))&ms;
    return j*lg+T[b];
  }

  inline int rmq(int l,int r){
    int i=l/lg,j=r/lg;
    if(i==j) return es(i,l,r);
    if(i+1==j) return comp(ls(i,l),rs(j,r));
    return comp(ls(i,l),cs(i+1,j),rs(j,r));    
  }
  
  int lca(int l,int r){
    if(l==r) return l;
    if(D[l]>D[r]) swap(l,r);
    int x=D[l],y=D[r];
    int m=rmq(x,y);
    return m==x?l:A[m];
  }
};


template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE

signed DSL_3_D(){
  int n,l;
  scanf("%d %d",&n,&l);
  vector<int> v(n);
  for(int i=0;i<n;i++) scanf("%d",&v[i]);
  CartesianTree ct(n);
  int r=ct.build(v);
  
  LCA lca(n);
  for(int i=0;i<n;i++)
    if(~ct.P[i]) lca.add_edge(i,ct.P[i]);
  lca.build(r);
    
  for(int i=0;i+l<=n;i++){
    if(i) printf(" ");
    printf("%d",v[lca.lca(i,i+l-1)]);
  }
  puts("");
  return 0;
}
/*
  verified on 2018/08/13
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D&lang=jp
*/

signed SPOJ_ADAPLANT(){
  int T;
  scanf("%d",&T);
  while(T--){
    int n,l;
    scanf("%d %d",&n,&l);
    vector<int> v(n);
    for(int i=0;i<n;i++) scanf("%d",&v[i]);
    
    const int BS=1e9+100;
    vector<int> w(n);    
    for(int i=0;i<n;i++) w[i]=BS-v[i];
    
    CartesianTree ct1(n),ct2(n);
    int r1=ct1.build(v);
    int r2=ct2.build(w);
    
    
    LCA lca1(n),lca2(n);    
    for(int i=0;i<n;i++){
      if(~ct1.P[i]) lca1.add_edge(i,ct1.P[i]);
      if(~ct2.P[i]) lca2.add_edge(i,ct2.P[i]);
    }
    lca1.build(r1);
    lca2.build(r2);

    l++;
    chmin(l,n-1);
    
    int ans=0;
    for(int i=0;i+l<n;i++){
      int x=v[lca1.lca(i,i+l)];
      int y=BS-w[lca2.lca(i,i+l)];
      chmax(ans,y-x);
    }
    
    printf("%d\n",ans);
  }
  return 0;
}
/*
  verified on 2018/08/13
  https://www.spoj.com/problems/ADAPLANT/
*/

signed main(){
  //DSL_3_D();
  SPOJ_ADAPLANT();
  return 0;
}
