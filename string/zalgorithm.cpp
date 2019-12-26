#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// longest common prefix of s and s[i:n]
vector<int> zalgorithm(string s){
  int n=s.size();
  vector<int> as(n,0);
  as[0]=n;
  int i=1,j=0;
  while(i<n){
    while(i+j<n&&s[j]==s[i+j]) j++;
    as[i]=j;
    if(j==0){
      i++;
      continue;
    }
    int k=1;
    while(i+k<n&&k+as[k]<j) as[i+k]=as[k],k++;
    i+=k;
    j-=k;
  }
  return as;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
