#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
#define MAX_N 1000000
Int euler_phi(Int n){
  Int res=n;
  for(Int i=2;i*i<=n;i++){
    if(n%i==0){
      res=res/i*(i-1);
      for(;n%i==0;n/=i);
    }
  }
  if(n!=1) res=res/n*(n-1);
  return res;
}

Int euler[MAX_N];

void euler_phi2(){
  for(Int i=0;i<MAX_N;i++) euler[i]=i;
  for(Int i=2;i<MAX_N;i++){
    if(euler[i]==i){
      for(Int j=i;j<MAX_N;j+=i) euler[j]=euler[j]/i*(i-1);
    }
  }
}
//END CUT HERE

//euler_phi:
signed AOJ_NTL1D(){
  Int n;
  cin>>n;
  cout<<euler_phi(n)<<endl;
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D&lang=jp
*/

signed main(){
  //AOJ_NTL1D();
  euler_phi2();
  int n;
  cin>>n;
  Int ans=0;
  for(Int i=1;i<=n;i++) ans+=euler[i];
  cout<<(ans*4+4)<<endl;
  return 0;
}
