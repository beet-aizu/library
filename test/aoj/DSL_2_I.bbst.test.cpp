// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I

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

  using P = pair<int, int>;
  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,int b){return P(a.second*b,a.second);};
  auto h=[](int,int b){return b;};
  auto flip=[](P a){return a;};

  int ei=-1010;
  using Data = decltype(Lazy(f,g,h,flip,P(0,0),ei));
  using Node = Data::Node;
  constexpr size_t LIM = 1e6;
  Basic<Data, LIM> G(f,g,h,flip,P(0,0),ei);
  auto rt=G.build(vector<Node>(n,Node(P(0,1),ei)));

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
      cout<<G.query(rt,s,t+1).first<<newl;
    }
  }
  return 0;
}
