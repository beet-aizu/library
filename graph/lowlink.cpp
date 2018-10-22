#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
struct LowLink{
  int n,pos;
  vector<int> ord,low,par,blg;
  vector<vector<int> > G,C,T;
  
  vector<int> ap;
  vector<pair<int, int> > bs;

  LowLink(int n):n(n),pos(0),ord(n,-1),low(n),par(n,-1),blg(n,-1),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  bool is_bridge(int u,int v){
    if(ord[u]>ord[v]) swap(u,v);
    return ord[u]<low[v];
  }

  void dfs(int v){
    ord[v]=low[v]=pos++;
    for(int u:G[v]){
      if(u==par[v]) continue;
      if(~ord[u]){
        low[v]=min(low[v],ord[u]);
        continue;
      }
      par[u]=v;
      dfs(u);
      low[v]=min(low[v],low[u]);
      if(is_bridge(u,v)) bs.emplace_back(u,v);
    }
  }

  void fill_component(int v){
    C[blg[v]].emplace_back(v);
    for(int u:G[v]){
      if(~blg[u]) continue;
      blg[u]=blg[v];
      fill_component(u);
    }
  }

  void add_component(int v,int &k){
    if(~blg[v]) return;
    blg[v]=k++;
    C.emplace_back();
    fill_component(v);
  }
  
  void build(){
    for(int i=0;i<n;i++)
      if(ord[i]<0) dfs(i);
    
    vector<int> cnt(n,0);
    for(int i=0;i<n;i++){
      int p=par[i];
      if(p<0) continue;
      if(par[p]<0) cnt[p]++;
      else if(ord[p]<=low[i]) ap.emplace_back(p);
    }
    
    for(int i=0;i<n;i++)
      if(cnt[i]>1) ap.emplace_back(i);

    sort(ap.begin(),ap.end());
    ap.erase(unique(ap.begin(),ap.end()),ap.end());

    int k=0;    
    for(int i=0;i<n;i++) add_component(i,k);

    T.assign(C.size(),vector<int>());
    for(auto e:bs){
      int u=blg[e.first],v=blg[e.first];
      T[u].emplace_back(v);
      T[v].emplace_back(u);
    }      
  }
};
//END CUT HERE

signed GRL_3_A(){
  int n,m;
  scanf("%d %d",&n,&m);
  LowLink G(n);
  for(int i=0;i<m;i++){
    int u,v;
    scanf("%d %d",&u,&v);
    G.add_edge(u,v);
  }
  G.build();
  auto ap=G.ap;
  sort(ap.begin(),ap.end());
  for(int v:ap) printf("%d\n",v);
  return 0;
}

signed GRL_3_B(){
  int n,m;
  scanf("%d %d",&n,&m);
  
  LowLink G(n);
  for(int i=0;i<m;i++){
    int u,v;
    scanf("%d %d",&u,&v);
    G.add_edge(u,v);
  }
  G.build();
  
  auto bs=G.bs;
  for(auto &e:bs)
    if(e.first>e.second) swap(e.first, e.second);
  
  sort(bs.begin(),bs.end());
  for(auto e:bs) printf("%d %d\n",e.first, e.second);
  
  return 0;
}

signed main(){
  //GRL_3_A();
  //GRL_3_B();
  return 0;
}
