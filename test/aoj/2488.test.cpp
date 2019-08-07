#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2488
#define main moin
#include "../../algorithm/knuthyao.cpp"
#undef main

signed main(){
  using ll = long long;
  int n;
  cin>>n;
  vector<ll> xs(n),ys(n);
  for(int i=0;i<n;i++) cin>>xs[i]>>ys[i];
  auto calc=
    [&](int i,int k,int j){
      return xs[k+1]-xs[i]+ys[k]-ys[j];
    };
  cout<<KnuthYao<ll>(n,calc)<<endl;
  return 0;
}
