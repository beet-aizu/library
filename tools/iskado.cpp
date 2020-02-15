#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
bool is_kado(T a,T b,T c){
  if(a==b||b==c||c==a) return 0;
  if(a<b&&b>c) return 1;
  if(a>b&&b<c) return 1;
  return 0;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
