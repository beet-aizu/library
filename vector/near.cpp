#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#endif
//BEGIN CUT HERE
template<typename T>
vector<T> add(vector<T> vs,vector<T> as){
  assert(vs.size()==as.size());
  for(int i=0;i<(int)vs.size();i++) vs[i]+=as[i];
  return vs;
}

template<typename T, typename U>
vector<T> add(vector<T> vs,U a){
  return add(vs,vector<T>(vs.size(),a));
}

template<typename T>
vector<T> mul(vector<T> vs,vector<T> as){
  assert(vs.size()==as.size());
  for(int i=0;i<(int)vs.size();i++) vs[i]*=as[i];
  return vs;
}

template<typename T, typename U>
vector<T> mul(vector<T> vs,U a){
  return mul(vs,vector<T>(vs.size(),a));
}

template<typename T, typename ...Ts>
vector<T> near(vector<T> vs,Ts... ts){
  vector<T> rs;
  rs.reserve(vs.size()*sizeof...(ts));
  auto append=[&](auto a){
    for(auto w:add(vs,a)) rs.emplace_back(w);
  };
  initializer_list<int>{(void(append(ts)),0)...};
  return rs;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
