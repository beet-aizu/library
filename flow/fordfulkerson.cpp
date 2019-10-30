#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
template<typename T,bool directed>
struct FordFulkerson{
  struct edge{
    int to;
    T cap;
    int rev;
    edge(){}
    edge(int to,T cap,int rev):to(to),cap(cap),rev(rev){}
  };

  vector< vector<edge> > G;
  vector<int> used;

  FordFulkerson(){}
  FordFulkerson(int n):G(n),used(n){}

  void add_edge(int from,int to,T cap){
    G[from].emplace_back(to,cap,G[to].size());
    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);
  }

  T dfs(int v,int t,T f){
    if(v==t) return f;
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++){
      edge &e=G[v][i];
      if(!used[e.to]&&e.cap>0){
        T d=dfs(e.to,t,min(f,e.cap));
        if(d==0) continue;
        e.cap-=d;
        G[e.to][e.rev].cap+=d;
        return d;
      }
    }
    return 0;
  }

  T flow(int s,int t,T lim){
    T fl=0;
    while(1){
      fill(used.begin(),used.end(),0);
      T f=dfs(s,t,lim);
      if(f==0) break;
      fl+=f;
      lim-=f;
    }
    return fl;
  }

  T flow(int s,int t){
    return flow(s,t,numeric_limits<T>::max()/2);
  }

};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
