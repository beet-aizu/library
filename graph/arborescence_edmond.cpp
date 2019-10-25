#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "stronglyconnectedcomponent.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T>
struct Arborescence{
  struct edge{
    int to;
    T cost;
    edge(int to,T cost):to(to),cost(cost){}
  };
  vector<vector<edge>> B;

  Arborescence(int n):B(n){}

  void add_edge(int u,int v,T cost){
    assert(u!=v);
    B[u].emplace_back(v,cost);
  }

  T build(int r){
    T res=0;
    auto G=B;
    const T INF = numeric_limits<T>::max()/2;
    while(1){
      int n=G.size();
      vector<T> ws(n,INF);
      vector<int> rs(n,-1);
      for(int v=0;v<n;v++){
        for(edge &e:G[v]){
          if(e.cost<ws[e.to]){
            ws[e.to]=e.cost;
            rs[e.to]=v;
          }
        }
      }
      SCC scc(n);
      for(int i=0;i<n;i++){
        if(i==r) continue;
        scc.add_edge(rs[i],i);
        res+=ws[i];
      }
      int m=scc.build();
      if(m==n) break;
      vector<vector<edge>> H(m);
      for(int v=0;v<n;v++){
        for(auto &e:G[v]){
          if(scc[v]==scc[e.to]) continue;
          H[scc[v]].emplace_back(scc[e.to],e.cost-ws[e.to]);
        }
      }
      r=scc[r];
      G=H;
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
