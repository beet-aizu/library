#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../string/suffixarray.cpp"
#undef call_from_test

signed main(){
  string s;
  cin>>s;

  SuffixArray sa(s);

  int n=s.size();
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<sa[i+1];
  }
  cout<<endl;
  return 0;
}
