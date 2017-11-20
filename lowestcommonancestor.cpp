#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct LowestCommonAncestor{
  const int MAX_LOG_V = 50;
  
  int n;
  vector<vector<int> > G,par;
  vector<int> depth;
  LowestCommonAncestor(){}
  LowestCommonAncestor(int sz):
    n(sz),G(sz),par(MAX_LOG_V,vector<int>(n)),depth(sz){}

  void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
  }
  
  void dfs(int v,int p,int d){
    par[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++){
      if(G[v][i]!=p) dfs(G[v][i],v,d+1);
    }
  }
  
  void build(int r=0){
    dfs(r,-1,0);
    for(int k=0;k+1<MAX_LOG_V;k++){
      for(int v=0;v<n;v++){
	if(par[k][v]<0) par[k+1][v]=-1;
	else par[k+1][v]=par[k][par[k][v]];
      }
    }
  }
  
  int lca(int u,int v){
    if(depth[u]>depth[v]) swap(u,v);
    for(int k=0;k<MAX_LOG_V;k++){
      if((depth[v]-depth[u])>>k&1){
	v=par[k][v];
      }
    }
    if(u==v) return u;
    for(int k=MAX_LOG_V-1;k>=0;k--){
      if(par[k][u]!=par[k][v]){
	u=par[k][u];
	v=par[k][v];
      }
    }
    return par[0][u];
  }

  int distance(int u,int v){
    return depth[u]+depth[v]-depth[lca(u,v)]*2;
  }
};
//END CUT HERE

signed main(){
  int n;
  cin>>n;
  LowestCommonAncestor lca(n);
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
verified on 2017/11/20
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=jp
*/
