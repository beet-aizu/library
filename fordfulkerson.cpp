#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX_V 55
int INF = 1 << 28;
struct edge{
  int to,cap,rev;
  edge(){}
  edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
};
vector<edge> G[MAX_V*2+2];
bool used[MAX_V*2+2];
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
    memset(used,0,sizeof(used));
    int f=dfs(s,t,INF);
    if(f==0) return flow;
    flow+=f;
  }
}
 
signed main(){
  int V,E;
  cin>>V>>E;
  for(int i=0;i<E;i++){
    int u,v,c;
    cin>>u>>v>>c;
    add_edge(u,v,c);
  }
  cout<<max_flow(0,V-1)<<endl;
  return 0;
}

/*
verified on 2017/04/22
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp
*/
