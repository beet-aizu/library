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
  bool used[55][55][4];
  memset(used,false,sizeof(used));
  Q q;
  p.s.clear();
  q.push(p);
  while(!q.empty()){
    p=q.front();q.pop();    
    p.s.insert(XY(p.x,p.y));
    if(used[p.y][p.x][p.d]) break;
    
    used[p.y][p.x][p.d]=true;
     
    if(st[p.y][p.x]=='G') {
      f=true;
      o=s;
      break;
    }
    move(p,q);
  }
  if(f){
    cout << o << endl;
  }
  else cout << -1 << endl;
  return 0;
}
