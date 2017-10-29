#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct frac{
  int num,dom;
  frac(){}
  frac(int num,int dom):num(num),dom(dom){}
  frac norm(){
    if(num==0) return frac(0,1);
    int tmp=__gcd(num,dom);
    return frac(num/tmp,dom/tmp);
  }
  frac norm2(){
    if(num==0) return frac(0,1);
    while(num<0) num+=dom;
    while(num>=dom) num-=dom;
    int tmp=__gcd(num,dom);
    return frac(num/tmp,dom/tmp);
  }
  frac operator+(frac a){return frac(num*a.dom+a.num*dom,dom*a.dom).norm();}
  frac operator-(frac a){return frac(num*a.dom-a.num*dom,dom*a.dom).norm();}
  frac operator*(frac a){return frac(num*a.num,dom*a.dom).norm();}
  frac operator/(frac a){return frac(num*a.dom,dom*a.num).norm();}
  frac operator*(int k){return frac(num*k,dom).norm();}
  frac operator/(int k){return frac(num,dom*k).norm();}
  bool operator<(const frac a)const{
    return num*a.dom<a.num*dom;
  }
  bool operator>(const frac a)const{
    return num*a.dom>a.num*dom;
  }
  bool operator==(const frac a)const{
    return num*a.dom==a.num*dom;
  }
  bool operator!=(const frac a)const{
    return num*a.dom!=a.num*dom;
  }
  bool operator<=(const frac a)const{
    return num*a.dom<=a.num*dom;
  }
  bool operator>=(const frac a)const{
    return num*a.dom>=a.num*dom;
  }
};
//END CUT HERE
signed main(){
  return 0;
}
