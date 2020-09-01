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
  F expand,shrink,query,reset;

  Sack(int n,F expand,F shrink,F query,F reset):
    sub(n,1),hvy(n,-1),big(n,0),G(n),Q(n),
    expand(expand),shrink(shrink),
    query(query),reset(reset){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void add_query(int v,int k){
    Q[v].emplace_back(k);
    sub[v]++;
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
    if(!k) add(v,p,0),reset(v);
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

// test with reset
signed ECR002_E(){
  using ll = long long;
  int n;
  scanf("%d",&n);
  vector<int> c(n);
  for(int i=0;i<n;i++) scanf("%d",&c[i]);
  vector<int> cnt(n+1,0);
  vector<ll> ans(n,0);
  int mx=0;
  ll res=0;
  auto expand=[&](int v){
    cnt[c[v]]++;
    if(mx<cnt[c[v]]){
      mx=cnt[c[v]];
      res=0;
    }
    if(mx==cnt[c[v]]) res+=c[v];
  };
  auto shrink=[&](int v){cnt[c[v]]--;};
  auto query =[&](int v){ans[v]=res;};
  auto reset =[&](int){mx=res=0;};
  Sack sc(n,expand,shrink,query,reset);
  for(int i=1;i<n;i++){
    int x,y;
    scanf("%d %d",&x,&y);
    x--;y--;
    sc.add_edge(x,y);
  }
  for(int i=0;i<n;i++) sc.add_query(i,i);
  sc.build();
  for(int i=0;i<n;i++){
    if(i) printf(" ");
    printf("%lld",ans[i]);
  }
  puts("");
  return 0;
}
/*
  verified on 2020/09/01
  http://codeforces.com/contest/600/problem/E
*/

signed main(){
  ECR002_E();
  return 0;
}
#endif
