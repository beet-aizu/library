#include<iostream>
using namespace std;
int main(){
  int n,m,s,g1,g2;
  while(cin>>n>>m>>s>>g1>>g2,n||m||s||g1||g2){
    int i,j,k;
    int b1,b2,c;
    int d[105][105];
    int inf = 1<<20;
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
	if(i==j) d[i][j]=0;
	else d[i][j]=inf;
      }
    }
    for(i=0;i<m;i++) {
      cin >> b1 >> b2 >> c;
      d[b1][b2]=c;
    }
    for(k=1;k<=n;k++){
      for(i=1;i<=n;i++){
	if(d[i][k]==inf) continue;
	for(j=1;j<=n;j++){
	  if(d[k][j]==inf) continue;
	  d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	} 
      } 
    }
    int o=inf;
    for(i=1;i<=n;i++){
      o=min(o,d[s][i]+d[i][g1]+d[i][g2]);
    }
    cout << o << endl;
  }

}
