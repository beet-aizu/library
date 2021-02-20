// verification-helper: PROBLEM https://yukicoder.me/problems/3354

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/yesno.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int a,b;
  cin>>a>>b;

  cout<<YESNO[a%b==0]<<endl;
  return 0;
}
