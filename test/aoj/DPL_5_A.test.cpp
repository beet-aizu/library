// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../combinatorics/enumeration.cpp"
#undef call_from_test

signed main(){
  int n;
  Mint<int> k;
  scanf("%d %d",&n,&k.v);
  printf("%d\n",k.pow(n).v);
  return 0;
}
