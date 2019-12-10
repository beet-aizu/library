#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
vector< vector<int> >
construct_from_distances_to_farthest_vertex(vector<int> ds){
  int n=ds.size();
  vector<vector<int>> G(n),NG;
  for(int d:ds) if(d>=n) return NG;

  vector<int> ts(n,0);
  vector<queue<int>> qs(n);
  for(int i=0;i<n;i++){
    ts[ds[i]]++;
    qs[ds[i]].emplace(i);
  }

  int dm=*max_element(ds.begin(),ds.end());

  for(int i=0;i<(dm+1)/2;i++)
    if(ts[dm-i]<2) return NG;

  if(ts[dm/2+(dm&1)]!=1+(dm&1)) return NG;

  for(int d:ds)
    if(d<(dm+1)/2) return NG;

  auto add_edge=
    [&](int x,int y){
      G[x].emplace_back(y);
      G[y].emplace_back(x);
    };

  vector<int> xs(n),ys(n);
  for(int i=0;i<(dm+1)/2;i++){
    xs[dm-i]=qs[dm-i].front();qs[dm-i].pop();
    ys[dm-i]=qs[dm-i].front();qs[dm-i].pop();
    if(i){
      add_edge(xs[dm-i+1],xs[dm-i]);
      add_edge(ys[dm-i+1],ys[dm-i]);
    }
  }

  if(dm&1){
    add_edge(xs[dm/2+1],ys[dm/2+1]);
  }else{
    xs[dm/2]=qs[dm/2].front();qs[dm/2].pop();
    add_edge(xs[dm/2+1],xs[dm/2]);
    add_edge(ys[dm/2+1],xs[dm/2]);
  }

  for(int i=0;i<n;i++){
    if(!G[i].empty()) continue;
    add_edge(i,xs[ds[i]-1]);
  }
  return G;
}
//END CUT HERE
#ifndef call_from_test
class TreeDistanceConstruction {
public:
  vector<int> construct(vector<int> ds) {
    auto G=construct_from_distances_to_farthest_vertex(ds);
    if(G.empty()) return {};
    vector<int> bs;
    for(int i=0;i<(int)G.size();i++)
      for(int j:G[i])
        if(i<j) bs.emplace_back(i),bs.emplace_back(j);
    return bs;
  }
};
/*
  verified on 2019/12/10
  https://vjudge.net/problem/TopCoder-14468
*/
#endif
