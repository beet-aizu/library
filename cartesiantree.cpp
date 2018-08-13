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

//INSERT ABOVE HERE

signed DSL_3_D(){
  int n,l;
  scanf("%d %d",&n,&l);
  vector<int> v(n);
  for(int i=0;i<n;i++) scanf("%d",&v[i]);
  CartesianTree ct(n);
  int r=ct.build(v);
  
  LowestCommonAncestor lca(n);
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

signed main(){
  DSL_3_D();
  return 0;
}
