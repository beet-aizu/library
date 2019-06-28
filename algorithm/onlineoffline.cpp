#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
namespace OnlineOffLine{
  vector<int> used;

  template<typename T,typename F>
  void induce(int l,int r,int a,int b,vector<T> &dp,F dist){
    if(l==r) return;
    int m=(l+r)>>1;
    int idx=a;
    T res=dp[idx+1]+dist(idx,m);
    for(int i=a;i<b;i++){
      T tmp=dp[i+1]+dist(i,m);
      if(tmp<res) res=tmp,idx=i;
    }
    if(!used[m]) dp[m]=res,used[m]=1;
    else dp[m]=min(dp[m],res);
    induce(l,m,a,idx+1,dp,dist);
    induce(m+1,r,idx,b,dp,dist);
  }

  template<typename T,typename F>
  void solve(int l,int r,vector<T> &dp,F dist){
    if(l+1==r){
      if(!used[l]) dp[l]=dp[r]+dist(l,l),used[l]=1;
      else dp[l]=min(dp[l],dp[r]+dist(l,l));
      return;
    }
    int m=(l+r)>>1;
    solve(m,r,dp,dist);
    induce(l,m,m,r,dp,dist);
    solve(l,m,dp,dist);
  }

  template<typename T,typename F>
  T solve(int n,F dist){
    vector<T> dp(n+1,0);
    used.assign(n+1,0);
    used[n]=1;
    solve(0,n,dp,dist);
    return dp[0];
  }
};
//END CUT HERE
//INSERT ABOVE HERE
using ll = long long;
signed YUKI_703(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<ll> as(n),xs(n),ys(n);
  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<n;i++) cin>>xs[i];
  for(int i=0;i<n;i++) cin>>ys[i];

  auto dist=
    [&](int i,int j)->ll{
      ll s=abs(as[i]-xs[j]);
      ll t=abs(ys[j]);
      return s*s+t*t;
    };

  cout<<OnlineOffLine::solve<ll>(n,dist)<<endl;
  return 0;
}
/*
  verified on 2019/06/28
  https://yukicoder.me/problems/no/703
*/

signed YUKI_704(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<ll> as(n),xs(n),ys(n);
  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<n;i++) cin>>xs[i];
  for(int i=0;i<n;i++) cin>>ys[i];

  auto dist=
    [&](int i,int j)->ll{
      ll s=abs(as[i]-xs[j]);
      ll t=abs(ys[j]);
      return s+t;
    };

  cout<<OnlineOffLine::solve<ll>(n,dist)<<endl;
  return 0;
}
/*
  verified on 2019/06/28
  https://yukicoder.me/problems/no/704
*/

signed YUKI_705(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<ll> as(n),xs(n),ys(n);
  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<n;i++) cin>>xs[i];
  for(int i=0;i<n;i++) cin>>ys[i];

  auto dist=
    [&](int i,int j)->ll{
      ll s=abs(as[i]-xs[j]);
      ll t=abs(ys[j]);
      return s*s*s+t*t*t;
    };

  cout<<OnlineOffLine::solve<ll>(n,dist)<<endl;
  return 0;
}
/*
  verified on 2019/06/28
  https://yukicoder.me/problems/no/705
*/


signed main(){
  //YUKI_703();
  //YUKI_704();
  //YUKI_705();
  return 0;
}
