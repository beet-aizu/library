// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0402

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../convolution/bitwise/fwht.cpp"
#include "../../convolution/bitwise/xor.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  ll n,k;
  cin>>n>>k;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  const int LOG = 20;
  const int sz = 1<<LOG;
  vector<ll> cnt(sz,0);
  cnt[0]++;
  for(int i=0,s=0;i<n;i++){
    s^=as[i];
    cnt[s]++;
  }

  fwht(cnt,bitwise_xor::zeta);
  for(ll &v:cnt) v=v*v;
  fwht(cnt,bitwise_xor::moebius);

  k--;
  for(int v=sz-1;v>=0;v--){
    cnt[v]/=2;
    if(cnt[v]<=k){
      k-=cnt[v];
      continue;
    }
    cout<<v<<endl;
    break;
  }
  return 0;
}
