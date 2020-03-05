#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/sqrt.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int T;
  cin>>T;
  for(int t=0;t<T;t++){
    int y,p;
    cin>>y>>p;
    auto res=mod_sqrt(y,p);
    if(res.empty()) cout<<-1<<"\n";
    else cout<<res[0]<<"\n";
  }
  cout<<flush;
  return 0;
}
