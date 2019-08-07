#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_L
#define main moin
#include "../../mod/enumeration.cpp"
#undef main

signed main(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",n>=k?Enumeration<Mint<int>>::D(n,k)[n-k][k].v:0);
  return 0;
}
