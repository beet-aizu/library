#include<bits/stdc++.h>
using namespace std;

//BEGIN CUT HERE
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T,typename U> 
using gmap = cc_hash_table<T, U, hash<T> >;
//END CUT HERE

//INSERT ABOVE HERE
signed AGC023_A(){
  using ll = long long;
  int n;
  scanf("%d",&n);
  vector<ll> a(n);
  for(int i=0;i<n;i++) scanf("%lld",&a[i]);

  gmap<ll, ll> m;
  ll ans=0,s=0;
  m[s]++;
  for(int i=0;i<n;i++){
    s+=a[i];
    ans+=m[s];
    m[s]++;
  }

  printf("%lld\n",ans);
  return 0;
}

signed main(){
  AGC023_A();
  return 0;
}
