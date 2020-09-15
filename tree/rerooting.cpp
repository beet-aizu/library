#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

//BEGIN CUT HERE
template<typename T, typename Edge>
struct ReRooting{
  struct Node{
    int to,rev;
    Edge data;
    Node(int to,Edge data):to(to),data(data){}
    bool operator<(const Node &v)const{return to<v.to;};
  };

  using Fold = function<T(T, T)>;
  using Lift = function<T(T, Edge)>;

  vector< vector<Node> > G;
  vector< vector<T> > ld,rd;
  vector<int> lp,rp;

  const Fold fold;
  const Lift lift;
  const T id;

  ReRooting(int n,const Fold fold,const Lift lift,const T id):
    G(n),ld(n),rd(n),lp(n),rp(n),fold(fold),lift(lift),id(id){}

  void add_edge(int u,int v,Edge d,Edge e){
    G[u].emplace_back(v,d);
    G[v].emplace_back(u,e);
  }

  void add_edge(int u,int v,Edge d){add_edge(u,v,d,d);}

  // k: idx for edge (not vertex)
  T dfs(int v,int k){
    while(lp[v]!=k and lp[v]<(int)G[v].size()){
      auto &e=G[v][lp[v]];
      ld[v][lp[v]+1]=fold(ld[v][lp[v]],lift(dfs(e.to,e.rev),e.data));
      lp[v]++;
    }
    while(rp[v]!=k and rp[v]>=0){
      auto &e=G[v][rp[v]];
      rd[v][rp[v]]=fold(rd[v][rp[v]+1],lift(dfs(e.to,e.rev),e.data));
      rp[v]--;
    }
    if(k<0) return rd[v][0];
    return fold(ld[v][k],rd[v][k+1]);
  }

  int search(vector<Node> &vs,int idx){
    return lower_bound(vs.begin(),vs.end(),Node(idx,vs[0].data))-vs.begin();
  }

  vector<T> build(){
    int n=G.size();
    for(int i=0;i<n;i++){
      sort(G[i].begin(),G[i].end());
      ld[i].assign((int)G[i].size()+1,id);
      rd[i].assign((int)G[i].size()+1,id);
      lp[i]=0;
      rp[i]=(int)G[i].size()-1;
    }

    for(int i=0;i<n;i++)
      for(Node &t:G[i])
        t.rev=search(G[t.to],i);

    vector<T> res;
    for(int i=0;i<n;i++)
      res.emplace_back(dfs(i,-1));

    return res;
  }

  // p: idx for vertex
  T subtree(int v,int p){
    int k=search(G[p],v);
    assert(k<(int)G[p].size() and G[p][k].to==v);
    return lift(dfs(v,G[p][k].rev),G[p][k].data);
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
