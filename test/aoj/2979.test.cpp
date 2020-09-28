// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2979

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../maxflow/dinic.cpp"
#include "../../maxflow/twocommodity.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,s,t,u,v;
  cin>>n>>m>>s>>t>>u>>v;
  s--;t--;u--;v--;

  TwoCommodity<int, false> G(n);
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    G.add_edge(x,y,1);
  }

  cout<<G.build(s,t,u,v)<<endl;
  return 0;
}
