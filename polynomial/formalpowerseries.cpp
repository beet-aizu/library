#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../combinatorics/enumeration.cpp"
#undef call_from_test

#endif

/*
 * @see http://beet-aizu.hatenablog.com/entry/2019/09/27/224701
 */
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
  Poly inv(Poly as,int deg){
    assert(as[0]!=M(0));
    Poly rs({M(1)/as[0]});
    for(int i=1;i<deg;i<<=1)
      rs=pre(sub(add(rs,rs),mul(mul(rs,rs),pre(as,i<<1))),i<<1);
    return rs;
  }

  // not zero
  Poly div(Poly as,Poly bs){
    while(as.back()==M(0)) as.pop_back();
    while(bs.back()==M(0)) bs.pop_back();
    if(bs.size()>as.size()) return Poly();
    reverse(as.begin(),as.end());
    reverse(bs.begin(),bs.end());
    int need=as.size()-bs.size()+1;
    Poly ds=pre(mul(as,inv(bs,need)),need);
    reverse(ds.begin(),ds.end());
    return ds;
  }

  Poly mod(Poly as,Poly bs){
    if(as==Poly(as.size(),0)) return Poly({0});
    as=sub(as,mul(div(as,bs),bs));
    if(as==Poly(as.size(),0)) return Poly({0});
    while(as.back()==M(0)) as.pop_back();
    return as;
  }

  // F(0) must be 1
  Poly sqrt(Poly as,int deg){
    assert(as[0]==M(1));
    M inv2=M(1)/M(2);
    Poly ss({M(1)});
    for(int i=1;i<deg;i<<=1){
      ss=pre(add(ss,mul(pre(as,i<<1),inv(ss,i<<1))),i<<1);
      for(M &x:ss) x*=inv2;
    }
    return ss;
  }

  Poly diff(Poly as){
    int n=as.size();
    Poly rs(n-1);
    for(int i=1;i<n;i++) rs[i-1]=as[i]*M(i);
    return rs;
  }

  Poly integral(Poly as){
    super::init(as.size()+1);
    int n=as.size();
    Poly rs(n+1);
    rs[0]=M(0);
    for(int i=0;i<n;i++) rs[i+1]=as[i]*invs[i+1];
    return rs;
  }

  // F(0) must be 1
  Poly log(Poly as,int deg){
    return pre(integral(mul(diff(as),inv(as,deg))),deg);
  }

  // F(0) must be 0
  Poly exp(Poly as,int deg){
    Poly f({M(1)});
    as[0]+=M(1);
    for(int i=1;i<deg;i<<=1)
      f=pre(mul(f,sub(pre(as,i<<1),log(f,i<<1))),i<<1);
    return f;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
