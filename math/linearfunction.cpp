#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// a * x + b
template<typename T>
struct LinearFunction{
  T a,b;
  LinearFunction():a(0),b(0){}
  LinearFunction(T a,T b):a(a),b(b){}

  using LF = LinearFunction;
  static LF add_identity(){return LF(T(0),T(0));}
  static LF mul_identity(){return LF(T(1),T(0));}
  LF& operator+=(const LF &o){
    a+=o.a;b+=o.b;
    return *this;
  }
  LF& operator*=(const LF &o){
    a=a*o.a;
    b=b*o.a+o.b;
    return *this;
  }
  LF operator+(const LF &o)const{return LF(*this)+=o;}
  LF operator*(const LF &o)const{return LF(*this)*=o;}

  T operator()(T x) const{return a*x+b;}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
