#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../graph/stronglyconnectedcomponent.cpp"
#include "../../graph/twosatisfiability.cpp"
#undef call_from_test

signed main(){
  string s;
  cin>>s;
  cin>>s;

  int n,m;
  cin>>n>>m;

  TwoSat ts(n+1);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    if(a<0) a=ts.negate(abs(a));
    if(b<0) b=ts.negate(abs(b));
    ts.add_or(a,b);
  }

  auto res=ts.build();
  if(res.empty()){
    cout<<"s UNSATISFIABLE"<<endl;
    return 0;
  }

  cout<<"s SATISFIABLE"<<endl;
  cout<<"v";
  for(int i=1;i<=n;i++)
    cout<<" "<<(res[i]?i:-i);
  cout<<" "<<0<<endl;
  return 0;
}
