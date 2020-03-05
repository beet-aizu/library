#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/path.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  using Node = NodeBase<int, int>;
  constexpr size_t LIM = 1e6;
  using LCT = Path<Node, LIM>;

  auto f=[](int a,int b){return a+b;};
  LCT lct(f,f,f,0);
  for(int i=0;i<n;i++) lct.create(0);

  for(int i=1;i<n;i++){
    int p;
    cin>>p;
    lct.link(lct[p],lct[i]);
  }

  for(int i=0;i<q;i++){
    int u,v;
    cin>>u>>v;
    cout<<lct.idx(lct.lca(lct[u],lct[v]))<<"\n";
  }
  cout<<flush;
  return 0;
}
