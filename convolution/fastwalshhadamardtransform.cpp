#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//BEGIN CUT HERE
template<typename T>
void FWT(vector<T> &a){
  int n=a.size();
  for(int d=1;d<n;d<<=1){
    for(int m=d<<1,i=0;i<n;i+=m){
      for(int j=0;j<d;j++){
        T x=a[i+j],y=a[i+j+d];
        a[i+j]=x+y;
        a[i+j+d]=x-y;
      }
    }
  }  
}

template<typename T>
void multiply(vector<T> &a,const vector<T> &b){
  for(int i=0;i<(int)a.size();i++)
    a[i]=a[i]*b[i];
}

template<typename T>
void UFWT(vector<T> &a,T rev2){
  int n=a.size();
  for(int d=1;d<n;d<<=1){
    for(int m=d<<1,i=0;i<n;i+=m){
      for(int j=0;j<d;j++){
        T x=a[i+j],y=a[i+j+d];
        a[i+j]=(x+y)*rev2;
        a[i+j+d]=(x-y)*rev2;
      }
    }
  }
}
//END CUT HERE

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

template<typename T,T MOD = 1000000007>
struct Mint{
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}

  Mint pow(long long k){
    Mint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }
  
  Mint inv(){return pow(MOD-2);}
  
  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}
  
  Mint operator+(Mint a) const{return Mint(v)+=a;};
  Mint operator-(Mint a) const{return Mint(v)-=a;};
  Mint operator*(Mint a) const{return Mint(v)*=a;};
  Mint operator/(Mint a) const{return Mint(v)/=a;};

  Mint operator-(){return v?MOD-v:v;}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}
};
//INSERT ABOVE HERE


signed CGR002_H(){
  using ll = long long;
  const int MOD = 998244353;
  using M = Mint<int, MOD>;
 
  int n,k;
  cin>>n>>k;
  
  ll p,q,r;
  cin>>p>>q>>r;

  int ofs=0;
  vector<int> a(n),b(n),c(n);  
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i]>>c[i];
    ofs^=a[i];
    b[i]^=a[i];
    c[i]^=a[i];
    a[i]=0;
  }
  
  vector<vector<ll> > vm((1<<k),vector<ll>(4,0));
  for(int t=0;t<4;t++){
    vector<ll> vs(1<<k,0);
    for(int i=0;i<n;i++){
      vs[a[i]]+=(t==0);
      vs[b[i]]+=(t==1);
      vs[c[i]]+=(t==2);
      vs[b[i]^c[i]]+=(t==3);
    }
    FWT(vs);
    for(int i=0;i<(1<<k);i++) vm[i][t]=vs[i];    
  }
  
  vector<M> vs(1<<k,1);
  for(int i=0;i<(1<<k);i++){
    ll x=(vm[i][0]+vm[i][1]+vm[i][2]+vm[i][3])/4;
    ll y=(vm[i][0]+vm[i][1]-vm[i][2]-vm[i][3])/4;
    ll z=(vm[i][0]-vm[i][1]+vm[i][2]-vm[i][3])/4;
    ll w=(vm[i][0]-vm[i][1]-vm[i][2]+vm[i][3])/4;
    
    vs[i]*=M(p+q+r).pow(x);
    vs[i]*=M(p+q-r).pow(y);
    vs[i]*=M(p-q+r).pow(z);
    vs[i]*=M(p-q-r).pow(w);
  }
  
  M rev2=M(2).inv();
  UFWT(vs,rev2);
  for(int i=0;i<(1<<k);i++){
    if(i) cout<<" ";
    cout<<vs[ofs^i].v;
  }
  cout<<endl;
  return 0;
}
/*
  verified on 2019/04/09
  https://codeforces.com/contest/1119/problem/H
*/

signed main(){
  CGR002_H();
  return 0;
}
