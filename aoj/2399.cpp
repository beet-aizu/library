#include <iostream>
using namespace std;
int main(){
  int n,i,j,k,b;
  cin >> n;
  while(n!=0){
    int table[101][101]={{}};
    int m[101]={};
    int l[101]={};
    for(i=1;i<=n;i++){
      cin >> m[i];
      for(j=0;j<m[i];j++){
	cin >> b;
	table[i][b]=1;
      }
    }
    cin >> k;
    for(i=0;i<k;i++){
      cin >> b;
      l[b]=1;
    }
    int o=0,f=0,q=0;
    for(i=1;i<=n;i++){
      f=0;
      for(j=1;j<=n;j++){
	if(l[j]==1)
	  if(table[i][j]!=1) f=1;
      }
      if(f==0){
	if(o==0) o=i;
	else q=1;
      }	
    }
    if(q==1||o==0) cout << -1 << endl;
    else cout << o << endl;
    cin >> n;
  }
  return 0;
}
