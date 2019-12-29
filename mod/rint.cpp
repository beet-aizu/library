#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct Rint{
  static T mod;
  static void set_mod(T nmod){mod=nmod;}

  T v;
  Rint():v(0){}
  Rint(signed v):v(v){}
  Rint(long long t){v=t%mod;if(v<0) v+=mod;}

  Rint pow(long long k){
    Rint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }

  static Rint add_identity(){return Rint(0);}
  static Rint mul_identity(){return Rint(1);}

  Rint inv(){return pow(mod-2);}

  Rint& operator+=(Rint a){v+=a.v;if(v>=mod)v-=mod;return *this;}
  Rint& operator-=(Rint a){v+=mod-a.v;if(v>=mod)v-=mod;return *this;}
  Rint& operator*=(Rint a){v=1LL*v*a.v%mod;return *this;}
  Rint& operator/=(Rint a){return (*this)*=a.inv();}

  Rint operator+(Rint a) const{return Rint(v)+=a;}
  Rint operator-(Rint a) const{return Rint(v)-=a;}
  Rint operator*(Rint a) const{return Rint(v)*=a;}
  Rint operator/(Rint a) const{return Rint(v)/=a;}

  Rint operator-() const{return v?Rint(mod-v):Rint(v);}

  bool operator==(const Rint a)const{return v==a.v;}
  bool operator!=(const Rint a)const{return v!=a.v;}
  bool operator <(const Rint a)const{return v <a.v;}
};
template<typename T> T Rint<T>::mod;
template<typename T>
ostream& operator<<(ostream &os,Rint<T> m){os<<m.v;return os;}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
