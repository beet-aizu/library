#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Flow,bool directed>
struct Dinic{
  struct Edge {
    int dst;
    Flow cap;
    int rev;
    Edge(int dst,Flow cap,int rev):dst(dst),cap(cap),rev(rev){}
  };

  vector< vector<Edge> > G;
  vector<int> level,iter;

  Dinic(){}
  Dinic(int n):G(n),level(n),iter(n){}

  int add_edge(int src,int dst,Flow cap){
    int e=G[src].size();
    int r=(src==dst?e+1:G[dst].size());
    G[src].emplace_back(dst,cap,r);
    G[dst].emplace_back(src,directed?0:cap,e);
    return e;
  }

  void bfs(int s){
    fill(level.begin(),level.end(),-1);
    queue<int> que;
    level[s]=0;
    que.emplace(s);
    while(!que.empty()){
      int v=que.front();que.pop();
      for(int i=0;i<(int)G[v].size();i++){
        Edge &e=G[v][i];
        if(e.cap>0&&level[e.dst]<0){
          level[e.dst]=level[v]+1;
          que.emplace(e.dst);
        }
      }
    }
  }

  Flow dfs(int v,int t,Flow f){
    if(v==t) return f;
    for(int &i=iter[v];i<(int)G[v].size();i++){
      Edge &e=G[v][i];
      if(e.cap>0&&level[v]<level[e.dst]){
        Flow d=dfs(e.dst,t,min(f,e.cap));
        if(d==0) continue;
        e.cap-=d;
        G[e.dst][e.rev].cap+=d;
        return d;
      }
    }
    return 0;
  }

  Flow flow(int s,int t,Flow lim){
    Flow fl=0;
    while(1){
      bfs(s);
      if(level[t]<0||lim==0) break;
      fill(iter.begin(),iter.end(),0);

      while(1){
        Flow f=dfs(s,t,lim);
        if(f==0) break;
        fl+=f;
        lim-=f;
      }
    }
    return fl;
  }

  Flow flow(int s,int t){
    return flow(s,t,numeric_limits<Flow>::max()/2);
  }

  Flow cut(int s,int t,int x,int a){
    static_assert(directed, "must be directed");
    auto &e=G[x][a];
    int y=e.dst;
    Flow cr=G[y][e.rev].cap;
    if(cr==0) return e.cap=0;
    e.cap=G[y][e.rev].cap=0;
    Flow cap=cr-flow(x,y,cr);
    if(x!=s&&cap!=0) flow(x,s,cap);
    if(t!=y&&cap!=0) flow(t,y,cap);
    return cap;
  }

  Flow link(int s,int t,int x,int a,Flow f){
    auto &e=G[x][a];
    e.cap+=f;
    return flow(s,t,f);
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
