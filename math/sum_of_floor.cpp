#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// sum_{i=0}^{n-1} (ai + b) // m
// 0 <= a, b
template<typename T>
T sum_of_floor(T n,T m,T a,T b){
  T res=0;
  if(a>=m){
    res+=(n-1)*n*(a/m)/2;
    a%=m;
  }
  if(b>=m){
    res+=n*(b/m);
    b%=m;
  }
  T y=(a*n+b)/m;
  T x=y*m-b;
  if(y==0) return res;
  res+=(n-(x+a-1)/a)*y;
  res+=sum_of_floor(y,a,m,(a-x%a)%a);
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
