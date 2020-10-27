#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
T largestrectangle(vector<T> &v){
  int n=v.size();
  T res=0;
  using P = pair<int, T>;
  stack<P> sp;
  sp.emplace(-1,T(0));
  for(int i=0;i<n;i++){
    int j=i;
    while(sp.top().second>v[i]){
      j=sp.top().first;
      res=max(res,(i-j)*sp.top().second);
      sp.pop();
    }
    if(sp.top().second<v[i]) sp.emplace(j,v[i]);
  }
  while(!sp.empty()){
    res=max(res,(n-sp.top().first)*sp.top().second);
    sp.pop();
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
