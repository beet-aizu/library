#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/suffixarray.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  string t;
  cin>>t;
  int q;
  cin>>q;
  SuffixArray sa(t);
  while(q--){
    string p;
    cin>>p;
    cout<<!!sa.count(p)<<"\n";
  }
  cout<<flush;
  return 0;
}
