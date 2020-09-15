#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

//BEGIN CUT HERE
template<typename T>
class BIT{
private:
  // \sum_{j < i}  v[j]
  T sum(int i){
    T s(0);
    for(int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }
public:
  int n;
  vector<T> bit;
  BIT(int n_):n(n_+1),bit(n+1,0){}

  // v[i] += a
  void add(int i,T a){
    for(int x=++i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }
  // \sum_{l <= i < r} v[i]
  T query(int l,int r){return sum(r)-sum(l);}

  // min({x | sum(x) >= w})
  int lower_bound(const T w){
    if(w<=0) return 0;
    T r=w;
    int x=0,p=1;
    while(p<n) p<<=1;
    for(int k=p;k>0;k>>=1){
      if(x+k<=n&&bit[x+k]<r){
        r-=bit[x+k];
        x+=k;
      }
    }
    x++;
    assert(sum(x-1)<w and sum(x)>=w);
    return x;
  }

  // min({x | sum(x) > w})
  int upper_bound(T w){return lower_bound(w+1);}
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
