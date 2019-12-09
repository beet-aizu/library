#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T,typename U>
using gmap = cc_hash_table<T, U, hash<T> >;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed AGC023_A(){
  using ll = long long;
  int n;
  scanf("%d",&n);
  vector<ll> as(n);
  for(int i=0;i<n;i++) scanf("%lld",&as[i]);

  gmap<ll, ll> mp;
  ll ans=0,sum=0;
  mp[sum]++;
  for(int i=0;i<n;i++){
    sum+=as[i];
    ans+=mp[sum];
    mp[sum]++;
  }

  printf("%lld\n",ans);
  return 0;
}
/*
  verified on 2019/12/09
  https://atcoder.jp/contests/agc023/tasks/agc023_a
*/

signed main(){
  AGC023_A();
  return 0;
}
#endif
