#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/eulertourforvertex.cpp"
#include "../../datastructure/binaryindexedtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  EulerTourForVertex G(n);
  for(int i=1;i<n;i++){
    int p;
    cin>>p;
    G.add_edge(p,i);
  }
  G.build(0);

  BIT<long long> bit(n);
  for(int i=0;i<n;i++)
    bit.add(G.idx(i),as[i]);

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int u,x;
      cin>>u>>x;
      bit.add(G.idx(u),x);
    }
    if(t==1){
      int u;
      cin>>u;
      G.exec(u,[&](int l,int r){cout<<bit.query(l,r)<<"\n";});
    }
  }
  cout<<flush;
  return 0;
}
