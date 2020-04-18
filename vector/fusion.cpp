#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

//BEGIN CUT HERE
template<typename T, typename ...Ts>
vector<T> fusion(vector<T> bs,Ts... ts){
  auto append=[&](auto vs){for(auto v:vs) bs.emplace_back(v);};
  initializer_list<int>{(void(append(ts)),0)...};
  return bs;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
