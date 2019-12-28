#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/mint.cpp"
#include "../../datastructure/slidingwindowaggregation.cpp"
#undef call_from_test

signed main(){
  using M = Mint<int, 998244353>;
  using P = pair<M, M>;
  auto f=[](P a,P b){return P(a.first*b.first,a.second*b.first+b.second);};
  SWAG<P, P> swag(f,P(M(1),M(0)));

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int a,b;
      cin>>a>>b;
      swag.push(P(M(a),M(b)));
    }
    if(t==1){
      swag.pop();
    }
    if(t==2){
      int x;
      cin>>x;
      auto q=
        [&](P a,P b){
          P res=f(a,b);
          cout<<res.first*M(x)+res.second<<"\n";
        };
      swag.fold(q);
    }
  }

  cout<<flush;
  return 0;
}
