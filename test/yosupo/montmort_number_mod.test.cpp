// verification-helper: PROBLEM https://judge.yosupo.jp/problem/montmort_number_mod

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/montmort.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  Montmort<int> mm(n,m);
  for(int i=1;i<=n;i++){
    if(i) cout<<" ";
    cout<<mm[i];
  }
  cout<<endl;
  return 0;
}
