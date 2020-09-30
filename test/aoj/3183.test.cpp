#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3183"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/drop.cpp"
#include "../../graph/stronglyconnectedcomponent.cpp"
#include "../../graph/dijkstra.cpp"
#include "../../maxflow/fordfulkerson.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

const int MAX = 303;
int G[MAX][MAX]={};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  SCC G(n);

  int S=n,T=n+1;
  Dijkstra<int> D(n+2);
  FordFulkerson<int, true> F(n+2);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G.add_edge(u,v);
    D.add_edge(u,v,1);
    F.add_edge(u,v,1);
  }
  int k=G.build();

  vector<int> indeg(n,0);
  vector<int> outdeg(n,0);

  for(int i=0;i<k;i++)
    for(int j:G.H[i])
      outdeg[i]++,indeg[j]++;

  for(int i=0;i<k;i++){
    if(i!=0 and indeg[i]==0) drop(-1);
    if(i!=k-1 and outdeg[i]==0) drop(-1);
  }

  for(int i=0;i<n;i++){
    if(G.blg[i]==0){
      D.add_edge(S,i,0);
      F.add_edge(S,i,2);
    }
    if(G.blg[i]==k-1){
      D.add_edge(i,T,0);
      F.add_edge(i,T,2);
    }
  }

  int res=F.flow(S,T,2);
  if(res!=2) drop(-1);

  D.build(S);
  if(~D.bs[T]) drop(D[T]);
  drop(-1);
  return 0;
}
