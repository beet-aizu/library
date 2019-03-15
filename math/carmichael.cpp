#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
// return maximum order in ((Z/nZ)*, *)
Int carmichael_lambda(Int n){
  auto lcm=[](auto a,auto b){return a/__gcd(a,b)*b;};
  Int res=1;
  if(n%8==0) n/=2;
  for(Int i=2;i*i<=n;i++){
    if(n%i==0){
      Int tmp=i-1;
      for(n/=i;n%i==0;n/=i) tmp*=i;
      res=lcm(res,tmp);
    }
  }
  if(n!=1) res=lcm(res,n-1);
  return res;
}
//END CUT HERE
//INSERT ABOVE HERE
// x^n mod m
Int mpow(Int x,Int n,Int m){
  Int r=1;
  x%=m;
  while(n){
    if(n&1) r=r*x%m;
    x=x*x%m;
    n>>=1;
  }
  return r;
}

signed main(){
  Int n;
  cin>>n;
  if(n==2){
    cout<<1<<endl;
    return 0;
  }
  for(Int i=2;i*i<=n;i++){
    if(n%(i*i)==0){
      cout<<-1<<endl;
      return 0;
    }
  }
  Int a=carmichael_lambda(n);
  Int b=carmichael_lambda(a);
  assert(n!=1);
  assert(a!=1);
  assert(b!=0);
  {
    Int x=mpow(n,b,a)!=1;
    Int y=__gcd(n%a,a)!=1;
    assert(x==y);
  }
  if(mpow(n,b,a)!=1){
    assert(n%a!=1);
    cout<<-1<<endl;
    return 0;
  }

  if(n%a==1) b=1;
  for(Int i=2;i*i<=b;i++){
    if(b%i!=0) continue;
    while(b%i==0){
      if(mpow(n,b/i,a)==1) b/=i;
      else break;
    }
    Int j=b/i;
    if(j==1) continue;
    while(b%j==0){
      if(mpow(n,b/j,a)==1) b/=j;
      else break;
    }
  }                 
  cout<<b<<endl;
  return 0;
}
