#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3024"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../segtree/persistent/ushi.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<int> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<n;i++) cin>>bs[i];

  auto f=[](int a,int b){return min(a,b);};
  int ti=INT_MAX;
  SegmentTree<int> seg(f,ti);
  auto ra=seg.build(as);
  auto rb=seg.build(bs);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int x,y,z;
    cin>>x>>y>>z;
    y--;
    if(x==1) ra=seg.set_val(ra,y,z);
    if(x==2) rb=seg.set_val(rb,y,z);
    if(x==3) cout<<seg.query(ra,y,z)<<"\n";
    if(x==4) cout<<seg.query(rb,y,z)<<"\n";
    if(x==5) ra=seg.clone(rb);
    if(x==6) rb=seg.clone(ra);
  }
  cout<<flush;
  return 0;
}
