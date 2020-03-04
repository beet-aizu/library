#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Centroid{
  vector<int> sz,dead;
  vector< vector<int> > G;
  Centroid(){}
  Centroid(int n):sz(n,1),dead(n,0),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  int dfs(int v,int p){
    sz[v]=1;
    for(int u:G[v])
      if(u!=p&&!dead[u]) sz[v]+=dfs(u,v);
    return sz[v];
  }

  void find(int v,int p,int tmp,vector<int> &cs) {
    int ok=1;
    for (int u:G[v]){
      if(u==p||dead[u]) continue;
      find(u,v,tmp,cs);
      ok&=(sz[u]<=tmp/2);
    }
    ok&=(tmp-sz[v]<=tmp/2);
    if(ok) cs.emplace_back(v);
  }

  vector<int> build(int r) {
    int tmp=dfs(r,-1);
    vector<int> cs;
    find(r,-1,tmp,cs);
    return cs;
  }

  void disable(int v){dead[v]=1;}
  void  enable(int v){dead[v]=0;}
  int alive(int v){return !dead[v];}
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
