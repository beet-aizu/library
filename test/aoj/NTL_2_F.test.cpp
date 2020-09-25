// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_F

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/bigint.cpp"
#undef call_from_test

signed main(){
  bigint a,b;
  cin>>a>>b;
  cout<<a*b<<endl;
  return 0;
}
