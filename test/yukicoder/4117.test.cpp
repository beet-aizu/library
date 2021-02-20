// verification-helper: PROBLEM https://yukicoder.me/problems/4117

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/yesno.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  long long l,r,m,k;
  cin>>l>>r>>m>>k;

  long long x=l*k,y=r*k;
  cout<<YesNo[x<=y/m*m]<<endl;
  return 0;
}
