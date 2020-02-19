#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../mod/enumeration.cpp"
#undef call_from_test

signed main(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Enumeration<Mint<int>>::H(n,k).v);
  return 0;
}
