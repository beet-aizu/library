#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef pair<int,int> i_i;
int o,h,w,c;
void rec(int st[8][8],int d){
  if(d==5){
    queue<i_i> q;
    vector<i_i> v;
    int u[8][8]={{}};
    i_i p,b;
    p.first=0;p.second=0;
    if(st[p.first][p.second]==c) q.push(p);
    u[p.first][p.second]=1;
    int ax[]={1,-1,0,0},ay[]={0,0,1,-1};
    while(!q.empty()){
      p=q.front();q.pop();
      v.push_back(p);
      for(int i=0;i<4;i++){
	b.first=p.first+ax[i];
	b.second=p.second+ay[i];
	if(b.first<0||b.first>=w||
	   b.second<0||b.second>=h) continue;
	if(u[b.first][b.second]==0&&
	   st[b.first][b.second]==c){
	  u[b.first][b.second]=1;
	  q.push(b);
	}
      }
    }
    int s=v.size();
    o=max(o,s);
    return;
  }
  
  queue<i_i> q;
  vector<i_i> v;
  int u[8][8]={{}};
  i_i p,b;
  p.first=0;p.second=0;
  int bc=st[p.first][p.second];
  u[p.first][p.second]=1;
  q.push(p);
  int ax[]={1,-1,0,0},ay[]={0,0,1,-1};
  while(!q.empty()){
    p=q.front();q.pop();
    v.push_back(p);
    for(int i=0;i<4;i++){
      b.first=p.first+ax[i];
      b.second=p.second+ay[i];
      if(b.first<0||b.first>=w||
	 b.second<0||b.second>=h) continue;
      if(u[b.first][b.second]==0&&
	 st[b.first][b.second]==bc){
	u[b.first][b.second]=1;
	q.push(b);
      }
    }
  }
  /*
  cout << d << ":";
  for(int j=0;j<v.size();j++){
    cout << v[j].first << ":" << v[j].second << endl;
  }
  
  
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout << st[j][i] << " ";
    }
    cout <<  endl;
  }
  cout << d << ":" << v.size() << endl;
  
  */
  int stage[8][8]={{}};
  for(int i=1;i<=6;i++){
    for(int j=0;j<h;j++)
      for(int k=0;k<w;k++)
	stage[k][j]=st[k][j];
    for(int j=0;j<v.size();j++){
      stage[v[j].first][v[j].second]=i;
    }
    rec(stage,d+1);
  }
  
}
int main(){
  cin >> h >> w >> c;
  while(h!=0){
    o=0;
    int st[8][8]={{}};
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cin >> st[j][i];
      }
    }
    rec(st,0);
    cout << o << endl;
    cin >> h >> w >> c;
  }
  return 0;
}
