// verification-helper: PROBLEM https://judge.yosupo.jp/problem/enumerate_primes

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/enumerate_primes.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,a,b;
  cin>>n>>a>>b;

  auto ps=enumerate_primes(n);
  vector<int> qs;
  for(int i=b;i<(int)ps.size();i+=a)
    qs.emplace_back(ps[i]);

  cout<<ps.size()<<' '<<qs.size()<<endl;
  for(int i=0;i<(int)qs.size();i++){
    if(i) cout<<' ';
    cout<<qs[i];
  }
  cout<<endl;
  return 0;
}
