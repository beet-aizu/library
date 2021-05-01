#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../datastructure/binaryindexedtree.cpp"
#undef call_from_test

#endif

//BEGIN CUT HERE
template<typename T>
long long inversion(vector<T> vs){
  int n=vs.size();
  long long res=0;
  BIT<T> bit(n);
  for(T v:vs){
    assert(v<=n);
    res+=bit.query(v+1,n+1);
    bit.add(v,1);
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
