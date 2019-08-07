#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A
#define main moin
#include "../../mod/enumeration.cpp"
#undef main

signed main(){
  int n;
  Mint<int> k;
  scanf("%d %d",&n,&k.v);
  printf("%d\n",k.pow(n).v);
  return 0;
}
