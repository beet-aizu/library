#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct BiMatch{
  int n,time;
  vector<vector<int>> G;
  vector<int> match,used,dead;

  BiMatch(){}
  BiMatch(int n):n(n),time(0),G(n),
                 match(n,-1),used(n,-1),dead(n,0){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  int dfs(int v){
    used[v]=time;
    for(int u:G[v]){
      if(dead[u]) continue;
      int w=match[u];
      if((w<0)||(used[w]<time&&dfs(w))){
        match[v]=u;
        match[u]=v;
        return 1;
      }
    }
    return 0;
  }

  int build(){
    int res=0;
    for(int v=0;v<n;v++){
      if(dead[v]) continue;
      if(match[v]<0){
        time++;
        res+=dfs(v);
      }
    }
    return res;
  }

  int disable(int v){
    assert(!dead[v]);
    int u=match[v];
    if(~u) match[u]=-1;
    match[v]=-1;
    dead[v]=1;
    time++;
    return ~u?dfs(u)-1:0;
  }

  int enable(int v){
    assert(dead[v]);
    dead[v]=0;
    time++;
    return dfs(v);
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
