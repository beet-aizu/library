#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct fraction{
  T num,dom;
  fraction(T n,T d):num(n),dom(d){
    assert(dom!=0);
    if(dom<0) num*=-1,dom*=-1;
    T tmp=__gcd(abs(num),abs(dom));
    num/=tmp;
    dom/=tmp;
  }
  fraction operator+(const fraction a) const{
    return fraction(num*a.dom+a.num*dom,dom*a.dom);
  }
  fraction operator-(const fraction a) const{
    return fraction(num*a.dom-a.num*dom,dom*a.dom);
  }
  fraction operator*(const fraction a) const{
    return fraction(num*a.num,dom*a.dom);
  }
  fraction operator/(const fraction a){
    return fraction(num*a.dom,dom*a.num);
  }
  fraction operator*(T k) const{return fraction(num*k,dom);}
  fraction operator/(T k) const{return fraction(num,dom*k);}
#define define_cmp(op) \
  bool operator op (const fraction a)const{return num*a.dom op a.num*dom;}
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
