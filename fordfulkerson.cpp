#include<bits/stdc++.h>
using namespace std;
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
 
int main(){
  return 0;
} 
