#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
vector<int> bfs(int s,vector< vector<int> > G){
  int n=G.size();
  vector<int> dp(n,-1);
  queue<int> que;
  dp[s]=0;
  que.emplace(s);
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int u:G[v]){
      if(~dp[u]) continue;
      dp[u]=dp[v]+1;
      que.emplace(u);
    }
  }
  return dp;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
