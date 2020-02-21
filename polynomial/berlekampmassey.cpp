#ifndef call_from_test
#include<bits/stdc++.h>
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

#define call_from_test
#include "../mod/mint.cpp"
#include "../tools/fastio.cpp"
#undef call_from_test

signed SPOJ_FIBPWSUM(){
  int T;
  cin>>T;

  using M = Mint<long long, 1000000007>;
  const int MAX = 10000;
  vector<M> fib(MAX);
  fib[0]=M(0);
  fib[1]=M(1);
  for(int i=2;i<MAX;i++) fib[i]=fib[i-1]+fib[i-2];

  for(int t=1;t<=T;t++){
    long long n;
    int c,k;
    cin>>n>>c>>k;

    vector<M> seq;
    for(int i=0;i*c<MAX;i++)
      seq.emplace_back(fib[i*c].pow(k));

    for(int i=1;i<(int)seq.size();i++)
      seq[i]+=seq[i-1];

    auto cs=berlekamp_massey(seq);
    cs.pop_back();
    reverse(cs.begin(),cs.end());
    int m=cs.size();

    auto mul=
      [&](auto xs,auto ys){
        vector<M> zs(xs.size()+ys.size()-1,M(0));
        for(int i=0;i<(int)xs.size();i++)
          for(int j=0;j<(int)ys.size();j++)
            zs[i+j]+=xs[i]*ys[j];

        for(int i=(int)zs.size()-1;i>=m;i--)
          for(int j=0;j<m;j++)
            zs[i-(j+1)]-=zs[i]*cs[j];

        zs.resize(m,M(0));
        return zs;
      };

    vector<M> ps({M(0),M(1)}),qs({M(1)});
    while(n){
      if(n&1) qs=mul(ps,qs);
      ps=mul(ps,ps);
      n>>=1;
    }

    M ans{0};
    qs.resize(m,M(0));
    for(int i=0;i<m;i++) ans+=seq[i]*qs[i];
    cout<<"Case "<<t<<": "<<ans<<endl;
  }
  return 0;
}
/*
  verified on 2020/02/09
  https://www.spoj.com/problems/FIBPWSUM/
*/

signed main(){
  //SPOJ_FIBPWSUM();
  return 0;
}
#endif
