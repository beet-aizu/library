#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2977"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../convolution/convolution2D.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,k,l;
  cin>>n>>m>>k>>l;
  vector<string> bs(n);
  for(int i=0;i<n;i++) cin>>bs[i];

  string s;
  cin>>s;

  NTT<0> ntt;
  using M = NTT<0>::M;
  auto tran=[&](auto &as,bool f){ntt.ntt(as,f);};
  Convolution2D<M, decltype(tran)> conv(tran);

  using Matrix=Convolution2D<M, decltype(tran)>::Matrix;

  Matrix A(n,vector<M>(n,0));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      A[i][j]=M(bs[i][j]=='X');

  Matrix B(m-n+1,vector<M>(m-n+1,0));
  int cy=0,cx=0;
  for(int i=0;i<l;i++){
    if(s[i]=='L') cx--;
    if(s[i]=='R') cx++;
    if(s[i]=='U') cy--;
    if(s[i]=='D') cy++;

    B[cy][cx]+=M(1);
  }

  auto C=conv.multiply(A,B);
  int ans=0;
  for(int i=0;i<m;i++)
    for(int j=0;j<m;j++)
      if(C[i][j].v>=k) ans++;

  cout<<ans<<endl;
  return 0;
}
