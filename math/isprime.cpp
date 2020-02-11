#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
int isprime(T x){
  if(x<=1) return 0;
  for(T i=2;i*i<=x;i++)
    if(x%i==0) return 0;
  return 1;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
