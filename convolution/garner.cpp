#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../mod/mint.cpp"
#include "numbertheoretictransform.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
struct Garner{
  using ll = long long;
  static NTT<0> ntt0;
  static NTT<1> ntt1;
  static NTT<2> ntt2;

  static constexpr int pow(int a,int b,int md){
    int res=1;
    a=a%md;
    while(b){
      if(b&1) res=(ll)res*a%md;
      a=(ll)a*a%md;
      b>>=1;
    }
    return res;
  }

  static constexpr int inv(int x,int md){
    return pow(x,md-2,md);
  }

  inline void garner(int &c0,int c1,int c2,int m01,int MOD){
    static constexpr int r01=inv(ntt0.md,ntt1.md);
    static constexpr int r02=inv(ntt0.md,ntt2.md);
    static constexpr int r12=inv(ntt1.md,ntt2.md);

    c1=(ll)(c1-c0)*r01%ntt1.md;
    if(c1<0) c1+=ntt1.md;

    c2=(ll)(c2-c0)*r02%ntt2.md;
    c2=(ll)(c2-c1)*r12%ntt2.md;
    if(c2<0) c2+=ntt2.md;

    c0%=MOD;
    c0+=(ll)c1*ntt0.md%MOD;
    if(c0>=MOD) c0-=MOD;
    c0+=(ll)c2*m01%MOD;
    if(c0>=MOD) c0-=MOD;
  }

  inline void garner(vector< vector<int> > &cs,int MOD){
    int m01 =(ll)ntt0.md*ntt1.md%MOD;
    int sz=cs[0].size();
    for(int i=0;i<sz;i++) garner(cs[0][i],cs[1][i],cs[2][i],m01,MOD);
  }

  vector<int> multiply(vector<int> as,vector<int> bs,int MOD){
    vector< vector<int> > cs(3);
    cs[0]=ntt0.multiply(as,bs);
    cs[1]=ntt1.multiply(as,bs);
    cs[2]=ntt2.multiply(as,bs);
    size_t sz=as.size()+bs.size()-1;
    for(auto& v:cs) v.resize(sz);
    garner(cs,MOD);
    return cs[0];
  }

  template<typename T>
  decltype(auto) multiply(vector<T> am,
                          vector<T> bm){
    vector<int> as(am.size()),bs(bm.size());
    for(int i=0;i<(int)as.size();i++) as[i]=am[i].v;
    for(int i=0;i<(int)bs.size();i++) bs[i]=bm[i].v;
    vector<int> cs=multiply(as,bs,T::mod);
    vector<T> cm(cs.size());
    for(int i=0;i<(int)cm.size();i++) cm[i]=T(cs[i]);
    return cm;
  }
};
NTT<0> Garner::ntt0;
NTT<1> Garner::ntt1;
NTT<2> Garner::ntt2;
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
