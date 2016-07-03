#include<iostream>
using namespace std;
int main(){
  int n,m;
  int i,j,k;
  int mat[100][100]={{}};
  int ve[100]={};
  cin >> n >> m;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      cin >> mat[i][j];
    }
  }
  for(j=0;j<m;j++) cin >> ve[j];
  for(i=0;i<n;i++){
    int x=0;
    for(j=0;j<m;j++) x+=mat[i][j]*ve[j];
    cout << x << endl;		       
  }
  
  return 0;
}
