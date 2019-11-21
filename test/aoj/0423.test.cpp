#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0423"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../graph/dijkstra.cpp"
#undef call_from_test

signed main(){
  int n,m;
  cin>>n>>m;

  vector<int> ts(n),es(n);
  for(int i=0;i<n;i++) cin>>ts[i]>>es[i];

  using P = pair<int, int>;
  vector< vector<P> > G(n+1);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;c--;
    G[b].emplace_back(a,c);
  }

  for(int i=0;i<n;i++) G[n].emplace_back(i,ts[i]);
  auto ds=dijkstra(n,G);

  long long ans=0;
  for(int i=0;i<n;i++) ans+=(long long)ds[i]*es[i];
  cout<<ans<<endl;
  return 0;
}
