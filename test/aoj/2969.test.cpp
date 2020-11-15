// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2969

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../segtree/basic/ushi.cpp"
#include "../../vector/compress.cpp"
#include "../../vector/fusion.cpp"
#include "../../vector/near.cpp"
#include "../../vector/sorted.cpp"
#include "../../vector/zip.cpp"
#undef call_from_test


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n;
  ll lim;
  cin>>n>>lim;
  vector<ll> ls(n),rs(n);
  for(int i=0;i<n;i++) cin>>ls[i]>>rs[i];

  auto dc=dict(compress(fusion(near(ls,0,1),near(rs,-1,0))));
  int m=dc.size();

  auto f=[&](int a,int b){return min(a,b);};
  SegmentTree<int> seg(f,n+3);
  seg.build(vector<int>(m,n+2));
  seg.set_val(dc[0],0);

  int res=n;
  for(auto[r,l]:sorted(zip(rs,ls))){
    int val=seg.query(dc[l],dc[r])+1;
    chmin(val,seg.query(dc[r],dc[r]+1));
    seg.set_val(dc[r],val);
    if(r==lim) chmin(res,val);
  }
  cout<<res<<' ';

  vector<int> sm(m,0);
  for(int i=0;i<n;i++){
    sm[dc[ls[i]]]++;
    sm[dc[rs[i]]]--;
  }
  for(int i=0;i+1<m;i++) sm[i+1]+=sm[i];

  cout<<n-*min_element(sm.begin()+dc[0],sm.begin()+dc[lim])+1<<endl;
  return 0;
}
