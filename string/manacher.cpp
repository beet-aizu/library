#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
/*
 * @see https://snuke.hatenablog.com/entry/2014/12/02/235837
 */
//BEGIN CUT HERE
vector<int> manacher(string s){
  int n=s.size();
  vector<int> vs(n);
  for(int i=0,j=0;i<n;){
    while(i-j>=0&&i+j<n&&s[i-j]==s[i+j]) j++;
    vs[i]=j;
    int k=1;
    while(i-k>=0&&i+k<n&&k+vs[i-k]<j) vs[i+k]=vs[i-k],k++;
    i+=k;j-=k;
  }
  return vs;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
