#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T>
T extgcd(T a,T b,T& x,T& y){
  T d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}
template<typename T>
T mod_inverse(T a,T mod){
  T x,y;
  extgcd(a,mod,x,y);
  return (x%mod+mod)%mod;
}
//END CUT HERE
//INSERT ABOVE HERE

//extgcd
signed AOJ_NTL1E(){
  Int a,b;
  cin>>a>>b;
  Int x,y;
  extgcd(a,b,x,y);
  cout<<x<<" "<<y<<endl;
  return 0;
}
/*
  verified on 2019/05/26
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=jp
*/

signed main(){
  AOJ_NTL1E();
  return 0;
}
