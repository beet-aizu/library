#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
int chromatic(vector< vector<int> > G){
  int n=G.size();
  if(n==0) return 0;
  assert(n<=30);

  vector<int> es(n,0);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      es[i]|=G[i][j]<<j;

  int s=1<<n;
  vector<int> dp(s);
  for(int b=0;b<s;b++)
    dp[b]=((n-__builtin_popcount(b))&1?-1:1);

  auto calc=
    [&](const int MOD){
      vector<int> res(s);
      res[0]=1;
      for(int b=1;b<s;b++){
        int ctz=__builtin_ctz(b);
        res[b]=res[b-(1<<ctz)]+res[(b-(1<<ctz))&~es[ctz]];
        if(res[b]>=MOD) res[b]-=MOD;
      }
      return res;
    };

  constexpr int MOD1 = 1077563119;
  constexpr int MOD2 = 1e9+7;
  vector<int> ind1=calc(MOD1);
  vector<int> ind2=calc(MOD2);

  using ll = long long;
  vector<int> dp1=dp,dp2=dp;
  for(int i=1;i<n;i++){
    ll sum1=0,sum2=0;
    for(int b=0;b<s;b++){
      dp1[b]=((ll)dp1[b]*ind1[b])%MOD1;
      sum1+=dp1[b];

      dp2[b]=((ll)dp2[b]*ind2[b])%MOD2;
      sum2+=dp2[b];
    }
    if(sum1%MOD1!=0) return i;
    if(sum2%MOD2!=0) return i;
  }
  return n;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
#endif
