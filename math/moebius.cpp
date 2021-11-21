#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// [0, n]
vector<int> moebius(int n){
  n++;
  vector<int> pr(n),sq(n);
  using ll = long long;
  for(ll i=2;i<n;i++){
    if(pr[i]) continue;
    for(ll j=i;j<n;j+=i) pr[j]=i;
    for(ll j=i*i;j<n;j+=i*i) sq[j]=1;
  }
  vector<int> sign(n,0);
  sign[1]=1;
  for(ll i=2;i<n;i++){
    if(sq[i]) continue;
    sign[i]=-sign[i/pr[i]];
  }
  return sign;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
