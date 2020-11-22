// verification-helper: PROBLEM https://yukicoder.me/problems/444

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/fastfouriertransform.cpp"
#include "../../convolution/arbitrarymod.cpp"
#include "../../polynomial/berlekampmassey.cpp"
#include "../../combinatorics/enumeration.cpp"
#include "../../formalpowerseries/base.cpp"
#include "../../formalpowerseries/inv.cpp"
#include "../../formalpowerseries/div.cpp"
#include "../../formalpowerseries/mod.cpp"
#include "../../math/sequence.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using M = Mint<int>;
  using Poly = vector<M>;
  ArbitraryMod<M> arb;
  auto conv=[&](auto as,auto bs){return arb.multiply(as,bs);};

  long long n;
  int p,c;
  cin>>n>>p>>c;

  const int d = 606 * 13;
  auto calc=[&](int l,vector<int> vs){
    int m=vs.size();
    vector<Poly> dp(m,Poly(d));
    for(int i=0;i<m;i++) dp[i][0]=M(1);
    for(int t=0;t<l;t++){
      for(int i=0;i<m;i++){
        for(int j=d-1;j>=0;j--){
          dp[i][j]=0;
          if(i) dp[i][j]+=dp[i-1][j];
          if(j>=vs[i]) dp[i][j]+=dp[i][j-vs[i]];
        }
      }
    }
    return dp.back();
  };

  Poly cf({M(1)});
  cf=conv(cf,calc(p,vector<int>({2,3,5,7,11,13})));
  cf=conv(cf,calc(c,vector<int>({4,6,8,9,10,12})));
  cf.resize(d,M(0));

  Poly dp(d*3,0),as(d*3,0);
  dp[0]=M(1);
  for(int i=0;i<(int)dp.size();i++){
    for(int j=0;j<d&&i+j<(int)dp.size();j++)
      dp[i+j]+=dp[i]*cf[j];

    for(int j=1;j<d&&i+j<(int)dp.size();j++)
      as[i]+=dp[i+j];
  }
  as.resize(d*2);

  Sequence<M> seq(conv);
  cout<<seq.build(as)(n)<<endl;
  return 0;
}
