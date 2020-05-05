#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0423"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../graph/dijkstra.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  int n,m;
  cin>>n>>m;

  vector<int> ts(n),es(n);
  for(int i=0;i<n;i++) cin>>ts[i]>>es[i];

  Dijkstra<int> G(n+1);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;c--;
    G.add_edge(b,a,c);
  }

  for(int i=0;i<n;i++) G.add_edge(n,i,ts[i]);
  G.build(n);

  long long ans=0;
  for(int i=0;i<n;i++) ans+=(long long)G[i]*es[i];
  cout<<ans<<endl;
  return 0;
}
