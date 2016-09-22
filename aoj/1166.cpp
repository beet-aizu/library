#include <iostream>
#include <queue>

using namespace std;

struct Point{int x,y;};

int main(){
  int t[30][30]={{}};
  int y[30][30]={{}};
  int dp[30][30]={{}};
  int w,h,c=0,i,j,k;
  int inf = 1000000;
  Point p,b;
  queue <Point> q; 
  cin >> w >> h;
  while(w!=0||h!=0){
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	dp[j][i] = inf;
      }
    }
    dp[0][0]=0;
      
    for(i=0;i<h-1;i++){
      for(j=0;j<w-1;j++){
	cin >> y[j][i];
      }
      for(j=0;j<w;j++){
	cin >> t[j][i];
      }
    }
    for(j=0;j<w-1;j++){
	cin >> y[j][h-1];
    }
    p.x=0;p.y=0;
    q.push(p);
    while(!q.empty()){
      p = q.front();
      q.pop();
      if(p.x+1<w&&y[p.x][p.y]==0){
	if(dp[p.x+1][p.y]>dp[p.x][p.y]+1){
	  dp[p.x+1][p.y]=dp[p.x][p.y]+1;
	  b.x=p.x+1;b.y=p.y;
	  q.push(b);
	}
      }
      if(p.x-1>=0&&y[p.x-1][p.y]==0){
	if(dp[p.x-1][p.y]>dp[p.x][p.y]+1){
	  dp[p.x-1][p.y]=dp[p.x][p.y]+1;
	  b.x=p.x-1;b.y=p.y;
	  q.push(b);
	}
      }
      if(p.y+1<h&&t[p.x][p.y]==0){
	if(dp[p.x][p.y+1]>dp[p.x][p.y]+1){
	  dp[p.x][p.y+1]=dp[p.x][p.y]+1;
	  b.x=p.x;b.y=p.y+1;
	  q.push(b);
	}
      }
      if(p.y-1>=0&&t[p.x][p.y-1]==0){
	if(dp[p.x][p.y-1]>dp[p.x][p.y]+1){
	  dp[p.x][p.y-1]=dp[p.x][p.y]+1;
	  b.x=p.x;b.y=p.y-1;
	  q.push(b);
	}
      }
    }
    
    c = (dp[w-1][h-1]==inf) ? 0:dp[w-1][h-1]+1;
    cout << c << endl;
    cin >> w >> h;
  }
}
