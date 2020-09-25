// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2647

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/stronglyconnectedcomponent.cpp"
#include "../../graph/arborescence_edmond.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;

  vector<vector<int>> G(n),R(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    G[a].emplace_back(b);
    R[b].emplace_back(a);
  }

  vector<int> vs;
  for(int i=0;i<n;i++)
    if(R[i].empty()) vs.emplace_back(i);

  int sz=vs.size();
  map<int, int> rev;
  for(int i=0;i<sz;i++) rev[vs[i]]=i;

  const int INF = 1e9;
  vector<vector<int>> H;
  for(int r:vs){
    vector<int> dp(n,INF);

    using P = pair<int, int>;
    deque<P> deq;

    dp[r]=0;
    deq.emplace_back(r,0);

    while(!deq.empty()){
      int v,d;
      tie(v,d)=deq.front();deq.pop_front();
      if(dp[v]<d) continue;
      for(int u:G[v]){
        if(dp[u]<=dp[v]) continue;
        dp[u]=dp[v];
        deq.emplace_front(u,dp[u]);
      }
      for(int u:R[v]){
        if(dp[u]<=dp[v]+1) continue;
        dp[u]=dp[v]+1;
        deq.emplace_back(u,dp[u]);
      }
    }

    vector<int> di(sz);
    for(int i=0;i<sz;i++) di[i]=dp[vs[i]];
    H.emplace_back(di);
  }

  int cost=INF;
  vector<int> ans;

  for(int i=0;i<sz;i++){
    Arborescence<int> arb(sz);
    for(int j=0;j<sz;j++)
      for(int k=0;k<sz;k++)
        if(j!=k) arb.add_edge(j,k,H[j][k]);

    int res=arb.build(i);
    if(res<cost) cost=res,ans.clear();
    if(res==cost) ans.emplace_back(vs[i]);
  }

  cout<<ans.size()<<" "<<cost<<endl;
  for(int i=0;i<(int)ans.size();i++){
    if(i) cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}
