#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2294"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/precision.cpp"
#include "../../vector/multi.cpp"
#undef call_from_test

#define ERROR "1e-6"

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using D = long double;
  int h,n,p,m,k;
  cin>>h>>n>>p>>m>>k;
  p--;

  vector<int> bs(h,-1);
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    bs[h-x]=y-1;
  }

  auto dp=make_v<D>(h+1,k+1,n+1);
  fill_v<D>(dp,0);

  dp[0][0][p]=1;
  for(int i=0;i<h;i++){
    for(int j=0;j<=k;j++){
      if(~bs[i]){
        swap(dp[i][j][bs[i]],dp[i][j][bs[i]+1]);
        for(int l=0;l<n;l++) dp[i+1][j][l]+=dp[i][j][l];
        continue;
      }
      for(int l=0;l<n;l++) dp[i+1][j][l]+=dp[i][j][l];
      if(j+1>k) continue;
      for(int l=0;l<n;l++){
        D x=0.0;
        if(l+1<n)  dp[i+1][j+1][l+1]+=dp[i][j][l]/(n-1.0),x+=1.0;
        if(l-1>=0) dp[i+1][j+1][l-1]+=dp[i][j][l]/(n-1.0),x+=1.0;
        dp[i+1][j+1][l]+=dp[i][j][l]*(n-1.0-x)/(n-1.0);
      }
    }
  }

  D ans=*max_element(dp[h][k].begin(),dp[h][k].end());
  for(int i=0;i<k;i++){
    ans/=(h-m-i);
    ans*=(i+1);
  }
  cout<<ans<<endl;
  return 0;
}
