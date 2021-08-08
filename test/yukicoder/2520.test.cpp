// verification-helper: PROBLEM https://yukicoder.me/problems/2520

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../math/sum_of_geometric_sequence.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using M = Mint<int>;
  long long n;
  cin>>n;
  cout<<M(10).pow(n)+M(3)*sum_of_geometric_sequence(M(10),n)<<endl;
  return 0;
}
