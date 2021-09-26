#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename SegmentTree>
struct SegmentTree2D{
  using F = typename SegmentTree::F;
  using T = typename F::result_type;
  const F f;
  const T ti;
  SegmentTree2D(F f_,T ti_):f(f_),ti(ti_){}

  vector<pair<int, int>> vp;
  void preupdate(int p,int q){
    vp.emplace_back(p,q);
  }

  void compress(vector<int> &vs){
    sort(vs.begin(),vs.end());
    vs.erase(unique(vs.begin(),vs.end()),vs.end());
  }

  int idx(int v,const vector<int> &vs){
    return lower_bound(vs.begin(),vs.end(),v)-vs.begin();
  }

  int sz;
  vector<int> ps;
  vector<vector<int>> I,L,R;
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
      auto& cur=I[k],lft=I[(k<<1)|0],rgh=I[(k<<1)|1];
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
    const auto& cur=I[k],lft=I[(k<<1)|0],rgh=I[(k<<1)|1];
    if(L[k][q]<(int)lft.size() and cur[q]==lft[L[k][q]])
      res=f(res,seg[(k<<1)|0].query(L[k][q],L[k][q]+1));
    if(R[k][q]<(int)rgh.size() and cur[q]==rgh[R[k][q]])
      res=f(res,seg[(k<<1)|1].query(R[k][q],R[k][q]+1));
    seg[k].set_val(q,res);
  }

  void update(int p,int q,T v){
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
  T query(int pa,int pb,int qa,int qb){
    return query(idx(pa,ps),idx(pb,ps),idx(qa,I[1]),idx(qb,I[1]),1,0,sz);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../basic/ushi.cpp"
#include "../../tools/chminmax.cpp"
#undef call_from_test

signed ACPC2021DAY2_H(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  map<pair<int, int>, int> mp;
  for(int i=0;i<m;i++){
    int y,x,a;
    cin>>y>>x>>a;
    mp[{y,x}]=a;
  }

  const int INF = 1e9+7;
  using P = pair<int, int>;
  auto f1=[&](int a,int b){return min(a,b);};
  auto f2=[&](int a,int b){return a+b;};
  auto f=[&](P a,P b){return P(f1(a.first,b.first),f2(a.second,b.second));};

  SegmentTree2D<SegmentTree<P>> seg(f,P(INF,0));

  for(auto[pos,a]:mp){
    auto[y,x]=pos;
    seg.preupdate(y,x);
  }
  seg.build();

  for(auto[pos,a]:mp){
    auto[y,x]=pos;
    seg.update(y,x,P(a,1));
  }

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    using ll = long long;
    ll u,d,l,r;
    cin>>u>>d>>l>>r;
    d++;r++;
    P res=seg.query(u,d,l,r);
    ll num=(d-u)*(r-l);
    if(res.second<num) chmin(res.first,0);
    cout<<res.first<<'\n';
  }
  return 0;
}

signed main(){
  ACPC2021DAY2_H();
  return 0;
}
#endif
