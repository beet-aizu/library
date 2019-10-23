#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../string/zalgorithm.cpp"
#undef call_from_test

signed main(){
  string s;
  cin>>s;

  auto zs=zalgorithm(s);

  int n=s.size();
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<zs[i];
  }
  cout<<endl;
  return 0;
}
