#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#endif
//BEGIN CUT HERE
// construct a charasteristic equation from sequence
// return a monic polynomial in O(n^2)
template<typename T>
vector<T> berlekamp_massey(vector<T> &as){
  using Poly = vector<T>;
  int n=as.size();
  Poly bs({-T(1)}),cs({-T(1)});
  T y(1);
  for(int ed=1;ed<=n;ed++){
    int l=cs.size(),m=bs.size();
    T x(0);
    for(int i=0;i<l;i++) x+=cs[i]*as[ed-l+i];
    bs.emplace_back(0);
    m++;
    if(x==T(0)) continue;
    T freq=x/y;
    if(m<=l){
      for(int i=0;i<m;i++)
        cs[l-1-i]-=freq*bs[m-1-i];
      continue;
    }
    auto ts=cs;
    cs.insert(cs.begin(),m-l,T(0));
    for(int i=0;i<m;i++) cs[m-1-i]-=freq*bs[m-1-i];
    bs=ts;
    y=x;
  }
  for(auto &c:cs) c/=cs.back();
  return cs;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
