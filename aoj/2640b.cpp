//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
using namespace std;
typedef pair<int,int> XY;
struct P{
  int x,y,d,h;
  set<XY> s;
  P(){}
  P(int x,int y,int d,int h,set<XY> s):x(x),y(y),d(d),h(h),s(s){}
};
typedef queue<P> Q;
string st[52];
int n,m,s;

int rx[]={1,0,-1,0};
int ry[]={0,1,0,-1};

int bx[4][4]={{0,1,1,1},
	      {1,1,0,-1},
	      {0,-1,-1,-1},
	      {-1,-1,0,1}};
int by[4][4]={{-1,-1,0,1},
	      {0,1,1,1},
	      {1,1,0,-1},
	      {0,-1,-1,-1}};

void move(P p,Q &q){
  if(p.h==0){
    if(st[p.y+by[p.d][1]][p.x+bx[p.d][1]]=='#') q.push(P(p.x,p.y,p.d,1,p.s));
    if(st[p.y+by[p.d][2]][p.x+by[p.d][2]]=='#'){
      q.push(P(p.x,p.y,p.d,2,p.s));
      if(st[p.y+by[p.d][3]][p.x+by[p.d][3]]=='#') q.push(P(p.x,p.y,p.d,3,p.s));
    }
  }
  if(p.h==1){
    if(st[p.y+by[p.d][0]][p.x+bx[p.d][0]]=='#') q.push(P(p.x,p.y,p.d,0,p.s));
    if(st[p.y+by[p.d][2]][p.x+bx[p.d][2]]=='#'){
      q.push(P(p.x,p.y,p.d,2,p.s));
      if(st[p.y+by[p.d][3]][p.x+bx[p.d][3]]=='#') q.push(P(p.x,p.y,p.d,3,p.s));
    }
  }
  if(p.h==2){
    if(st[p.y+by[p.d][3]][p.x+bx[p.d][3]]=='#') q.push(P(p.x,p.y,p.d,3,p.s));
    if(st[p.y+by[p.d][1]][p.x+bx[p.d][1]]=='#') q.push(P(p.x,p.y,p.d,1,p.s));
    if(st[p.y+by[p.d][0]][p.x+bx[p.d][0]]=='#') q.push(P(p.x,p.y,p.d,0,p.s));
  }
  if(p.h==3){
    if(st[p.y+by[p.d][2]][p.x+bx[p.d][2]]=='#'){
      q.push(P(p.x,p.y,p.d,2,p.s));
      if(st[p.y+by[p.d][1]][p.x+bx[p.d][1]]=='#') q.push(P(p.x,p.y,p.d,1,p.s));
      if(st[p.y+by[p.d][0]][p.x+bx[p.d][0]]=='#') q.push(P(p.x,p.y,p.d,0,p.s));
    }
  }
}
 
int main(){
  cin >> n >> m;
  int i,j,k;
  for(j=0;j<m+2;j++){
    st[0]+="#";
    st[n+1]+="#";
  }
  P p,b;
  for(i=1;i<=n;i++){
    cin >> st[i];
    for(j=0;j<m;j++){
      if(st[i][j]=='^'){
	p.x=j+1;p.y=i;p.d=0;st[i][j]='.';p.h=2;
      }
      if(st[i][j]=='>'){
	p.x=j+1;p.y=i;p.d=1;st[i][j]='.';p.h=2;
      }
      if(st[i][j]=='v'){
	p.x=j+1;p.y=i;p.d=2;st[i][j]='.';p.h=2;
      }
      if(st[i][j]=='<'){
	p.x=j+1;p.y=i;p.d=3;st[i][j]='.';p.h=2;
      }
    }
    st[i]="#"+st[i]+"#";
  }
 
  int ax[]={0,1,0,-1};
  int ay[]={-1,0,1,0};
 
  bool f=false;
  int o=55*55;
  int inf = 1 << 20;
  int used[55][55][4][4];
  memset(used,-1,sizeof(used));
  Q q;
  p.s.clear();
  q.push(p);
  while(!q.empty()){
    p=q.front();q.pop();    
    p.s.insert(XY(p.x,p.y));
    s=p.s.size();
    if(s>=o) continue;
    if(used[p.y][p.x][p.d][p.h]!=-1&&used[p.y][p.x][p.d][p.h]<=s) continue;
    if(st[p.y+by[p.d][p.h]][p.x+bx[p.d][p.h]]!='#') continue;
    
    used[p.y][p.x][p.d][p.h]=s;
     
    if(st[p.y][p.x]=='G') {
      f=true;
      o=min(o,s);
    }
 
    if(st[p.y+ry[p.d]][p.x+rx[p.d]]!='#'&&p.h==3) q.push(P(p.x,p.y,(p.d+1)%4,1,p.s));
    if(p.h==0) q.push(P(p.x,p.y,(p.d+3)%4,2,p.s));

    move(p,q);
    
    if(st[p.y+ay[p.d]][p.x+ax[p.d]]!='#'){
      if(p.h==1||p.h==2)
	q.push(P(p.x+ax[p.d],p.y+ay[p.d],p.d,p.h+1,p.s));
    }
  }
  if(f){
    cout << o << endl;
  }
  else cout << -1 << endl;
  return 0;
}
