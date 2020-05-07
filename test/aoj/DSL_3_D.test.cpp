#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/rangeslide.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,l;
  cin>>n>>l;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto cmp=[](int a,int b){return a<b;};
  RangeSlide<int, decltype(cmp)> rs(as,cmp);

  for(int i=0;i+l<=n;i++) rs.add_range(i,i+l);
  auto res=rs.build();
  for(int i=0;i+l<=n;i++){
    if(i) cout<<" ";
    cout<<as[res[i]];
  }
  cout<<endl;
  return 0;
}
