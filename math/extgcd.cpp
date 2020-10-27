#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// find (x, y) s.t. ax + by = gcd(a, b)
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
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
