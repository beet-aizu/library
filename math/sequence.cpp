#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../combinatorics/enumeration.cpp"
#include "../formalpowerseries/base.cpp"
#include "../polynomial/berlekampmassey.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename M>
struct Sequence : FormalPowerSeries<M>{
  using FormalPowerSeries<M>::FormalPowerSeries;
  using Poly = vector<M>;

  struct Calculator{
    const Poly as,cs;
    Sequence* seq;
    Calculator(const Poly as_,const Poly cs_,Sequence *seq_):
      as(as_),cs(cs_),seq(seq_){}
    M operator()(long long n){
      if(n<(int)as.size()) return as[n];
      Poly rs({M(1)}),ts({M(0),M(1)});
      while(n){
        if(n&1) rs=seq->mod(seq->mul(rs,ts),cs);
        ts=seq->mod(seq->mul(ts,ts),cs);
        n>>=1;
      }
      M res(0);
      rs.resize(cs.size(),M(0));
      for(int i=0;i<(int)cs.size();i++) res+=as[i]*rs[i];
      return res;
    }
  };

  Calculator build(vector<M> as){
    return Calculator(as,berlekamp_massey(as),this);
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
