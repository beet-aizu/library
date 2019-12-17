#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../algorithm/knuthyao.cpp"
#undef call_from_test

signed main(){
  using ll = long long;
  int n;
  cin>>n;
  vector<ll> ws(n);
  for(int i=0;i<n;i++) cin>>ws[i];
  vector<ll> sm(n+1);
  for(int i=0;i<n;i++) sm[i+1]=sm[i]+ws[i];
  auto cost=[&](int i,int k,int j){(void) k;return sm[j+1]-sm[i];};
  cout<<KnuthYao<ll>(n,cost)<<endl;
  return 0;
}
