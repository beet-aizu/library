#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
#define MOD 1000000007
#define MAX_P 200005
Int fact[MAX_P];

Int extgcd(Int a,Int b,Int& x,Int& y){
  Int d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}
Int mod_inverse(Int a,Int mod){
  Int x,y;
  extgcd(a,mod,x,y);
  return (mod+x%mod)%mod;
}

void init(Int mod){
  fact[0]=1;
  for(Int i=1;i<MAX_P;i++)
    fact[i]=(fact[i-1]*i)%mod;
}

Int mod_fact(Int n,Int mod,Int& e){
  e=0;
  if(n==0) return 1;
  Int res=mod_fact(n/mod,mod,e);
  e+=n/mod;
  if(n/mod%2!=0)return res*(mod-fact[n%mod]) %mod;
  return res*fact[n%mod]%mod;
}

Int mod_comb(Int n,Int k,Int mod){
  if(n==k||k==0) return 1;
  Int e1,e2,e3;
  Int a1=mod_fact(n,mod,e1),a2=mod_fact(k,mod,e2),a3=mod_fact(n-k,mod,e3);
  if(e1>e2+e3) return 0;
  return a1*mod_inverse(a2*a3%mod,mod)%mod;
}

//END CUT HERE
//INSERT ABOVE HERE

//extgcd
signed AOJ_NTL1E(){
  Int a,b;
  cin>>a>>b;
  Int x,y;
  extgcd(a,b,x,y);
  cout<<x<<" "<<y<<endl;
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=jp
*/

signed main(){
  AOJ_NTL1E();
  return 0;
}
