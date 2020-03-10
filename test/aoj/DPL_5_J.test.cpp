#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_J"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../combinatorics/enumeration.cpp"
#include "../../combinatorics/partitiontable.cpp"
#undef call_from_test

signed main(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",PartitionTable<Mint<int>>(n,k)(n,k).v);
  return 0;
}
