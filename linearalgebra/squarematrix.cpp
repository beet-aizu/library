#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename R, size_t N>
struct SquareMatrix{
  typedef array<R, N> arr;
  typedef array<arr, N> mat;
  mat dat;

  SquareMatrix(){
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<N;j++)
        dat[i][j]=R::add_identity();
  }

  bool operator==(const SquareMatrix& a) const{
    return dat==a.dat;
  }

  size_t size() const{return N;}
  arr& operator[](size_t k){return dat[k];}
  const arr& operator[](size_t k) const {return dat[k];}

  static SquareMatrix add_identity(){return SquareMatrix();}
  static SquareMatrix mul_identity(){
    SquareMatrix res;
    for(size_t i=0;i<N;i++) res[i][i]=R::mul_identity();
    return res;
  }

  SquareMatrix operator*(const SquareMatrix &B) const{
    SquareMatrix res;
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<N;j++)
        for(size_t k=0;k<N;k++)
          res[i][j]=res[i][j]+(dat[i][k]*B[k][j]);
    return res;
  }

  SquareMatrix operator+(const SquareMatrix &B) const{
    SquareMatrix res;
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<N;j++)
        res[i][j]=dat[i][j]+B[i][j];
    return res;
  }

  SquareMatrix pow(long long n) const{
    SquareMatrix a=*this,res=mul_identity();
    while(n){
      if(n&1) res=res*a;
      a=a*a;
      n>>=1;
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
