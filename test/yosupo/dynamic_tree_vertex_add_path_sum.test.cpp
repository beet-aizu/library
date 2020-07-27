#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/path.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,q;
  cin>>n>>q;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  using ll = long long;
  using Node = NodeBase<ll, ll>;
  auto f=[&](ll a,ll b){return a+b;};
  constexpr size_t LIM = 2e5+100;
  using LCT = Path<Node, LIM>;
  LCT lct(f,f,f,0);

  for(int i=0;i<n;i++) lct.create(as[i]);

  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    lct.evert(lct[v]);
    lct.link(lct[u],lct[v]);
  }

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int u,v,w,x;
      cin>>u>>v>>w>>x;

      lct.evert(lct[u]);
      lct.cut(lct[v]);

      lct.evert(lct[x]);
      lct.link(lct[w],lct[x]);
    }

    if(t==1){
      int p,x;
      cin>>p>>x;
      lct.evert(lct[p]);
      lct.update(lct[p],x);
    }

    if(t==2){
      int u,v;
      cin>>u>>v;
      lct.evert(lct[u]);
      cout<<lct.query(lct[v])<<newl;
    }
  }
  return 0;
}
