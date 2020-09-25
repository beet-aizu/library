// verification-helper: PROBLEM https://yukicoder.me/problems/3453

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../toptree/toptree.cpp"
#include "../../toptree/steiner.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  const size_t LIM = 3e6;
  using Cluster = SteinerTree<long long>;
  TopTree<Vertex, Cluster, LIM> G;

  int n;
  cin>>n;

  vector<Vertex*> vs(n);
  for(int i=0;i<n;i++) vs[i]=G.create();

  for(int i=1;i<n;i++){
    int u,v,w;
    cin>>u>>v>>w;
    G.link(vs[u],Cluster(w),vs[v]);
  }

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;

    if(t==1){
      int u,v,w,x;
      cin>>u>>v>>w>>x;
      G.cut(vs[u],vs[v]);
      G.link(vs[v],Cluster(x),vs[w]);
    }

    if(t==2){
      int k;
      cin>>k;
      vector<int> xs(k);
      for(int j=0;j<k;j++) cin>>xs[j];

      for(int x:xs) G.set_vertex(vs[x],Vertex(1));

      cout<<G.get_subtree(vs[xs[0]]).ans<<newl;

      for(int x:xs) G.set_vertex(vs[x],Vertex(0));
    }
  }

  return 0;
}
