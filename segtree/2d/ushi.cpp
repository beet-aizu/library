#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename index_t,typename SegmentTree>
struct SegmentTree2D{
  using F = typename SegmentTree::F;
  using T = typename F::result_type;
  const F f;
  const T ti;
  SegmentTree2D(F f_,T ti_):f(f_),ti(ti_){}

  vector<pair<index_t, index_t>> vp;
  void preupdate(index_t p,index_t q){
    vp.emplace_back(p,q);
  }

  void compress(vector<index_t> &vs){
    sort(vs.begin(),vs.end());
    vs.erase(unique(vs.begin(),vs.end()),vs.end());
  }

  int idx(index_t v,const vector<index_t> &vs){
    return lower_bound(vs.begin(),vs.end(),v)-vs.begin();
  }

  int sz;
  vector<index_t> ps;
  vector<vector<index_t>> I;
  vector<vector<int>> L,R;
  vector<SegmentTree> seg;
  void build(){
    for(auto[p,q]:vp) ps.emplace_back(p);
    compress(ps);

    sz=1;
    while(sz<(int)ps.size()) sz<<=1;

    I.resize(sz<<1);
    for(auto[p,q]:vp) I[sz+idx(p,ps)].emplace_back(q);
    for(int k=(int)I.size()-1;k>=sz;k--) compress(I[k]);

    L.resize(sz);
    R.resize(sz);
    for(int k=sz-1;k>0;k--){
      auto& cur=I[k];
      const auto& lft=I[(k<<1)|0];
      const auto& rgh=I[(k<<1)|1];
      cur.resize(lft.size()+rgh.size());
      merge(lft.begin(),lft.end(),rgh.begin(),rgh.end(),cur.begin());
      cur.erase(unique(cur.begin(),cur.end()),cur.end());
      L[k].resize(cur.size()+1);
      R[k].resize(cur.size()+1);
      int tl=0,tr=0;
      for(int i=0;i<(int)cur.size();i++){
        while(tl<(int)lft.size() and lft[tl]<cur[i]) tl++;
        while(tr<(int)rgh.size() and rgh[tr]<cur[i]) tr++;
        L[k][i]=tl;R[k][i]=tr;
      }
      L[k][cur.size()]=lft.size();
      R[k][cur.size()]=rgh.size();
    }
    for(int k=0;k<(int)I.size();k++){
      seg.emplace_back(f,ti);
      seg.back().build(vector<T>(I[k].size(),ti));
    }
  }

  void update(int p,int q,T v,int k,int l,int r){
    if(r<=p||p+1<=l) return;
    if(p<=l&&r<=p+1) return seg[k].set_val(q,v);
    int m=(l+r)>>1;
    update(p,L[k][q],v,(k<<1)|0,l,m);
    update(p,R[k][q],v,(k<<1)|1,m,r);
    T res=ti;
    const auto& cur=I[k];
    const auto& lft=I[(k<<1)|0];
    const auto& rgh=I[(k<<1)|1];
    if(L[k][q]<(int)lft.size() and cur[q]==lft[L[k][q]])
      res=f(res,seg[(k<<1)|0].query(L[k][q],L[k][q]+1));
    if(R[k][q]<(int)rgh.size() and cur[q]==rgh[R[k][q]])
      res=f(res,seg[(k<<1)|1].query(R[k][q],R[k][q]+1));
    seg[k].set_val(q,res);
  }

  void update(index_t p,index_t q,T v){
    update(idx(p,ps),idx(q,I[1]),v,1,0,sz);
  }

  T query(int pa,int pb,int qa,int qb,int k,int l,int r){
    if(r<=pa||pb<=l) return ti;
    if(pa<=l&&r<=pb) return seg[k].query(qa,qb);
    int m=(l+r)>>1;
    return f(query(pa,pb,L[k][qa],L[k][qb],(k<<1)|0,l,m),
             query(pa,pb,R[k][qa],R[k][qb],(k<<1)|1,m,r));
  }

  // [pa, pb) x [qa, qb)
  T query(index_t pa,index_t pb,index_t qa,index_t qb){
    return query(idx(pa,ps),idx(pb,ps),idx(qa,I[1]),idx(qb,I[1]),1,0,sz);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../basic/ushi.cpp"
#include "../../vector/zip.cpp"
#include "../../tools/chminmax.cpp"
#undef call_from_test

signed ABC266_H(){
  int n;
  cin>>n;
  vector<int> ts(n),xs(n),ys(n),as(n);
  for(int i=0;i<n;i++) cin>>ts[i]>>xs[i]>>ys[i]>>as[i];

  {
    auto zs=zip(ys,ts,xs,as);
    sort(zs.begin(),zs.end());
    for(int i=0;i<n;i++) tie(ys[i],ts[i],xs[i],as[i])=zs[i];
  }
  vector<int> bs(n),cs(n);
  for(int i=0;i<n;i++){
    bs[i]=ts[i]-ys[i]+xs[i];
    cs[i]=ts[i]-ys[i]-xs[i];
  }

  using ll = long long;
  auto f=[&](ll a,ll b){return max(a,b);};
  SegmentTree2D<int, SegmentTree<ll>> seg(f,0LL);
  for(int i=0;i<n;i++){
    seg.preupdate(bs[i],cs[i]);
  }
  seg.build();

  ll ans=0;
  for(int i=0;i<n;i++){
    if(ts[i]<xs[i]+ys[i]) continue;
    ll res=as[i]+seg.query(0,bs[i]+1,0,cs[i]+1);
    seg.update(bs[i],cs[i],res);
    chmax(ans,res);
  }
  cout<<ans<<endl;

  return 0;
}
/*
  verified on 2022/08/28
  https://atcoder.jp/contests/abc266/tasks/abc266_h
*/

signed main(){
  ABC266_H();
  return 0;
}
#endif
