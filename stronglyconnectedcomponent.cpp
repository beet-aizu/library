#include<bits/stdc++.h>
using namespace std;
#define int long long
//BEGIN CUT HERE
struct SCC{
  int V;
  vector<vector<int> > G,rG,T,C;
  vector<int> vs,used,cmp;
  SCC(){}
  SCC(int V):V(V){init();}
  void init(){
    for(int i=0;i<(int)G.size();i++) G[i].clear();
    for(int i=0;i<(int)rG.size();i++) rG[i].clear();
    for(int i=0;i<(int)T.size();i++) T[i].clear();
    G.clear();
    rG.clear();
    vs.clear();
    used.clear();
    cmp.clear();
    T.clear();
    
    G.resize(V);
    rG.resize(V);
    used.resize(V);
    cmp.resize(V);
  }
  
  void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
  }
  
  void dfs(int v){
    used[v]=1;
    for(int i=0;i<(int)G[v].size();i++){
      if(!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
  }
  
  void rdfs(int v,int k){
    used[v]=1;
    cmp[v]=k;
    C[k].push_back(v);
    for(int i=0;i<(int)rG[v].size();i++){
      if(!used[rG[v][i]]) rdfs(rG[v][i],k);
    }
  }
  
  int build(){
    fill(used.begin(),used.end(),0);
    vs.clear();
    for(int v=0;v<V;v++){
      if(!used[v]) dfs(v);
    }
    fill(used.begin(),used.end(),0);
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
      if(!used[vs[i]]){
	T.push_back(vector<int>());
	C.push_back(vector<int>());
	rdfs(vs[i],k++);
      }
    }
    for(int i=0;i<V;i++)
      for(int u:G[i])
	if(cmp[i]!=cmp[u])
	  T[cmp[i]].push_back(cmp[u]);
    for(int i=0;i<k;i++){
      sort(T[i].begin(),T[i].end());
      T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());
    }
    return k;
  }
};
//END CUT HERE

signed main(){
  
  return 0;
}
/*
verified 2017/06/12
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2598
*/
