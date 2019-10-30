#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0314"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/mint.cpp"
#include "../../linearalgebra/matrix.cpp"
#include "../../datastructure/unionfindtree.cpp"
#include "../../linearalgebra/tree_theorem.cpp"
#undef call_from_test

signed main(){
  int n,m;
  cin>>n>>m;
  using M = Mint<int>;
  using edge=MatrixTreeTheorem<M, int>::edge;
  vector<edge> es;
  for(int i=0;i<m;i++){
    int s,t,d;
    cin>>s>>t>>d;
    s--;t--;
    es.emplace_back(s,t,d);
  }
  sort(es.begin(),es.end());
  UnionFind uf(n);
  int cost=0;
  for(auto e:es){
    uf.unite(e.a,e.b);
    cost=e.c;
    if(uf.count()==1) break;
  }
  cout<<cost<<" ";

  uf=UnionFind(n);
  for(auto e:es){
    if(e.c==cost) break;
    uf.unite(e.a,e.b);
  }

  vector<int> rs;
  for(int i=0;i<n;i++)
    if(uf.find(i)==i) rs.emplace_back(i);

  M ans{0};
  int k=rs.size();
  int sz=1<<k;
  for(int b=1;b+1<sz;b++){
    UnionFind tmp(uf);
    for(int i=0;i<k;i++)
      for(int j=0;j<k;j++)
        if(((b>>i)&1)==((b>>j)&1))
          tmp.unite(rs[i],rs[j]);

    MatrixTreeTheorem<M, int> G(n);
    for(auto e:es)
      if(tmp.same(e.a,e.b))
        G.add_edge(e.a,e.b,0);

    M res=G.build();

    if(G.uf.count()==2)
      ans+=res;
  }
  cout<<ans<<endl;
  return 0;
}
