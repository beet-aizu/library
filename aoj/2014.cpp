#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct Point {int x,y;};
int main(){
  int w,h;
  cin >> w >> h;
  while(w!=0||h!=0){
    int bw[55][55]={{}};
    string str;
    int i,j,k;
    vector <Point> bs;
    vector <Point> ws;
    Point p,b;
    for(i=0;i<h;i++){
      cin >> str;
      for(j=0;j<w;j++){
	if(str[j]=='W') {
	  bw[j][i]=1;
	  p.x=j;p.y=i;
	  ws.push_back(p);
	}
	if(str[j]=='B') {
	  bw[j][i]=2;
	  p.x=j;p.y=i;
	  bs.push_back(p);
	}
      }
    }
    queue <Point> q;
    for(i=0;i<ws.size();i++){
      p.x = ws[i].x;p.y = ws[i].y;
      q.push(p);
      while(!q.empty()){
	p=q.front();
	q.pop();
	int xs[]={1,-1,0,0},ys[]={0,0,1,-1};
	for(j=0;j<4;j++){
	  b.x=p.x+xs[j];b.y=p.y+ys[j];
	  if(b.x<0||w<=b.x||b.y<0||h<=b.y){
	  }else{
	    if(bw[b.x][b.y]==0){
	      bw[b.x][b.y]=3;
	      q.push(b);
	    }
	  }
	}
      }
    }
    for(i=0;i<bs.size();i++){
      p.x = bs[i].x;p.y = bs[i].y;
      q.push(p);
      while(!q.empty()){
	p=q.front();
	q.pop();
	int xs[]={1,-1,0,0},ys[]={0,0,1,-1};
	for(j=0;j<4;j++){
	  b.x=p.x+xs[j];b.y=p.y+ys[j];
	  if(b.x<0||w<=b.x||b.y<0||h<=b.y) {
	  }else{
	    if(bw[b.x][b.y]==0){
	      bw[b.x][b.y]=4;
	      q.push(b);
	    }
	    if(bw[b.x][b.y]==3){
	      bw[b.x][b.y]=5;
	      q.push(b);
	    }
	  }
	}
      }
    }
    int wn=0,bn=0;
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	if(bw[j][i]==3) wn++;
	if(bw[j][i]==4) bn++;
      }
    }
    cout << bn << " " << wn <<  endl;
    cin >> w >> h;
  }
  return 0;
}
