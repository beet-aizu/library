// verification-helper: PROBLEM https://judge.yosupo.jp/problem/range_kth_smallest

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/waveletmatrix.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  WaveletMatrix<int, 30> wm(as);

  for(int i=0;i<q;i++){
    int l,r,k;
    cin>>l>>r>>k;
    cout<<wm.rquantile(l,r,k)<<"\n";
  }
  cout<<flush;
  return 0;
}
