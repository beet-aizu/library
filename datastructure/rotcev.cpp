#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// no resize() because it is dangerous
template<typename T>
struct Rotcev{
  vector<T> data;

  size_t size()const{return data.size();};
  bool empty()const{return data.empty();}

  T& operator[](size_t n){return data[size()-1-n];}
  const T& operator[](size_t n)const{return data[size()-1-n];}

  void push_front(T val){data.push_back(val);}
  void pop_front(){data.pop_back();};
  void clear(){data.clear();}

  template<typename... Args>
  Rotcev(Args ...args):data(forward<Args>(args)...){}
  template<typename... Args>
  void emplace_front(Args ...args){data.emplace_back(forward<Args>(args)...);}
  template<typename... Args>
  void assign(Args ...args){data.assign(forward<Args>(args)...);}
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
