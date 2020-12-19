// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0168

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/bostan_mori.cpp"
#undef call_from_test

signed main(){
  using ll = long long;
  using Poly = vector<ll>;
  auto conv=[](Poly as, Poly bs){
    Poly cs(as.size()+bs.size()-1,0);
    for(int i=0;i<(int)as.size();i++)
      for(int j=0;j<(int)bs.size();j++)
        cs[i+j]+=as[i]*bs[j];
    return cs;
  };
  BostanMori<ll> bm(conv);

  Poly as({0,0,1}),cs({-1,-1,-1,1});

  int n;
  while(cin>>n,n)
    cout<<(bm.build(n+2,as,cs)+3650-1)/3650<<endl;

  return 0;
}
