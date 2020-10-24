// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3062

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/pow.cpp"
#include "../../mod/order.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int MOD;
  cin>>MOD;

  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;

    vector<int> gs(n);
    for(int i=0;i<n;i++) cin>>gs[i];

    int a;
    cin>>a;

    if(a==1){
      cout<<1<<"\n";
      continue;
    }

    sort(gs.rbegin(),gs.rend());
    if(gs[0]==1){
      cout<<0<<"\n";
      continue;
    }
    while(gs.back()==1) gs.pop_back();

    auto mlcm=[&](int a,int b){return a/gcd(a,b)*b;};

    int res=order(gs[0],MOD);
    for(int x:gs) res=mlcm(res,order(x,MOD));

    cout<<(res%order(a,MOD)==0?1:0)<<newl;
  }
  return 0;
}
