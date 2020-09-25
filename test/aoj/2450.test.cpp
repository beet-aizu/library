// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/heavylightdecomposition.cpp"
#include "../../segtree/basic/chien.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  HLD hld(n);
  vector<int> ws(n);
  for(int i=0;i<n;i++) cin>>ws[i];
  for(int i=0;i+1<n;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    hld.add_edge(a,b);
  }
  hld.build();

  using T = tuple<int, int, int, int, int>;
  using E = pair<int, int>;

  T ti(-1,-1,-1,-1,-1);
  E ei(-1,-(1e4+10));

  auto f=[&](T a,T b){
    if(a==ti) return b;
    if(b==ti) return a;

    auto[asz,ava,avi,avl,avr]=a;
    auto[bsz,bva,bvi,bvl,bvr]=b;

    int csz=asz+bsz;
    int cva=ava+bva;
    int cvi=max({avi,bvi,avr+bvl});
    int cvl=max(avl,ava+bvl);
    int cvr=max(bvr,avr+bva);
    return T(csz,cva,cvi,cvl,cvr);
  };

  auto g=[&](T a,E p){
    if(p==ei) return a;
    auto[asz,ava,avi,avl,avr]=a;
    auto[v,b]=p;
    if(~v) asz=1;
    if(b>=0) return T(asz,b*asz,b*asz,b*asz,b*asz);
    return T(asz,b*asz,b,b,b);
  };

  auto h=[&](E,E b){return b;};
  SegmentTree<T, E> seg(f,g,h,ti,ei);

  vector<T> vt(n);
  for(int i=0;i<n;i++) vt[hld.vid[i]]=g(ti,E(i,ws[i]));
  seg.build(vt);

  for(int i=0;i<q;i++){
    int t,a,b,c;
    cin>>t>>a>>b>>c;
    a--;b--;
    if(t==1){
      hld.for_each(a,b,[&](int l,int r){seg.update(l,r,E(-1,c));});
    }
    if(t==2){
      int c=hld.lca(a,b);
      T x=ti,y=ti;
      hld.for_each(c,a,[&](int l,int r){x=f(seg.query(l,r),x);});
      hld.for_each_edge(c,b,[&](int l,int r){y=f(seg.query(l,r),y);});
      auto&[xsz,xva,xvi,xvl,xvr]=x;
      swap(xvl,xvr);
      auto[vsz,vva,vvi,vvl,vvr]=f(x,y);
      cout<<max({vva,vvi,vvl,vvr})<<'\n';
    }
  }
  return 0;
}
