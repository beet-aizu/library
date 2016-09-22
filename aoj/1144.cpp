#include<iostream>
using namespace std;
int sx,sy,ex,ey;

int step;
int w,h;
void rec(int stage[21][21],int x,int y,int d){
  int bx,by;
  if(d>=step) return;
  //cout << d << endl;
  int st[21][21];
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      st[j][i]=stage[j][i];

  //right
  bx=x;by=y;
  while(bx<w-1&&stage[bx+1][by]==0) bx++;
  if(bx+1==w){
    //rec(stage,bx,by,d+1);
  }else if(stage[bx+1][by]==3){
    step=min(step,d+1);
    st[bx][by]=2;
    /*
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cout << st[j][i] << " ";
      }
      cout << endl;
    }
    */
  }else if(stage[bx+1][by]==1){
    if(bx!=x||by!=y){
      st[bx+1][by]=0;
      rec(st,bx,by,d+1);
      st[bx+1][by]=1;
    }
  }
  
  //left
  bx=x;by=y;
  
  while(bx>0&&stage[bx-1][by]==0) bx--;
  if(bx==0){
    //rec(st,bx,by,d+1);
  }else if(stage[bx-1][by]==3){
    step=min(step,d+1);
  }else if(stage[bx-1][by]==1){
    if(bx!=x||by!=y){
      st[bx-1][by]=0;
      rec(st,bx,by,d+1);
      st[bx-1][by]=1;
    }
  }
  //up
  bx=x;by=y;
  
  while(by<h-1&&stage[bx][by+1]==0) by++;
  if(by+1==h){
    //rec(st,bx,by,d+1);
  }else if(stage[bx][by+1]==3){
    step=min(step,d+1);
  }else if(stage[bx][by+1]==1){
    if(bx!=x||by!=y){
      st[bx][by+1]=0;
      rec(st,bx,by,d+1);
      st[bx][by+1]=1;
    }
  }
  //down
  bx=x;by=y;
  
  while(by>0&&stage[bx][by-1]==0) by--;
  if(by==0){
    //rec(st,bx,by,d+1);
  }else if(stage[bx][by-1]==3){
    step=min(step,d+1);
  }else if(stage[bx][by-1]==1){
    if(bx!=x||by!=y){
      st[bx][by-1]=0;
      rec(st,bx,by,d+1);
      st[bx][by-1]=1;
    }
  }
}
int main(){
  cin >> w >> h;
  while(w!=0){
    int stage[21][21]={{}};
    int b;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cin >> stage[j][i];
	if(stage[j][i]==2) {
	  stage[j][i]=0;
	  sx=j;
	  sy=i;
	}
      }
    }
    step=11;
    rec(stage,sx,sy,0);
    if(step>10) cout << -1 << endl;
    else cout << step << endl;
    cin >> w >> h;
  }
  return 0;
}
