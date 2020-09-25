// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2488

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../algorithm/knuthyao.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  int n;
  cin>>n;
  vector<ll> xs(n),ys(n);
  for(int i=0;i<n;i++) cin>>xs[i]>>ys[i];
  auto calc=
    [&](int i,int k,int j){
      return (xs[k+1]-xs[i])+(ys[k]-ys[j]);
    };
  cout<<KnuthYao<ll>(n,calc)<<endl;
  return 0;
}
