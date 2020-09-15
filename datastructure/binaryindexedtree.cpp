#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

//BEGIN CUT HERE
template<typename T>
class BIT{
private: // 1-indexed
  T sum_impl(int i){
    T s(0);
    for(int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }
  void add_impl(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }
public: // 0-indexed
  int n;
  vector<T> bit;
  BIT(int n_):n(n_+1),bit(n+1,0){}

  // min({i | sum(i) >= w})
  int lower_bound(int w){
    if(w<=0) return 0;
    int x=0,r=1;
    while(r<n) r<<=1;
    for(int k=r;k>0;k>>=1){
      if(x+k<=n&&bit[x+k]<w){
        w-=bit[x+k];
        x+=k;
      }
    }
    return x;
  }

  T sum(int i){return sum_impl(i+1);}
  void add(int i,T a){add_impl(i+1,a);}
  T query(int l,int r){return sum_impl(r)-sum_impl(l);}
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
