#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
namespace MonotoneMinima{
  template<typename T,typename F>
  void induce(int l,int r,int a,int b,vector<int> &dp,F dist){
    if(l==r) return;
    int m=(l+r)>>1;
    int &idx=(dp[m]=a);
    T res=dist(idx,m);
    for(int i=a;i<b;i++){
      T tmp=dist(i,m);
      if(tmp<res) res=tmp,idx=i;
    }
    induce<T>(l,m,a,idx+1,dp,dist);
    induce<T>(m+1,r,idx,b,dp,dist);
  }

  template<typename T,typename F>
  vector<int> args(int n,F dist){
    vector<int> dp(n,-1);
    induce<T>(0,n,0,n,dp,dist);
    return dp;
  }
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed COLOPL2018FINAL_C(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n;
  cin>>n;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto dist=[&](int i,int j){return as[i]+(ll)(i-j)*(i-j);};
  auto res=MonotoneMinima::args<ll>(n,dist);

  for(int i=0;i<n;i++) cout<<dist(res[i],i)<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/28
  https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
*/
signed main(){
  //COLOPL2018FINAL_C();
  return 0;
}
#endif
