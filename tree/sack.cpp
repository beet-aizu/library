#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

/**
 * @see https://codeforces.com/blog/entry/44351
 */
//BEGIN CUT HERE
struct Sack{
  using F = function<void(int)>;

  vector<int> sub,hvy,big;
  vector< vector<int> > G,Q;
  F expand,shrink,query;

  Sack(int n,F expand,F shrink,F query):
    sub(n,1),hvy(n,-1),big(n,0),G(n),Q(n),
    expand(expand),shrink(shrink),query(query){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void add_query(int v,int k){
    Q[v].emplace_back(k);
  }

  void add(int v,int p,int x){
    if(x==1) expand(v);
    else shrink(v);
    for(int u:G[v])
      if(u!=p&&!big[u]) add(u,v,x);
  }

  void dfs(int v=0,int p=-1,bool k=0){
    for(int u:G[v])
      if(u!=p&&u!=hvy[v]) dfs(u,v,0);
    if(~hvy[v]){
      dfs(hvy[v],v,1);
      big[hvy[v]]=1;
    }
    add(v,p,1);
    for(int k:Q[v]) query(k);
    if(~hvy[v]) big[hvy[v]]=0;
    if(!k) add(v,p,0);
  }

  void build(int v=0,int p=-1){
    for(int u:G[v]){
      if(u==p) continue;
      build(u,v);
      if(hvy[v]<0||sub[hvy[v]]<sub[u]) hvy[v]=u;
      sub[v]+=sub[u];
    }
    if(p==-1) dfs(v,p);
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
