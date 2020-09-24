#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../math/linearfunction.cpp"
#include "../../datastructure/slidingwindowaggregation.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using M = Mint<int, 998244353>;
  using T = LinearFunction<M>;
  auto f=[](T a,T b){return a*b;};
  SWAG<T, T> swag(f,T::mul_identity());

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int a,b;
      cin>>a>>b;
      swag.push(T(M(a),M(b)));
    }
    if(t==1){
      swag.pop();
    }
    if(t==2){
      int x;
      cin>>x;
      swag.fold([&](T a,T b){cout<<f(a,b)(x)<<"\n";});
    }
  }
  return 0;
}
