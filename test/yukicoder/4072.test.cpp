#define PROBLEM "https://yukicoder.me/problems/4072"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/disjointsparsetable.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  int n;
  cin>>n;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto f=[&](ll a,ll b){return gcd(a,b);};
  DisjointSparseTable<ll> dst(f);
  dst.build(as);

  ll ans=0;
  for(int i=0;i<n;i++){
    int l=i;
    ll pre=as[i],lst=dst.query(i,n);
    while(lst!=pre){
      int r=n,pl=l;
      while(l+1<r){
        int m=(l+r)>>1;
        if(dst.query(i,m)!=pre) r=m;
        else l=m;
      }
      if(pre==1) ans+=l-pl;
      pre=dst.query(i,r);
    }
    if(lst==1) ans+=n-l;
  }

  cout<<ans<<endl;
  return 0;
}
