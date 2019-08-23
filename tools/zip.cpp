#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
template<typename ...Ts>
decltype(auto) zip(vector<Ts>... args){
  vector<decltype(make_tuple(args[0]...))> res;
  int n=min({args.size()...});
  res.reserve(n);
  for(int i=0;i<n;i++) res.emplace_back(args[i]...);
  return res;
}
//END CUT HERE
signed main(){
  vector<int> as({1,2,3});
  vector<string> bs({"a","b","c"});
  auto zs=zip(as,bs);
  for(auto [x,y]:zs) cout<<x<<" "<<y<<endl;
  return 0;
}
