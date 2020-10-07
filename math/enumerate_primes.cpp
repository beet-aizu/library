#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// O(n)
vector<int> enumerate_primes(int n){
  vector<bool> dp((n+1)/2,false);
  vector<int> ps;
  ps.reserve(n/10);
  if(2<=n) ps.emplace_back(2);
  for(int i=3;i<=n;i+=2){
    if(!dp[i/2]) ps.emplace_back(i);
    for(int j=1;i*ps[j]<=n;j++){
      dp[i*ps[j]/2]=1;
      if(i%ps[j]==0) break;
    }
  }
  return ps;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
