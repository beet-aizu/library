#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct Point{int x,y,a,d;};
int w,h;
bool in(Point a){
  if(a.x<0||a.x>=w||a.y<0||a.y>=h) return false;
  return true;
}
int main(){
  cin >> w >> h;
  while(w!=0){
    int i,j,k;
    int st[30][30]={{}};
    int wfs[31][31][4]={{{}}};
    int c[4]={};
    int inf = 1 << 30;
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	cin >> st[j][i];  
      }
    }
    fill(wfs[0][0],wfs[30][30],inf);
    //memset(wfs,inf,sizeof(wfs));
    for(i=0;i<4;i++)
      cin >> c[i];
    
    queue<Point> q;
    Point p,b;
    p.x=0;p.y=0;p.a=0;p.d=0;
    
    q.push(p);
    int ax[]={1,0,-1,0},ay[]={0,1,0,-1};
    while(!q.empty()){
      p=q.front();q.pop();
      
      if(wfs[p.x][p.y][p.a]>p.d) wfs[p.x][p.y][p.a]=p.d;
      else continue;
      //cout << p.x << ":" << p.y << ":" << p.d << endl;
      if(st[p.x][p.y]==4) {
	for(i=0;i<4;i++){
	  b.x=p.x+ax[i];b.y=p.y+ay[i];b.a=i;b.d=p.d+c[(4-p.a+i)%4];
	  if(in(b)) q.push(b);
	}
      }else{
	for(i=0;i<4;i++){
	  b.x=p.x+ax[i];b.y=p.y+ay[i];b.a=i;b.d=p.d;
	  if((p.a+st[p.x][p.y])%4!=i) b.d+=c[(4-p.a+i)%4];
	  if(in(b)) q.push(b);
	}
      }
    }
    
    int o=inf;
    
    for(i=0;i<4;i++)
      o=min(o,wfs[w-1][h-1][i]);
    
    cout << o << endl;
    cin >> w >> h;
  }
  return 0;
}
