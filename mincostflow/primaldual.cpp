#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// O(F E log V)
template<typename Flow, typename Cost>
struct PrimalDual{
  struct Edge{
    int to;
    Flow cap;
    Cost cost;
    int rev;
    Edge(int to,Flow cap,Cost cost,int rev):
      to(to),cap(cap),cost(cost),rev(rev){}
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
        if(dist[v]+e.cost+h[v]-h[e.to]<dist[e.to]){
          dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
          prevv[e.to]=v;
          preve[e.to]=i;
          pq.emplace(dist[e.to],e.to);
        }
      }
    }
  }

  Cost res;

  bool build(int s,int t,Flow f){
    res=0;
    fill(h.begin(),h.end(),0);
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
signed geocon2013_B(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using D = double;

  int n;
  cin>>n;
  vector<D> xs(n),ys(n);
  for(int i=0;i<n;i++) cin>>xs[i]>>ys[i];

  vector<int> pos,neg;
  for(int i=0;i<n;i++){
    if(xs[i]>0) pos.emplace_back(i);
    if(xs[i]<0) neg.emplace_back(i);
  }

  int f=max(pos.size(),neg.size());
  if(f==0){
    cout<<0<<endl;
    return 0;
  }

  PrimalDual<int, D> G(n+3);
  int S=n,T=n+1,U=n+2;
  for(int z:pos) G.add_edge(S,z,1,0);
  for(int z:neg) G.add_edge(z,T,1,0);

  int dif=pos.size()-neg.size();
  if(dif>0){
    G.add_edge(U,T,dif,0);
    for(int p:pos)
      G.add_edge(p,U,1,abs(xs[p]));
  }
  if(dif<0){
    G.add_edge(S,U,-dif,0);
    for(int q:neg)
      G.add_edge(U,q,1,abs(xs[q]));
  }

  for(int p:pos)
    for(int q:neg)
      G.add_edge(p,q,1,
                 min(hypot(xs[p]+xs[q],ys[p]-ys[q]),abs(xs[p])+abs(xs[q])));

  assert(G.build(S,T,f));
  cout<<fixed<<setprecision(12)<<G.get_cost()<<endl;
  return 0;
}
/*
  verified on 2020/09/24
  https://atcoder.jp/contests/geocon2013/tasks/geocon2013_b
*/

signed main(){
  geocon2013_B();
  return 0;
}
#endif
