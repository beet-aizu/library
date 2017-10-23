#include<bits/stdc++.h>
using namespace std;
#define int long long
//BEGIN CUT HERE
struct BiconectedGraph{
  typedef pair<int,int> P;
  vector<vector<int> > G,C,T;
  vector<int> ord,low,belong;
  vector<P> B;
  int n;
  BiconectedGraph(){}
  BiconectedGraph(int n):n(n){
    G.clear();
    C.clear();
    T.clear();
    G.resize(n);
    C.resize(n);
    T.resize(n);
  }
  
  void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
  }

  void input(int m,int offset){
    int a,b;
    for(int i=0;i<m;i++){
      cin>>a>>b;
      add_edge(a+offset,b+offset);
    }
  }
  
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
  
  int build(){
    int k=0;
    ord.clear();
    low.clear();
    belong.clear();
    ord.resize(n,-1);
    low.resize(n);
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
    for(int u=0;u<n;u++) add_component(u,k);
    for(int i=0;i<(int)B.size();i++){
      int u=belong[B[i].first],v=belong[B[i].second];
      T[u].push_back(v);
      T[v].push_back(u);
    }
    return k;
  }
};
//END CUT HERE

signed main(){
  int v,e;
  cin>>v>>e;
  BiconectedGraph bcc(v);
  bcc.input(e,0);
  bcc.build();
  typedef pair<int,int> P;
  vector<P> B=bcc.B;
  for(P &p:B) if(p.first>p.second) swap(p.first,p.second);
  sort(B.begin(),B.end());
  for(P p:B) cout<<p.first<<" "<<p.second<<endl;
  return 0;
}

/*
  verified on 2017/10/21
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B&lang=jp
*/
