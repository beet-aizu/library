#include<bits/stdc++.h>
using namespace std;
#define int long long
//BEGIN CUT HERE
struct ArticulationPoints{
  vector<vector<int> > G;
  vector<int> used,pre,par,low;
  int V,timer;
  set<int> ap;
  ArticulationPoints(){}
  ArticulationPoints(int V):V(V){init();}
  void init(){
    for(int i=0;i<(int)G.size();i++) G[i].clear();
    G.clear();
    used.clear();
    pre.clear();
    par.clear();
    low.clear();
    ap.clear();
    
    G.resize(V);
    used.resize(V);
    pre.resize(V);
    par.resize(V);
    low.resize(V);
  }
  
  void add_edge(int from,int to){
    G[from].push_back(to);
    G[to].push_back(from);
  }
  
  void dfs(int v,int p){
    pre[v]=low[v]=timer;
    timer++;
    used[v]=1;
    for(int u:G[v]){
      if(!used[u]){
	par[u]=v;
	dfs(u,v);
	low[v]=min(low[v],low[u]);
      }else if(u!=p){
	low[v]=min(low[v],pre[u]);
      }
    }
  }
  
  void build(){
    fill(used.begin(),used.end(),0);
    timer=1;
    dfs(0,-1);
    ap.clear();
    int np=0;
    for(int i=1;i<V;i++){
      int p=par[i];
      if(p==0) np++;
      else if(pre[p]<=low[i]) ap.insert(p);
    }
    if(np>1) ap.insert(0);
  }
};
//END CUT HERE

signed main(){
  int v,e;
  cin>>v>>e;
  ArticulationPoints ap(v);
  for(int i=0;i<e;i++){
    int s,t;
    cin>>s>>t;
    ap.add_edge(s,t);
  }
  ap.build();
  for(int i:ap.ap) cout<<i<<endl;
  return 0;
}

/*
  verified on 2017/07/13
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=jp
*/
