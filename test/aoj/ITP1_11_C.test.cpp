#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/dice.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Die ds[2];
  for(int j=0;j<2;j++)
    for(int i=0;i<6;i++)
      cin>>ds[j].s[i];

  bool f=false;
  auto vd=makeDice(ds[1]);
  for(auto e:vd) f|=ds[0]==e;
  cout<<(f?"Yes":"No")<<endl;
  return 0;
}
