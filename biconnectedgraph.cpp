#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct BiconectedGraph{
  typedef pair<int,int> P;
  int n;
  vector<vector<int> > G,C,T;
  vector<int> ord,low,belong;
  vector<P> B;
  BiconectedGraph(){}
  BiconectedGraph(int sz):n(sz),G(sz),C(sz),T(sz){}
  
  void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
  }

  void input(int m,int offset=0){
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
  
  void dfs(int v,int p,int &k){
    ord[v]=low[v]=k;
    ++k;
    for(int u:G[v]){
      if(u==p) continue;
      if(ord[u]>=0){
	low[v]=min(low[v],ord[u]);
      }else{
	dfs(u,v,k);
	low[v]=min(low[v],low[u]);
      }
      if(is_bridge(u,v)) B.push_back(P(u,v));
    }
  }
  
  void fill_component(int c,int v){
    C[c].push_back(v);
    belong[v]=c;
    for(int u:G[v]){
      if(belong[u]>=0||is_bridge(u,v)) continue;
      fill_component(c,u);
    }
  }
  
  void add_component(int v,int &k){
    if(belong[v]>=0) return;
    fill_component(k++,v);
  }
  
  int build(){
    int k=0;
    ord.resize(n);
    low.resize(n);
    belong.resize(n);
    fill(ord.begin(),ord.end(),-1);
    fill(belong.begin(),belong.end(),-1);
    for(int v=0;v<n;v++){
      if(ord[v]>=0) continue;
      dfs(v,-1,k);
    }
    k=0;
    for(int i=0;i<(int)B.size();i++){
      add_component(B[i].first,k);
      add_component(B[i].second,k);
    }
    for(int v=0;v<n;v++) add_component(v,k);
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
  verified on 2017/12/20
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B&lang=jp
*/
