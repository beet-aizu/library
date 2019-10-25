#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
// longest common prefix of s and s[i:n]
vector<int> zalgorithm(string s){
  int n=s.size();
  vector<int> a(n,0);
  a[0]=n;
  int i=1,j=0;
  while(i<n){
    while(i+j<n&&s[j]==s[i+j]) j++;
    a[i]=j;
    if(j==0){
      i++;
      continue;
    }
    int k=1;
    while(i+k<n&&k+a[k]<j) a[i+k]=a[k],k++;
    i+=k;
    j-=k;
  }
  return a;
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
  BIT<int> bit(n+100,0);
  for(int i=0;i<n;i++){
    bit.add0(as[i],1);
    if(i+as[i]!=n) continue;
    ss.emplace(as[i]);
  }
  cout<<ss.size()<<endl;
  for(auto x:ss) cout<<x<<" "<<bit.sum0(x)<<endl;
  return 0;
}
/*
  verified on 2019/10/25
  http://codeforces.com/problemset/problem/432/D
*/

signed main(){
  CFR432_D();
  return 0;
}
#endif
