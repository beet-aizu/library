// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bbst/rbst/rbst.cpp"
#include "../../bbst/rbst/data/ushi.cpp"
#include "../../bbst/rbst/impl/basic.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,q;
  cin>>n>>q;
  vector<int> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];

  auto f=[](int a,int b){return min(a,b);};
  auto flip=[](int a){return a;};
  const int INF = 1e9;

  using Data = Ushi<int, decltype(f), decltype(flip)>;
  using Node = Data::Node;
  constexpr size_t LIM = 1e6;
  Basic<Data, LIM> G(f,flip,INF);

  auto rt=G.build(vector<Node>(vs.begin(),vs.end()));

  for(int i=0;i<q;i++){
    int x,y,z;
    cin>>x>>y>>z;
    if(x==0){
      int l=y,r=z+1;
      rt=G.toggle(rt,l,r);
      rt=G.toggle(rt,l+1,r);
    }
    if(x==1){
      int l=y,r=z+1;
      cout<<G.query(rt,l,r)<<newl;
    }
    if(x==2){
      rt=G.set_val(rt,y,z);
    }
  }
  return 0;
}
