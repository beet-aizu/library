#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/knuth_morris_pratt.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  string t,p;
  cin>>t>>p;

  vector<int> res=pattern_match(p,t);
  for(int x:res) cout<<x<<"\n";
  cout<<flush;
  return 0;
}
