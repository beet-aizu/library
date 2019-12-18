#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_J"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../mod/enumeration.cpp"
#include "../../mod/partition_function.cpp"
#undef call_from_test

signed main(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Partition<Mint<int>>(n,k)(n,k).v);
  return 0;
}
