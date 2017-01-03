#include<bits/stdc++.h>
using namespace std;
const double EPS=1E-8;
typedef vector<double> vec;
typedef vector<vec> mat;
vec gauss_jordan(const mat& A,const vec& b){
  int n=A.size();
  mat B(n,vec(n+1));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      B[i][j]=A[i][j];
  for(int i=0;i<n;i++) B[i][n]=b[i];
  for(int i=0;i<n;i++){
    int pivot=i;
    for(int j=0;j<n;j++)
      if(abs(B[j][i])>abs(B[pivot][i])) pivot=j;
    swap(B[i],B[pivot]);
    if(abs(B[i][i])<EPS) return vec();
    for(int j=i+1;j<=n;j++) B[i][j]/=B[i][i];
    for(int j=0;j<n;j++){
      if(i!=j){
	for(int k=i+1;k<=n;k++) B[j][k]-=B[j][i]*B[i][k];
      }
    }
  }
  vec x(n);
  for(int i=0;i<n;i++) x[i]=B[i][n];
  return x;
}
int main(){
  return 0;
}
