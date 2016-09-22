#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<map>
using namespace std;
typedef pair<int,int> P;
#define Y first
#define X second
int main(){
  int m,n;
  cin >> m >> n;
  string st[600];
  int i,j,k;
  for(i=0;i<m;i++) cin >> st[i];
  bool alp[26]={};
  vector<P> v[26];
  P p;
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      if(st[i][j]!='.') {
	alp[st[i][j]-'A']=true;
	p.Y=i;p.X=j;
	v[st[i][j]-'A'].push_back(p);
      }
    }
  }
  //cout << "x" << endl;
  bool f=true,e;
  int ans=0;
  while(f){
    f=false;
    for(k=0;k<26;k++){
      if(!alp[k]) continue;
      if(v[k][0].X==v[k][1].X){
	if(abs(v[k][0].Y-v[k][1].Y)<2) continue;
	e=true;
	for(i=min(v[k][0].Y,v[k][1].Y)+1;i<max(v[k][0].Y,v[k][1].Y);i++){
	  if(st[i][v[k][0].X]!='.') e=false;
	}
	if(e){
	  st[v[k][0].Y][v[k][0].X]='.';
	  st[v[k][1].Y][v[k][1].X]='.';
	  alp[k]=false;
	  ans++;f=true;
	  break;
	}
      }else if(v[k][0].Y==v[k][1].Y){
	if(abs(v[k][0].X-v[k][1].X)<2) continue;
	e=true;
	for(i=min(v[k][0].X,v[k][1].X)+1;i<max(v[k][0].X,v[k][1].X);i++){
	  if(st[v[k][0].Y][i]!='.') e=false;
	}
	if(e){
	  st[v[k][0].Y][v[k][0].X]='.';
	  st[v[k][1].Y][v[k][1].X]='.';
	  alp[k]=false;
	  ans++;f=true;
	  break;
	}
      }else if((v[k][0].X-v[k][1].X)*(v[k][0].Y-v[k][1].Y)>0){
	if(v[k][0].X>v[k][1].X) swap(v[k][0],v[k][1]);
	e=true;
	for(i=v[k][0].X+1;i<=v[k][1].X;i++){
	  if(st[v[k][0].Y][i]!='.') e=false;
	}
	for(i=v[k][0].Y;i<v[k][1].Y;i++){
	  if(st[i][v[k][1].X]!='.') e=false;
	}
	if(e){
	  st[v[k][0].Y][v[k][0].X]='.';
	  st[v[k][1].Y][v[k][1].X]='.';
	  alp[k]=false;
	  ans++;f=true;
	  break;
	}
	e=true;
	for(i=v[k][0].Y+1;i<=v[k][1].Y;i++){
	  if(st[i][v[k][0].X]!='.') e=false;
	}
	for(i=v[k][0].X;i<v[k][1].X;i++){
	  if(st[v[k][1].Y][i]!='.') e=false;
	}
	if(e){
	  st[v[k][0].Y][v[k][0].X]='.';
	  st[v[k][1].Y][v[k][1].X]='.';
	  alp[k]=false;
	  ans++;f=true;
	  break;
	}
      }else{
	if(v[k][0].X>v[k][1].X) swap(v[k][0],v[k][1]);
	e=true;
	for(i=v[k][0].X+1;i<=v[k][1].X;i++){
	  if(st[v[k][0].Y][i]!='.') e=false;
	}
	for(i=v[k][0].Y;i>v[k][1].Y;i--){
	  if(st[i][v[k][1].X]!='.') e=false;
	}
	if(e){
	  st[v[k][0].Y][v[k][0].X]='.';
	  st[v[k][1].Y][v[k][1].X]='.';
	  alp[k]=false;
	  ans++;f=true;
	  break;
	}
	e=true;
	for(i=v[k][0].Y-1;i>=v[k][1].Y;i--){
	  if(st[i][v[k][0].X]!='.') e=false;
	}
	for(i=v[k][0].X;i<v[k][1].X;i++){
	  if(st[v[k][1].Y][i]!='.') e=false;
	}
	if(e){
	  st[v[k][0].Y][v[k][0].X]='.';
	  st[v[k][1].Y][v[k][1].X]='.';
	  alp[k]=false;
	  ans++;f=true;
	  break;
	}
      }
    }
    //for(i=0;i<m;i++) cout << st[i] << endl; cout << endl;
  }
  //for(i=0;i<m;i++) cout << st[i] << endl;
  cout << ans*2 << endl;
  return 0;
}
