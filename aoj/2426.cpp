#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct Point{
  int x,y;
  bool operator<(const Point & p) const{
    return x < p.x; 
  }
};
int main(){
  int n,m;cin>>n>>m;
  int i,j,k;
  Point p[n];
  for(i=0;i<n;i++) scanf("%d %d",&p[i].x,&p[i].y);
  sort(p,p+n);
  int sx,sy,tx,ty;
  for(i=0;i<m;i++){
    scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
    int ans = 0;
    for(j=0;j<n;j++) {
      if(sx<=p[j].x&&p[j].x<=tx&&sy<=p[j].y&&p[j].y<=ty){
	ans++;
      }
      if(tx<p[j].x) break;
    }
    printf("%d\n",ans);
  }
  return 0;
}
