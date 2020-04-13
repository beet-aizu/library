#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct CumulativeSum{
  vector<T> sm;
  CumulativeSum(const vector<T> &as){
    int n=as.size();
    sm.resize(n+1);
    sm[0]=T();
    for(int i=0;i<n;i++)
      sm[i+1]=sm[i]+as[i];
  }
  // [l, r)
  T query(int l,int r){return -sm[l]+sm[r];}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
