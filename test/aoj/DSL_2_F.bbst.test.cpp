#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

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
  auto g=[](int a,int b){(void)a;return b;};
  RBST<int, int> rbst(f,g,g,INT_MAX,-1);
  vector<int> vs(n,INT_MAX);
  auto rt=rbst.build(vs);

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
