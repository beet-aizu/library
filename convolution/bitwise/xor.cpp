#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
auto zeta=[](auto& lo,auto& hi){
  auto x=lo+hi,y=lo-hi;
  lo=x;
  hi=y;
};
auto moebius=[](auto& lo,auto& hi){
  auto x=lo+hi,y=lo-hi;
  lo=x/decltype(x)(2);
  hi=y/decltype(y)(2);
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
