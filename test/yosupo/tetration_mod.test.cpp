#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../math/totient.cpp"
#include "../../mod/tetration.cpp"
#undef call_from_test

signed main(){
  int T;
  cin>>T;
  for(int t=0;t<T;t++){
    int a,b,m;
    cin>>a>>b>>m;
    cout<<tetration(a,b,m)<<"\n";
  }
  cout<<flush;
  return 0;
}
