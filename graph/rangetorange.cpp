#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct RangeToRange{
  using E = pair<int, T>;
  const int n;
  vector<vector<E>> G;
  // (0n, 2n) : top segtree (to)
  // (2n, 4n) : bottom segtree (from)
  RangeToRange(int n):n(n){
    G.resize(n*4);
    for(int i=1;i<n;i++){
      int l=(i<<1)|0;
      int r=(i<<1)|1;
      G[0*n+i].emplace_back(0*n+l,0);
      G[0*n+i].emplace_back(0*n+r,0);
      G[2*n+l].emplace_back(2*n+i,0);
      G[2*n+r].emplace_back(2*n+i,0);
    }
    for(int i=0;i<n;i++)
      G[1*n+i].emplace_back(3*n+i,0);
  }
  // [l1, r1) -> [l2, r2)
  void add_edge(int l1,int r1,int l2,int r2,T c){
    int k=G.size();
    for(l1+=n,r1+=n;l1<r1;l1>>=1,r1>>=1){
      if(l1&1) G[2*n+(l1++)].emplace_back(k,0);
      if(r1&1) G[2*n+(--r1)].emplace_back(k,0);
    }
    vector<E> es;
    for(l2+=n,r2+=n;l2<r2;l2>>=1,r2>>=1){
      if(l2&1) es.emplace_back(l2++,c);
      if(r2&1) es.emplace_back(--r2,c);
    }
    G.emplace_back(es);
  }
  int idx(int v)const{return 1*n+v;}
  size_t size()const{return G.size();}
  const vector<E>& operator[](int k)const{return G[k];}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
