// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/parse.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  while(n--){
    string s;
    int p=0;
    cin>>s;
    s.pop_back();
    cout<<expression(s,p)<<endl;
  }
  return 0;
}
