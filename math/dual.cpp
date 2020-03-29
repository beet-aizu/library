#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct Dual{
  T v;
  Dual(T v=T()):v(v){}
  Dual operator+(const Dual &o)const{return Dual(o.v+v);}
  Dual operator*(const Dual &o)const{return Dual(o.v*v);}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
