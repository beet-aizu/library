#include<iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  int d[100][100];
  int i,j,k,l;
  int o=-10005;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cin >> d[i][j];
      o=max(o,d[i][j]);
    }
  }
  
  int row[100][100];
  for(i=0;i<n;i++){
    row[i][0]=d[i][0];
    for(j=1;j<n;j++){
      row[i][j]=row[i][j-1]+d[i][j];
      o=max(o,row[i][j]);
    }
  }
  int sum[100][100];
  for(j=0;j<n;j++){
    sum[0][j]=row[0][j];
    for(i=1;i<n;i++){
      sum[i][j]=sum[i-1][j]+row[i][j];
      o=max(o,sum[i][0]);
    }
  }
  
  for(i=1;i<n;i++){
    for(j=1;j<n;j++){
      for(k=1;i+k<n;k++){
	for(l=1;j+l<n;l++){
	  o=max(o,sum[i-1][j-1]+sum[i+k][j+l]-sum[i+k][j-1]-sum[i-1][j+l]);
	}
      }
    }
  }

  for(i=1;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<i;k++){
	o=max(o,sum[i][j]-sum[k][j]);
      }
    }
  }

  for(j=1;j<n;j++){
    for(i=0;i<n;i++){
      for(k=0;k<i;k++){
	o=max(o,sum[i][j]-sum[i][k]);
      }
    }
  }
  
  cout << o << endl;
  return 0;
}
