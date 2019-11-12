#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0415"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tools/chminmax.cpp"
#include "../../graph/lowlink.cpp"
#include "../../tree/diameterforvertex.cpp"
#undef call_from_test

signed main(){
  using ll = long long;

  int n,m;
  cin>>n>>m;
  vector<ll> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];

  LowLink G(n);
  for(int i=0;i<m;i++){
    int s,t;
    cin>>s>>t;
    s--;t--;
    G.add_edge(s,t);
  }

  int k=G.build();
  vector<ll> sm(k,0);
  for(int i=0;i<n;i++)
    sm[G.blg[i]]+=vs[i];

  ll ans=0;
  vector<int> used(k,-1);
  for(int i=0;i<k;i++){
    if(~used[i]) continue;
    int sz=0;
    queue<int> que;
    used[i]=sz++;
    que.emplace(i);

    vector<int> vv;
    vector<ll> ws;
    while(!que.empty()){
      int v=que.front();que.pop();
      vv.emplace_back(v);
      ws.emplace_back(sm[v]);
      for(int u:G.T[v]){
        if(~used[u]) continue;
        used[u]=sz++;
        que.emplace(u);
      }
    }

    DiameterForVertex<ll> H(ws);
    for(int v:vv)
      for(int u:G.T[v])
        if(u<v) H.add_edge(used[u],used[v]);

    chmax(ans,H.build());
  }

  cout<<ans<<endl;
  return 0;
}
