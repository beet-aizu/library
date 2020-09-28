#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "./dinic.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Flow, bool directed>
struct TwoCommodity{
  Dinic<Flow, directed> G,H;
  int S,T;
  TwoCommodity(int n):G(n+2),H(n+2),S(n),T(n+1){}

  void add_edge(int src,int dst,Flow cap){
    G.add_edge(src,dst,cap);
    H.add_edge(src,dst,cap);
  }

  // maximize sum of two flows (s -> t) and (u -> v)
  Flow build(int s,int t,int u,int v){
    const Flow INF = numeric_limits<Flow>::max()/4;

    G.add_edge(S,s,INF);
    G.add_edge(S,u,INF);
    G.add_edge(t,T,INF);
    G.add_edge(v,T,INF);

    H.add_edge(S,s,INF);
    H.add_edge(S,v,INF);
    H.add_edge(t,T,INF);
    H.add_edge(u,T,INF);

    return min(G.flow(S,T),H.flow(S,T));
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
