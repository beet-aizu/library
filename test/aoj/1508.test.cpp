#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bbst/rbst/basic/base.cpp"
#include "../../bbst/rbst/basic/ushi.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  vector<int> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];

  auto f=[](int a,int b){return min(a,b);};
  const int INF = 1e9;

  using Node = NodeBase<int>;
  constexpr size_t LIM = 1e6;
  Ushi<Node, LIM> G(f,INF);

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
      cout<<G.query(rt,l,r)<<"\n";
    }
    if(x==2){
      rt=G.set_val(rt,y,z);
    }
  }
  cout<<flush;

  return 0;
}
