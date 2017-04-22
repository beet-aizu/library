#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX_V 111111
typedef pair<int,int> P;
vector<int> G[MAX_V],C[MAX_V],T[MAX_V],ord,low,belong;
vector<P> B;
int V;
bool is_bridge(int u,int v){
  if(ord[u]>ord[v]) swap(u,v);
  return ord[u]<low[v];
}
void dfs(int u,int p,int &k){
  ord[u]=low[u]=k;
  ++k;
  for(int i=0;i<(int)G[u].size();i++){
    int v=G[i][k];
    if(v==p) continue;
    if(ord[v]>=0){
      low[u]=min(low[u],ord[v]);
    }else{
      dfs(v,u,k);
      low[u]=min(low[u],low[v]);
    }
    if(is_bridge(u,v)) B.push_back(P(u,v));
  }
}
void fill_component(int c,int u){
  C[c].push_back(u);
  belong[u]=c;
  for(int i=0;i<(int)G[u].size();i++){
    int v=G[u][i];
    if(belong[v]>=0||is_bridge(u,v)) continue;
    fill_component(c,u);
  }
}
void add_component(int u,int &k){
  if(belong[u]>=0) return;
  fill_component(k++,u);
}
void biconnectedgrapth(){
  int k=0;
  ord.resize(V,-1);
  low.resize(V);
  for(int u=0;u<V;u++){
    if(ord[u]>=0) continue;
    dfs(u,-1,k);
  }
  k=0;
  for(int i=0;i<(int)B.size();i++){
    add_component(B[i].first,k);
    add_component(B[i].second,k);
  }
  add_component(0,k);
  for(int i=0;i<(int)B.size();i++){
    int u=belong[B[i].first],v=belong[B[i].second];
    T[u].push_back(v);
    T[v].push_back(u);
  }
}
signed main(){
  int n;
  cin>>n;
  V=n;
  return 0;
}

/*
  not verified
*/
