#define PROBLEM "https://yukicoder.me/problems/2147"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../datastructure/waveletmatrix.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;
  vector<int> xs(n);
  for(int i=0;i<n;i++) cin>>xs[i],xs[i]--;

  WaveletMatrix<int, 20> wm(xs);

  int ans=n*(n-1);
  for(int i=0;i<n;i++){
    ans-=wm.rangefreq(0,i,0,xs[i]);
    ans-=wm.rangefreq(i+1,n,xs[i]+1,n*2);
  }
  cout<<ans/2<<endl;
  return 0;
}
