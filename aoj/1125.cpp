#include<iostream>
using namespace std;
int main(){
  int n,w,h,i,j,k,l,s,t,x,y;
  int p[501][501]={};
  cin >> n;
  while(n!=0){
    cin >> w >> h;
    for(i=0;i<w;i++){
      for(j=0;j<h;j++){
	p[i][j]=0;
      }
    }
    for(i=0;i<n;i++){
      cin >> x >> y;
      p[x-1][y-1]=1;
    }
    int o=0,m=0;
    cin >> s >> t;
    for(i=0;i<w-s+1;i++){
      for(j=0;j<h-t+1;j++){
	m=0;
	for(k=i;k<i+s;k++){
	  for(l=j;l<j+t;l++){
	    m+=p[k][l];
	  }
	}
	if(o<m) o=m;
      }
    }
    cout << o << endl;
    cin >> n;
  }
  return 0;
}
