#include<bits/stdc++.h>
using namespace std;
#define int long long
//BEGIN CUT HERE
struct SCC{
  int V;
  vector<vector<int> > G,rG,T;
  vector<int> vs,used,cmp;
  SCC(){}
  SCC(int V):V(V){init();}
  void init(){
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
    T[k].push_back(v);
    for(int i=0;i<(int)rG[v].size();i++){
      if(!used[rG[v][i]]) rdfs(rG[v][i],k);
    }
  }
  
  int scc(){
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
	rdfs(vs[i],k++);
      }
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
