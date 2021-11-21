// verification-helper: PROBLEM https://yukicoder.me/problems/3267

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/divisor.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  const int MAX = 3e6+100;
  using M = Mint<int>;
  vector<M> ys(MAX,0),xs(MAX,0);

  int h,w;
  cin>>h>>w;
  for(int i=1;i<h;i++) ys[i]=h-i;
  for(int j=1;j<w;j++) xs[j]=w-j;

  GCDConvolution::zeta(ys);
  GCDConvolution::zeta(xs);
  for(int i=1;i<MAX;i++) ys[i]*=xs[i];
  GCDConvolution::moebius(ys);

  M ans{0};
  ans+=ys[1]*M(2);
  ans+=M(h-1)*M(w);
  ans+=M(h)*M(w-1);
  cout<<ans<<endl;

  return 0;
}
