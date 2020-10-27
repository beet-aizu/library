#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Triangle{
  // if not simple, use vector<set<int>>
  vector<vector<int>> G;
  Triangle(int n):G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  template<typename F>
  void build(F f){
    int n=G.size();
    using P = pair<int, int>;
    vector<P> vp(n);
    for(int i=0;i<n;i++) vp[i]=P(G[i].size(),i);

    vector<vector<int>> H(n);
    for(int i=0;i<n;i++)
      for(int j:G[i])
        if(vp[i]>vp[j])
          H[i].emplace_back(j);

    vector<int> used(n,0);
    // x->y->z
    for(int x=0;x<n;x++){
      for(int z:H[x]) used[z]=1;
      for(int y:H[x])
        for(int z:H[y])
          if(used[z]) f(x,y,z);
      for(int z:H[x]) used[z]=0;
    }
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
