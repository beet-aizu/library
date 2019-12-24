#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/montmort.cpp"
#undef call_from_test

signed main(){
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
