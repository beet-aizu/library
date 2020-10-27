#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct TopologicalSort{
  vector< set<int> > G;
  vector<int> used,indeg,ps;

  TopologicalSort(int n):G(n),used(n,0),indeg(n,0){}

  void add_edge(int s,int t){
    G[s].emplace(t);
    indeg[t]++;
  }

  void bfs(int s){
    queue<int> que;
    que.emplace(s);
    used[s]=1;
    while(!que.empty()){
      int v=que.front();que.pop();
      ps.emplace_back(v);
      for(int u:G[v]){
        indeg[u]--;
        if(indeg[u]==0 and !used[u]){
          used[u]=1;
          que.emplace(u);
        }
      }
    }
  }

  vector<int> build(){
    int n=G.size();
    for(int i=0;i<n;i++)
      if(indeg[i]==0 and !used[i]) bfs(i);
    return ps;
  }
};
//END CUT HERE
#ifndef call_from_test
#endif
