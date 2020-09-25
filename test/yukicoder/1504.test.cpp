// verification-helper: PROBLEM https://yukicoder.me/problems/1504

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../convolution/garner.cpp"
#include "../../mod/rint.cpp"
#include "../../mod/factorial.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  const int MOD = 1e9+7;
  long long n;
  cin>>n;
  cout<<factorial(n,MOD)<<endl;
  return 0;
}
