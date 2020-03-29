#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct TwoWay{
  T x,y;
  TwoWay(T z=T()):x(z),y(z){}
  TwoWay(T x,T y):x(x),y(y){}
  TwoWay operator+(const TwoWay &o)const{return TwoWay(x+o.x,o.y+y);}
  TwoWay operator*(const TwoWay &o)const{return TwoWay(x*o.x,o.y*y);}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
