#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "enumeration.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
// put n distinct balls into k distinct boxes
template<typename M>
M surjection(int n,int k){
  using E = Enumeration<M>;
  E::init(k);
  M res(0);
  for(int i=1;i<=k;i++){
    M tmp=E::C(k,i)*M(i).pow(n);
    if((k-i)&1) res-=tmp;
    else res+=tmp;
  }
  return res;
}
//END CUT HERE

#ifndef call_from_test
signed main(){
  return 0;
}
#endif
