#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#undef call_from_test

signed main(){
  const char newl = '\n';
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    long long a,b;
    cin>>a>>b;
    cout<<a+b<<newl;
  }
  return 0;
}
