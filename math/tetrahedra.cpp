#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
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

  template<typename T, typename ET<T>::type* = nullptr>
  static bool compare(T x,T y){return abs(x)<abs(y);}
  template<typename T, typename EF<T>::type* = nullptr>
  static bool compare(T x,T y){(void)x;return y!=T(0);}

  // assume regularity
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
        if(compare(C[p][i],C[j][i])) p=j;
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
        if(compare(A[p][i],A[j][i])) p=j;
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
#endif
//BEGIN CUT HERE
bool isTriangle(double a1,double a2,double a3){
  if(a1+a2<=a3||a2+a3<=a1||a3+a1<=a2) return 0;
  return 1;
}

double tetrahedra(double OA,double OB,double OC,double AB,double AC,double BC){
  if(!isTriangle(OA,OB,AB)) return 0;
  if(!isTriangle(OB,OC,BC)) return 0;
  if(!isTriangle(OC,OA,AC)) return 0;
  if(!isTriangle(AB,AC,BC)) return 0;
  Matrix<double> A(5,5);
  A[0][0]=    0;A[0][1]=AB*AB;A[0][2]=AC*AC;A[0][3]=OA*OA;A[0][4]=1;
  A[1][0]=AB*AB;A[1][1]=    0;A[1][2]=BC*BC;A[1][3]=OB*OB;A[1][4]=1;
  A[2][0]=AC*AC;A[2][1]=BC*BC;A[2][2]=    0;A[2][3]=OC*OC;A[2][4]=1;
  A[3][0]=OA*OA;A[3][1]=OB*OB;A[3][2]=OC*OC;A[3][3]=    0;A[3][4]=1;
  A[4][0]=    1;A[4][1]=    1;A[4][2]=    1;A[4][3]=    1;A[4][4]=0;
  double res=A.determinant();
  if(res<=0) return 0;
  return sqrt(res/288.0);
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
