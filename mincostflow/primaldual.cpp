#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// O(F E log V)
template<typename Flow, typename Cost>
struct PrimalDual{
  struct Edge{
    int dst;
    Flow cap;
    Cost cost;
    int rev;
    Edge(int dst,Flow cap,Cost cost,int rev):
      dst(dst),cap(cap),cost(cost),rev(rev){}
  };

  vector<vector<Edge>> G;
  vector<Cost> h,dist;
  vector<int> prevv,preve;

  PrimalDual(int n):G(n),h(n),dist(n),prevv(n),preve(n){}

  void add_edge(int u,int v,Flow cap,Cost cost){
    int e=G[u].size();
    int r=(u==v?e+1:G[v].size());
    G[u].emplace_back(v,cap,cost,r);
    G[v].emplace_back(u,0,-cost,e);
  }

  Cost residual_cost(int src,Edge &e){
    return e.cost+h[src]-h[e.dst];
  }

  void dijkstra(int s){
    struct P{
      Cost first;
      int second;
      P(Cost first,int second):first(first),second(second){}
      bool operator<(const P&a) const{return first>a.first;}
    };
    priority_queue<P> pq;

    dist[s]=0;
    pq.emplace(dist[s],s);
    while(!pq.empty()){
      P p=pq.top();pq.pop();
      int v=p.second;
      if(dist[v]<p.first) continue;
      for(int i=0;i<(int)G[v].size();i++){
        Edge &e=G[v][i];
        if(e.cap==0) continue;
        if(dist[v]+residual_cost(v,e)<dist[e.dst]){
          dist[e.dst]=dist[v]+e.cost+h[v]-h[e.dst];
          prevv[e.dst]=v;
          preve[e.dst]=i;
          pq.emplace(dist[e.dst],e.dst);
        }
      }
    }
  }

  Cost res;

  bool build(int s,int t,Flow f,
             function<void(decltype(h)&)> init=[](decltype(h) &p){
               fill(p.begin(),p.end(),0);
             }){
    res=0;
    init(h);
    const Cost INF = numeric_limits<Cost>::max();
    while(f>0){
      fill(dist.begin(),dist.end(),INF);
      dijkstra(s);
      if(dist[t]==INF) return false;

      for(int v=0;v<(int)h.size();v++)
        if(dist[v]<INF) h[v]=h[v]+dist[v];

      Flow d=f;
      for(int v=t;v!=s;v=prevv[v])
        d=min(d,G[prevv[v]][preve[v]].cap);

      f-=d;
      res=res+h[t]*d;
      for(int v=t;v!=s;v=prevv[v]){
        Edge &e=G[prevv[v]][preve[v]];
        e.cap-=d;
        G[v][e.rev].cap+=d;
      }
    }
    return true;
  }

  Cost get_cost(){return res;}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
