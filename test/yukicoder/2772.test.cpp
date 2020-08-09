#define PROBLEM "https://yukicoder.me/problems/2772"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../combinatorics/enumeration.cpp"
#include "../../combinatorics/surjection.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;

  using M = Mint<int>;
  cout<<surjection<M>(n,m)<<endl;
  return 0;
}
