#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T>
T extgcd(T a,T b,T& x,T& y){
  T d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}
template<typename T>
T mod_inverse(T a,T mod){
  T x,y;
  extgcd(a,mod,x,y);
  return (x%mod+mod)%mod;
}
#endif
//BEGIN CUT HERE
template<typename T>
pair<T, T> linear_congruence(const vector<T> &A,
                             const vector<T> &B,
                             const vector<T> &M){
  T x=0,m=1;
  for(int i=0;i<(int)A.size();i++){
    T a=A[i]*m,b=B[i]-A[i]*x,d=__gcd(M[i],a);
    if(b%d!=0) return make_pair(0,-1);
    T t=b/d*mod_inverse(a/d,M[i]/d)%(M[i]/d);
    x=x+m*t;
    m*=M[i]/d;
  }
  return make_pair((x%m+m)%m,m);
}
//END CUT HERE
#ifndef call_from_test

int is_prime(Int x){
  if(x<=1) return 0;
  for(Int i=2;i*i<=x;i++)
    if(x%i==0) return 0;
  return 1;
}

signed DDCC2018QUALB_D(){
  const Int n = 30;
  vector<Int> A,B,M;

  vector<Int> x(n+1);
  for(Int i=2;i<=n;i++){
    cin>>x[i];
    if(!is_prime(i-1)) continue;
    A.emplace_back(1);
    B.emplace_back(x[i]%(i-1));
    M.emplace_back(i-1);
  }
  auto p=linear_congruence(A,B,M);
  if(p.second<Int(0)){
    cout<<"invalid"s<<endl;
    return 0;
  }
  Int LIM(1e12);
  Int res=p.first,dif=p.second;
  while(res<=LIM){
    Int flg=1;
    for(Int i=2;i<=n;i++){
      Int sum=0,tmp=res;
      while(tmp>Int(0)){
        sum+=tmp%i;
        tmp/=Int(i);
      }
      flg&=(sum==x[i]);
    }
    if(flg){
      cout<<res<<endl;
      return 0;
    }
    res+=dif;
  }
  cout<<"invalid"s<<endl;
  return 0;
}
/*
   verified on 2019/10/08
   https://atcoder.jp/contests/ddcc2019-qual/tasks/ddcc2018_qual_d
*/

signed YUKI_186(){
  vector<Int> A(3,1),B(3),M(3);
  for(Int i=0;i<3;i++) cin>>B[i]>>M[i];
  auto p=linear_congruence(A,B,M);
  if(p.second==-1) cout<<-1<<endl;
  else cout<<(p.first?p.first:p.second)<<endl;
  return 0;
}
/*
   verified on 2019/10/08
   https://yukicoder.me/problems/no/186
*/

//INSERT ABOVE HERE
signed main(){
  //DDCC2018QUALB_D();
  //YUKI_186();
  return 0;
}
#endif
