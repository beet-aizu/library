#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

// http://wwwmayr.in.tum.de/konferenzen/Jass08/courses/1/smal/Smal_Talk.pdf
//BEGIN CUT HERE
struct AHU{
  static map<vector<int>, int> I;
  vector< vector<int> > G;
  AHU(int n):G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  int dfs(int v,int p){
    vector<int> hs;
    for(int u:G[v])
      if(u!=p) hs.emplace_back(dfs(u,v));
    sort(hs.begin(),hs.end());

    int sz=I.size();
    if(!I.count(hs)) I[hs]=sz;
    return I[hs];
  }

  int build(int r=0){
    return dfs(r,-1);
  }
};
map<vector<int>, int> AHU::I;

//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
