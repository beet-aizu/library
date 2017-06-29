#include<bits/stdc++.h>
using namespace std;
#define int long long
//BEGIN CUT HERE
struct TopologicalSort{
  int n;
  vector<set<int> > G;
  vector<int> indeg,V,p;
  TopologicalSort(){}
  TopologicalSort(int n):n(n){init();}
  
  void init(){
    for(int i=0;i<(int)G.size();i++) G[i].clear();
    G.clear();
    indeg.clear();
    V.clear();
    p.clear();
    G.resize(n);
    indeg.resize(n);
    V.resize(n);
  }

  void add_edge(int s,int t){
    G[s].insert(t);
  }
  
  void bfs(int s){
    queue<int> q;
    q.push(s);
    V[s]=1;
    while(!q.empty()){
      int u=q.front();q.pop();
      p.push_back(u);
      for(int v:G[u]){
	indeg[v]--;
	if(indeg[v]==0&&!V[v]){
	  V[v]=1;
	  q.push(v);
	}
      }
    }
  }
  
  void tsort(){
    fill(V.begin(),V.end(),0);
    fill(indeg.begin(),indeg.end(),0);
    for(int u=0;u<n;u++)
      for(int v:G[u])
	indeg[v]++;
    for(int u=0;u<n;u++)
      if(indeg[u]==0&&!V[u]) bfs(u);
    for(int i=0;i<n;i++)
      cout<<p[i]<<endl;
  }
};
//END CUT HERE

signed main(){
  int n,e;
  cin>>n>>e;
  TopologicalSort ts(n);
  for(int i=0;i<e;i++){
    int s,t;
    cin>>s>>t;
    ts.add_edge(s,t);
  }
  ts.tsort();
  return 0;
}

/*
verified on 2017/06/29
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp
*/
