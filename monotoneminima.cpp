#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T>
struct MonotoneMinima{
  using F = function<T(int, int)>;
  int n;
  F dist;
  T INF;
  vector<T> dp;

  // dist(i,l) + dist(j,k) >= dist(i,k) + dist(j,l)
  // if( i<=j && k<=l )
  MonotoneMinima(int n,F dist,T INF):
    n(n),dist(dist),INF(INF),dp(n+1,INF){}

  void dfs(int l,int r,int a,int b){
    if(l==r) return;
    int m=(l+r)>>1;
    T ma=INF;
    int mi=-1;
    for(int i=a;i<b;i++){
      T tmp=dp[i+1]+dist(i,m);
      if(tmp<ma) ma=tmp,mi=i;
    }
    dp[m]=min(dp[m],ma);
    dfs(l,m,a,mi+1);
    dfs(m+1,r,mi,b);
  }
  
  void solve(int l,int r){
    if(l+1==r){
      dp[l]=min(dp[l],dp[r]+dist(l,l));
      return;
    }
    int m=(l+r)>>1;
    solve(m,r);
    dfs(l,m,m,r);
    solve(l,m);
  }

  T solve(){
    dp[n]=0;
    solve(0,n);
    return dp[0];
  }
};
//END CUT HERE
//INSERT ABOVE HERE

signed YUKI_703(){
  int n;
  cin>>n;
  vector<Int> a(n),x(n),y(n);
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>x[i];
  for(int i=0;i<n;i++) cin>>y[i];

  auto dist=
    [&](int i,int j)->Int{
      Int s=abs(a[i]-x[j]);
      Int t=abs(y[j]);
      return s*s+t*t;
    };

  const Int INF = 1e18;
  MonotoneMinima<Int> monge(n,dist,INF);
  
  cout<<monge.solve()<<endl;
  return 0;
}
/*
  verified on 2018/06/21
  https://yukicoder.me/problems/no/703
*/

signed YUKI_704(){
  int n;
  cin>>n;
  vector<Int> a(n),x(n),y(n);
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>x[i];
  for(int i=0;i<n;i++) cin>>y[i];

  auto dist=
    [&](int i,int j)->Int{
      Int s=abs(a[i]-x[j]);
      Int t=abs(y[j]);
      return s+t;
    };

  const Int INF = 1e18;
  MonotoneMinima<Int> monge(n,dist,INF);
  
  cout<<monge.solve()<<endl;
  return 0;
}
/*
  verified on 2018/06/21
  https://yukicoder.me/problems/no/704
*/

signed YUKI_705(){
  int n;
  cin>>n;
  vector<Int> a(n),x(n),y(n);
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>x[i];
  for(int i=0;i<n;i++) cin>>y[i];

  auto dist=
    [&](int i,int j)->Int{
      Int s=abs(a[i]-x[j]);
      Int t=abs(y[j]);
      return s*s*s+t*t*t;
    };

  const Int INF = 1e18;
  MonotoneMinima<Int> monge(n,dist,INF);
  
  cout<<monge.solve()<<endl;
  return 0;
}
/*
  verified on 2018/06/21
  https://yukicoder.me/problems/no/705
*/


signed main(){
  YUKI_703();
  //YUKI_704();
  //YUKI_705();
  return 0;
}
