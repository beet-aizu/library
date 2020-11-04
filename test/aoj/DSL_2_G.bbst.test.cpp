// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bbst/rbst/rbst.cpp"
#include "../../bbst/rbst/data/lazy.cpp"
#include "../../bbst/rbst/impl/basic.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,q;
  cin>>n>>q;

  using ll = long long;
  using P = pair<ll, ll>;
  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,ll b){return P(a.first+b*a.second,a.second);};
  auto h=[](ll a,ll b){return a+b;};
  auto flip=[](P a){return a;};

  using Data = Lazy<P, ll, decltype(f), decltype(g), decltype(h),
                    decltype(flip)>;
  using Node = Data::Node;
  constexpr size_t LIM = 1e6;
  Basic<Data, LIM> G(f,g,h,flip,P(0,0),0);
  auto rt=G.build(vector<Node>(n,Node(P(0,1),0)));

  for(int i=0;i<q;i++){
    int c;
    cin>>c;
    if(c==0){
      int s,t,x;
      cin>>s>>t>>x;
      s--;
      rt=G.update(rt,s,t,x);
    }
    if(c==1){
      int s,t;
      cin>>s>>t;
      s--;
      cout<<G.query(rt,s,t).first<<newl;
    }
  }
  return 0;
}
