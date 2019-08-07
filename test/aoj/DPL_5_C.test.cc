#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_C
#define main moin
#include "../../mod/enumeration.cpp"
#undef main

signed main(){
  int n,k;
  scanf("%d %d",&n,&k);
  Enumeration<Mint<int>>::init(k);
  printf("%d\n",(Enumeration<Mint<int>>::S(n,k)*
                 Enumeration<Mint<int>>::Fact(k)).v);
  return 0;
}
