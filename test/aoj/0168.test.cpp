// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0168

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/kitamasa.cpp"
#undef call_from_test

template<typename T>
struct Z{
  T v;
  Z(){*this=add_identity();}
  Z(T v):v(v){}
  Z operator+(const Z &a)const{return Z(v+a.v);}
  Z operator*(const Z &a)const{return Z(v*a.v);}
  static Z add_identity(){return Z(0);}
  static Z mul_identity(){return Z(1);}
};

signed main(){
  using ZL = Z<long long>;

  vector<ZL> as({0,0,1}),cs({1,1,1});
  Kitamasa<ZL> K(cs);

  int n;
  while(cin>>n,n)
    cout<<(K.calc(as,n+2).v+3650-1)/3650<<endl;

  return 0;
}
