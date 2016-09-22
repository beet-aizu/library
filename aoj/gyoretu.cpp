#include <iostream>

#define MAX 10

using namespace std;

int main(){
  int l,m,n,i,j,k,out;
  int a[MAX][MAX]={{}},b[MAX][MAX]={{}};
  cin >> l >> m >> n;
  for(i=0;i<l;i++)
    for(j=0;j<m;j++)
      cin >> a[i][j];
  
  for(i=0;i<m;i++)
    for(j=0;j<n;j++)
      cin >> b[i][j];

  for(i=0;i<l;i++){
    for(j=0;j<n;j++){
      out=0;
      for(k=0;k<m;k++)
	out+=a[i][k]*b[k][j];
      cout << out << " ";
    }
    cout << endl;
  }
  return 0;
}
