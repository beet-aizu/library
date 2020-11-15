// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2981

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../tools/drop.cpp"
#include "../../convolution/bitwise/fwht.cpp"
#include "../../convolution/bitwise/and.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  int sz=1<<n;
  auto as=read(sz);

  auto dp(as);
  fwht(dp,zeta);

  for(int i=0;i<sz;i++){
    if(!as[i]) continue;
    if(dp[i]!=(1<<(n-__builtin_popcount(i)))) drop(-1);
  }

  auto bs(as);
  for(int i=1;i<sz;i<<=1)
    for(int j=0;j<sz;j++)
      if(i&j) if(as[i^j]) bs[j]=0;

  cout<<accumulate(bs.begin(),bs.end(),0)<<endl;
  return 0;
}
