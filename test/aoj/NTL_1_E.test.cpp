// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/extgcd.cpp"
#undef call_from_test

signed main(){
  int a,b;
  cin>>a>>b;
  auto[x,y]=extgcd(a,b);
  cout<<x<<" "<<y<<endl;
  return 0;
}
