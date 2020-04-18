#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2359"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/drop.cpp"
#include "../../vector/compress.cpp"
#include "../../vector/fusion.cpp"
#include "../../vector/shift.cpp"
#include "../../segtree/basic/dual.cpp"
#define SegmentTree SegmentTree2
#include "../../segtree/basic/chien.cpp"
#undef SegmentTree
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int q;
  cin>>q;
  vector<int> ts(q),as(q),bs(q),ys(q);
  for(int i=0;i<q;i++) cin>>ts[i]>>as[i]>>bs[i]>>ys[i];

  vector<int> vs=fusion(near(as,-1,0,1),near(bs,-1,0,1));
  vs.emplace_back(0);
  vs.emplace_back(1e9+10);
  vs=compress(vs);
  auto dc=dict(vs);
  int m=dc.size();

  using P = pair<int, int>;
  auto h=[&](P a,P b){
    if(a.first) return a;
    return P(b.first,max(a.second,b.second));
  };
  P ei(0,0);
  SegmentTree<P> seg(h,ei);
  seg.init(m);

  for(int i=0;i<q;i++){
    int l=dc[as[i]];
    int r=dc[bs[i]+1];

    if(ts[i]==0) seg.update(l,r,P(0,ys[i]));
    if(ts[i]==1) seg.update(l,r,P(1,0));
  }

  vector<int> zs(m);
  for(int i=0;i<m;i++) zs[i]=seg.get_val(i).second;

  auto ff=[&](int a,int b){return min(a,b);};
  auto gg=[&](int  ,int b){return b;};
  SegmentTree2<int, int> seg2(ff,gg,gg,INT_MAX,-1);
  seg2.build(zs);

  for(int i=0;i<q;i++){
    int l=dc[as[i]];
    int r=dc[bs[i]+1];
    if(ts[i]==0){
      if(seg2.query(l,r)!=ys[i]) drop("NO");
    }
    if(ts[i]==1){
      seg2.update(l,r,ys[i]);
    }
  }
  drop("YES");
  return 0;
}
