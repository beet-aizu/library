#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
Int phi(Int n){
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

Int mpow(Int x,Int n,Int m){
  Int v=1;
  while(n){
    if(n&1) v=v*x%m;
    x=x*x%m;
    n>>=1;
  }
  return v;
}

const Int MAX = 1e8;
Int tetr(Int a,Int n){
  if(n==0) return 1;  
  if(a==1) return 1;
  Int v=1;
  for(Int i=0;i<n;i++){
    Int u=1;
    for(Int j=0;j<v;j++){
      u*=a;
      if(u>MAX) return -1;
    }
    v=u;
  }
  return v;
}

Int mtetra(Int a,Int n,Int m){
  if(m==1) return 0;
  if(n==0) return 1;
  Int x=tetr(a,n-1);
  if(~x) return mpow(a,x,m);
  Int v=phi(m);
  return mpow(a,MAX+((mtetra(a,n-1,v)-MAX)%v+v)%v,m);
}
//END CUT HERE
//INSERT ABOVE HERE

signed solve(){
  Int a,n,m;
  cin>>a>>n>>m;
  cout<<mtetra(a,n,m)<<endl;
  return 0;
}

signed main(){
  solve();
}
