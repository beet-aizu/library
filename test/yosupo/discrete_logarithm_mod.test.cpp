#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/log.cpp"
#undef call_from_test

signed main(){
  int T;
  cin>>T;
  while(T--){
    int x,y,m;
    cin>>x>>y>>m;
    int l=mod_log(x,y,m);
    if(l==m) l=-1;
    cout<<l<<"\n";
  }
  cout<<flush;
  return 0;
}
