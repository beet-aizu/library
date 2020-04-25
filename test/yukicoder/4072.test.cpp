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
  for(int l=0,r=0;l<n;l++){
    if(as[l]==1){
      ans+=n-l;
      continue;
    }
    if(r<=l) r=l+1;
    while(r<=n and dst.query(l,r)>1) r++;
    ans+=n-r+1;
  }

  cout<<ans<<endl;
  return 0;
}
