#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T, typename U, typename V>
struct trio{
  T first;
  U second;
  V third;
  trio(T first,U second,V third):
    first(first),second(second),third(third){}
  operator tuple<T&, U&, V&>(){
    return forward_as_tuple(first,second,third);
  }
  using X = tuple<T, U, V>;
  operator X() const{return make_tuple(first,second,third);}
  bool operator==(const trio&a) const{return (X)(*this)==(X)a;}
  bool operator!=(const trio&a) const{return (X)(*this)!=(X)a;}
  bool operator< (const trio&a) const{return (X)(*this)< (X)a;}
  bool operator<=(const trio&a) const{return (X)(*this)<=(X)a;}
  bool operator> (const trio&a) const{return (X)(*this)> (X)a;}
  bool operator>=(const trio&a) const{return (X)(*this)>=(X)a;}
};
template<typename T, typename U, typename V>
trio<T, U, V> make_trio(T first,U second,V third){
  return trio<T, U, V>(first,second,third);
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
