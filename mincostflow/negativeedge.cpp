#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "primaldual.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
// O((F+F') E \log V), F': sum of caps with negative cost
template<typename Flow, typename Cost>
struct NegativeEdge{
  PrimalDual<Flow, Cost> G;
  vector<Flow> fs;
  Cost sum;
  int S,T;
  NegativeEdge(int n):G(n+2),fs(n+2,0),sum(0),S(n),T(n+1){}

  void use_edge(int u,int v,Flow cap,Cost cost){
    fs[u]-=cap;
    fs[v]+=cap;
    sum=sum+cost*cap;
  }

  void add_edge(int u,int v,Flow cap,Cost cost){
    if(cost<Cost(0)){
      use_edge(u,v,cap,cost);
      swap(u,v);
      cost=-cost;
    }
    G.add_edge(u,v,cap,cost);
  }

  bool build(){
    Flow f=0;
    for(int i=0;i<S;i++){
      if(fs[i]>0){
        f+=fs[i];
        G.add_edge(S,i,+fs[i],Cost(0));
      }
      if(fs[i]<0){
        G.add_edge(i,T,-fs[i],Cost(0));
      }
    }
    return G.build(S,T,f);
  }

  bool build(int ts,int tt,Flow tf){
    fs[ts]+=tf;
    fs[tt]-=tf;
    return build();
  }

  Cost get_cost(){
    return sum+G.get_cost();
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
