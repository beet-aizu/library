#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/isprime.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;
  int ans=0;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    ans+=isprime(x);
  }
  cout<<ans<<endl;
  return 0;
}
