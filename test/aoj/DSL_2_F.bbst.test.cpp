// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bbst/rbst/rbst.cpp"
#include "../../bbst/rbst/data/lazy.cpp"
#include "../../bbst/rbst/impl/basic.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,q;
  cin>>n>>q;

  auto f=[](int a,int b){return min(a,b);};
  auto g=[](int  ,int b){return b;};
  auto flip=[](int a){return a;};

  using Data = decltype(Lazy(f,g,g,flip,INT_MAX,-1));
  using Node = Data::Node;
  constexpr size_t LIM = 1e6;
  Basic<Data, LIM> G(f,g,g,flip,INT_MAX,-1);
  auto rt=G.build(vector<Node>(n,Node(INT_MAX,-1)));

  for(int i=0;i<q;i++){
    int c;
    cin>>c;
    if(c==0){
      int s,t,x;
      cin>>s>>t>>x;
      rt=G.update(rt,s,t+1,x);
    }
    if(c==1){
      int s,t;
      cin>>s>>t;
      cout<<G.query(rt,s,t+1)<<newl;
    }
  }
  return 0;
}
