#include <iostream>
#include <string>
#include <queue>

using namespace std;
struct Point{
  int x;int y;
};

int main(){
  int w,h,i,j,k,c=0;
  string str;
  Point p,b;
  cin >> w >> h;
  while(w!=0&&h!=0){
    c=1;
    int dp[21][21]={{}};
    for(i=0;i<h;i++){
      cin >> str;
      for(j=0;j<w;j++){
	if(str[j]=='.') dp[j][i]= 1;
	if(str[j]=='#') dp[j][i]= 2;
	if(str[j]=='@') {
	  dp[j][i]= 3;
	  p.x=j;p.y=i;
	}
      }
    }
    
    queue <Point> q;
    q.push(p);
    while(!q.empty()){
      p = q.front();
      q.pop();
      if((p.x+1)<w&&dp[p.x+1][p.y]==1){
	c++;
	b.x=p.x+1;b.y=p.y;
	dp[p.x+1][p.y]=-1;
	q.push(b);
      }
      if((p.x-1)>=0&&dp[p.x-1][p.y]==1){
	c++;
	b.x=p.x-1;b.y=p.y;
	dp[p.x-1][p.y]=-1;
	q.push(b);
      }
      if((p.y+1)<h&&dp[p.x][p.y+1]==1){
	c++;
	b.x=p.x;b.y=p.y+1;
	dp[p.x][p.y+1]=-1;
	q.push(b);
      }
      if((p.y-1)>=0&&dp[p.x][p.y-1]==1){
	c++;
	b.x=p.x;b.y=p.y-1;
	dp[p.x][p.y-1]=-1;
	q.push(b);
      }
    }
    cout << c << endl;
    cin >> w >> h;
  }
  return 0;
}
