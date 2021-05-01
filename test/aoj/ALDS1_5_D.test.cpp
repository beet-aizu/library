// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/binaryindexedtree.cpp"
#include "../../vector/compress.cpp"
#include "../../vector/inversion.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  cout<<inversion(compressed(as))<<endl;
  return 0;
}
