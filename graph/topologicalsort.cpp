#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct TopologicalSort{
  vector<vector<int>> G;
  vector<int> indeg;
  TopologicalSort(int n):G(n),indeg(n,0){}

  void add_edge(int s,int t){
    G[s].emplace_back(t);
    indeg[t]++;
  }

  vector<int> build(){
    int n=G.size();

    queue<int> que;
    vector<int> used(n,0);
    auto push=[&](int v){
      if(used[v]) return;
      que.emplace(v);
      used[v]=1;
    };

    for(int i=0;i<n;i++)
      if(indeg[i]==0) push(i);

    vector<int> ps;
    while(!que.empty()){
      int v=que.front();que.pop();
      ps.emplace_back(v);
      for(int u:G[v]){
        indeg[u]--;
        if(indeg[u]==0) push(u);
      }
    }

    if(n!=(int)ps.size()) return {};
    return ps;
  }
};
//END CUT HERE
#ifndef call_from_test
#endif
