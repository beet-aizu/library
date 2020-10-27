#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

//BEGIN CUT HERE
template<typename TV, const int N> void read_tuple_impl(TV&) {}
template<typename TV, const int N, typename Head, typename... Tail>
void read_tuple_impl(TV& ts) {
  get<N>(ts).emplace_back(*(istream_iterator<Head>(cin)));
  read_tuple_impl<TV, N+1, Tail...>(ts);
}
template<typename... Ts> decltype(auto) read_tuple(size_t n) {
  tuple<vector<Ts>...> ts;
  for(size_t i=0;i<n;i++) read_tuple_impl<decltype(ts), 0, Ts...>(ts);
  return ts;
}
//END CUT HERE

#ifndef call_from_test
signed main(){
  return 0;
}
#endif
