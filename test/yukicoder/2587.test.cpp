// verification-helper: PROBLEM https://yukicoder.me/problems/2587

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
  const size_t N = 1e5;
  DistanceSum<ll, N> G;

  vector<int> xs(n,1);
  vector<decltype(G)::Vertex*> vs(n);
  for(int i=0;i<n;i++) vs[i]=G.create(xs[i]);

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
      G.link(vs[a],c,vs[b]);
    }

    if(t==2){
      int a,b;
      cin>>a>>b;
      a--;b--;
      a+=pre;a%=n;
      b+=pre;b%=n;
      G.cut(vs[a],vs[b]);
    }

    if(t==3){
      int a;
      cin>>a;
      a--;
      a+=pre;a%=n;
      xs[a]^=1;
      G.set_vertex(vs[a],xs[a]);

      auto cc=G.centroid(vs[a]);
      ll res=G.query(cc);
      cout<<res<<newl;
      pre+=res;pre%=n;
    }
  }
  return 0;
}
