#include<iostream>
#include<queue>
using namespace std;
struct Point{int x,y,t;};
int main(){
  int t,n,i,j,k,x,y;
  cin >> t >> n;
  while(t!=0||n!=0){
    
    int m[200][200]={{}};
    int dis[200][200]={{}};
    queue <Point> ps;
    Point p,b;
    for(i=0;i<n;i++){
      cin >> x >> y;
      dis[100+x][100+y]=1;
    }
    cin >> p.x  >> p.y;
    p.x+=100;p.y+=100;
    m[p.x][p.y]=1;
    p.t=0;
    ps.push(p);
    int o=0;
    while(!ps.empty()){
      o++;
      p=ps.front();
      ps.pop();
      if(p.t<t){
	if(m[p.x+1][p.y]+dis[p.x+1][p.y]==0){
	  b.x=p.x+1;b.y=p.y;b.t=p.t+1;
	  m[b.x][b.y]=1;
	  ps.push(b);
	}
	if(m[p.x][p.y+1]+dis[p.x][p.y+1]==0){
	  b.x=p.x;b.y=p.y+1;b.t=p.t+1;
	  m[b.x][b.y]=1;
	  ps.push(b);
	}
	if(m[p.x+1][p.y+1]+dis[p.x+1][p.y+1]==0){
	  b.x=p.x+1;b.y=p.y+1;b.t=p.t+1;
	  m[b.x][b.y]=1;
	  ps.push(b);
	}
	if(m[p.x-1][p.y]+dis[p.x-1][p.y]==0){
	  b.x=p.x-1;b.y=p.y;b.t=p.t+1;
	  m[b.x][b.y]=1;
	  ps.push(b);
	}
	if(m[p.x][p.y-1]+dis[p.x][p.y-1]==0){
	  b.x=p.x;b.y=p.y-1;b.t=p.t+1;
	  m[b.x][b.y]=1;
	  ps.push(b);
	}
	if(m[p.x-1][p.y-1]+dis[p.x-1][p.y-1]==0){
	  b.x=p.x-1;b.y=p.y-1;b.t=p.t+1;
	  m[b.x][b.y]=1;
	  ps.push(b);
	}
      }
    }
    cout << o << endl;
    //cout << t << endl;
    cin >> t >> n;
  }
}
