#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
namespace OnlineOffline{
  vector<int> used;

  template<typename T>
  void update(vector<T> &dp,int k,T val){
    if(!used[k]) dp[k]=val;
    dp[k]=min(dp[k],val);
    used[k]=1;
  }

  // [l, r), [a, b]
  template<typename T,typename F>
  void induce(int l,int r,int a,int b,vector<T> &dp,F dist){
    if(l==r) return;
    int m=(l+r)>>1;
    assert(m<a);
    int idx=a;
    T res=dist(m,idx-1)+dp[idx];
    for(int i=a;i<=b;i++){
      T tmp=dist(m,i-1)+dp[i];
      if(tmp<res) res=tmp,idx=i;
    }
    update(dp,m,res);
    induce(l,m+0,a,idx,dp,dist);
    induce(m+1,r,idx,b,dp,dist);
  }

  template<typename T,typename F>
  void solve(int l,int r,vector<T> &dp,F dist){
    if(l+1==r) return update(dp,l,dist(l,l)+dp[r]);
    int m=(l+r)>>1;
    solve(m,r,dp,dist);
    induce(l,m,m,r,dp,dist);
    solve(l,m,dp,dist);
  }

  // dp[i] = min_{i<j} dist(i,j-1) + dp[j]
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
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
