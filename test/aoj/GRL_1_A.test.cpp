#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/radixheap.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,r;
  cin>>n>>m>>r;

  using P = pair<int, int>;
  vector< vector<P> > G(n);
  for(int i=0;i<m;i++){
    int s,t,d;
    cin>>s>>t>>d;
    G[s].emplace_back(t,d);
  }

  const int INF = numeric_limits<int>::max();
  RadixHeap<int, int> pq;
  vector<int> dist(n,INF);
  dist[r]=0;
  pq.emplace(dist[r],r);
  while(!pq.empty()){
    P p=pq.pop();
    int v=p.second;
    if(dist[v]<p.first) continue;
    for(auto& e:G[v]){
      int u=e.first,c=e.second;
      if(dist[u]>dist[v]+c){
        dist[u]=dist[v]+c;
        pq.emplace(dist[u],u);
      }
    }
  }

  for(int i=0;i<n;i++){
    if(dist[i]==INF) cout<<"INF\n";
    else cout<<dist[i]<<"\n";
  }
  cout<<flush;
  return 0;
}
