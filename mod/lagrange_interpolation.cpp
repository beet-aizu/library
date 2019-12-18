#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#endif
//BEGIN CUT HERE
template<typename M>
M lagrange_interpolation(vector<M> &y,M t){
  int n=y.size()-1;
  if(t.v<=n) return y[t.v];

  vector<M> dp(n+1,1),pd(n+1,1);
  for(int i=0;i<n;i++) dp[i+1]=dp[i]*(t-M(i));
  for(int i=n;i>0;i--) pd[i-1]=pd[i]*(t-M(i));

  vector<M> fact(n+1,1),finv(n+1,1);
  for(int i=1;i<=n;i++) fact[i]=fact[i-1]*M(i);
  finv[n]=M(1)/fact[n];
  for(int i=n;i>=1;i--) finv[i-1]=finv[i]*M(i);

  M res(0);
  for(int i=0;i<=n;i++){
    M tmp=y[i]*dp[i]*pd[i]*finv[i]*finv[n-i];
    if((n-i)&1) res-=tmp;
    else res+=tmp;
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../mod/mint.cpp"
#undef call_from_test

signed ARC033_D(){
  int n;
  scanf("%d",&n);

  using M = Mint<int>;
  vector<M> y(n+1);
  for(int i=0;i<=n;i++) scanf("%d",&y[i].v);

  int t;
  scanf("%d",&t);
  printf("%d\n",lagrange_interpolation(y,M(t)).v);
  return 0;
}
/*
  verified on 2019/12/17
  https://atcoder.jp/contests/arc033/tasks/arc033_4
*/

signed YUKI_042(){
  using M = Mint<int, int(1e9+9)>;
  const int MAX = 666 * 6 + 10;
  vector<M> dp(MAX,0);
  dp[0]=M(1);

  for(int x:{1,5,10,50,100,500})
    for(int j=x;j<MAX;j++) dp[j]+=dp[j-x];

  int T;
  scanf("%d",&T);
  while(T--){
    using ll = long long;
    ll m;
    scanf("%lld",&m);
    vector<M> y(6);
    for(int i=0;i<6;i++) y[i]=dp[(m%500)+(i*500)];
    printf("%d\n",lagrange_interpolation(y,M(m/500)).v);
  }
  return 0;
}
/*
  verified on 2019/12/17
  https://yukicoder.me/problems/no/42
*/

signed main(){
  //ARC033_D();
  //YUKI_042();
  return 0;
}
#endif
