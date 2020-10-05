#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../algorithm/mo.cpp"
#include "../tree/eulertourforedge.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
struct MoOnTree{
  Mo* mo;
  using F = Mo::F;
  EulerTourForEdge et;
  vector<int> app,idx;
  int width;
  F expand,shrink;
  MoOnTree(int n,int width,F expand,F shrink):
    et(n),app(n,0),idx(n),width(width),expand(expand),shrink(shrink){}
  vector<pair<int,int>> es,qs;
  void add_edge(int u,int v){
    es.emplace_back(u,v);
    et.add_edge(u,v);
  }
  void add_query(int u,int v){
    qs.emplace_back(u,v);
  }
  void build(){
    et.build();
    int num=0;
    for(auto[u,v]:es) idx[et.child(u,v)]=num++;
    F exec=[&](int k){
      int v=et.bottom(k);
      int e=idx[v];
      app[v]^=1;
      if(app[v]) expand(e);
      else shrink(e);
    };
    int n=et.G.size();
    mo=new Mo(2*n,width,exec,exec);
    auto f=[&](int l,int r){mo->add(min(l,r),max(l,r));};
    for(auto[u,v]:qs) et.query(u,v,f);
    mo->build();
  }
  int process(){return mo->process();}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
