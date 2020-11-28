#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
namespace Affine{
  template<typename T>
  T op(T a,T b){return T(a.first+b.first,a.second+b.second);}
  template<typename T, typename E>
  T mapping(T a,E b){return T(a.first*b.first+a.second*b.second,a.second);}
  template<typename E>
  E composition(E a,E b){return E(a.first*b.first,a.second*b.first+b.second);}

  template<typename T> T e(){return T(0,0);};
  template<typename E> E id(){return E(1,0);};

  template<typename T, typename E>
  decltype(auto) params(){
    auto f=[](T a,T b){return op(a,b);};
    auto g=[](T a,E b){return mapping(a,b);};
    auto h=[](E a,E b){return composition(a,b);};
    return make_tuple(f,g,h,e<T>(),id<E>());
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
