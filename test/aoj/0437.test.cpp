// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0437

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../bbst/rbst/rbst.cpp"
#include "../../bbst/rbst/data/ushi.cpp"
#include "../../bbst/rbst/impl/persistent.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  using ll = long long;
  auto f=[&](ll a,ll b){return a+b;};
  auto flip=[&](ll a){return a;};
  using Data = Ushi<ll, decltype(f), decltype(flip)>;
  using Node = Data::Node;
  const size_t LIM = 3e6;
  Persistent<Data, LIM> G(f,flip,0);

  int n,m;
  cin>>n>>m;
  auto as=read<ll>(n);
  auto bs=read<ll>(n);

  auto A=G.build(vector<Node>(as.begin(),as.end()));
  auto B=G.build(vector<Node>(bs.begin(),bs.end()));
  auto R=G.merge(A,B);

  for(int i=0;i<m;i++){
    int t;
    cin>>t;

    tie(A,B)=G.split(R,n);

    if(t==0){
      int x,y,z;
      cin>>x>>y>>z;
      x--;y--;
      auto pa=G.split(A,x);
      auto qa=G.split(pa.second,z);

      auto pb=G.split(B,y);
      auto qb=G.split(pb.second,z);

      A=G.merge(pa.first,G.merge(qb.first,qa.second));
    }

    if(t==1){
      int p,q;
      cin>>p>>q;
      p--;
      cout<<G.query(A,p,q)<<newl;
    }

    R=G.merge(A,B);

    if(G.almost_full()) R=G.rebuild(R);
  }
  return 0;
}
