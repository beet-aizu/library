// verification-helper: PROBLEM https://judge.yosupo.jp/problem/static_range_frequency

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../datastructure/waveletmatrix.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  auto as=read(n);
  WaveletMatrix<int, 30> wm(as);

  for(int i=0;i<q;i++){
    int l,r,x;
    cin>>l>>r>>x;
    cout<<wm.rank(x,r)-wm.rank(x,l)<<'\n';
  }
  return 0;
}
