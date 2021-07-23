#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// O(n)
struct BipartiteDecomposition{
  vector<vector<int>> G;
  BipartiteDecomposition(int n):G(n){}
  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  vector<pair<int, int>> build(){
    vector<pair<int, int>> res;
    vector<int> used(G.size(),-1);
    for(int i=0;i<(int)G.size();i++){
      if(~used[i]) continue;
      queue<int> que;
      used[i]=0;
      que.emplace(i);
      pair<int, int> cnt;
      while(!que.empty()){
        int v=que.front();que.pop();
        if(used[v]==0) cnt.first++;
        else cnt.second++;
        for(int u:G[v]){
          if(~used[u]){
            if(used[u]==used[v]) return {};
            continue;
          }
          used[u]=used[v]^1;
          que.emplace(u);
        }
      }
      res.emplace_back(cnt);
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
int main(){
  return 0;
}
#endif
