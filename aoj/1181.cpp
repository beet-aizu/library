#include<iostream>
#include<vector>
using namespace std;
struct dice{
  int x,y,z;
  int top,front,bottom,back,right,left;
  void roll(int d){
    //cout << d << endl;
    int buf;
    if(d==0){
      buf=top;top=back;back=bottom;bottom=front;front=buf;x--;
    }else if(d==1){
      buf=top;top=left;left=bottom;bottom=right;right=buf;z++;
    }else if(d==2){
      buf=top;top=front;front=bottom;bottom=back;back=buf;x++;
    }else if(d==3){
      buf=top;top=right;right=bottom;bottom=left;left=buf;z--;
    }
    y--;
  }
  
};
int ch(int a,int b){
  int x=0;
  if(a==1&&b==3) x=5;if(a==1&&b==5) x=4;if(a==1&&b==4) x=2;if(a==1&&b==2) x=3;
  if(a==2&&b==3) x=1;if(a==2&&b==1) x=4;if(a==2&&b==4) x=6;if(a==2&&b==6) x=3;
  if(a==3&&b==6) x=5;if(a==3&&b==5) x=1;if(a==3&&b==1) x=2;if(a==3&&b==2) x=6;
  if(a==4&&b==1) x=5;if(a==4&&b==5) x=6;if(a==4&&b==6) x=2;if(a==4&&b==2) x=1;
  if(a==5&&b==3) x=6;if(a==5&&b==6) x=4;if(a==5&&b==4) x=1;if(a==5&&b==1) x=3;
  if(a==6&&b==4) x=5;if(a==6&&b==5) x=3;if(a==6&&b==3) x=2;if(a==6&&b==2) x=4;
  return x;
}

int main(){
  int n;
  cin >> n;
  while(n!=0){
    
    int i,j,k;
    int ex[100][100][100]={{{}}};
    dice d;
    vector<dice> v;
    
    for(i=0;i<n;i++){
      cin >> d.top >> d.front;
      d.bottom=7-d.top;
      d.back=7-d.front;
      d.right=ch(d.top,d.front);
      d.left=7-d.right;
      d.x=50;d.y=50;d.z=50;
      int f=0;
      while(f==0){
	//cout << d.y << endl;
	if(d.y==0) f=1;
	else if(ex[d.x][d.y-1][d.z]==0) d.y--;
	else {
	  if(d.front==6&&ex[d.x-1][d.y-1][d.z]==0) d.roll(0);
	  else if(d.right==6&&ex[d.x][d.y-1][d.z+1]==0) d.roll(1);
	  else if(d.back==6&&ex[d.x+1][d.y-1][d.z]==0) d.roll(2);
	  else if(d.left==6&&ex[d.x][d.y-1][d.z-1]==0) d.roll(3);
	  else if(d.front==5&&ex[d.x-1][d.y-1][d.z]==0) d.roll(0);
	  else if(d.right==5&&ex[d.x][d.y-1][d.z+1]==0) d.roll(1);
	  else if(d.back==5&&ex[d.x+1][d.y-1][d.z]==0) d.roll(2);
	  else if(d.left==5&&ex[d.x][d.y-1][d.z-1]==0) d.roll(3);
	  else if(d.front==4&&ex[d.x-1][d.y-1][d.z]==0) d.roll(0);
	  else if(d.right==4&&ex[d.x][d.y-1][d.z+1]==0) d.roll(1);
	  else if(d.back==4&&ex[d.x+1][d.y-1][d.z]==0) d.roll(2);
	  else if(d.left==4&&ex[d.x][d.y-1][d.z-1]==0) d.roll(3);
	  else f=1;
	}
      }
      ex[d.x][d.y][d.z]=1;
      v.push_back(d);
    }
    
    int o[7]={};
    for(i=0;i<v.size();i++) {
      if(ex[v[i].x][v[i].y+1][v[i].z]==0) o[v[i].top]++;
    }
    cout << o[1];
    for(i=2;i<=6;i++) cout << " " << o[i];
    cout << endl;
    cin >> n;
  }
  return 0;
}
