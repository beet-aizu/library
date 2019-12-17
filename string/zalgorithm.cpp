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

#define call_from_test
#include "../datastructure/binaryindexedtree.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed CFR432_D(){
  string s;
  cin>>s;
  vector<int> as=zalgorithm(s);
  int n=s.size();
  set<int> ss;
  BIT<int> bit(n+100);
  for(int i=0;i<n;i++){
    bit.add0(as[i],1);
    if(i+as[i]!=n) continue;
    ss.emplace(as[i]);
  }
  cout<<ss.size()<<"\n";
  for(auto x:ss) cout<<x<<" "<<bit.query0(x,n+100)<<"\n";
  return 0;
}
/*
  verified on 2019/12/17
  http://codeforces.com/problemset/problem/432/D
*/

signed main(){
  CFR432_D();
  return 0;
}
#endif
