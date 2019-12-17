#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
/*
  multiprecision:
  #include <boost/multiprecision/cpp_int.hpp>
  using Int = boost::multiprecision::cpp_int;
*/
#endif
//BEGIN CUT HERE
__int128_t abs128(__int128_t val){return val<0?-val:val;}

ostream &operator<<(ostream &os,__int128_t val){
  if(ostream::sentry(os)){
    __uint128_t tmp=abs128(val);
    char buf[64];
    char *d=end(buf);
    do{
      --d;
      *d=char(tmp%10+'0');
      tmp/=10;
    }while(tmp);
    if(val<0) *--d='-';
    int len=end(buf)-d;
    if(os.rdbuf()->sputn(d,len)!=len){
      os.setstate(ios_base::badbit);
    }
  }
  return os;
}

istream &operator>>(istream &is,__int128_t &val){
  string s;
  is>>s;
  val=0;
  for(int i=0;i<(int)s.size();i++)
    if(isdigit(s[i])) val=val*10+s[i]-'0';
  if(s[0]=='-') val*=-1;
  return is;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
