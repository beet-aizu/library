#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T,bool directed>
struct Dinic{
  struct edge {
    int to;
    T cap;
    int rev;
    edge(){}
    edge(int to,T cap,int rev):to(to),cap(cap),rev(rev){}
  };

  T INF;
  vector<vector<edge> > G;
  vector<int> level,iter;

  Dinic(){}  
  Dinic(int n,T INF):INF(INF),G(n),level(n),iter(n){}
  
  void add_edge(int from,int to,int cap){
    G[from].emplace_back(to,cap,G[to].size());
    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);
  }
  
  void bfs(int s){
    fill(level.begin(),level.end(),-1);
    queue<int> que;
    level[s]=0;
    que.emplace(s);
    while(!que.empty()){
      int v=que.front();que.pop();
      for(int i=0;i<(int)G[v].size();i++){
        edge &e=G[v][i];
        if(e.cap>0&&level[e.to]<0){
          level[e.to]=level[v]+1;
          que.emplace(e.to);
        }
      }
    }
  }
  
  T dfs(int v,int t,T f){
    if(v==t) return f;
    for(int &i=iter[v];i<(int)G[v].size();i++){
      edge &e=G[v][i];
      if(e.cap>0&&level[v]<level[e.to]){
        T d=dfs(e.to,t,min(f,e.cap));
        if(d==0) continue;
        e.cap-=d;
        G[e.to][e.rev].cap+=d;
        return d;      
      }
    }
    return 0;
  }
  
  T flow(int s,int t,T lim){
    T fl=0;
    while(1){
      bfs(s);
      if(level[t]<0||lim==0) break;
      fill(iter.begin(),iter.end(),0);
      
      while(1){
        T f=dfs(s,t,lim);
        if(f==0) break;
        fl+=f;
        lim-=f;
      }
    }
    return fl;
  }

  T flow(int s,int t){
    return flow(s,t,INF);
  }
};
//END CUT HERE


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed GRL_6_A(){
  int V,E;
  cin>>V>>E;
  Dinic<int, true> dinic(V,1<<28);
  for(int i=0;i<E;i++){
    int u,v,c;
    cin>>u>>v>>c;
    dinic.add_edge(u,v,c);
  }
  cout<<dinic.flow(0,V-1)<<endl;
  return 0;
}

/*
  verified on 2019/03/17
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp
*/


signed SPOJ_FASTFLOW(){
  Int n,m;
  cin>>n>>m;
  Dinic<Int, false> G(n,1LL<<55);
  for(Int i=0;i<m;i++){
    Int a,b,c;
    cin>>a>>b>>c;
    if(a==b) continue;
    a--;b--;
    G.add_edge(a,b,c);
  }
  cout<<G.flow(0,n-1)<<endl;
  return 0;
}
/*
  verified on 2019/03/17
  https://www.spoj.com/problems/FASTFLOW/
*/

signed main(){
  //GRL_6_A();
  //SPOJ_FASTFLOW();
  return 0;
}
