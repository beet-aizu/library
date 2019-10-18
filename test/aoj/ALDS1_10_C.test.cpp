#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../string/longestcommonsubstring.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int q;
  cin>>q;
  while(q--){
    string s,t;
    cin>>s>>t;
    cout<<longest_common_substring(s,t)<<"\n";
  }
  cout<<flush;
  return 0;
}
