#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

//BEGIN CUT HERE
template<typename T>
decltype(auto) runlength(vector<T> vs){
  vector<pair<T, int>> es;
  for(auto v:vs){
    if(es.empty() or es.back().first!=v)
      es.emplace_back(v,0);
    es.back().second++;
  }
  return es;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
