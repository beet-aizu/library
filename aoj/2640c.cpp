//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
using namespace std;
typedef pair<int,int> XY;
struct P{
  int x,y,d;
  set<XY> s;
  P(){}
  P(int x,int y,int d,set<XY> s):x(x),y(y),d(d),s(s){}
};
 
string st[52];
int n,m;
 
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
	p.x=j+1;p.y=i;p.d=0;st[i][j]='.';
      }
      if(st[i][j]=='>'){
	p.x=j+1;p.y=i;p.d=1;st[i][j]='.';
      }
      if(st[i][j]=='v'){
	p.x=j+1;p.y=i;p.d=2;st[i][j]='.';
      }
      if(st[i][j]=='<'){
	p.x=j+1;p.y=i;p.d=3;st[i][j]='.';
      }
    }
    st[i]="#"+st[i]+"#";
  }
 
  //for(i=0;i<=n+1;i++) cout << st[i] << endl;
 
  int ax[]={0,1,0,-1};
  int ay[]={-1,0,1,0};
  
  int rx[]={1,0,-1,0};
  int ry[]={0,1,0,-1};
 
  bool f=false;
  int o;
  int inf = 1 << 20;
  bool used[55][55][4];
  memset(used,false,sizeof(used));
  queue<P> q;
  p.s.clear();
  q.push(p);
  while(!q.empty()){
    p=q.front();q.pop();    
    //cout << p.y <<":"<< p.x <<"/"<< p.d << ":"<<p.s.size()<<endl;
    //cout << used[p.y][p.x][p.d]<<":"<<p.s.size()<<endl;
    if(used[p.y][p.x][p.d]) continue;
    used[p.y][p.x][p.d]=true;

    p.s.insert(XY(p.x,p.y));
  
    if(st[p.y][p.x]=='G') {
      f=true;
      o=p.s.size();
      break;
    }
    
    if(st[p.y+ry[p.d]][p.x+rx[p.d]]!='#') q.push(P(p.x+rx[p.d],p.y+ry[p.d],(p.d+1)%4,p.s));
    else if(st[p.y+ay[p.d]][p.x+ax[p.d]]!='#') q.push(P(p.x+ax[p.d],p.y+ay[p.d],p.d,p.s));
    else q.push(P(p.x,p.y,(p.d+3)%4,p.s));
  }
  if(f){
    cout << o << endl;
  }
  else cout << -1 << endl;
  return 0;
}
