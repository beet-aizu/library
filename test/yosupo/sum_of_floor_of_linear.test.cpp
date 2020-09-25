// verification-helper: PROBLEM https://judge.yosupo.jp/problem/sum_of_floor_of_linear

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/sum_of_floor.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int T;
  cin>>T;
  for(int t=0;t<T;t++){
    long long n,m,a,b;
    cin>>n>>m>>a>>b;
    cout<<sum_of_floor(n,m,a,b)<<"\n";
  }
  cout<<flush;
  return 0;
}
