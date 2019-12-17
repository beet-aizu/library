#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct SCC{
  vector< vector<int> > G,R,T,C;
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

  int operator[](int k) const{return blg[k];}
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
