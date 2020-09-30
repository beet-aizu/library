#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// O(E \sqrt V)
struct HopcroftKarp{
  int L,R;
  vector< vector<int> > G;
  vector<int> match,level;

  HopcroftKarp(){}
  HopcroftKarp(int L,int R):L(L),R(R),G(L+R),match(L+R,-1),level(L+R){}

  void add_edge(int u,int v){
    G[u].emplace_back(v+L);
    G[v+L].emplace_back(u);
  }

  bool bfs(){
    fill(level.begin(),level.end(),-1);
    queue<int> que;
    for(int i=0;i<L;i++){
      if(~match[i]) continue;
      level[i]=0;
      que.emplace(i);
    }
    bool found=false;
    while(!que.empty()){
      int v=que.front();que.pop();
      for(int u:G[v]){
        if(~level[u]) continue;
        level[u]=level[v]+1;
        int w=match[u];
        if(w==-1){
          found=true;
          continue;
        }
        if(~level[w]) continue;
        level[w]=level[u]+1;
        que.emplace(w);
      }
    }
    return found;
  }

  bool dfs(int v){
    for(int u:G[v]){
      if(level[v]+1!=level[u]) continue;
      level[u]=-1;
      int w=match[u];
      if(w<0||dfs(w)){
        match[v]=u;
        match[u]=v;
        level[v]=-1;
        return true;
      }
    }
    level[v]=-1;
    return false;
  }

  int build(){
    int res=0;
    while(bfs())
      for(int i=0;i<L;i++)
        if(match[i]<0&&dfs(i))
          res++;
    return res;
  }

};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
