#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../mod/enumeration.cpp"
#undef call_from_test

signed main(){
  int n,k;
  scanf("%d %d",&n,&k);
  Enumeration<Mint<int>>::init(k);
  printf("%d\n",(Enumeration<Mint<int>>::S(n,k)*
                 Enumeration<Mint<int>>::Fact(k)).v);
  return 0;
}
