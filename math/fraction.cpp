#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct fraction{
  T num,den;
  fraction(T n,T d):num(n),den(d){
    assert(den!=0);
    if(den<0) num*=-1,den*=-1;
    T tmp=gcd(abs(num),abs(den));
    num/=tmp;
    den/=tmp;
  }
  const fraction operator+(const fraction& a) const{
    return fraction(num*a.den+a.num*den,den*a.den);
  }
  const fraction operator-(const fraction& a) const{
    return fraction(num*a.den-a.num*den,den*a.den);
  }
  const fraction operator*(const fraction& a) const{
    return fraction(num*a.num,den*a.den);
  }
  const fraction operator/(const fraction& a) const{
    return fraction(num*a.den,den*a.num);
  }
  const fraction operator*(T k) const{return fraction(num*k,den);}
  const fraction operator/(T k) const{return fraction(num,den*k);}
#define define_cmp(op) \
  bool operator op (const fraction& a) const{return num*a.den op a.num*den;}
  define_cmp(==)
  define_cmp(!=)
  define_cmp(<)
  define_cmp(>)
  define_cmp(<=)
  define_cmp(>=)
#undef define_cmp
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
