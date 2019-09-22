#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../linearalgebra/matrix.cpp"
#undef call_from_test

signed main(){
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
        const double EPS = 1e-5;
        if(abs(res[0]-v[i])>0.5&&abs(res[1]-v[j])<EPS) ans=i;
        if(abs(res[0]-v[i])<EPS&&abs(res[1]-v[j])>0.5) ans=j;
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
