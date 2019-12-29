#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0422"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/drop.cpp"
#include "../../mod/rint.cpp"
#undef call_from_test

signed main(){

  int n,k,m;
  cin>>n>>k>>m;

  using R = Rint<int>;
  R::set_mod(m);
  if(n>k*2) drop(R(k).pow(n));

  int sz=1<<(k*2-1);
  vector< vector<R> > dp(k,vector<R>(sz,0));
  for(int i=0;i<k;i++) dp[i][0]=1;

  R ans=R(k).pow(n);
  for(int bit=0;bit<sz;bit++){
    for(int i=0;i<k;i++){
      if(dp[i][bit]==0) continue;
      if(__builtin_popcount(bit)+1==n){
        ans-=dp[i][bit];
      }
      for(int j=0;j<k;j++){
        int d=(i-j)+(k-1);
        if((bit>>d)&1) continue;
        dp[j][bit|(1<<d)]+=dp[i][bit];
      }
    }
  }

  cout<<ans<<endl;
  return 0;
}
