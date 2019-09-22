#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// no muliple edge
template<typename Graph>
bool hasMultipleEulerianTrail(Graph &G){
  int n=G.size();
  vector<int> ind(n,0),outd(n,0),pre(n,-1),loop(n,0);
  for(int v=0;v<n;v++){
    for(int u:G[v]){
      ind[u]++,outd[v]++;
      if(u==v) loop[v]=1;
      if(u!=v) pre[u]=v;
    }
  }

  int st=-1,en=-1,sz=0;
  for(int i=0;i<n;i++){
    if(ind[i]>=3||outd[i]>=3) return true;
    if(ind[i]<outd[i]) st=i;
    if(ind[i]>outd[i]) en=i;
    if(ind[i]+outd[i]) sz++;
  }
  if(sz<2) return false;
  if(st<0) return true;

  while(ind[en]==1+loop[en]&&st!=en) en=pre[en];
  if(st==en) return false;

  queue<int> que;
  vector<int> rs(n,0);
  que.emplace(st);
  rs[st]=1;
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int u:G[v]){
      if(u==en||rs[u]) continue;
      rs[u]=1;
      que.emplace(u);
    }
  }

  vector<int> us(n,0);
  que.emplace(en);
  us[en]=1;
  while(!que.empty()){
    int v=que.front();que.pop();
    if(rs[v]) return true;
    for(int u:G[v]){
      if(u==en||us[u]) continue;
      us[u]=1;
      que.emplace(u);
    }
  }
  return false;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
#endif
