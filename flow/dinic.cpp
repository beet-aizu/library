#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct Dinic{
  const int INF=1<<28;
  
  struct edge {
    int to,cap,rev;
    edge(){}
    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
  };

  int n;
  vector<vector<edge> > G;
  vector<map<int,int> > M;
  vector<int> level,iter;

  Dinic(){}
  Dinic(int sz):n(sz),G(n),M(n),level(n),iter(n){}
  
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
    fill(level.begin(),level.end(),-1);
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
  
  int flow(int s,int t,int lim){
    int fl=0;
    for(;;){
      bfs(s);
      if(level[t]<0||lim==0) return fl;
      fill(iter.begin(),iter.end(),0);
      int f;
      while((f=dfs(s,t,lim))>0){
        fl+=f;
        lim-=f;
      }
    }
  }

  int flow(int s,int t){
    return flow(s,t,INF);
  }

  //cap==1 only
  bool back_edge(int s,int t,int from, int to){
    for(int i=0;i<(int)G[from].size();i++) {
      edge& e=G[from][i];
      if(e.to==to) {
        if(e.cap==0&&flow(from,to,1)==0) {
          flow(from,s,1);
          flow(t,to,1);
          return 1;
        }
      }
    }
    return 0;
  }
};
//END CUT HERE

signed main(){
  int V,E;
  cin>>V>>E;
  Dinic dinic(V);
  for(int i=0;i<E;i++){
    int u,v,c;
    cin>>u>>v>>c;
    dinic.add_edge(u,v,c);
  }
  cout<<dinic.flow(0,V-1)<<endl;
  return 0;
}

/*
  verified on 2017/10/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp
*/
