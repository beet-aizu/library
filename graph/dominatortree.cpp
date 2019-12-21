#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct DominatorTree{
  struct UnionFind{
    vector<int> &semi;
    vector<int> ps,ms;
    UnionFind(vector<int> &semi):
      semi(semi),ps(semi.size()),ms(semi.size()){
      iota(ps.begin(),ps.end(),0);
      iota(ms.begin(),ms.end(),0);
    }
    int find(int v){
      if(ps[v]==v) return v;
      int r=find(ps[v]);
      if(semi[ms[v]]>semi[ms[ps[v]]]) ms[v]=ms[ps[v]];
      return ps[v]=r;
    }
    int eval(int v){
      find(v);
      return ms[v];
    }
    void link(int p,int v){ps[v]=p;}
  };

  vector< vector<int> > G,R;
  vector<int> ord,par,idom,semi;
  DominatorTree(int n):
    G(n),R(n),par(n),idom(n,-1),semi(n,-1){
    ord.reserve(n);
  }

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    R[v].emplace_back(u);
  }

  void dfs(int v){
    semi[v]=ord.size();
    ord.emplace_back(v);
    for(int u:G[v]){
      if(~semi[u]) continue;
      par[u]=v;
      dfs(u);
    }
  }

  void build(int rt){
    int n=G.size();
    dfs(rt);

    vector< vector<int> > bkt(n);
    UnionFind uf(semi);
    vector<int> us(n);

    for(int i=(int)ord.size()-1;i>=0;i--){
      int v=ord[i];
      for(int u:R[v]){
        if(semi[u]<0) continue;
        u=uf.eval(u);
        if(semi[v]>semi[u]) semi[v]=semi[u];
      }
      bkt[ord[semi[v]]].emplace_back(v);
      for(int u:bkt[par[v]]) us[u]=uf.eval(u);
      bkt[par[v]].clear();
      uf.link(par[v],v);
    }

    for(int i=1;i<(int)ord.size();i++){
      int v=ord[i],u=us[v];
      idom[v]=(semi[v]==semi[u]?semi[v]:idom[u]);
    }

    for(int i=1;i<(int)ord.size();i++){
      int v=ord[i];
      idom[v]=ord[idom[v]];
    }

    idom[rt]=rt;
  }

  int operator[](int k){return idom[k];}
};
//END CUT HERE
#ifndef call_from_test
int main(){
  return 0;
}
#endif
