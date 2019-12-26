#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
class EulerTourForEdge{
private:
  vector<int> ds,us,dep,btm;

  void dfs(int v,int p,int d){
    dep[v]=d;
    for(int u:G[v]){
      if(u==p) continue;
      ds[u]=btm.size();
      btm.emplace_back(u);
      dfs(u,v,d+1);
      us[u]=btm.size();
      btm.emplace_back(u);
    }
  }
public:
  vector< vector<int> > G;

  EulerTourForEdge(){}
  EulerTourForEdge(int n):
    ds(n),us(n),dep(n),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build(int r=0){
    btm.clear();
    ds[r]=btm.size();
    btm.emplace_back(r);
    dfs(r,-1,0);
    us[r]=btm.size();
    btm.emplace_back(r);
  }

  int child(int u,int v){
    return dep[u]<dep[v]?v:u;
  }

  int bottom(int e){
    return btm[e];
  }

  // lca(u, v) must be u or v
  template<typename F>
  void query(int u,int v,F f){
    if(dep[u]>dep[v]) swap(u,v);
    f(ds[u]+1,ds[v]+1);
  }

  template<typename T,typename G>
  void update(int v,T x,G g){
    g(ds[v], x);
    g(us[v],-x);
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
