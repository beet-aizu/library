#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
// https://noshi91.hatenablog.com/entry/2019/09/23/002445
//BEGIN CUT HERE
// O(n \log \log n)
namespace DivisorTransform{
  template<typename T, typename F>
  void inc(vector<T> &as,F f){
    assert(as[0]==T(0));
    int n=as.size();
    vector<bool> sieve(n,false);
    for(int p=2;p<n;p++){
      if(sieve[p]) continue;
      for(int k=1;k*p<n;k++){
        sieve[k*p]=true;
        f(as[k],as[k*p]);
      }
    }
  }
  template<typename T, typename F>
  void dec(vector<T> &as,F f){
    assert(as[0]==T(0));
    int n=as.size();
    vector<bool> sieve(n,false);
    for(int p=2;p<n;p++){
      if(sieve[p]) continue;
      for(int k=(n-1)/p;k!=0;--k){
        sieve[k*p]=true;
        f(as[k],as[k*p]);
      }
    }
  }
}
namespace GCDConvolution{
  template<typename T>
  void zeta(vector<T> &as){
    auto f=[](T &lo,T &hi){lo+=hi;};
    DivisorTransform::dec(as,f);
  }
  template<typename T>
  void moebius(vector<T> &as){
    auto f=[](T &lo,T &hi){lo-=hi;};
    DivisorTransform::inc(as,f);
  }
}
namespace LCMConvolution{
  template<typename T>
  void zeta(vector<T> &as){
    auto f=[](T &lo,T &hi){hi+=lo;};
    DivisorTransform::inc(as,f);
  }
  template<typename T>
  void moebius(vector<T> &as){
    auto f=[](T &lo,T &hi){hi-=lo;};
    DivisorTransform::dec(as,f);
  }
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
