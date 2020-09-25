// verification-helper: PROBLEM https://yukicoder.me/problems/1950

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../algorithm/onlineoffline.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;

  int n;
  cin>>n;
  auto as=read<ll>(n);
  auto xs=read<ll>(n);
  auto ys=read<ll>(n);

  auto dist=
    [&](int i,int j)->ll{
      ll s=abs(xs[i]-as[j-1]);
      ll t=abs(ys[i]);
      return s+t;
    };

  cout<<OfflineOnline::solve<ll>(n,dist)<<endl;
  return 0;
}
