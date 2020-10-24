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
      cout<<1<<newl;
      continue;
    }

    if(gs==vector<int>(n,1)){
      cout<<0<<newl;
      continue;
    }
    sort(gs.rbegin(),gs.rend());
    while(gs.back()==1) gs.pop_back();

    using ll = long long;
    int res=order<ll>(gs[0],MOD);
    for(int x:gs) res=lcm(res,order<ll>(x,MOD));

    cout<<(res%order<ll>(a,MOD)==0?1:0)<<newl;
  }
  return 0;
}
