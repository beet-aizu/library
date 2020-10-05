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
// Mo on Tree
signed ABC133_F(){
  int n,q;
  cin>>n>>q;
  vector<int> as(n),bs(n),cs(n),ds(n);
  vector<int> xs(q),ys(q),us(q),vs(q);

  int all=0;
  vector<int> cnt(n),sum(n),app(n,0);
  auto expand=[&](int e){
    all+=ds[e];
    cnt[cs[e]]++;
    sum[cs[e]]+=ds[e];
  };
  auto shrink=[&](int e){
    all-=ds[e];
    cnt[cs[e]]--;
    sum[cs[e]]-=ds[e];
  };

  MoOnTree mo(n+1,400,expand,shrink);
  mo.add_edge(0,1);
  for(int i=1;i<n;i++){
    cin>>as[i]>>bs[i]>>cs[i]>>ds[i];
    mo.add_edge(as[i],bs[i]);
  }

  for(int i=0;i<q;i++){
    cin>>xs[i]>>ys[i]>>us[i]>>vs[i];
    mo.add_query(us[i],vs[i]);
  }
  mo.build();

  vector<int> ans(q);
  for(int i=0;i<q;i++){
    int k=mo.process();
    ans[k]=all-sum[xs[k]]+cnt[xs[k]]*ys[k];
  }

  for(int i=0;i<q;i++) cout<<ans[i]<<'\n';
  return 0;
}
/*
  verified on 2020/10/05
  https://atcoder.jp/contests/abc133/tasks/abc133_f
*/

signed main(){
  ABC133_F();
  return 0;
}
#endif
