#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../combinatorics/enumeration.cpp"
#include "../../combinatorics/surjection.cpp"
#undef call_from_test

signed main(){
  int n,k;
  scanf("%d %d",&n,&k);
  using M = Mint<int>;
  M res=surjection<M>(n,k);
  for(int i=1;i<=k;i++) res/=M(i);
  printf("%d\n",res.v);
  return 0;
}
