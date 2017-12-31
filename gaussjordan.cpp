#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
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
    for(int j=i;j<n;j++)
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
//END CUT HERE

signed main(){
  int d;
  while(cin>>d,d){
    vec v(d+3);
    for(int i=0;i<d+3;i++) cin>>v[i];
    int ans=0;
    mat m(d+3,vec(d+2));
    for(int i=0;i<d+3;i++)
      for(int j=0;j<d+1;j++)
	m[i][j]=pow(1.0*i,j);
    for(int i=0;i<d+3;i++){
      for(int j=i+1;j<d+3;j++){
	vec b(d+1);
	mat A(d+1,vec(d+1));
	for(int k=0,l=0;k<d+3;k++)
	  if(i!=k&&j!=k) A[l]=m[k],b[l]=v[k],l++;
	vec x=gauss_jordan(A,b);
	double res[2]={};
	for(int k=0;k<d+1;k++){
	  res[0]+=x[k]*m[i][k];
	  res[1]+=x[k]*m[j][k];
	}
	if(abs(res[0]-v[i])+1e-5>1.0&&abs(res[1]-v[j])<1e-5) ans=i;
	if(abs(res[0]-v[i])<1e-5&&abs(res[1]-v[j])+1e-5>1.0) ans=j;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}

/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1328
*/

