#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
decltype(auto) naive(){
  using Poly = vector<T>;
  auto conv=[](Poly as, Poly bs){
    Poly cs(as.size()+bs.size()-1,0);
    for(int i=0;i<(int)as.size();i++)
      for(int j=0;j<(int)bs.size();j++)
        cs[i+j]+=as[i]*bs[j];
    return cs;
  };
  return +conv;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
