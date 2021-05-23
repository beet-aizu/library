// verification-helper: PROBLEM https://yukicoder.me/problems/4941

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/fraction.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s,t;
  cin>>s>>t;
  int a=(s[0]-'0')*10+(s[1]-'0');
  int b=(t[0]-'0')*10+(t[1]-'0');

  using F = fraction<int>;
  F c(a*60+b,1);
  F d(720,11);
  F x(0,1);
  while(x<c) x=x+d;
  x=x-c;
  cout<<x.num*60/x.den<<endl;
  return 0;
}
