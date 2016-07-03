#include<iostream>
using namespace std;
typedef long long ll;
int main(){
  ll a[105][105]={{}};
  ll b[105][105]={{}};
  int n,m,l;
  int i,j,k;
  cin >> n >> m >> l;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      cin >> a[i][j];
    }
  }
  for(i=0;i<m;i++){
    for(j=0;j<l;j++){
      cin >> b[i][j];
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<l;j++){
      ll o=0;
      for(k=0;k<m;k++){
	o+=a[i][k]*b[k][j];
      }
      if(j==0) cout << o;
      else cout << " " << o; 
    }
    cout << endl;
  }
  return 0;
}
