#include<bits/stdc++.h>
using namespace std;
#define EPS (1e-10)
using Int = long long;

//BEGIN CUT HERE
typedef vector<double> arr;
typedef vector<arr> mat;

double det(mat A){
  int n=A.size();
  double res=1;
  for(int i=0;i<n;i++){
    int pivot=i;
    for(int j=i+1;j<n;j++)
      if(abs(A[j][i])>abs(A[pivot][i])) pivot=j;
    swap(A[pivot],A[i]);
    res*=A[i][i]*(i!=pivot?-1:1);
    if(abs(A[i][i])<EPS) break;
    for(int j=i+1;j<n;j++)
      for(int k=n-1;k>=i;k--)
        A[j][k]-=A[i][k]*A[j][i]/A[i][i];
  }
  return res;
}

bool isTriangle(double a1,double a2,double a3){
  if(a1+a2<=a3||a2+a3<=a1||a3+a1<=a2) return 0;
  return 1;
}
double tetrahedra(double OA,double OB,double OC,double AB,double AC,double BC){
  if(!isTriangle(OA,OB,AB)) return 0;
  if(!isTriangle(OB,OC,BC)) return 0;
  if(!isTriangle(OC,OA,AC)) return 0;
  if(!isTriangle(AB,AC,BC)) return 0;
  mat A(5,arr(5,0));
  A[0][0]=    0;A[0][1]=AB*AB;A[0][2]=AC*AC;A[0][3]=OA*OA;A[0][4]=1;
  A[1][0]=AB*AB;A[1][1]=    0;A[1][2]=BC*BC;A[1][3]=OB*OB;A[1][4]=1;
  A[2][0]=AC*AC;A[2][1]=BC*BC;A[2][2]=    0;A[2][3]=OC*OC;A[2][4]=1;
  A[3][0]=OA*OA;A[3][1]=OB*OB;A[3][2]=OC*OC;A[3][3]=    0;A[3][4]=1;
  A[4][0]=    1;A[4][1]=    1;A[4][2]=    1;A[4][3]=    1;A[4][4]=0;
  //cout<<"det(A):"<<det(A)<<endl;
  if(det(A)<=0) return 0; 
  return sqrt(det(A)/288.0);
}
//END CUT HERE

signed main(){
  int n;
  while(cin>>n,n){
    double a[n];
    double ans=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        for(int k=j+1;k<n;k++){
          for(int x=0;x<n;x++){
            if(i==x||j==x||k==x) continue;
            for(int y=0;y<n;y++){
              if(i==y||j==y||k==y||x==y) continue;
              for(int z=0;z<n;z++){
                if(i==z||j==z||k==z||x==z||y==z) continue;
                ans=max(ans,tetrahedra(a[i],a[j],a[k],a[x],a[y],a[z]));
              }
            }
          }
        }
      }
    }
    printf("%.10f\n",ans);
  }
  return 0;
}


/*
  verified on 2017/10/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2060
*/
