#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// find (x, y) s.t. ax + by = gcd(a, b), minimize |x| + |y|
// |x| <= b, |y| <= a
// return gcd(a, b)
template<typename T>
T extgcd(T a,T b,T& x,T& y){
  T d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}
template<typename T>
pair<T, T> extgcd(T a,T b){
  T x,y;
  extgcd(a,b,x,y);
  return make_pair(x,y);
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
