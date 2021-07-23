// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2370

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/bipartitedecomposition.cpp"
#include "../../algorithm/partialsum.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  BipartiteDecomposition G(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G.add_edge(u,v);
  }
  auto res=G.build();
  if(res.empty()){
    cout<<-1<<endl;
    return 0;
  }

  int offset=0;
  vector<int> vs;
  for(auto[x,y]:res){
    offset+=min(x,y);
    vs.emplace_back(abs(x-y));
  }
  auto dp=partial_sum<100000>(vs);

  long long ans=0;
  for(int i=0;i<=n;i++){
    if(!dp[i]) continue;
    long long part=offset+i;
    ans=max(ans,part*(n-part)-m);
  }
  cout<<ans<<endl;
  return 0;
}
