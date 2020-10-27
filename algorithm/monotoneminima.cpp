#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
namespace MonotoneMinima{
  template<typename T,typename F>
  void induce(int l,int r,int a,int b,vector<int> &dp,F dist){
    if(l==r) return;
    int m=(l+r)>>1;
    int &idx=(dp[m]=a);
    T res=dist(m,idx);
    for(int i=a;i<b;i++){
      T tmp=dist(m,i);
      if(tmp<res) res=tmp,idx=i;
    }
    induce<T>(l,m,a,idx+1,dp,dist);
    induce<T>(m+1,r,idx,b,dp,dist);
  }

  // p < q -> argmin f(p, *) < argmin f(q, *)
  template<typename T,typename F>
  vector<int> args(int n,int m,F dist){
    vector<int> dp(n,-1);
    induce<T>(0,n,0,m,dp,dist);
    return dp;
  }
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
