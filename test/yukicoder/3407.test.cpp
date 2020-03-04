#define PROBLEM "https://yukicoder.me/problems/3407"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tree/eulertourforvertex.cpp"
#include "../../tree/lowestcommonancestor.cpp"
#include "../../tree/auxiliarytree.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;

  AuxiliaryTree G(n);
  vector<map<int, int>> ws(n);
  for(int i=1;i<n;i++){
    int u,v,w;
    cin>>u>>v>>w;
    G.add_edge(u,v);
    ws[u][v]=ws[v][u]=w;
  }
  G.build();

  using ll = long long;
  vector<ll> dep(n,-1);
  queue<int> que;
  dep[0]=0;
  que.emplace(0);
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int u:G.G[v]){
      if(~dep[u]) continue;
      dep[u]=dep[v]+ws[v][u];
      que.emplace(u);
    }
  }

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int k;
    cin>>k;
    vector<int> vs(k);
    for(int j=0;j<k;j++) cin>>vs[j];

    auto H=G.query(vs).second;
    ll ans=0;
    for(int v:vs)
      for(int u:H[v])
        ans+=dep[u]-dep[v];

    cout<<ans<<"\n";
  }
  cout<<flush;
  return 0;
}
