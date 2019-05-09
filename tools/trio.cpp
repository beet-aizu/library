#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
template<typename T, typename U, typename V>
struct trio{
  T first;
  U second;
  V third;
  trio(){}
  trio(T first,U second,V third):
    first(first),second(second),third(third){}
  operator tuple<T&, U&, V&>(){
    return forward_as_tuple(first,second,third);
  }
  using X = tuple<T, U, V>;
  operator X() const{return make_tuple(first,second,third);}
  bool operator==(const trio&a) const{return (X)(*this)==(X)a;}
  bool operator!=(const trio&a) const{return (X)(*this)!=(X)a;}
  bool operator< (const trio&a) const{return (X)(*this)< (X)a;}
  bool operator<=(const trio&a) const{return (X)(*this)<=(X)a;}
  bool operator> (const trio&a) const{return (X)(*this)> (X)a;}
  bool operator>=(const trio&a) const{return (X)(*this)>=(X)a;}  
};
template<typename T, typename U, typename V>
trio<T, U, V> make_trio(T first,U second,V third){
  return trio<T, U, V>(first,second,third);
}
//END CUT HERE
//INSERT ABOVE HERE
signed main(){
  trio<int, int, int> t(0,2,5);
  int x,y,z;
  tie(x,y,z)=t;
  cout<<x<<" "<<y<<" "<<z<<endl;
  cout<<(t==make_trio(x,y,z))<<endl;
  cout<<(t!=make_trio(x,y+1,z))<<endl;
  
  return 0;
}
