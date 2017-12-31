#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
int isprime(int x){
  if(x<=1) return 0;
  for(int i=2;i*i<=x;i++)
    if(x%i==0) return 0;
  return 1;
}
//END CUT HERE
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
/*
  verified on 2017/12/30
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp
*/
