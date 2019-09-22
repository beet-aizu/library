#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_B"

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

  int n;
  cin>>n;

  while(n--){
    int a,b;
    cin>>a>>b;
    if(d.west()==a) d.roll('E');
    if(d.east()==a) d.roll('W');
    while(d.top()!=a) d.roll('N');
    while(d.south()!=b) d.roll('R');
    cout<<d.east()<<endl;
  }
  return 0;
}
