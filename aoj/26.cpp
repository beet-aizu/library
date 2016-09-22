#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
bool in(int x,int y){
  if(x<0||x>9||y<0||y>9) return false;
  return true;
}
int main(){
  int pa[10][10]={{}};
  string str;
  int i,j;
  while(cin >> str){
    int x=str[0]-'0',y=str[2]-'0',s=str[4]-'0';
    if(s==1){
      for(i=-1;i<=1;i++){
	for(j=-1+abs(i);j<=1-abs(i);j++){
	  if(in(x+i,y+j)) pa[x+i][y+j]++;
	}
      }
    }else if(s==2){
      for(i=-1;i<=1;i++){
	for(j=-1;j<=1;j++){
	  if(in(x+i,y+j)) pa[x+i][y+j]++;
	}
      }
    }else if(s==3){
      for(i=-2;i<=2;i++){
	for(j=-2+abs(i);j<=2-abs(i);j++){
	  if(in(x+i,y+j)) pa[x+i][y+j]++;
	}
      }
    }
  }
  int o=0,m=0;
  for(i=0;i<10;i++){
    for(j=0;j<10;j++){
      //cout << pa[i][j];
      m=max(m,pa[i][j]);
      if(pa[i][j]==0) o++;
    }
    //cout << endl;
  }
  cout << o << endl << m << endl;
  return 0;
}
