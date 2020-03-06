#pragma once
#include <iostream>

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct Polynomial{
  using P = Polynomial;
  vector<T> co;
  Polynomial():co(1,T(1)){}
  Polynomial(int sz):co(sz,0){}
  Polynomial(vector<T> co):co(co){}

  size_t size() const{
    return co.size();
  };

  void shrink(){
    while(co.size()>1u&&!co.back())
      co.pop_back();
  }

  void reduce(){
    T g=abs(co.back());
    if(!g) return;
    for(T c:co)
      if(c!=0) g=__gcd(g,abs(c));
    if(co.back()<0) g*=-1;
    for(T &c:co) c/=g;
  }

  void print(){
    shrink();
    reduce();
    int n=size(),flg=0;
    for(int i=n-1;i>0;i--){
      if(!co[i]) continue;
      flg=1;
      if(i!=n-1&&co[i]>0) cout<<"+";
      if(co[i]==-1) cout<<"-";
      else if(co[i]!=1) cout<<co[i];

      cout<<"x";
      if(i!=1) cout<<"^"<<i;
    }
    if(co[0]){
      if(flg&&co[0]>0) cout<<"+";
      cout<<co[0];
    }
    cout<<endl;
  }

  T operator[](int i) const{
    return co[i];
  }

  T &operator[](int i){
    return co[i];
  }

  P operator-() const{
    P res=*this;
    for(T &c:res.co) c*=-1;
    return res;
  }

  P operator+(const P &a) const{
    int n=size(),m=a.size();
    P res(max(n,m));
    for(int i=0;i<n;i++) res[i]+=co[i];
    for(int i=0;i<m;i++) res[i]+=a[i];
    return res;
  }

  P operator-(const P &a) const{return *this+(-a);};

  P operator*(const P &a) const{
    int n=size(),m=a.size();
    P res(n+m);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        res[i+j]+=co[i]*a[j];
    res.shrink();
    return res;
  }

  P pow(const P &a,int k) const{
    P res;
    for(int i=0;i<k;i++) res=res*a;
    return res;
  }

  pair<P, P> divide(const P &a) const{
    int n=size(),m=a.size(),s=n-m+1;
    if(s<0) return make_pair(P(1),*this);
    P div(s);
    P rest=*this;
    for(int i=0;i<s;i++){
      if(rest[n-(i+1)]%a[m-1]!=0)
        for(T &c:rest.co) c*=a[m-1];
      T d=rest[n-(i+1)]/a[m-1];
      div[s-(i+1)]=d;
      for(int j=m;j>0;j--) rest[n-(i+j)]-=a[m-j]*d;
    }
    return make_pair(div,rest);
  }

  P operator/(const P &a) const{return divide(a).first;};
  P operator%(const P &a) const{return divide(a).second;};
};

template<typename T>
Polynomial<T> gcd(Polynomial<T> a,Polynomial<T> b){
  a.shrink();a.reduce();
  b.shrink();b.reduce();
  if(a.size()<b.size()) swap(a,b);
  if(b.size()==1u&&!b[0]) return a;
  return gcd(b,a%b);
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
