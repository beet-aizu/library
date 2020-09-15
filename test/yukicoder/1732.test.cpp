#define PROBLEM "https://yukicoder.me/problems/1732"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../vector/compress.cpp"
#include "../../datastructure/waveletmatrix.cpp"
#include "../../datastructure/binaryindexedtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  int n,k;
  cin>>n>>k;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto vx=compress(as);
  auto mx=dict(vx);

  BIT<ll> bit1(n+10),bit2(n+10);

  ll ans=1e18,sum=0;
  for(int i=0;i<k;i++){
    bit1.add(mx[as[i]],1);
    bit2.add(mx[as[i]],as[i]);
    sum+=as[i];
  }

  WaveletMatrix<int, 30> wm(as);
  for(int i=0;i+k<=n;i++){
    int j=i+k;
    int x=wm.quantile(i,j,k>>1);

    ll p=bit1.sum(mx[x]),q=k-p;
    ll s=bit2.sum(mx[x]);
    chmin(ans,p*x-s+(sum-s)-q*x);

    bit1.add(mx[as[i]],-1);
    bit2.add(mx[as[i]],-as[i]);
    sum-=as[i];

    if(j==n) continue;
    bit1.add(mx[as[j]],1);
    bit2.add(mx[as[j]],as[j]);
    sum+=as[j];
  }

  cout<<ans<<endl;
  return 0;
}
