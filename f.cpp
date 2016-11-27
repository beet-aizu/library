#include<bits/stdc++.h>
using namespace std;
#define INF 1<<28
#define MAX_V 105
#define ll int
struct edge{
  ll to,cap,rev;
  edge(ll to ,ll cap,ll rev):to(to),cap(cap),rev(rev){}
};
vector<edge> G[MAX_V];
vector<edge> G2[MAX_V];
bool used[MAX_V];
int level[MAX_V];
int iter[MAX_V];


void add_edge(ll from,ll to,ll cap){
  G[from].push_back(edge(to,cap,G[to].size()));
  G[to].push_back(edge(from,cap,G[from].size()-1));
}

void bfs(int s){
  memset(level,-1,sizeof(level));
  queue<int> que;
  level[s]=0;
  que.push(s);
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int i=0;i<G[v].size();i++){
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
  for(int &i=iter[v];i<G[v].size();i++){
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

void bfs2(int s){
  memset(level,-1,sizeof(level));
  queue<int> que;
  level[s]=0;
  que.push(s);
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int i=0;i<G2[v].size();i++){
      edge &e = G2[v][i];
      if(e.cap>0&&level[e.to]<0){
	level[e.to]=level[v]+1;
	que.push(e.to);
      }
    }
  }
}

int dfs2(int v,int t,int f){
  if(v==t) return f;
  for(int &i=iter[v];i<G2[v].size();i++){
    edge &e=G2[v][i];
    if(e.cap>0&&level[v]<level[e.to]){
      int d = dfs2(e.to,t,min(f,e.cap));
      if(d>0){
	e.cap-=d;
	G2[e.to][e.rev].cap+=d;
	return d;
      }
    }
  }
  return 0;
}

int flow=0;
int max_flow(int s,int t){
  for(;;){
    bfs(s);
    if(level[t]<0) return flow;
    memset(iter,0,sizeof(iter));
    int f;
    while((f=dfs(s,t,INF))>0){
      flow+=f;
    }
  }
}

int max_flow2(int s,int t){
  int flow2=0;
  for(;;){
    bfs2(s);
    if(level[t]<0) return flow2;
    memset(iter,0,sizeof(iter));
    int f;
    while((f=dfs2(s,t,INF))>0){
      flow2+=f;
    }
  }
}

signed main(){
  ll k,n,m,i,j,a,b,c,x,y;
  cin >> k >> n >> m;
  ll s=MAX_V-1,t=0;
  for(i=0;i<m;i++){
    cin >> a >> b >> c;
    add_edge(a,b,c);
  }
  for(i=1;i<=k;i++){
    add_edge(s,i,INF);
  }
  ll ans=max_flow(s,t);
  for(i=1;i<MAX_V-1;i++){
    for(j=0;j<G[i].size();j++){
      if(G[i][j].cap!=0) continue;
      for(x=0;x<MAX_V;x++) G2[x]=G[x];
      G2[i][j].cap=INF;
      ans=max(ans,flow+max_flow2(s,t));
      if(ans>=INF) break;
    }
  } if(ans>=INF) cout << "overfuro" << endl;
  else cout << ans << endl;
  return 0;
}

