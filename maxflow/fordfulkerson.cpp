#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// O(F E \log V)
template<typename Flow, bool directed>
struct FordFulkerson{
  struct edge{
    int dst;
    Flow cap;
    int rev;
    edge(){}
    edge(int dst,Flow cap,int rev):dst(dst),cap(cap),rev(rev){}
  };

  vector< vector<edge> > G;
  vector<int> used;

  FordFulkerson(){}
  FordFulkerson(int n):G(n),used(n){}

  int add_edge(int src,int dst,Flow cap){
    int e=G[src].size();
    int r=(src==dst?e+1:G[dst].size());
    G[src].emplace_back(dst,cap,r);
    G[dst].emplace_back(src,directed?0:cap,e);
    return e;
  }

  Flow dfs(int v,int t,Flow f){
    if(v==t) return f;
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++){
      edge &e=G[v][i];
      if(!used[e.dst]&&e.cap>0){
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
      fill(used.begin(),used.end(),0);
      Flow f=dfs(s,t,lim);
      if(f==0) break;
      fl+=f;
      lim-=f;
    }
    return fl;
  }

  Flow flow(int s,int t){
    return flow(s,t,numeric_limits<Flow>::max()/2);
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
