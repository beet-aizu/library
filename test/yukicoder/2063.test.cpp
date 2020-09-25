#define PROBLEM "https://yukicoder.me/problems/2063"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../segtree/count/dynamic_offline.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,m;
  cin>>n>>m;
  vector<int> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];

  RangeCount<int, int> seg(m);
  for(int i=0;i<n;i++){
    if(as[i]>bs[i]) swap(as[i],bs[i]);
    seg.preupdate(as[i],bs[i]);
  }
  seg.build();

  long long ans=0;
  for(int i=0;i<n;i++){
    ans+=seg.query(0,as[i],as[i],bs[i]);
    ans+=seg.query(as[i],bs[i],bs[i],m);
    seg.update(as[i],bs[i],1);
  }

  cout<<ans<<newl;
  return 0;
}
