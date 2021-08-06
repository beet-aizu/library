// verification-helper: PROBLEM https://yukicoder.me/problems/6680

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../graph/grid.cpp"
#include "../../graph/dijkstra.cpp"
#undef call_from_test

signed main(){
  using ll = long long;
  cin.tie(0);
  ios::sync_with_stdio(0);

  int h,w;
  cin>>h>>w;
  ll u,d,r,l,k,p;
  cin>>u>>d>>r>>l>>k>>p;
  int ys,xs,yt,xt;
  cin>>ys>>xs>>yt>>xt;
  ys--;xs--;yt--;xt--;

  auto C=read<string>(h);

  map<int, ll> cost;
  cost[-w]=u;
  cost[+w]=d;
  cost[+1]=r;
  cost[-1]=l;

  Grid G(h,w,[&](int y,int x){return C[y][x];});
  Dijkstra<ll> D(h*w);
  for(auto[a,b]:G.edges()){
    if(G[a]=='#' or G[b]=='#') continue;
    D.add_edge(a,b,cost[b-a]+p*(G[b]=='@'));
    D.add_edge(b,a,cost[a-b]+p*(G[a]=='@'));
  }

  D.build(G.idx(ys,xs));
  cout<<(D[G.idx(yt,xt)]<=k?"Yes":"No")<<endl;
  return 0;
}
