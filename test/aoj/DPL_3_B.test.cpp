// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../algorithm/largestrectangle.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int h,w;
  cin>>h>>w;

  vector< vector<int> > cs(h,vector<int>(w));
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin>>cs[i][j];

  int res=0;
  vector<int> dp(w,0);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)
      dp[j]=cs[i][j]==0?dp[j]+1:0;
    chmax(res,largestrectangle(dp));
  }

  cout<<res<<endl;
  return 0;
}
