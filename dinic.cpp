#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1<<28
#define MAX_V 600
struct edge {
  int to,cap,rev;
  edge(){}
  edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
};

vector<edge> G[MAX_V];
map<int,int> M[MAX_V];
int level[MAX_V];
int iter[MAX_V];


void add_edge(int from,int to,int cap){
  M[from][to]=G[from].size();
  M[to][from]=G[to].size();
  G[from].push_back(edge(to,cap,G[to].size()));
  // undirected
  //G[to].push_back(edge(from,cap,G[from].size()-1));
  // directed
  G[to].push_back(edge(from,0,G[from].size()-1));
}

void bfs(int s){
  memset(level,-1,sizeof(level));
  queue<int> que;
  level[s]=0;
  que.push(s);
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int i=0;i<(int)G[v].size();i++){
      edge &e = G[v][i];
      if(e.cap>0&&level[e.to]<0){
	level[e.to]=level[v]+1;
	que.push(e.to);
      }
    }
  }
}

int dfs(int v,int t,int f){
  if(v==t) return f;
  for(int &i=iter[v];i<(int)G[v].size();i++){
    edge &e=G[v][i];
    if(e.cap>0&&level[v]<level[e.to]){
      int d = dfs(e.to,t,min(f,e.cap));
      if(d>0){
	e.cap-=d;
	G[e.to][e.rev].cap+=d;
	return d;
      }
    }
  }
  return 0;
}

int max_flow(int s,int t,int lim){
  int flow=0;
  for(;;){
    bfs(s);
    if(level[t]<0||lim==0) return flow;
    memset(iter,0,sizeof(iter));
    int f;
    while((f=dfs(s,t,lim))>0){
      flow+=f;
      lim-=f;
    }
  }
}

int max_flow(int s,int t){
  return max_flow(s,t,INF);
}

//cap==1 only
bool back_edge(int s,int t,int from, int to){
  for(int i=0;i<(int)G[from].size();i++) {
    edge& e=G[from][i];
    if(e.to==to) {
      if(e.cap==0&&max_flow(from,to,1)==0) {
	max_flow(from,s,1);
	max_flow(t,to,1);
	return 1;
      }
    }
  }
  return 0;
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
