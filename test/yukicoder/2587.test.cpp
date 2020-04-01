#define PROBLEM "https://yukicoder.me/problems/2587"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../toptree/toptree.cpp"
#include "../../toptree/distancesum.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,q;
  cin>>n>>q;

  using ll = long long;
  const size_t LIM = 3e6;
  DistanceSum<ll, LIM> G;
  using Vertex = decltype(G)::Vertex;
  using Cluster = decltype(G)::Cluster;

  vector<int> xs(n,1);
  vector<Vertex*> vs(n);
  for(int i=0;i<n;i++) vs[i]=G.G.create(Vertex(xs[i]));

  ll pre=0;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;

    if(t==1){
      int a,b,c;
      cin>>a>>b>>c;
      a--;b--;
      a+=pre;a%=n;
      b+=pre;b%=n;
      G.G.link(vs[a],Cluster(c),vs[b]);
    }

    if(t==2){
      int a,b;
      cin>>a>>b;
      a--;b--;
      a+=pre;a%=n;
      b+=pre;b%=n;
      G.G.cut(vs[a],vs[b]);
    }

    if(t==3){
      int a;
      cin>>a;
      a--;
      a+=pre;a%=n;
      xs[a]^=1;
      G.G.set_vertex(vs[a],Vertex(xs[a]));

      auto cc=G.centroid(vs[a]);
      ll res=G.query(cc);
      cout<<res<<newl;
      pre+=res;pre%=n;
    }
  }
  return 0;
}
