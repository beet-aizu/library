#include<iostream>
#include<vector>
#include<math.h>
#include<stdio.h>
using namespace std;
#define inf 1<<21
struct cell{
  double x,y,z,r;
};
double dis(cell a,cell b){
  double o=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z))-(a.r+b.r);
  if(o<=0) return 0;
  return o;
}
int main(){
  int n;
  cin >> n;
  while(n!=0){
    int i,j,k;
    vector<cell> cells;
    cell c;
    for(i=0;i<n;i++){
      cin >> c.x >> c.y >> c.z >> c.r;
      cells.push_back(c);
    }
    
    double cost[100][100]={{}};
    for(i=0;i<n;i++){
      for(j=i;j<n;j++){
	if(i==j) cost[i][j]=inf;
	else{
	  cost[i][j]=dis(cells[i],cells[j]);
	  cost[j][i]=cost[i][j];
	}
      }
    }
    
    int color[100]={},d[100]={},p[100]={};
    double o=inf;
    for(k=0;k<n;k++){
      fill(color,color+100,0);
      fill(d,d+100,inf);
      fill(p,p+100,-1);
      double sum=0,minv;
      int u;
      d[k]=0;
      while(1){
	minv=inf;
	u=-1;
	for(i=0;i<n;i++){
	  if(minv>d[i]&&color[i]!=2){
	    u=i;
	    minv=d[i];
	  }
	}
	if(u==-1) break;
	color[u]=2;
	for(i=0;i<n;i++){
	  if(color[i]!=2&&u!=i){
	    if(d[i]>cost[u][i]){
	      d[i]=cost[u][i];
	      p[i]=u;
	      color[i]=1;
	    }
	  }
	}
	
      }
      for(i=0;i<n;i++){
	if(p[i]!=-1) sum+=cost[i][p[i]];
      }
      if(o>sum) o=sum;
    }
    
    printf("%.3f\n",o);
    
    cin >> n;
  }
  return 0;
}
