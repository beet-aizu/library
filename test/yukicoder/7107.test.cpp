// verification-helper: PROBLEM https://yukicoder.me/problems/7107

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../math/moebius.cpp"
#include "../../convolution/divisor.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  using M = Mint<int, 998244353>;
  vector<M> emp(n+1,0),way(n+1,0);
  M cnt{0};
  M all{0};

  auto sign=moebius(n);
  using ll = long long;
  for(int i=1;i<=n;i++){
    emp[i]=M((ll)sign[i])*M(1).pow(n/i);
    way[i]=M((ll)sign[i])*M(2).pow(n/i);
    cnt+=emp[i];
    all+=way[i];
  }

  LCMConvolution::zeta(way);
  LCMConvolution::zeta(emp);

  vector<M> dp0(n+1,0),dp1(n+1,0),dp2(n+1,0);
  for(int i=1;i<=n;i++){
    dp0[i]=emp[i]*emp[i];
    dp1[i]=emp[i]*way[i];
    dp2[i]=way[i]*way[i];
  }

  LCMConvolution::moebius(dp0);
  LCMConvolution::moebius(dp1);
  LCMConvolution::moebius(dp2);

  M ans=(all-cnt)*(all-cnt);
  M cof=M(3)/M(4);
  for(int i=1;i<=n;i++){
    ans+=dp0[i];
    ans-=dp1[i]*M(2);
    ans+=dp2[i]*cof.pow(n/i);

    ans-=dp0[i];
    ans+=dp1[i]*M(2);
    ans-=dp2[i];
  }

  cout<<ans<<endl;
  return 0;
}
