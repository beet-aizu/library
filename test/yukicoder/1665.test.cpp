// verification-helper: PROBLEM https://yukicoder.me/problems/1665

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/totient_table.cpp"
#include "../../mod/mint.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  auto ts=totient_table(n/m+1);

  using M = Mint<int>;

  M ans{0};
  for(int i=2;i<=n/m;i++) ans+=M(ts[i]*2);
  for(int i=1;i<=n-2;i++) ans*=M(i);
  cout<<ans<<endl;
  return 0;
}
