#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct Fordfulkerson{
  const int INF = 1 << 28;
  struct edge{
    int to,cap,rev;
    edge(){}
    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
  };

  int n;
  vector<vector<edge> > G;
  vector<int> used;
  
  Fordfulkerson(){}
  Fordfulkerson(int sz):n(sz),G(n),used(n){}
  
  void add_edge(int from,int to,int cap){
    G[from].push_back(edge(to,cap,G[to].size()));
    // undirected
    //G[to].push_back(edge(from,cap,G[from].size()-1));
    // directed
    G[to].push_back(edge(from,0,G[from].size()-1));
  }
 
  int dfs(int v,int t,int f){
    if(v==t) return f;
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++){
      edge &e = G[v][i];
      if(!used[e.to] && e.cap > 0 ){
	int d=dfs(e.to,t,min(f,e.cap));
	if(d>0){
	  e.cap-=d;
	  G[e.to][e.rev].cap+=d;
	  return d;
	}
      } 
    }
    return 0;
  }
 
  int max_flow(int s,int t){
    int flow=0;
    for(;;){
      fill(used.begin(),used.end(),0);
      int f=dfs(s,t,INF);
      if(f==0) return flow;
      flow+=f;
    }
  }
};
//END CUT HERE

signed main(){
  int V,E;
  cin>>V>>E;
  Fordfulkerson ford(V);
  for(int i=0;i<E;i++){
    int u,v,c;
    cin>>u>>v>>c;
    ford.add_edge(u,v,c);
  }
  cout<<ford.max_flow(0,V-1)<<endl;
  return 0;
}

/*
verified on 2017/10/29
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp
*/
