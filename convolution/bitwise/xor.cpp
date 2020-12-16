#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
auto divide_by_two(T x)
  ->enable_if_t<!is_class<T>::value, T>{
  return x/T(2);
}

template<typename T>
auto divide_by_two(T x)
  ->enable_if_t< is_class<T>::value, T>{
  static const T inv = T(2).inv();
  return x*inv;
}
auto zeta=[](auto& lo,auto& hi){
  auto x=lo+hi,y=lo-hi;
  lo=x;
  hi=y;
};
auto moebius=[](auto& lo,auto& hi){
  auto x=lo+hi,y=lo-hi;
  lo=divide_by_two(x);
  hi=divide_by_two(y);
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
