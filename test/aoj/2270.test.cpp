// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../vector/compress.cpp"
#include "../../algorithm/mo.cpp"
#include "../../tree/eulertourforedge.cpp"
#include "../../tree/lowestcommonancestor.cpp"
#include "../../tree/mo_on_tree.cpp"
#include "../../datastructure/binaryindexedtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  vector<int> xs(n+1);
  for(int i=1;i<=n;i++) cin>>xs[i];
  auto cs=compress(xs);
  auto dc=dict(cs);
  vector<int> ys(n+1);
  for(int i=0;i<=n;i++) ys[i]=dc[xs[i]];


  vector<int> zs(n);
  BIT<int> bit(n);
  auto expand=[&](int e){bit.add(zs[e],+1);};
  auto shrink=[&](int e){bit.add(zs[e],-1);};
  MoOnTree mo(n+1,400,expand,shrink);
  LowestCommonAncestor lca(n+1);

  vector<int> as(n),bs(n);
  as[0]=0;bs[0]=1;
  mo.add_edge(as[0],bs[0]);
  lca.add_edge(as[0],bs[0]);
  for(int i=1;i<n;i++){
    cin>>as[i]>>bs[i];
    mo.add_edge(as[i],bs[i]);
    lca.add_edge(as[i],bs[i]);
  }
  vector<int> vs(q),ws(q),ls(q);
  for(int i=0;i<q;i++){
    cin>>vs[i]>>ws[i]>>ls[i];
    mo.add_query(vs[i],ws[i]);
  }
  mo.build();
  lca.build();

  for(int i=0;i<n;i++)
    zs[i]=ys[mo.et.child(as[i],bs[i])];

  vector<int> ans(q);
  for(int i=0;i<q;i++){
    int k=mo.process();
    int r=lca.lca(vs[k],ws[k]);
    bit.add(ys[r],+1);
    ans[k]=bit.lower_bound(ls[k])-1;
    bit.add(ys[r],-1);
  }

  for(int a:ans) cout<<cs[a]<<'\n';
  return 0;
}
