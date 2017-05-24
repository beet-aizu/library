#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX_V 114514
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
  for(int v:G[u]){
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
  for(int v:G[u]){
    if(belong[v]>=0||is_bridge(u,v)) continue;
    fill_component(c,v);
  }
}
void add_component(int u,int &k){
  if(belong[u]>=0) return;
  fill_component(k++,u);
}

set<int> ans;

void biconnectedgraph(int n){
  int k=0;
  ord.clear();
  ord.resize(n,-1);
  low.clear();
  low.resize(n);
  belong.clear();
  belong.resize(n,-1);
  for(int u=0;u<n;u++){
    if(ord[u]>=0) continue;
    dfs(u,-1,k);
  }
  k=0;
  for(int i=0;i<(int)B.size();i++){
    add_component(B[i].first,k);
    add_component(B[i].second,k);
  }
  add_component(0,k);
  V=k;
  for(int i=0;i<(int)B.size();i++){
    int u=belong[B[i].first],v=belong[B[i].second];
    T[u].push_back(v);
    T[v].push_back(u);
  }
}
signed main(){
  int n,e;
  cin>>n>>e;
  for(int i=0;i<e;i++){
    int s,t;
    cin>>s>>t;
    //cout<<s<<" "<<t<<endl;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  biconnectedgraph(n);
  set<int> ans;
  for(int i=0;i<(int)B.size();i++){
    int u=belong[B[i].first],v=belong[B[i].second];
    if((int)C[u].size()>1||(int)T[u].size()!=1) ans.insert(B[i].first);
    if((int)C[v].size()>1||(int)T[v].size()!=1) ans.insert(B[i].second);
  }
  for(int i:ans) cout<<i<<endl;
  return 0;
}

/*
  not verified
*/
