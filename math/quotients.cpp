#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// split [1, n] into ranges whose elements have same quotients
template<typename T>
decltype(auto) quotients(T n){
  vector<pair<T, T>> vp;
  T m;
  for(m=1;m*m<=n;m++) vp.emplace_back(m,m);
  for(T i=m;i>=1;i--){
    T l=n/(i+1)+1,r=n/i;
    if(l<=r and vp.back().second<l)
      vp.emplace_back(l,r);
  }
  return vp;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
