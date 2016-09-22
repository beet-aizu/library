//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef pair<int,int> XY;
struct P{
  int x,y,d;
  set<XY> s;
  P(){}
  P(int x,int y,int d,set<XY> s):x(x),y(y),d(d),s(s){}
  bool operator<(const P & p) const{
    return s.size() < p.s.size();
  }
  bool operator>(const P & p) const{
    return s.size() > p.s.size();
  }
  bool operator==(const P & p) const{
    return s.size() == p.s.size();
  }
};
 
string st[52];
int n,m;
 
bool ch(int x,int y,int d){
  if(d==0){
    if(st[y-1][x+1]=='#'||st[y][x+1]=='#'||st[y+1][x+1]=='#') return true;
  }
  if(d==1){
    if(st[y-1][x-1]=='#'||st[y-1][x]=='#'||st[y-1][x+1]=='#') return true;
  }
  if(d==2){
    if(st[y-1][x-1]=='#'||st[y][x-1]=='#'||st[y+1][x-1]=='#') return true;
  }
  if(d==3){
    if(st[y+1][x-1]=='#'||st[y+1][x]=='#'||st[y+1][x+1]=='#') return true;
  }
  return false;
}
 
 
bool f_ch(int x,int y,int d){
  if(d==0){
    if(st[y][x+1]=='#') return true;
    if(st[y-1][x+1]=='#') return true;
  }
  if(d==1){
    if(st[y+1][x]=='#') return true;
    if(st[y+1][x+1]=='#') return true;
  }
  if(d==2){
    if(st[y][x-1]=='#') return true;
    if(st[y+1][x-1]=='#') return true;
  }
  if(d==3){
    if(st[y-1][x]=='#') return true;
    if(st[y-1][x-1]=='#') return true;
  }
  return false;
}
 
bool r_ch(int x,int y,int d){
  if(d==0){
    if(st[y+1][x+1]=='#'&&st[y][x+1]!='#') return true;
  }
  if(d==1){
    if(st[y+1][x-1]=='#'&&st[y+1][x]!='#') return true;
  }
  if(d==2){
    if(st[y-1][x-1]=='#'&&st[y][x-1]!='#') return true;
  }
  if(d==3){
    if(st[y-1][x+1]=='#'&&st[y-1][x]!='#') return true;
  }
  return false;
}
 
bool l_ch(int x,int y,int d){
  if(d==0){
    if(st[y][x+1]=='#'&&st[y-1][x]=='#') return true;
  }
  if(d==1){
    if(st[y][x+1]=='#'&&st[y+1][x]=='#') return true;
  }
  if(d==2){
    if(st[y][x-1]=='#'&&st[y+1][x]=='#') return true;
  }
  if(d==3){
    if(st[y][x-1]=='#'&&st[y-1][x]=='#') return true;
  }
  return false;
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
 
  bool f=false;
  int o;
  int inf = 1 << 20;
  int used[55][55][4];
  fill(used[0][0],used[54][54],inf);
  //memset(used,inf,sizeof(used));
  priority_queue<P,vector<P>,greater<P> > q;
  p.s.clear();
  q.push(p);
  while(!q.empty()){
    p=q.top();q.pop();    
    //cout << p.y <<":"<< p.x <<"/"<< p.d << ":"<<p.s.size()<<endl;
    //cout << used[p.y][p.x][p.d]<<":"<<p.s.size()<<endl;
    if(used[p.y][p.x][p.d]<=p.s.size()) continue;
    p.s.insert(XY(p.x,p.y));
 
    used[p.y][p.x][p.d]=p.s.size();
     
    if(st[p.y][p.x]=='G') {
      f=true;
      o=p.s.size();
      break;
    }
 
    if(r_ch(p.x,p.y,p.d)) q.push(P(p.x,p.y,(p.d+1)%4,p.s));
    if(l_ch(p.x,p.y,p.d)) q.push(P(p.x,p.y,(p.d+3)%4,p.s));
     
    if(f_ch(p.x,p.y,p.d)&&st[p.y+ay[p.d]][p.x+ax[p.d]]!='#') 
      q.push(P(p.x+ax[p.d],p.y+ay[p.d],p.d,p.s));
  }
  if(f){
    cout << o << endl;
  }
  else cout << -1 << endl;
  return 0;
}
