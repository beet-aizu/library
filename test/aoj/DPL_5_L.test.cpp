#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_L"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../mod/enumeration.cpp"
#undef call_from_test

signed main(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",n>=k?Enumeration<Mint<int>>::D(n,k)[n-k][k].v:0);
  return 0;
}
