#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_L"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../combinatorics/partitiontable.cpp"
#undef call_from_test

signed main(){
  int n,k;
  scanf("%d %d",&n,&k);
  PartitionTable<Mint<int>> P(n,k);
  printf("%d\n",k<=n?P(n-k,k).v:0);
  return 0;
}
