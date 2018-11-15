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

Int mpow(Int a,Int n,Int m,Int &f){
  using ull = unsigned long long;
  if(a==1||n==0) return 1;
  ull v=1,x=a,z=m;
  f|=x>=z;
  x%=m;
  while(1){
    if(n&1) v*=x;
    if(v>=z) f=1,v%=m;
    n>>=1;
    if(!n) break;
    x=x*x;
    if(x>=z) f=1,x%=m;
  }
  return v;
}

Int mtetra(Int a,Int n,Int m,Int &f){
  if(a==0) return ~n&1;
  if(m==1) return f=1;
  if(a==1||n==0) return 1;
  if(n==1){
    f|=a>=m;
    return a%m+f*m;
  }
  Int z=mtetra(a,n-1,phi(m),f);
  Int r=mpow(a,z,m,f);  
  return r+f*m;
}
//END CUT HERE
//INSERT ABOVE HERE

signed YUKI_181(){
  Int a,n,m,f=0;
  cin>>a>>n>>m;
  cout<<mtetra(a,n,m,f)%m<<endl;
  return 0;
}
/*
  verified on 2018/11/15
  https://yukicoder.me/problems/no/181
*/

signed SPOJ_POWTOW(){
  Int T;
  cin>>T;
  while(T--){
    Int a,n,f=0;
    cin>>a>>n;
    stringstream ss;  
    ss<<mtetra(a,n,1e9,f)%Int(1e9);
    auto s=ss.str();
    if(f){
      while(s.size()<9u) s='0'+s;
      cout<<"..."<<s<<endl;
    }else{
      cout<<s<<endl;
    }
  }
  return 0;
}
/*
  verified on 2018/11/15
  https://www.spoj.com/problems/POWTOW/
*/

signed SPOJ_MTETRA(){
  Int T;
  scanf("%lld",&T);
  while(T--){    
    Int a,n,m,f=0;
    scanf("%lld %lld %lld",&a,&n,&m);
    printf("%lld\n",mtetra(a,n,m,f)%m);
  }
  return 0;
}
/*
  verified on 2018/11/15
  https://www.spoj.com/problems/MTETRA/
*/

signed SUMMERFES2018_F(){
  Int a,m,k;
  cin>>a>>m>>k;
  Int ans=0;
 
  k--;
  for(Int i=0,p=-1;i<k;i++){
    Int f=0;
    Int x=mtetra(a,i,m,f)%m;
    if(p==x){
      ans+=(k-i)%m*x%m;
      ans%=m;
      break;
    }
    ans+=x;
    ans%=m;
    p=x;
  }
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2018/11/15
  https://beta.atcoder.jp/contests/summerfes2018-div1/tasks/summerfes2018_f
*/

signed main(){
  //YUKI_181();
  //SPOJ_POWTOW();
  //SPOJ_MTETRA();
  //SUMMERFES2018_F();
}
