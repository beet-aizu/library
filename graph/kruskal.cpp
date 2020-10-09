#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../datastructure/unionfind.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T>
struct Kruskal : UnionFind{
  using UnionFind::UnionFind;
  struct Edge{
    int src,dst;
    T cost;
    int used;
    Edge(int src,int dst,T cost):
      src(src),dst(dst),cost(cost),used(0){}
    bool operator<(const Edge& o) const{
      return cost<o.cost;
    }
  };

  vector<Edge> es;
  void add_edge(int u,int v,T c){
    es.emplace_back(u,v,c);
  }

  T build(){
    sort(es.begin(),es.end());
    T res=0;
    for(auto &e:es){
      if(same(e.src,e.dst)) continue;
      res+=e.cost;
      unite(e.src,e.dst);
      e.used=1;
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
int main(){
  return 0;
}
#endif
