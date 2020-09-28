// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3142

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../tools/fixpoint.cpp"
#include "../../tree/centroid.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n;
  cin>>n;
  Centroid G(n);
  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G.add_edge(u,v);
  }

  vector<ll> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<n;i++) cin>>bs[i];

  using P = pair<int, ll>;
  vector<vector<P>> H(n);
  MFP([&](auto dfs,int v,int p)->ll{
    ll res=as[v]-bs[v];
    for(int u:G[v]){
      if(u==p) continue;
      ll tmp=dfs(u,v);
      H[u].emplace_back(v,-tmp);
      H[v].emplace_back(u,+tmp);
      res+=tmp;
    }
    return res;
  })(0,-1);

  vector<ll> dp(n,0);
  queue<int> que;
  que.emplace(G.build(0)[0]);

  vector<ll> tmp(n);
  while(!que.empty()){
    int r=que.front();que.pop();

    for(int t=0;t<2;t++){
      ll res=0;
      for(auto ch:H[r]){
        int c=ch.first;
        if(!G.alive(c)) continue;

        // calc cost
        MFP([&](auto dfs,int v,int p,ll d)->void{
          chmin(dp[v],-d+res);
          for(auto[u,w]:H[v]){
            if(u==p) continue;
            if(!G.alive(u)) continue;
            dfs(u,v,d+w);
          }
        })(c,r,ch.second);

        // update cost
        MFP([&](auto dfs,int v,int p,ll d)->void{
          chmin(res,d);
          for(auto[u,w]:H[v]){
            if(u==p) continue;
            if(!G.alive(u)) continue;
            dfs(u,v,d+w);
          }
        })(c,r,ch.second);
      }
      chmin(dp[r],res);
      reverse(H[r].begin(),H[r].end());
    }

    G.disable(r);
    for(int c:G.G[r])
      if(G.alive(c))
        que.emplace(G.build(c)[0]);
  }

  ll ans=0;
  for(ll x:dp) ans+=x;
  cout<<-ans<<endl;
  return 0;
}
