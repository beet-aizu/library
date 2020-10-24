#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// min m s.t. a^m = 1 mod n (a, n are coprime)
template<typename T>
T carmichael_lambda(T n){
  T res=1;
  if(n%8==0) n/=2;
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      T tmp=i-1;
      for(n/=i;n%i==0;n/=i) tmp*=i;
      res=lcm(res,tmp);
    }
  }
  if(n!=1) res=lcm(res,n-1);
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
