#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/dice.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Die d;
  for(int i=0;i<6;i++) cin>>d.s[i];

  string s;
  cin>>s;

  for(int i=0;i<(int)s.size();i++) d.roll(s[i]);

  cout<<d.top()<<endl;
  return 0;
}
