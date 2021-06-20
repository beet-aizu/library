#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

//BEGIN CUT HERE
// half open interval [l, r)
template<typename T=unsigned long long>
struct BitVector{
  inline static constexpr size_t B = sizeof(T) * CHAR_BIT;
  size_t n;
  vector<T> dat;
  BitVector(size_t n_):n(n_),dat(n_/B+1,0){}

  inline T get(size_t i)const{return (dat[i/B]>>(i%B))&T(1);}

  void set(size_t i,T v){
    dat[i/B]&=~(T(1)<<(i%B));
    dat[i/B]|=v<<(i%B);
  }

  // O(B + (r - l) / B)
  BitVector get(size_t l,size_t r)const{
    BitVector res(r-l);
    if(r-l<=B){
      for(size_t i=l;i<r;i++) res.set(i-l,get(i));
      return res;
    }
    size_t p=(l+B-1)/B*B,q=r/B*B;
    // [l, p)
    for(size_t i=l;i<p;i++) res.set(i-l,get(i));
    // [p, q)
    for(size_t i=p;i<q;i+=B){
      if(l%B==0) res.dat[(i-l)/B]=dat[i/B];
      else{
        res.dat[(i-l)/B+0]|=dat[i/B]<<(p-l);
        res.dat[(i-l)/B+1]|=dat[i/B]>>(B-(p-l));
      }
    }
    // [q, r)
    for(size_t i=q;i<r;i++) res.set(i-l,get(i));
    return res;
  }

  void set(size_t l,size_t r,const BitVector& bv){
    if(r-l<=B){
      for(size_t i=l;i<r;i++) set(i,bv.get(i-l));
      return;
    }
    size_t p=(l+B-1)/B*B,q=r/B*B;
    // [l, p)
    for(size_t i=l;i<p;i++) set(i,bv.get(i-l));
    // [p, q)
    for(size_t i=p;i<q;i+=B){
      if(l%B==0) dat[i/B]=bv.dat[(i-l)/B];
      else dat[i/B]=(bv.dat[(i-l)/B+0]>>(p-l))|(bv.dat[(i-l)/B+1]<<(B-(p-l)));
    }
    // [q, r)
    for(size_t i=q;i<r;i++) set(i,bv.get(i-l));
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
