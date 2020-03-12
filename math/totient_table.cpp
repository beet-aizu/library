#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
vector<int> totient_table(int n){
  vector<int> ts(n+1);
  iota(ts.begin(),ts.end(),0);
  for(int i=2;i<=n;i++){
    if(ts[i]!=i) continue;
    for(int j=i;j<=n;j+=i) ts[j]=ts[j]/i*(i-1);
  }
  return ts;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
