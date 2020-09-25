// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3062

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/factorize.cpp"
#include "../../mod/pow.cpp"
#include "../../mod/order.cpp"
#undef call_from_test

signed main(){
  int MOD;
  cin>>MOD;

  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;

    vector<int> g(n);
    for(int i=0;i<n;i++) cin>>g[i];

    int a;
    cin>>a;

    if(a==1){
      cout<<1<<"\n";
      continue;
    }

    sort(g.rbegin(),g.rend());
    if(g[0]==1){
      cout<<0<<"\n";
      continue;
    }
    while(g.back()==1) g.pop_back();

    auto mlcm=[&](int a,int b){return a/__gcd(a,b)*b;};

    int res=order(g[0],MOD);
    for(int x:g) res=mlcm(res,order(x,MOD));

    cout<<(res%order(a,MOD)==0?1:0)<<"\n";
  }
  cout<<flush;
  return 0;
}
