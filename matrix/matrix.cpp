#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename K>
struct Matrix{
  typedef vector<K> arr;
  typedef vector<arr> mat;
  mat dat;

  Matrix(size_t r,size_t c):dat(r,arr(c,K())){}
  Matrix(mat dat):dat(dat){}

  size_t size() const{return dat.size();};
  bool empty() const{return size()==0;};
  arr& operator[](size_t k){return dat[k];};
  const arr& operator[](size_t k) const {return dat[k];};
  
  static Matrix cross(const Matrix &A,const Matrix &B){
    Matrix res(A.size(),B[0].size());    
    for(int i=0;i<(int)A.size();i++)
      for(int j=0;j<(int)B[0].size();j++)
        for(int k=0;k<(int)B.size();k++)
          res[i][j]+=A[i][k]*B[k][j];
    return res;
  }

  static Matrix identity(size_t n){
    Matrix res(n,n);
    for(int i=0;i<(int)n;i++) res[i][i]=K(1);
    return res;
  }
  
  Matrix pow(long long n) const{
    Matrix a(dat),res=identity(size());
    while(n){
      if(n&1) res=cross(res,a);
      a=cross(a,a);      
      n>>=1;
    }
    return res;
  }

  template<typename T> using ET = enable_if<is_floating_point<T>::value>;
  template<typename T> using EF = enable_if<!is_floating_point<T>::value>;
  
  template<typename T, typename ET<T>::type* = nullptr>
  static bool is_zero(T x){return abs(x)<1e-8;}
  template<typename T, typename EF<T>::type* = nullptr>
  static bool is_zero(T x){return x==T(0);}

  static Matrix gauss_jordan(const Matrix &A,const Matrix &B){
    int n=A.size(),l=B[0].size();
    Matrix C(n,n+l);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
        C[i][j]=A[i][j];      
      for(int j=0;j<l;j++)
        C[i][n+j]=B[i][j];
    }
    for(int i=0;i<n;i++){
      int p=i;
      for(int j=i;j<n;j++)
        if(abs(C[p][i])<abs(C[j][i])) p=j;
      swap(C[i],C[p]);
      if(is_zero(C[i][i])) return Matrix(0,0);
      for(int j=i+1;j<n+l;j++) C[i][j]/=C[i][i];
      for(int j=0;j<n;j++){
        if(i==j) continue;
        for(int k=i+1;k<n+l;k++)
          C[j][k]-=C[j][i]*C[i][k];
      }
    }
    Matrix res(n,l);
    for(int i=0;i<n;i++)
      for(int j=0;j<l;j++)
        res[i][j]=C[i][n+j];
    return res;
  }
  
  Matrix inv() const{
    Matrix B=identity(size());
    return gauss_jordan(*this,B);
  }
  
  K determinant() const{
    Matrix A(dat);
    K res(1);
    int n=size();
    for(int i=0;i<n;i++){
      int p=i;
      for(int j=i;j<n;j++)
        if(abs(A[p][i])<abs(A[j][i])) p=j;      
      if(i!=p) swap(A[i],A[p]),res=-res;      
      if(is_zero(A[i][i])) return K(0);      
      res*=A[i][i];
      for(int j=i+1;j<n;j++) A[i][j]/=A[i][i];
      for(int j=i+1;j<n;j++)
        for(int k=i+1;k<n;k++)
          A[j][k]-=A[j][i]*A[i][k];
    }
    return res;
  }

  static arr linear_equations(const Matrix &A,const arr &b){
    Matrix B(b.size(),1);
    for(int i=0;i<(int)b.size();i++) B[i][0]=b[i];
    Matrix tmp=gauss_jordan(A,B);
    arr res(tmp.size());
    for(int i=0;i<(int)tmp.size();i++) res[i]=tmp[i][0];
    return res;
  }
  
  static K sigma(K x,long long n){
    Matrix A(2,2);
    A[0][0]=x;A[0][1]=0;
    A[1][0]=1;A[1][1]=1;
    return A.pow(n)[1][0];
  }
};
//END CUT HERE

signed AOJ_1328(){
  using M = Matrix<double>;
  using arr = M::arr;
  
  int d;
  while(scanf("%d",&d),d){
    arr v(d+3);
    for(int i=0;i<d+3;i++) scanf("%lf",&v[i]);
    int ans=0;
    M m(d+3,d+2);
    for(int i=0;i<d+3;i++)
      for(int j=0;j<d+1;j++)
        m[i][j]=pow(1.0*i,j);
    
    for(int i=0;i<d+3;i++){
      for(int j=i+1;j<d+3;j++){
        arr b(d+1);
        M A(d+1,d+1);
        for(int k=0,l=0;k<d+3;k++)
          if(i!=k&&j!=k) A[l]=m[k],b[l]=v[k],l++;
	
        arr x=M::linear_equations(A,b);
        if(x.empty()) continue;
        double res[2]={};
        for(int k=0;k<d+1;k++){
          res[0]+=x[k]*m[i][k];
          res[1]+=x[k]*m[j][k];
        }
        if(abs(res[0]-v[i])>0.5&&abs(res[1]-v[j])<1e-5) ans=i;
        if(abs(res[0]-v[i])<1e-5&&abs(res[1]-v[j])>0.5) ans=j;
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
/*
  verified on 2018/10/17
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328
*/

template<typename T>
struct Mint{
  static T MOD;
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
  bool operator <(const Mint a)const{return v <a.v;};
};
template<typename T> Mint<T> abs(Mint<T> a){return a;};
template<typename T> T Mint<T>::MOD = 1e9+7;


signed ARC050_C(){
  using ll = long long;
  using M = Mint<ll>;
  using MM = Matrix<M>;
  ll a,b,m;
  scanf("%lld %lld %lld",&a,&b,&m);
  M::MOD = m;
  ll c=__gcd(a,b);
  M x=M((ll)10).pow(c);
  M ans=MM::sigma(x,a/c)*MM::sigma(M((ll)10),b);
  printf("%lld\n",ans.v);
  return 0;
}
/*
  verified on 2018/10/17
  https://beta.atcoder.jp/contests/arc050/tasks/arc050_c
*/

signed SPOJ_MIFF(){
  int first=1;
  int n,p;
  while(scanf("%d %d",&n,&p),n){
    if(!first) puts("");
    first=0;
    using M = Mint<int>;
    M::MOD = p;
    using MM = Matrix<M>;
    MM A(n,n);
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        scanf("%d",&A[i][j].v);
    MM B=A.inv();
    if(B.empty()) puts("singular");
    else{
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(j) printf(" ");
          printf("%d",B[i][j].v);
        }
        puts("");
      }
    }      
  }
  return 0;
}
/*
  verified on 2018/10/17
  https://www.spoj.com/problems/MIFF/
*/

signed SPOJ_MPOW(){
  int T;
  scanf("%d",&T);
  while(T--){
    int n,p;
    scanf("%d %d",&n,&p);
    using M = Mint<int>;
    M::MOD = 1e9+7;
    using MM = Matrix<M>;
    MM A(n,n);
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        scanf("%d",&A[i][j].v);
    MM B=A.pow(p);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(j) printf(" ");
        printf("%d",B[i][j].v);
      }
      puts("");
    }      
  }
  return 0;
}
/*
  verified on 2018/10/17
  https://www.spoj.com/problems/MPOW/
*/

signed main(){
  //AOJ_1328();
  //ARC050_C();
  //SPOJ_MIFF();
  SPOJ_MPOW();
}
