#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0403"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/manhattanmst.cpp"
#include "../../datastructure/unionfind.cpp"
#include "../../graph/kruskal.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  vector<int> xs(n),ys(n);
  for(int i=0;i<n;i++)
    cin>>xs[i]>>ys[i];

  vector<long long> us(n),vs(n);
  for(int i=0;i<n;i++){
    us[i]=xs[i]+ys[i];
    vs[i]=xs[i]-ys[i];
  }

  Kruskal<long long> G(n);
  for(auto [u,v]:manhattanmst(us,vs)){
    int c=max(abs(xs[u]-xs[v]),abs(ys[u]-ys[v]));
    G.add_edge(u,v,c);
  }
  cout<<G.build()<<endl;
  return 0;
}
