#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../matrix/squarematrix.cpp"
#include "../../mod/mint.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  const int MAX = 80;
  const int MOD = 1e9+9;
  using M = Mint<int, MOD>;
  using SM = SquareMatrix<M, MAX>;

  using ll = long long;
  ll w,h,n;
  ll cnt=0;
  while(cin>>w>>h>>n,w){
    vector<ll> x(n),y(n);
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    {
      using P = pair<ll, ll>;
      vector<P> vp;
      for(int i=0;i<n;i++) vp.emplace_back(y[i],x[i]);
      sort(vp.begin(),vp.end());
      for(int i=0;i<n;i++) tie(y[i],x[i])=vp[i];
    }
    SM b;
    for(int i=0;i<w;i++){
      b[i][i]=M(1);
      if(i-1>=0) b[i][i-1]=M(1);
      if(i+1<w)  b[i][i+1]=M(1);
    }
    ll d=1;
    SM res=SM::mul_identity();
    for(int k=0;k<n;k++){
      if(y[k]==d) continue;
      res=b.pow(y[k]-d-1)*res;
      int j=k;
      SM c(b);
      while(j<n&&y[k]==y[j]){
        for(int i=0;i<w;i++) c[x[j]-1][i]=0;
        j++;
      }
      res=c*res;
      d=y[k];
    }
    res=b.pow(h-d)*res;
    cout<<"Case "<<++cnt<<": "<<res[w-1][0].v<<endl;
  }
  return 0;
}
