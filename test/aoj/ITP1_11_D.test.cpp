// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/dice.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  vector<Die<int>> ds(n);
  for(int j=0;j<n;j++)
    for(int i=0;i<6;i++)
      cin>>ds[j].fs[i];

  bool ff=true;
  for(int i=0;i<n;i++){
    auto vd=makeDice(ds[i]);
    for(int j=0;j<i;j++){
      bool f=false;
      for(auto d:vd) f|=d==ds[j];
      ff&=!f;
    }
  }

  cout<<(ff?"Yes":"No")<<endl;
  return 0;
}
