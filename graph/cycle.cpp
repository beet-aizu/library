#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<bool directed>
struct Cycle{
  vector<int> used;
  vector<vector<int>> G;
  Cycle(int n_):used(n_,0),G(n_){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    if(not directed) G[v].emplace_back(u);
  }

  vector<int> vs;
  int dfs(int v,int p){
    used[v]=1;
    vs.emplace_back(v);
    for(int u:G[v]){
      if((not directed) and u==p) continue;
      if(used[u]==2) continue;
      if(used[u]==1) return u;
      int res=dfs(u,v);
      if(~res) return res;
    }
    used[v]=2;
    vs.pop_back();
    return -1;
  }

  vector<int> build(){
    for(int i=0;i<(int)G.size();i++){
      if(used[i]) continue;
      int start=dfs(i,-1);
      if(start<0) continue;
      vs.erase(vs.begin(),find(vs.begin(),vs.end(),start));
      return vs;
    }
    return {};
  }
};
using DirectedCycle = Cycle<true>;
using UndirectedCycle = Cycle<false>;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
