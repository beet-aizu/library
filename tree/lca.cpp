#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
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

  // if it need leftmost, then add: if(E[i]==E[j]) return i<j?i:j;
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
//END CUT HERE

//INSERT ABOVE HERE
signed GRL_5_C(){
  int n;
  scanf("%d",&n);
  LCA lca(n);
  for(int i=0;i<n;i++){
    int k,c;
    scanf("%d",&k);
    for(int j=0;j<k;j++){
      scanf("%d",&c);
      lca.add_edge(i,c);
    }
  }
  
  lca.build();
  int q;
  scanf("%d",&q);
  for(int i=0;i<q;i++){
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d\n",lca.lca(x,y));
  }
  return 0;
}

/*
  verified on 2018/08/13
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=jp
*/


//INSERT ABOVE HERE
signed main(){
  GRL_5_C();
  return 0;
}
