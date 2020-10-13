#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../combinatorics/enumeration.cpp"
#undef call_from_test

#endif
// http://beet-aizu.hatenablog.com/entry/2019/09/27/224701
//BEGIN CUT HERE
template<typename M_>
struct FormalPowerSeries : Enumeration<M_> {
  using M = M_;
  using super = Enumeration<M>;
  using super::fact;
  using super::finv;
  using super::invs;

  using Poly = vector<M>;
  using Conv = function<Poly(Poly, Poly)>;
  Conv conv;
  FormalPowerSeries(Conv conv):conv(conv){}

  Poly pre(const Poly &as,int deg){
    return Poly(as.begin(),as.begin()+min((int)as.size(),deg));
  }

  Poly add(Poly as,Poly bs){
    int sz=max(as.size(),bs.size());
    Poly cs(sz,M(0));
    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
    for(int i=0;i<(int)bs.size();i++) cs[i]+=bs[i];
    return cs;
  }

  Poly sub(Poly as,Poly bs){
    int sz=max(as.size(),bs.size());
    Poly cs(sz,M(0));
    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
    for(int i=0;i<(int)bs.size();i++) cs[i]-=bs[i];
    return cs;
  }

  Poly mul(Poly as,Poly bs){
    return conv(as,bs);
  }

  Poly mul(Poly as,M k){
    for(auto &a:as) a*=k;
    return as;
  }

  // F(0) must not be 0
  Poly inv(Poly as,int deg);

  // not zero
  Poly div(Poly as,Poly bs);

  // not zero
  Poly mod(Poly as,Poly bs);

  // F(0) must be 1
  Poly sqrt(Poly as,int deg);

  Poly diff(Poly as);
  Poly integral(Poly as);

  // F(0) must be 1
  Poly log(Poly as,int deg);

  // F(0) must be 0
  Poly exp(Poly as,int deg);

  // not zero
  Poly pow(Poly as,long long k,int deg);

  // x <- x + c
  Poly shift(Poly as,M c);
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
