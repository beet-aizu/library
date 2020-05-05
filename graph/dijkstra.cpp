#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct Dijkstra{
  struct Edge{
    int to;
    T cost;
    Edge(int to,T cost):to(to),cost(cost){}
    bool operator<(const Edge &o)const{return cost>o.cost;}
  };

  vector< vector<Edge> > G;
  vector<T> ds;
  vector<int> bs;
  Dijkstra(int n):G(n){}

  void add_edge(int u,int v,T c){
    G[u].emplace_back(v,c);
  }

  void build(int s){
    int n=G.size();
    ds.assign(n,numeric_limits<T>::max());
    bs.assign(n,-1);

    priority_queue<Edge> pq;
    ds[s]=0;
    pq.emplace(s,ds[s]);

    while(!pq.empty()){
      auto p=pq.top();pq.pop();
      int v=p.to;
      if(ds[v]<p.cost) continue;
      for(auto e:G[v]){
        if(ds[e.to]>ds[v]+e.cost){
          ds[e.to]=ds[v]+e.cost;
          bs[e.to]=v;
          pq.emplace(e.to,ds[e.to]);
        }
      }
    }
  }

  T operator[](int k){return ds[k];}

  vector<int> restore(int to){
    vector<int> res;
    while(~bs[to]) res.emplace_back(to),to=bs[to];
    res.emplace_back(bs[to]);
    reverse(res.begin(),res.end());
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
