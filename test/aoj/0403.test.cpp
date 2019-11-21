#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0403"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../graph/chebyshevneighbors.cpp"
#include "../../graph/kruskal.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;

  vector<int> xs(n),ys(n);
  for(int i=0;i<n;i++)
    cin>>xs[i]>>ys[i];

  ChebyshevNeighbors<int> C(xs,ys);
  auto es=C.build();

  Kruskal<long long> G(n);
  for(auto e:es){
    int u,v;
    tie(u,v)=e;
    int c=max(abs(xs[u]-xs[v]),abs(ys[u]-ys[v]));
    G.add_edge(u,v,c);
  }
  cout<<G.build()<<endl;
  return 0;
}
