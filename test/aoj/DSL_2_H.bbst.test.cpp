#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../bbst/basic/chien.cpp"
#undef call_from_test

signed main(){
  int n,q;
  cin>>n>>q;

  auto f=[](int a,int b){return min(a,b);};
  auto g=[](int a,int b){return a+b;};
  RBST<int, int> rbst(f,g,g,INT_MAX,0);
  auto rt=rbst.build(vector<int>(n,0));

  for(int i=0;i<q;i++){
    int c;
    cin>>c;
    if(c==0){
      int s,t,x;
      cin>>s>>t>>x;
      rt=rbst.update(rt,s,t+1,x);
    }
    if(c==1){
      int s,t;
      cin>>s>>t;
      cout<<rbst.query(rt,s,t+1)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
