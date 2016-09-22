#include <iostream>
using namespace std;
int main(){
  int n,q,m,i,j,k,b;
  cin >> n >> q;
  while(n!=0){
    int l[51][101]={{}};
    int d[101]={};
    for(i=0;i<n;i++){
      cin >> m;
      for(j=0;j<m;j++){
	cin >> b;
	l[i][b]=1;
      }
    }
    for(i=0;i<n;i++){
      for(j=0;j<101;j++){
	d[j]+=l[i][j];
      }
    }
    int da,ma=0;;
    for(i=0;i<101;i++){
      if(ma<d[i]) {
	ma=d[i];
	da=i;
      }
    }
    if(ma>=q) cout << da << endl;
    else cout << 0 << endl;
    cin >> n >> q;
  }
  return 0;
}
