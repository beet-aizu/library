#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
class EulerTourForVertex{
private:
  vector<int> ls,rs;
  int pos;

  void dfs(int v,int p){
    ls[v]=pos++;
    for(int u:G[v])
      if(u!=p) dfs(u,v);
    rs[v]=pos;
  }

public:
  vector< vector<int> > G;

  EulerTourForVertex(){}
  EulerTourForVertex(int n):ls(n),rs(n),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build(int r=0){
    pos=0;
    dfs(r,-1);
  }

  int idx(int v){return ls[v];}

  template<typename F>
  void exec(int v,F f){
    f(ls[v],rs[v]);
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
