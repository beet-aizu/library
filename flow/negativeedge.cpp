#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "primaldual.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
// O((F+F') E log V), F': sum of caps with negative cost
template<typename TF,typename TC>
struct NegativeEdge{
  PrimalDual<TF, TC> G;
  vector<TF> fs;
  TC sum;
  int S,T;
  NegativeEdge(){}
  NegativeEdge(int n):G(n+2),fs(n+2,0),sum(0),S(n),T(n+1){}

  void use_edge(int u,int v,TF cap,TC cost){
    fs[u]-=cap;
    fs[v]+=cap;
    sum=sum+cost*cap;
  }

  void add_edge(int u,int v,TF cap,TC cost){
    if(cost<TC(0)){
      use_edge(u,v,cap,cost);
      swap(u,v);
      cost=-cost;
    }
    G.add_edge(u,v,cap,cost);
  }

  TC flow(int &ok){
    TF f=0;
    for(int i=0;i<S;i++){
      if(fs[i]>0){
        f+=fs[i];
        G.add_edge(S,i,+fs[i],TC(0));
      }
      if(fs[i]<0){
        G.add_edge(i,T,-fs[i],TC(0));
      }
    }
    return sum+G.flow(S,T,f,ok);
  }

  TC flow(int ts,int tt,TF tf,int &ok){
    fs[ts]+=tf;
    fs[tt]-=tf;
    return flow(ok);
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
