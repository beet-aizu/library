#pragma once
#include <iostream>

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// n questions, q operations
vector<int> parallel_binary_search(int n,int q,
                                   function<void(void)> init,
                                   function<void(int)> apply,
                                   function<bool(int)> check){
  vector< vector<int> > C(q);
  vector<int> L(n,-1),R(n,q);
  bool flg=1;
  while(flg){
    flg=0;
    init();
    for(int i=0;i<n;i++)
      if(L[i]+1<R[i]) C[(L[i]+R[i])>>1].emplace_back(i);
    for(int i=0;i<q;i++){
      flg|=!C[i].empty();
      apply(i);
      for(int j:C[i]){
        if(check(j)) R[j]=i;
        else L[j]=i;
      }
      C[i].clear();
    }
  }
  return R;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
