#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct fraction{
  T num,dom;
  fraction(){}
  fraction(T n,T d):num(n),dom(d){
    assert(dom!=0);
    if(dom<0) num*=-1,dom*=-1;
    T tmp=__gcd(abs(num),abs(dom));
    num/=tmp;
    dom/=tmp;
  }
  fraction operator+(const fraction a) const{
    return fraction(num*a.dom+a.num*dom,dom*a.dom);
  }
  fraction operator-(const fraction a) const{
    return fraction(num*a.dom-a.num*dom,dom*a.dom);
  }
  fraction operator*(const fraction a) const{
    return fraction(num*a.num,dom*a.dom);
  }
  fraction operator/(const fraction a){
    return fraction(num*a.dom,dom*a.num);
  }
  fraction operator*(T k) const{return fraction(num*k,dom);}
  fraction operator/(T k) const{return fraction(num,dom*k);}
  bool operator<(const fraction a)const{
    return num*a.dom<a.num*dom;
  }
  bool operator>(const fraction a)const{
    return num*a.dom>a.num*dom;
  }
  bool operator==(const fraction a)const{
    return num*a.dom==a.num*dom;
  }
  bool operator!=(const fraction a)const{
    return num*a.dom!=a.num*dom;
  }
  bool operator<=(const fraction a)const{
    return num*a.dom<=a.num*dom;
  }
  bool operator>=(const fraction a)const{
    return num*a.dom>=a.num*dom;
  }
};
//END CUT HERE
#ifndef call_from_test
struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed CPSCO2019_Session3_G(){
  using ll = long long;

  int n,x;
  cin>>n>>x;

  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  using F = fraction<ll>;
  using T = tuple<F, int, int>;
  priority_queue<T> pq;

  int sum=0;
  for(int i=0;i<n;i++) sum+=as[i];

  for(int i=0;i<n;i++){
    int p=x*as[i]/sum;
    pq.emplace(F(1,as[i]),i,p);
    if((x*as[i])%sum!=0)
      pq.emplace(F(2*x,sum)-F(2*p+1,as[i]),i,1);
    pq.emplace(F(-1,as[i]),i,x+1);
  }

  vector<int> bs(n,0);
  int k=x;
  while(k>0){
    int i,l;
    tie(ignore,i,l)=pq.top();pq.pop();

    int t=min(k,l);
    bs[i]+=t;
    k-=t;
  }

  for(int i=0;i<n;i++) cout<<bs[i]<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/12/17
  https://atcoder.jp/contests/cpsco2019-s3/tasks/cpsco2019_s3_g
*/

signed main(){
  //CPSCO2019_Session3_G();
  return 0;
}
#endif
