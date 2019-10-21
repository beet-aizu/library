#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../string/parse.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;
  while(n--){
    string s;
    int p=0;
    cin>>s;s.pop_back();
    cout<<expression(s,p)<<endl;
  }
  return 0;
}
