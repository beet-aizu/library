#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
// f(i,l) + f(j,k) >= f(i,k) + f(j,l) (i <= j, k <= l)
template<typename T, typename F>
T KnuthYao(int n,F cost){
  vector< vector<T> > dp(n,vector<T>(n));
  vector< vector<int> > ar(n,vector<int>(n));
  for(int i=0;i<n;i++) dp[i][i]=T(0),ar[i][i]=i;
  for(int w=1;w<n;w++){
    for(int i=0;i+w<n;i++){
      int j=i+w;
      int p=ar[i][j-1],q=ar[i+1][j];
      dp[i][j]=dp[i][p]+dp[p+1][j]+cost(i,p,j);
      ar[i][j]=p;
      for(int k=p;k<=q&&k+1<=j;k++){
        T res=dp[i][k]+dp[k+1][j]+cost(i,k,j);
        if(res<dp[i][j]) dp[i][j]=res,ar[i][j]=k;
      }
    }
  }
  return dp[0][n-1];
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed KUPC2012_J(){
  using ll = long long;
  int n;
  cin>>n;
  vector<ll> ws(n);
  for(int i=0;i<n;i++) cin>>ws[i];
  vector<ll> sm(n+1);
  for(int i=0;i<n;i++) sm[i+1]=sm[i]+ws[i];
  auto cost=[&](int i,int k,int j){(void) k;return sm[j+1]-sm[i];};
  cout<<KnuthYao<ll>(n,cost)<<endl;
  return 0;
}
/*
  verified on 2019/10/29
  https://atcoder.jp/contests/kupc2012/tasks/kupc2012_10
*/

signed main(){
  KUPC2012_J();
  return 0;
}
#endif
