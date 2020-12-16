#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
// https://kazuma8128.hatenablog.com/entry/2018/05/31/144519
//BEGIN CUT HERE
// O(n \log n)
template<typename T, typename F>
void fwht(vector<T> &as,F f){
  int n=as.size();
  for(int d=1;d<n;d<<=1)
    for(int m=d<<1,i=0;i<n;i+=m)
      for(int j=0;j<d;j++)
        f(as[i+j],as[i+j+d]);
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
