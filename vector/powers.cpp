#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

//BEGIN CUT HERE
// [0, n]
template<typename T>
vector<T> powers(int n,T x){
  vector<T> po(n+1,T(1));
  for(int i=0;i<n;i++) po[i+1]=po[i]*x;
  return po;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
