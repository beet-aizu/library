#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct cc_hash{
  uint64_t operator()(T x) const{
    uint64_t y(x);
    y += 0x9e3779b97f4a7c15;
    y = (y ^ (y >> 30)) * 0xbf58476d1ce4e5b9;
    y = (y ^ (y >> 27)) * 0x94d049bb133111eb;
    return y ^ (y >> 31);
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
