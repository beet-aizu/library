#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename K>
struct Matrix{
  typedef vector<K> arr;
  typedef vector<arr> mat;
  mat dat;

  Matrix(int r,int c):dat(r,arr(c,K())){}
  Matrix(mat dat):dat(dat){}
  
  static Matrix cross(const Matrix &a,const Matrix &b){
    Matrix res(a.dat.size(),b.dat[0].size());    
    for(int i=0;i<(int)a.dat.size();i++)
      for(int j=0;j<(int)b.dat[0].size();j++)
	for(int k=0;k<(int)b.dat.size();k++)
	  res.dat[i][j]+=a.dat[i][k]*b.dat[k][j];
    return res;
  }

  static Matrix identity(int n){
    Matrix res(n,n);
    for(int i=0;i<n;i++) res.dat[i][i]=K(1);
    return res;
  }
  
  Matrix pow(long long n){
    Matrix a(dat),res=identity(dat.size());
    while(n){
      if(n&1) res=cross(res,a);
      a=cross(a,a);      
      n>>=1;
    }
    return res;
  }
};
//END CUT HERE

template<typename T,T MOD = 1000000007>
struct Mint{
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}

  Mint pow(int k){
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
  
};

//INSERT ABOVE HERE
signed main(){
  using M = Matrix< Mint<int, int(1e9+9)> >;
  
  Int w,h,n,cnt=0;
  while(scanf("%lld %lld %lld",&w,&h,&n),w||h||n){    
    vector<Int> x(n),y(n);
    for(Int i=0;i<n;i++) scanf("%lld %lld",&x[i],&y[i]);

    using P = pair<Int, Int>;  
    vector<P> p(n);
    for(Int i=0;i<n;i++) p[i]=P(y[i],x[i]);
    sort(p.begin(),p.end());
    for(Int i=0;i<n;i++) tie(y[i],x[i])=p[i];
    
    M b(w,w);
    for(Int i=0;i<w;i++){
      b.dat[i][i]=1;
      if(i-1>=0) b.dat[i][i-1]=1;
      if(i+1<w)  b.dat[i][i+1]=1;
    }
    
    M a(w,1);
    a.dat[0][0]=1;
    
    Int d=1;
    for(Int k=0;k<n;k++){
      if(y[k]==d) continue;
      a=M::cross(b.pow(y[k]-d-1),a);      
      Int j=k;
      M c=b;
      while(j<n&&y[k]==y[j]){
	for(Int i=0;i<w;i++) c.dat[x[j]-1][i]=0;
	j++;
      }
      a=M::cross(c,a);
      d=y[k];
    }
    a=M::cross(b.pow(h-d),a);    
    printf("Case %lld: %d\n",++cnt,a.dat[w-1][0].v);    
  }
  return 0;
}

/*
  verified on 2018/01/17
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397
*/
