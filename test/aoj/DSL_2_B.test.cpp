#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/binaryindexedtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  BIT<long long> bit(n+100,0);
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c) cout<<bit.query(x,y+1)<<endl;
    else bit.add(x,y);
  }
  return 0;
}
