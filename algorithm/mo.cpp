#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Mo{
  using F = function<void(int)>;
  vector<int> ls,rs,ord;
  int n,width,nl,nr,ptr;
  F expandL,expandR;
  F shrinkL,shrinkR;

  Mo(int n,int width,F expandL,F expandR,F shrinkL,F shrinkR):
    n(n),width(width),nl(0),nr(0),ptr(0),
    expandL(expandL),expandR(expandR),
    shrinkL(shrinkL),shrinkR(shrinkR){}

  Mo(int n,int width,F expand,F shrink){
    *this=Mo(n,width,expand,expand,shrink,shrink);
  }

  void add(int l,int r){
    ls.emplace_back(l);
    rs.emplace_back(r);
  }

  void build(){
    ord.resize(ls.size());
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),
         [&](int a,int b){
           if(ls[a]/width!=ls[b]/width) return ls[a]<ls[b];
           if(rs[a]==rs[b]) return ls[a]<ls[b];
           return bool((rs[a]<rs[b])^((ls[a]/width)&1));
         });
  }

  int process(){
    if(ptr==(int)ord.size()) return -1;
    const int idx=ord[ptr++];
    while(nl>ls[idx]) expandL(--nl);
    while(nr<rs[idx]) expandR(nr++);
    while(nl<ls[idx]) shrinkL(nl++);
    while(nr>rs[idx]) shrinkR(--nr);
    return idx;
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../tree/eulertourforedge.cpp"
#undef call_from_test

//INSERT ABOVE HERE
// Mo on Tree
signed ABC133_F(){
  int n,q;
  cin>>n>>q;
  vector<int> as(n),bs(n),cs(n),ds(n);
  vector<int> xs(q),ys(q),us(q),vs(q);

  EulerTourForEdge et(n);
  for(int i=1;i<n;i++){
    cin>>as[i]>>bs[i]>>cs[i]>>ds[i];
    as[i]--;bs[i]--;
    et.add_edge(as[i],bs[i]);
  }
  et.build();

  vector<int> idx(n,0);
  for(int i=1;i<n;i++)
    idx[et.child(as[i],bs[i])]=i;

  for(int i=0;i<q;i++){
    cin>>xs[i]>>ys[i]>>us[i]>>vs[i];
    us[i]--;vs[i]--;
  }

  int all=0;
  vector<int> cnt(n),sum(n),app(n,0);
  auto exec=
    [&](int k){
      int v=et.bottom(k);
      int e=idx[v];
      app[v]^=1;
      if(app[v]){
        all+=ds[e];
        cnt[cs[e]]++;
        sum[cs[e]]+=ds[e];
      }else{
        all-=ds[e];
        cnt[cs[e]]--;
        sum[cs[e]]-=ds[e];
      }
    };
  Mo mo(n*2,400,exec,exec);

  for(int i=0;i<q;i++){
    auto f=[&](int l,int r){mo.add(min(l,r),max(l,r));};
    et.query(us[i],vs[i],f);
  }
  mo.build();

  vector<int> ans(q,0);
  for(int i=0;i<q;i++){
    int k=mo.process();
    ans[k]=all-sum[xs[k]]+cnt[xs[k]]*ys[k];
  }

  for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/11/12
  https://atcoder.jp/contests/abc133/tasks/abc133_f
*/

signed main(){
  //ABC133_F();
  return 0;
}
#endif
