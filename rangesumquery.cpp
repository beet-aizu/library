#include<bits/stdc++.h>
using namespace std;
#define int long long
struct RMQ{
  int n;
  vector<int> dat;
  const int def=0;
  RMQ(){}
  RMQ(int n_){init(n_);}
  RMQ(vector<int> v){init(v);}
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1,def);
  }
  void init(vector<int> v){
    int n_=v.size();
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1,def);
    for(int i=0;i<n_;i++)
      dat[i+n-1]=v[i];
    for(int i=n-2;i>=0;i--) dat[i]=dat[i*2+1]+dat[i*2+2];
  }
  void update(int k,int a){
    k+=n-1;
    dat[k]=a;
    while(k>0){
      k=(k-1)/2;
      dat[k]=dat[k*2+1]+dat[k*2+2];
    }
  }
  int query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return def;
    if(a<=l&&r<=b) return dat[k];
    else{
      int vl=query(a,b,k*2+1,l,(l+r)/2);
      int vr=query(a,b,k*2+2,(l+r)/2,r);
      return vl+vr;
    }
  }
  int query(int a,int b){
    return query(a,b,0,0,n);
  }
};

