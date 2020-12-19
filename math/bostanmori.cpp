#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// Find k-th term of linear recurrence
// execute `conv` O(\log k) times
template<typename T>
struct BostanMori{
  using Poly = vector<T>;
  using Conv = function<Poly(Poly, Poly)>;

  Conv conv;
  BostanMori(Conv conv_):conv(conv_){}

  Poly sub(Poly as,int odd){
    Poly bs((as.size()+!odd)/2);
    for(int i=odd;i<(int)as.size();i+=2) bs[i/2]=as[i];
    return bs;
  }

  // as: initial values
  // cs: monic polynomial
  T build(long long k,Poly as,Poly cs){
    reverse(cs.begin(),cs.end());
    assert(cs[0]==T(1));
    int n=cs.size()-1;
    as.resize(n,0);
    Poly bs=conv(as,cs);
    bs.resize(n);
    while(k){
      Poly ds(cs);
      for(int i=1;i<(int)ds.size();i+=2) ds[i]=-ds[i];
      bs=sub(conv(bs,ds),k&1);
      cs=sub(conv(cs,ds),0);
      k>>=1;
    }
    return bs[0];
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
