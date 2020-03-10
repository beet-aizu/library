#pragma once
#include <iostream>

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

/*
 * @see http://beet-aizu.hatenablog.com/entry/2019/09/27/224701
 */
//BEGIN CUT HERE
template<typename T>
struct FormalPowerSeries{
  using Poly = vector<T>;
  using Conv = function<Poly(Poly, Poly)>;
  Conv conv;
  FormalPowerSeries(Conv conv):conv(conv){}

  Poly pre(const Poly &as,int deg){
    return Poly(as.begin(),as.begin()+min((int)as.size(),deg));
  }

  Poly add(Poly as,Poly bs){
    int sz=max(as.size(),bs.size());
    Poly cs(sz,T(0));
    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
    for(int i=0;i<(int)bs.size();i++) cs[i]+=bs[i];
    return cs;
  }

  Poly sub(Poly as,Poly bs){
    int sz=max(as.size(),bs.size());
    Poly cs(sz,T(0));
    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
    for(int i=0;i<(int)bs.size();i++) cs[i]-=bs[i];
    return cs;
  }

  Poly mul(Poly as,Poly bs){
    return conv(as,bs);
  }

  Poly mul(Poly as,T k){
    for(auto &a:as) a*=k;
    return as;
  }

  // F(0) must not be 0
  Poly inv(Poly as,int deg){
    assert(as[0]!=T(0));
    Poly rs({T(1)/as[0]});
    for(int i=1;i<deg;i<<=1)
      rs=pre(sub(add(rs,rs),mul(mul(rs,rs),pre(as,i<<1))),i<<1);
    return rs;
  }

  // not zero
  Poly div(Poly as,Poly bs){
    while(as.back()==T(0)) as.pop_back();
    while(bs.back()==T(0)) bs.pop_back();
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
    while(as.back()==T(0)) as.pop_back();
    return as;
  }

  // F(0) must be 1
  Poly sqrt(Poly as,int deg){
    assert(as[0]==T(1));
    T inv2=T(1)/T(2);
    Poly ss({T(1)});
    for(int i=1;i<deg;i<<=1){
      ss=pre(add(ss,mul(pre(as,i<<1),inv(ss,i<<1))),i<<1);
      for(T &x:ss) x*=inv2;
    }
    return ss;
  }

  Poly diff(Poly as){
    int n=as.size();
    Poly rs(n-1);
    for(int i=1;i<n;i++) rs[i-1]=as[i]*T(i);
    return rs;
  }

  Poly integral(Poly as){
    int n=as.size();
    Poly rs(n+1);
    rs[0]=T(0);
    for(int i=0;i<n;i++) rs[i+1]=as[i]/T(i+1);
    return rs;
  }

  // F(0) must be 1
  Poly log(Poly as,int deg){
    return pre(integral(mul(diff(as),inv(as,deg))),deg);
  }

  // F(0) must be 0
  Poly exp(Poly as,int deg){
    Poly f({T(1)});
    as[0]+=T(1);
    for(int i=1;i<deg;i<<=1)
      f=pre(mul(f,sub(pre(as,i<<1),log(f,i<<1))),i<<1);
    return f;
  }

  Poly partition(int n){
    Poly rs(n+1);
    rs[0]=T(1);
    for(int k=1;k<=n;k++){
      if(1LL*k*(3*k+1)/2<=n) rs[k*(3*k+1)/2]+=T(k%2?-1LL:1LL);
      if(1LL*k*(3*k-1)/2<=n) rs[k*(3*k-1)/2]+=T(k%2?-1LL:1LL);
    }
    return inv(rs,n+1);
  }

  template<typename E>
  Poly bernoulli(int n){
    E::init(n+2);
    Poly rs(n+1,1);
    for(int i=1;i<=n;i++) rs[i]=E::Finv(i+1);
    rs=inv(rs,n+1);
    for(int i=1;i<=n;i++) rs[i]*=E::Fact(i);
    return rs;
  }

  template<typename E>
  Poly stirling_1st(int n){
    E::init(n+1);
    if(n==0) return {T(1)};
    int m=1;
    Poly ss({T(0),T(1)});
    for(int e=31-__builtin_clz(n)-1;e>=0;e--){
      Poly as(m+1),bs(m+1);
      for(int i=0;i<=m;i++) as[i]=E::Fact(i)*ss[i];
      bs[m-0]=T(1);
      for(int i=1;i<=m;i++) bs[m-i]=bs[m-(i-1)]*-T(m);
      for(int i=0;i<=m;i++) bs[m-i]*=E::Finv(i);
      Poly cs=mul(as,bs);
      Poly ds(m+1);
      for(int i=0;i<=m;i++) ds[i]=E::Finv(i)*cs[m+i];
      ss=mul(ss,ds);
      m<<=1;
      if((n>>e)&1){
        Poly ts(m+1+1,T(0));
        for(int i=0;i<=m;i++){
          ts[i+0]+=ss[i]*-T(m);
          ts[i+1]+=ss[i];
        }
        ss=ts;
        m|=1;
      }
    }
    assert(m==n);
    return ss;
  }

  template<typename E>
  Poly stirling_2nd(int n){
    E::init(n+1);
    Poly as(n+1),bs(n+1);
    for(int i=0;i<=n;i++){
      as[i]=T(i).pow(n)*E::Finv(i);
      bs[i]=(i&1?-T(1):T(1))*E::Finv(i);
    }
    return pre(mul(as,bs),n+1);
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
