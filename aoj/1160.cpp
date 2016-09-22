#include <iostream>
#include <queue>
using namespace std;
struct Point{int x,y;};
int main(){
  int w,h,p[60][60]={},v[60][60]={},i,j,k,o;
  queue <Point> q;
  Point n,b;
  cin >> w >> h;
  while(w!=0){
    for(j=0;j<h;j++){
      for(i=0;i<w;i++){
	cin >> p[i][j];
	v[i][j]=0;
      }
    }
    o=0;
    for(j=0;j<h;j++){
      
      for(i=0;i<w;i++){
	if(p[i][j]==1){
	  o++;
	  n.x=i;n.y=j;
	  q.push(n);
	  p[i][j]=0;
	  while(!q.empty()){
	    n=q.front();
	    q.pop();
	    if(n.x+1<w&&p[n.x+1][n.y]==1) {
	      b.x=n.x+1;b.y=n.y;
	      p[n.x+1][n.y]=0;
	      q.push(b);
	    }
	    if(n.y+1<h&&p[n.x][n.y+1]==1) {
	      b.x=n.x;b.y=n.y+1;
	      p[n.x][n.y+1]=0;
	      q.push(b);
	    }
	    if(n.x-1>=0&&p[n.x-1][n.y]==1) {
	      b.x=n.x-1;b.y=n.y;
	      p[n.x-1][n.y]=0;
	      q.push(b);
	    }
	    if(n.y-1>=0&&p[n.x][n.y-1]==1) {
	      b.x=n.x;b.y=n.y-1;
	      p[n.x][n.y-1]=0;
	      q.push(b);
	    }
	    if(n.x+1<w&&n.y+1<h&&p[n.x+1][n.y+1]==1) {
	      b.x=n.x+1;b.y=n.y+1;
	      p[n.x+1][n.y+1]=0;
	      q.push(b);
	    }
	    if(n.x-1>=0&&n.y-1>=0&&p[n.x-1][n.y-1]==1) {
	      b.x=n.x-1;b.y=n.y-1;
	      p[n.x-1][n.y-1]=0;
	      q.push(b);
	    }
	    if(n.x+1<w&&n.y-1>=0&&p[n.x+1][n.y-1]==1) {
	      b.x=n.x+1;b.y=n.y-1;
	      p[n.x+1][n.y-1]=0;
	      q.push(b);
	    }
	    if(n.x-1>=0&&n.y+1<h&&p[n.x-1][n.y+1]==1) {
	      b.x=n.x-1;b.y=n.y+1;
	      p[n.x-1][n.y+1]=0;
	      q.push(b);
	    }
	  }
	}
      }
    }
    cout << o << endl;
    cin >> w >> h;
  }
  return 0;
}
