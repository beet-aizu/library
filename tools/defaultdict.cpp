#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Key,typename T>
struct DefaultDict : map<Key, T>{
  using super = map<Key, T>;
  const T val;
  DefaultDict(T val_):val(val_){}
  T& operator[](const Key& key){
    if(!super::count(key))
      super::operator[](key)=val;
    return super::operator[](key);
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
