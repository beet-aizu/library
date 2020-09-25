// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/factorize.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  auto mp=factorize(n);

  cout<<n<<":";
  for(auto p:mp)
    for(int i=0;i<p.second;i++)
      cout<<" "<<p.first;
  cout<<endl;
  return 0;
}
