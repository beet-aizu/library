#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct SCC{
  vector<vector<int> > G,R,T,C;
  vector<int> vs,used,blg;
  SCC(){}
  SCC(int n):G(n),R(n),used(n),blg(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    R[v].emplace_back(u);
  }

  void dfs(int v){
    used[v]=1;
    for(int u:G[v])
      if(!used[u]) dfs(u);
    vs.emplace_back(v);
  }

  void rdfs(int v,int k){
    used[v]=1;
    blg[v]=k;
    C[k].emplace_back(v);
    for(int u:R[v])
      if(!used[u]) rdfs(u,k);
  }

  int build(){
    int n=G.size();
    for(int v=0;v<n;v++)
      if(!used[v]) dfs(v);

    fill(used.begin(),used.end(),0);
    int k=0;
    for(int i=n-1;i>=0;i--){
      if(!used[vs[i]]){
        T.emplace_back();
        C.emplace_back();
        rdfs(vs[i],k++);
      }
    }
    for(int v=0;v<n;v++)
      for(int u:G[v])
        if(blg[v]!=blg[u])
          T[blg[v]].push_back(blg[u]);

    for(int i=0;i<k;i++){
      sort(T[i].begin(),T[i].end());
      T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());
    }
    return k;
  }
  int operator[](int k) const{return blg[k];};
};
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
