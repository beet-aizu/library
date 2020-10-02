#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0439"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../tools/chminmax.cpp"
#include "../../tree/lowestcommonancestor.cpp"
#include "../../tree/auxiliarytree.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n;
  cin>>n;

  auto cs=read(n);

  AuxiliaryTree G(n);
  for(int i=1;i<n;i++){
    int s,t;
    cin>>s>>t;
    s--;t--;
    G.add_edge(s,t);
  }
  G.build();
  auto dep=G.dep;

  vector<vector<int>> C(n);
  for(int i=0;i<n;i++)
    C[cs[i]-1].emplace_back(i);

  vector<int> ds(n),idx(n);
  auto dijkstra=[&](auto &vs,auto &ss){
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    for(int v:vs) ds[v]=n,idx[v]=-1;
    for(int s:ss) ds[s]=0,idx[s]=s,pq.emplace(ds[s],s);
    while(!pq.empty()){
      int d=pq.top().first;
      int v=pq.top().second;
      pq.pop();
      if(ds[v]<d) continue;
      for(auto u:G.T[v]){
        int c=abs(dep[u]-dep[v]);
        if(ds[u]>ds[v]+c){
          ds[u]=ds[v]+c;
          idx[u]=idx[v];
          pq.emplace(ds[u],u);
        }
      }
    }
  };

  vector<int> ans(n,n);
  for(int c=0;c<n;c++){
    if(C[c].empty()) continue;
    assert(C[c].size()>1);
    auto vs=C[c];

    G.query(vs);

    dijkstra(vs,C[c]);

    for(int v:vs){
      for(int u:G.T[v]){
        if(idx[v]==idx[u]) continue;
        chmin(ans[idx[v]],G.distance(idx[v],idx[u]));
        chmin(ans[idx[u]],G.distance(idx[v],idx[u]));
      }
    }

    G.clear(vs);
  }

  for(int a:ans) cout<<a<<newl;
  return 0;
}
