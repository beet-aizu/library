#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 11
bool e[MAX][MAX];
int mod_pow(int x,int n,int mod){
  int res=1;
  while(n>0){
    if(n&1) (res*=x)%=mod;
    (x*=x)%=mod;
    n>>=1;
  }
  return res;
}
int I[1<<MAX],bn[1<<MAX];
bool check(int n,int k){
  int g=0;
  int MOD=10009;
  for(int i=0;i<(1<<n);i++){
    if(bn[i]%2==0) g+=mod_pow(I[i],k,MOD);
    else g-=mod_pow(I[i],k,MOD);
  }
  return (g%MOD+MOD)%MOD!=0;
}
int paint(int n){
  vector<int> N(1<<n);
  for(int i=0;i<n;i++){
    int bit=(1<<i);
    for(int j=0;j<n;j++)
      if(e[i][j]) bit|=(1<<j);
    N[i]=bit;
  }
  memset(I,0,sizeof(I));
  I[0]=1;
  for(int S=1;S<(1<<n);S++){
    bn[S]=__builtin_popcountll(S);
    int v=0;
    while(!((S>>v)&1)) v++;
    I[S]=I[S-(1<<v)]+I[S&~N[v]];
  }
  int l=0,r=n;
  while(l+1<r){
    int m=(l+r)/2;
    if(check(n,m)) r=m;
    else l=m;
  }
  return r;
}
signed main(){
  
  return 0;
}

/*
  not verified
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1254
*/
